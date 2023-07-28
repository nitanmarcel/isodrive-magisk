#include <fcntl.h>
#include <mntent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <array>
#include <memory>
#include <cstdio>
#include <dirent.h>

char* fs_mount_point(char *filesystem_type)
{
  struct mntent *ent;
  FILE *mounts;
  char *mount_point = nullptr;

  mounts = setmntent("/proc/mounts", "r");

  while (nullptr != (ent = getmntent(mounts)))
  {
    if (strcmp(ent->mnt_fsname, filesystem_type) == 0)
    {
      mount_point = ent->mnt_dir;
      break;
    }
  }

  // Alternate search location on Android
  if (mount_point == nullptr)
  {
    const char *alt_usb_gadget = "/config/usb_gadget";
    DIR *dir                   = opendir(alt_usb_gadget);

    if (dir)
    {
      mount_point = (char *)"/config";
    }
  }
  return mount_point;
}

char* strjin(char *w1, char *w2)
{
  char *s = new char[strlen(w1) + strlen(w2) + 1];

  strcpy(s, w1);
  strcat(s, w2);
  return s;
}

bool isdir(char *path)
{
  struct stat sb;

  if (stat(path, &sb) == 0)
    return true;
  else
    return false;
}

void sysfs_write(char *path, char *content)
{
  printf("Write: %s -> %s\n", content, path);
  std::ofstream sysfsFile(path);
  sysfsFile << content << std::endl;
  sysfsFile.close();
}

char* sysfs_read(char *path)
{
  std::string   value;
  std::ifstream sysfsFile(path);

  if (!sysfsFile.is_open())
  {
    return nullptr;
  }
  sysfsFile >> value;
  sysfsFile.close();

  if (value.empty())
  {
    return nullptr;
  }
  char *result = new char[value.length() + 1];

  strcpy(result, value.c_str());
  return result;
}
