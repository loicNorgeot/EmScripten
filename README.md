![Build status](https://travis-ci.org/loicNorgeot/EmScripten.svg)

#Emscripten compilation tests

Understand the use of EmScripten with C++ code and libraries

##Pre-requisites

* [node.js](http://nodejs.org)
* [git](https://git-scm.com/)
* [cmake](https://cmake.org/)
* [SDK EmScripten](http://kripken.github.io/emscripten-site/)
* [Xcode and command line tools (OSX only)](http://superuser.com/questions/455214/where-is-svn-on-os-x-mountain-lion#answer-455216)

##Build

### Classical installation
Pour générer les librairies et executables:
```
mkdir build
cd build
cmake ..
make
make install
```

### Emscripten compilation workflow
Pour générer un .js et .html:
```
mkdir build
cd build
cmake -DWEB=ON ..
make
```

##Examples

Coming soon...
