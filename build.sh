#!/bin/sh

[ -d ".build" ] || mkdir ".build"
CURR=`pwd`
export CC="ccache gcc"
export CXX="ccache g++"

pushd ".build"
cmake "$CURR" $@
make -j5
popd
