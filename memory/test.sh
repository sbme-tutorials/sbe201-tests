#!/bin/bash
cp ../../myheader.hpp .
mkdir build && cd build && cmake ..
make test
