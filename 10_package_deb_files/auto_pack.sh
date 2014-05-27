#!/bin/sh -x
# Prepare tarball
SRC_DIR=../08_autoconf
cd $SRC_DIR
./autogen.sh
./configure
make dist

# Add orig before generate dsc file
cd -
TEST_DIR=test
mkdir -p $TEST_DIR
cd $TEST_DIR
# mv ../$SRC_DIR/testautotools-0.tar.gz testautotools_0.orig.tar.gz
# tar -zxvf testautotools_0.orig.tar.gz
# cd testautotools-0
# dh_make
tar -zxvf ../$SRC_DIR/testautotools-0.tar.gz
cd testautotools-0
echo -e "\n" | dh_make --createorig -s
dpkg-buildpackage
