#!/bin/sh

SRC_PATH="../src"

gcc $SRC_PATH/controllers/*.c \
    $SRC_PATH/interfaces/*.c \
    $SRC_PATH/models/*.c \
    $SRC_PATH/menu/*.c \
    $SRC_PATH/main.c \
    -o \
    main.x

exit 0
