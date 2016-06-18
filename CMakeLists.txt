cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE  "Release")

INCLUDE_DIRECTORIES(  "/usr/local/include/")
LINK_DIRECTORIES(     "/usr/local/lib/")

SET(CMAKE_CXX_FLAGS   "-w -g -O3")
set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

#Elasticity library
project(myLibrary)
file(                  GLOB_RECURSE source_files src/*.cpp)
file(                  GLOB_RECURSE header_files src/*.h)
ADD_LIBRARY(           myLib SHARED ${source_files})
#find_library(          Commons NAMES Commons HINTS "lib")
#target_link_libraries( Elas Commons)
INSTALL(               TARGETS myLib LIBRARY DESTINATION "/usr/local/lib/")
INSTALL(               FILES ${header_files} DESTINATION "/usr/local/include/")

#Executable
project(myExecutable)
add_executable(        myExe main.cpp)
target_link_libraries( myExe myLib)
INSTALL(               TARGETS myExe RUNTIME DESTINATION "/usr/local/bin/")


 



