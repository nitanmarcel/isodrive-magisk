#!/usr/bin/env bash

set -euo pipefail

build_mode="${1:-release}"

cd "$(dirname "$0")"

pushd native
rm -fr libs obj
debug_mode=1
if [[ "$build_mode" == "release" ]]; then
    debug_mode=0
fi
ndk-build -j4 NDK_DEBUG=$debug_mode
popd

rm -rf out/*
mkdir -p out
cp -af hatget-module out
mv -fT native/libs out/hatget-module/libs

cd out/hatget-module
MODULE_TARGET_ZIP="../hatget-$(sed -n 's/^version=//p' module.prop).zip"
zip -r9 -X $MODULE_TARGET_ZIP * -x \.* libs/\.*
cd -
