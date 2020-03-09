#!/bin/bash
cp ../../myheader.hpp .
rm build -rf
mkdir build && cd build && cmake ..
make all
make test
