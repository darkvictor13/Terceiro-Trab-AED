#!/bin/sh

SRC_PATH="../src"
TESTS_PATH="../tests"

gcc $SRC_PATH/models/*.c \
    $SRC_PATH/menu/*.c \
    $TESTS_PATH/main_test.c \
    -o \
    main_test.x

exit 0
