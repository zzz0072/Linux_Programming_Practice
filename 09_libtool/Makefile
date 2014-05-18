COMPILE_DIRS = libs src
INC_DIR=$(shell pwd)/include

.PHONY: all

all:
	for i in $(COMPILE_DIRS); do make -C $$i INC_DIR=$(INC_DIR); done

clean:
	for i in $(COMPILE_DIRS); do make -C $$i INC_DIR=$(INC_DIR) clean; done
