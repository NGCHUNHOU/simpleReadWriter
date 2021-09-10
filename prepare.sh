#!/bin/bash
g++ -c -fPIC ./lib/libcore.cpp 
mv ./libcore.o ./lib/
g++ -shared -fPIC ./lib/libcore.o -o ./lib/libcore.so
g++ -c -fPIC ./data/datacenter.cpp 
mv ./datacenter.o ./data/
g++ -shared -fPIC ./data/datacenter.o -o ./data/datacenter.so