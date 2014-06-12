#!/bin/sh -x
# Configs
SRC_DIR=../../12_cmake
TEST_DIR=test
SRC_NAME=$(basename $SRC_DIR)
PKG_NAME=testcmake
VER=1

# Prepare tarball
rm -rf $TEST_DIR
mkdir -p $TEST_DIR
cp -rv $SRC_DIR test
mv test/$SRC_NAME test/$PKG_NAME-$VER
rm -rf test/$PKG_NAME-$VER/build
cd $TEST_DIR
tar zcvf ${PKG_NAME}_$VER.orig.tar.gz $PKG_NAME-$VER

# Packing
cd $PKG_NAME-$VER
echo -e "\n" | dh_make -s
dpkg-buildpackage -uc -us
