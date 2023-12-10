# isodrive (configfs)

## Building

* `sudo apt install build-essential`

* `git clone https://github.com/nitanmarcel/isodrive`

* `cd isodrive`

* `make`

* `sudo make install` (optional)

## Usage

Run `su` to be able to access and use the `isodrive` command.

```
Usage:
isodrive [FILE]... [OPTION]...
Mounts the given FILE as a bootable device using configfs.
Run without any arguments to unmount any mounted files and display this help message.

Optional arguments:
-rw		Mounts the file in read write mode.
-cdrom		Mounts the file as a cdrom.
-configfs	Forces the app to use configfs.
-usbgadget	Forces the app to use sysfs.
```

## Os Support
* _Should support almost every bootable OS images, but for those who don't work or need extra steps, are documented in the [WIKI](https://github.com/nitanmarcel/isodrive/wiki)_

## Download
The only officially maintained versions by me are available on [github releases](https://github.com/nitanmarcel/isodrive-magisk/releases/) and [Magisk-Modules-Alt-Repo](https://github.com/Magisk-Modules-Alt-Repo). I assume no liability for any downloads  originating from unofficial sources.

## Source Code
* https://github.com/nitanmarcel/isodrive-magisk
* 
## Credits

Inspired by https://github.com/fredldotme/ISODriveUT
