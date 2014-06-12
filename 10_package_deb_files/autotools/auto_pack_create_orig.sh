#!/bin/sh -x
# Prepare tarball
SRC_DIR=../../08_autoconf
cd $SRC_DIR
./autogen.sh
./configure
make dist

# Pack package with --createorig option
cd -
TEST_DIR=test
rm -rf $TEST_DIR
mkdir -p $TEST_DIR
cd $TEST_DIR
tar -zxvf ../$SRC_DIR/testautotools-0.tar.gz
cd testautotools-0
echo -e "\n" | dh_make --createorig -s
dpkg-buildpackage -uc -us
