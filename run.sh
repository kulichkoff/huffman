#!/bin/bash
bash ./build.sh
cd build
./huffman
cd ..
rm -rf build
