#Building instructions

## Classical installation
Pour générer les librairies et executables:
    mkdir build
    cd build
    cmake ..
    make
    make install
    
## Emscripten compilation workflow
Pour générer un .js et .html:
    mkdir build
    cd build
    cmake -DWEB=ON
    make