#!/bin/bash
DIR=$1
TARGET=leetcode

make clean DIR=${DIR} > /dev/null
if [ $? -eq 0 ]; then
	make DIR=${DIR}
	if [ $? -eq 0 ]; then
		echo "------------------"
		./${TARGET}
		make clean DIR=${DIR} > /dev/null
	fi
fi