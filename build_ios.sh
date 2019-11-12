#! /bin/sh

set -ex

function compile_unistring() {
    local SDK=$1
    local PLATFORM=$2
    local HOST=$3
    local SUFFIX=$4

    local DEVELOPER_DIR="$(xcode-select -p)"
    local VERSION_MIN="9.0"

    local DEVROOT="${DEVELOPER_DIR}/Platforms/${SDK}.platform/Developer"
    local SDKROOT="${DEVROOT}/SDKs/${SDK}.sdk"

    export PREFIX="$(pwd)/${SUFFIX}"
    mkdir -p ${PREFIX}

    export PATH="${DEVROOT}/usr/bin:${DEVROOT}/usr/sbin:${PATH}"

    local COMMON_FLAGS="-arch ${PLATFORM} -isysroot ${SDKROOT} -mios-version-min=${VERSION_MIN} -fembed-bitcode"

    export CPPFLAGS="-I${PREFIX}/include ${COMMON_FLAGS} -I${SDKROOT}/usr/include -O2 -g -Wno-error=tautological-compare"
    export LDFLAGS="-L$(pwd)/lib ${COMMON_FLAGS} -L${SDKROOT}/usr/lib -Wno-error=unused-command-line-argument"

    ./configure \
        --prefix="${PREFIX}" \
        --host=${HOST} \
        --disable-shared
    make -j 10
    make install
}

git pull && ./gitsub.sh pull
./autogen.sh
compile_unistring iPhoneOS          arm64   arm-apple-darwin    .build/iphoneos-arm64
# compile_unistring iPhoneOS          armv7   arm-apple-darwin    .build/iphoneos-armv7
# compile_unistring iPhoneOS          armv7s  arm-apple-darwin    .build/iphoneos-armv7s
# compile_unistring iPhoneSimulator   i386    i686-apple-darwin   .build/iphonesimulator-i386
# compile_unistring iPhoneSimulator   x86_64  x86_64-apple-darwin .build/iphonesimulator-x86_64

# mkdir -p .build/iphoneos/lib .build/iphonesimulator/lib
# cp -R .build/iphoneos-arm64/include .build/
# lipo -create .build/iphoneos-{arm64,armv7,armv7s}/lib/libunistring.a -output .build/iphoneos/lib/libunistring.a
# lipo -create .build/iphonesimulator-{i386,x86_64}/lib/libunistring.a -output .build/iphonesimulator/lib/libunistring.a
