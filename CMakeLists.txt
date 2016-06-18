cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE  "Release")

INCLUDE_DIRECTORIES(  "/usr/local/include/")
LINK_DIRECTORIES(     "/usr/local/lib/")

set(WEB false CACHE BOOL "Use web and compile with emscripten")
if(WEB)
	set(EM_DIR "~/Downloads/emsdk_portable/emscripten/1.35.0/")
	set(CMAKE_TOOLCHAIN_FILE "${EM_DIR}cmake/Modules/Platform/Emscripten.cmake")
	set(LIB STATIC)
	set(TYPE ARCHIVE)	
else()
	set(LIB SHARED)
	set(TYPE LIBRARY)
endif()

SET(CMAKE_CXX_FLAGS   "-w -g -O3")
set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

#library
project(myLibrary)
file(                  GLOB_RECURSE source_files src/*.cpp)
file(                  GLOB_RECURSE header_files src/*.h)
add_library(           myLib ${LIB} ${source_files})


#executable
project(myExecutable)
if(WEB)
	set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()
add_executable(        myExe main.cpp)
target_link_libraries( myExe myLib)

INSTALL(               TARGETS myLib ${TYPE} DESTINATION "/usr/local/lib/")
INSTALL(               FILES ${header_files} DESTINATION "/usr/local/include/")
INSTALL(               TARGETS myExe RUNTIME DESTINATION "/usr/local/bin/")
