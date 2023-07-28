# hatget (configfs)

## Building a single host executable
```
sudo apt install build-essential
git clone https://github.com/newbit1/hatget && cd hatget/native/jni/hatget
make
```

## Build the whole Package
```
wget https://dl.google.com/android/repository/android-ndk-r25c-linux.zip
unzip android-ndk-r25c-linux.zip
export PATH=$(pwd)/android-ndk-r25c:$PATH
git clone https://github.com/newbit1/hatget.git && cd hatget
git submodule update --init --depth 1 -j $(nproc)
./build.sh
```

## Usage
Run `su` to be able to access and use the `hatget` command.
```
hatget [FILE]... [OPTION]...
Mounts the given FILE as a bootable device using configfs.
Run without any arguments to unmount any mounted files and to display this help message.

Optional arguments:
-rw	 Mounts the file in read write mode.
-cdrom	 Mounts the file as a cdrom.
```
### Examples

mount iso as rw
```bash
hatget /path/to/file.iso -rw
```

mount iso as cdrom
```bash
hatget /path/to/file.iso -cdrom
```

## Linux
* Has been only tested on Halium based mobile linux, but should work on mainline devices too.

## Android
* can be compiled in termux, using clang++
* you might manually need to mount configfs by running: `mount -t configfs configfs /sys/kernel/config`

## Os Support
* _Should support almost every bootable OS images, but for those who don't work or need extra steps, are documented in the [WIKI](https://github.com/nitanmarcel/isodrive/wiki)_

## Original Source Code
* [Nitan Alexandru Marcel isodrive-magisk](https://github.com/nitanmarcel/isodrive-magisk)

## Credits
* [Inspired by Alfred E. Neumayer (fredldotme)](https://github.com/fredldotme/ISODriveUT)
* [Forked from Nitan Alexandru Marcel (nitanmarcel)](https://github.com/nitanmarcel/isodrive)
