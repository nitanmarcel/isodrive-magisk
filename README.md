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
cdrom [FILE]... [OPTION]...
Mounts the given FILE as a bootable device using configfs.
Run without any arguments to unmount any mounted files and to display this help message.

Optional arguments:
-rw	 Mounts the file in read write mode.
-cdrom	 Mounts the file as a cdrom.
```

## Os Support
* _Should support almost every bootable OS images, but for those who don't work or need extra steps, are documented in the [WIKI](https://github.com/nitanmarcel/isodrive/wiki)_

## Source Code
* https://github.com/nitanmarcel/isodrive-magisk

## Credits

Inspired by https://github.com/fredldotme/ISODriveUT
