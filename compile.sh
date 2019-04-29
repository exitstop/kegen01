#!/bin/bash

function clean {
    rm -R -f debug
    rm -R -f release
}

function build {
    build_type=$1
    lowercase_build_type=$(echo ${build_type} | tr '[:upper:]' '[:lower:]')
    mkdir -p $lowercase_build_type
    cd $lowercase_build_type
    cmake -GNinja .. -DCMAKE_BUILD_TYPE=$build_type
    ninja
    cd ..
}

if [ $# -eq 0 ]; then
    build Debug
    build Release
elif [ "$1" = "clean" ]; then
    clean
elif [ "$1" = "debug" ]; then
    build Debug
elif [ "$1" = "release" ]; then
    build Release
elif [ "$1" = "all" ]; then
    build Debug
    build Release
else
    echo "build.sh <clean|all|debug|release|help>"
fi
