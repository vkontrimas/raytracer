# raytracer
A simple project used to learn raytracing and practice setting up a project.

## Building
This project uses CMake.

### Linux
Run the following in the project root:    
```bash
mkdir build
cd build
cmake ..
make
```
### Windows
1. Open the project via the CMake GUI, configure and generate.
2. Build the produced project.

## Running
Build the project and run `rayexe/ray` (or `rayexe/ray.exe` on Windows) within the build directory. 

## Testing
Build the project with the `BUILD_TESTING` option enabled. Then, run `raytest/testray` (or `raytest/testray.exe` on
Windows) within the build directory.

The project depends on [Catch2](https://github.com/catchorg/Catch2) for testing. It is automatically downloaded by
cloning the git repository when the project is built using CMake with `BUILD_TESTING` enabled.

