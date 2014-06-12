#!/bin/sh -x
# Prepare tarball
SRC_DIR=../../08_autoconf
cd $SRC_DIR
./autogen.sh
./configure
make dist

# Add orig and create package
cd -
TEST_DIR=test
rm -rf $TEST_DIR
mkdir -p $TEST_DIR
cd $TEST_DIR
mv ../$SRC_DIR/testautotools-0.tar.gz testautotools_0.orig.tar.gz
tar -zxvf testautotools_0.orig.tar.gz
cd testautotools-0
echo -e "\n" | dh_make -s
dpkg-buildpackage -uc -us
