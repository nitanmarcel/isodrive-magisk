#ifndef UTIL_H
#define UTIL_H

char* fs_mount_point(char *filesystem_type);
char* strjin(char *w1,
             char *w2);
bool  isdir(char *path);
char* sysfs_read(char *path);
void  sysfs_write(char *path,
                  char *content);

#endif // ifndef UTIL_H
