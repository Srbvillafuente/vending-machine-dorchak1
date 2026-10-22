cmake_minimum_required(VERSION 4.1)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        PackageSlot.h
        Door.h
        SnackDispenser.cpp
        SnackRow.cpp
        PackageSlot.cpp
        RetrievalBin.cpp
        SnackStorage.cpp
        slotRow.h)
