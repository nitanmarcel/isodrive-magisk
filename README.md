# isodrive (configfs)

* `apt install build-essential`

* `git clone https://github.com/nitanmarcel/isodrive`

* `cd isodrive`

* `make`

* `make install` (optional)

usage:

* `isodrive {iso} {cdrom[0/1]} {readonly[1/0]}`

mount

* `isodrive /full/path/to/file.iso`

umount

* `isodrive`

mount (as cdrom)

* `isodrive /full/path/to/file.iso 1 1`

mount (as read write)

* `isodrive /full/path/to/file.iso 0 0`

## Termux

* Run `su` before using isodrive command

## Os Support
* _Should support almost every bootable OS images, but for those who don't work or need extra steps, are documented in the [WIKI](https://github.com/nitanmarcel/isodrive/wiki)_

## Credits

Inspired by https://github.com/fredldotme/ISODriveUT
