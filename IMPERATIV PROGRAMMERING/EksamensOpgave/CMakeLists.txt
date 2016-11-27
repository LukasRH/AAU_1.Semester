cmake_minimum_required(VERSION 3.6)
project(EksamensOpgave)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    superliga-2015-2016
    superliga.c)

add_executable(EksamensOpgave ${SOURCE_FILES})