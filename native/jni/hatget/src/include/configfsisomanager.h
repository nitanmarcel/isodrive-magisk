#ifndef CONFIGFSISOMANAGER_H
#define CONFIGFSISOMANAGER_H

bool  supported();
char* get_gadget_root();
char* get_config_root();

void  mount_iso(char *iso_path,
                char *cdrom,
                char *ro);
void  umount_iso();
void  set_udc(char *udc,
              char *gadget);
char* get_udc();

#endif // ifndef CONFIGFSISOMANAGER_H
