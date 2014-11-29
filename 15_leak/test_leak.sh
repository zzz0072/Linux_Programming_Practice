#!/bin/sh
rm -f leak
CFLAGS=" -g" make leak

#valgrind --verbose --db-attach=yes ./leak
valgrind --vgdb=yes --vgdb-error=0 ./leak
#valgrind --leak-check=full --show-leak-kinds=all --verbose ./leak
