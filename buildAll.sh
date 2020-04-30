set -e

pushd zlib
mkdir -p build
pushd build
mkdir -p debug
mkdir -p release
pushd debug
cmake -DCMAKE_BUILD_TYPE=Debug ../../
# The first run forces release, so run again to override
cmake -DCMAKE_BUILD_TYPE=Debug ../../
make -j8
popd
pushd release
cmake -DCMAKE_BUILD_TYPE=Release ../../
make -j8
popd
popd
popd

pushd tinyxmldll
mkdir -p build
pushd build
mkdir -p debug
mkdir -p release
pushd debug
cmake -DCMAKE_BUILD_TYPE=Debug ../../
# The first run forces release, so run again to override
cmake -DCMAKE_BUILD_TYPE=Debug ../../
make -j8
popd
pushd release
cmake -DCMAKE_BUILD_TYPE=Release ../../
make -j8
popd
popd
popd

pushd Board
mkdir -p build
pushd build
mkdir -p debug
mkdir -p release
pushd debug
cmake -DCMAKE_BUILD_TYPE=Debug ../../
# The first run forces release, so run again to override
cmake -DCMAKE_BUILD_TYPE=Debug ../../
make -j8 board
popd
pushd release
cmake -DCMAKE_BUILD_TYPE=Release ../../
make -j8 board
popd
popd
popd

pushd JGTL
mkdir -p build
pushd build
mkdir -p debug
mkdir -p release
pushd debug
cmake -DCMAKE_BUILD_TYPE=Debug ../../
# The first run forces release, so run again to override
cmake -DCMAKE_BUILD_TYPE=Debug ../../
make -j8
popd
pushd release
cmake -DCMAKE_BUILD_TYPE=Release ../../
make -j8
popd
popd
popd

pushd NE/HyperNEAT
mkdir -p build
pushd build
mkdir -p debug
mkdir -p release
#pushd debug
#cmake -DCMAKE_BUILD_TYPE=Debug ../../
# The first run forces release, so run again to override
#cmake -DCMAKE_BUILD_TYPE=Debug ../../
#make -j8
#popd
pushd release
cmake -DCMAKE_BUILD_TYPE=Release ../../
make VERBOSE=1 -j8
popd
popd
popd
