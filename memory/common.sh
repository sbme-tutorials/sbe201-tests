#!/bin/bash
cp ../../myheader.hpp .
rm build -rf
mkdir build && cd build && cmake ..
make all
cd ..
chmod a+x ./test1.sh 