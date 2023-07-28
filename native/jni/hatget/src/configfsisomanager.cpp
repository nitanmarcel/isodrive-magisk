
#include <sys/stat.h>
#include <sys/types.h>

#include "util.h"
#include "configfsisomanager.h"
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

bool supported()
{
  return fs_mount_point((char *)"configfs") != nullptr;
}

char* get_gadget_root()
{
  char *configFsRoot  = fs_mount_point((char *)"configfs");
  char *usbGadgetRoot = strjin(configFsRoot, (char *)"/usb_gadget/");
  char *gadgetRoot    = nullptr;

  struct dirent *entry = nullptr;
  DIR *dp              = nullptr;

  dp = opendir(usbGadgetRoot);

  if (dp != nullptr)
  {
    while ((entry = readdir(dp)))
    {
      if (entry->d_name[0] != '.')
      {
        char *gadget = strjin(usbGadgetRoot, entry->d_name);

        if (sysfs_read(strjin(gadget, (char *)"/UDC")) != nullptr)
        {
          gadgetRoot = gadget;
          break;
        }
      }
    }
  }
  return gadgetRoot;
}

char* get_config_root()
{
  char *gadgetRoot = get_gadget_root();

  if (gadgetRoot == nullptr)
  {
    return nullptr;
  }
  char *usbConfigRoot = strjin(gadgetRoot, (char *)"/configs/");
  char *configRoot    = nullptr;

  struct dirent *entry = nullptr;
  DIR *dp              = nullptr;

  dp = opendir(usbConfigRoot);

  if (dp != nullptr)
  {
    while ((entry = readdir(dp)))
    {
      if (entry->d_name[0] != '.')
      {
        configRoot = strjin(usbConfigRoot, entry->d_name);
        break;
      }
    }
  }
  return configRoot;
}

void mount_iso(char *iso_path, char *cdrom, char *ro)
{
  char *gadgetRoot = get_gadget_root();

  if (gadgetRoot == nullptr)
  {
    printf("No active gadget found\n");
    return;
  }
  char *configRoot      = get_config_root();
  char *udc             = get_udc();
  char *functionRoot    = strjin(gadgetRoot, (char *)"/functions");
  char *massStorageRoot = strjin(functionRoot, (char *)"/mass_storage.0");
  char *lunRoot         = strjin(massStorageRoot, (char *)"/lun.0");

  char *stallFile = strjin(massStorageRoot, (char *)"/stall");
  char *udcFile   = strjin(gadgetRoot, (char *)"/UDC");
  char *lunFile   = strjin(lunRoot, (char *)"/file");
  char *lunCdRom  = strjin(lunRoot, (char *)"/cdrom");
  char *lunRo     = strjin(lunRoot, (char *)"/ro");

  set_udc((char *)"", gadgetRoot);

  if (!isdir(massStorageRoot))
  {
    mkdir(massStorageRoot, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  }

  if (!isdir(strjin(configRoot, (char *)"/mass_storage.0")))
  {
    symlink(massStorageRoot, strjin(configRoot, (char *)"/mass_storage.0"));
  }
  sysfs_write(lunCdRom, cdrom);
  sysfs_write(lunRo,    ro);
  sysfs_write(lunFile,  iso_path);

  set_udc(udc, gadgetRoot);
}

void set_udc(char *udc, char *gadget)
{
  char *udcFile = strjin(gadget, (char *)"/UDC");

  sysfs_write(udcFile, udc);
}

char* get_udc()
{
  char *gadget_root = get_gadget_root();

  if (gadget_root == nullptr)
  {
    return nullptr;
  }
  char *udcFile = strjin(gadget_root, (char *)"/UDC");

  return sysfs_read(udcFile);
}
