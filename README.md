# Mantrana
[![Build Status](https://app.travis-ci.com/jatindalal/mantrana.svg?branch=main)](https://app.travis-ci.com/jatindalal/mantrana)

Cross platform GUI desktop chat application made with QT

## Build

### Dependencies
* Qt5 base and websocket packages
* Cmake version >= 3.5
* (Optionally) Ninja

### Instructions

Make sure you have a C++ compiler and cmake can find QT5 config files.

#### Using Cmake
```
cmake . -B <build-directory>
cmake --build <build-directory> -j <jobs>
```

The number of jobs can be set in accordance with your cpu cores or can be ignored.

#### Using Cmake + Ninja
```
cmake . -B <build-directory> -G Ninja
cd <build-directory>
ninja
```

#### Docker for server

```
docker build . --tag mantrana
docker run --rm -itd -p 8880:8880 \
                     -v $(pwd)/config:/home/mantrana/config \
                     -u $(id -u):$(id -g) \
                     mantrana
```
