#!/bin/bash
mkdir build
cd build
../libedit-20130712-3.1/configure --prefix=$HOME/.local ; make -j4; make install
