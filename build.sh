#!/bin/bash
cd luajit-2.0
make
cd ..

echo "Building luajit_template"
clang++ -std=c++11 *.cpp -l luajit -L luajit-2.0/src/ -I luajit-2.0/src/ -arch i386 -o luajit_template
echo "==================="
