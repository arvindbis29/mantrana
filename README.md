# Mantrana
Cross platform GUI desktop chat application made with QT

## Build

### Dependencies
* Qt5 base and websocket packages
* Cmake version >= 3.5
* (OPTIONALLY) Ninja

### Instructions

Make sure you have a C++ compiler and cmake can find QT5 config files.

#### Using Cmake
```
cmake . -B <build-directory>
cmake --build <build-directory> -j <jobs>
```

The no. of jobs can be set according to your processor's no. of cores for faster builds.

#### Using Cmake + Ninja
```
cmake . -G Ninja -B <build-directory>
cd <build-directory>
ninja
```

This will create binaries in cmake build directory

