# Mantrana
Cross platform GUI desktop chat application made with QT

## Build

### Dependencies
* Qt5 with base and websocket packages
* cmake version >= 3.5

### Windows

You may need to set path to point to Qt5's msvc build tools's bin directory.

```
cd <source-directory>
cmake . -B <build-directory>
cmake --build <build-directory>
```

### Linux

```
cd <source-directory>
cmake . -B <build-directory>
cmake --build <build-directory>
```

This will create binaries in cmake build directory
