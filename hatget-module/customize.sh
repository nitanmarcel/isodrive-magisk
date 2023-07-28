#zip -r -X ../hatget-magisk-$(sed -n 's/^version=//p' module.prop).zip * -x \.* libs/\.*
# Set to true if you do *NOT* want Magisk to mount
# any files for you. Most modules would NOT want
# to set this flag to true
SKIPMOUNT=false

# Set to true if you need to load system.prop
PROPFILE=false

# Set to true if you need post-fs-data script
POSTFSDATA=false

# Set to true if you need late_start service script
LATESTARTSERVICE=false

VERSION=$(grep_prop version "${TMPDIR}/module.prop")
api_level_arch_detect

ui_print ""
ui_print "  hatget ${VERSION} on $ABI          "
ui_print "  Use your mobile device to boot Linux "
ui_print "  distributions/ISO files on your PC   "
ui_print "  the Gatget Hatchet                   "
ui_print ""

if $BOOTMODE; then
	ui_print "- Installing from Magisk app"
else
	ui_print "*********************************************************"
	ui_print "! Install from recovery is NOT supported"
	ui_print "! Recovery sucks"
	ui_print "! Please install from Magisk app"
	abort "*********************************************************"
fi

[ ! -d "$MODPATH/libs/$ABI" ] && abort "! $ABI not supported"

mkdir -p "$MODPATH/system/bin"
cp -af "$MODPATH/libs/$ABI/"* "$MODPATH/system/bin"
rm -rf "$MODPATH/libs"

set_perm "$MODPATH/system/bin/hatget" 0 0 0755 u:object_r:system_file:s0
