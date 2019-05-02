#!/bin/bash

function clean {
    rm -R -f debug
    rm -R -f release
    rm -R -f relwithdebinfo
    rm -R -f MinSizeRel
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
    build relwithdebinfo
elif [ "$1" = "clean" ]; then
    clean
elif [ "$1" = "debug" ]; then
    build Debug
elif [ "$1" = "release" ]; then
    build Release
elif [ "$1" = "relwithdebinfo" ]; then
    build RelWithDebInfo
elif [ "$1" = "minsizerel" ]; then
    build MinSizeRel
elif [ "$1" = "all" ]; then
    build Debug
    build Release
    build RelWithDebInfo
    build MinSizeRel
else
    echo "compile.sh <clean|all|debug|release|relwithdebinfo|>"
fi
