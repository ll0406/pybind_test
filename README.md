# pybind_test
Test the c++ and python binding

## How to install
1. Download CMake at https://cmake.org/download/, put the app inside of Application folder.
2. Install CMake command line by running `sudo "/Applications/CMake.app/Contents/bin/cmake-gui" --install`
3. Clone this repo, and make a python virtual env
4. Install the requirements by running `pip install -r requirements.txt`
5. Run `cd first_bind` and `cmake .` and finally `make`
6. Inside of `first_bind` folder, start python shell, and run `import first_bind`
7. Run `first_bind.simple_thresh()`, you should see a list returned

Expected output
```
Python 2.7.10 (default, Aug 17 2018, 17:41:52)
[GCC 4.2.1 Compatible Apple LLVM 10.0.0 (clang-1000.0.42)] on darwin
Type "help", "copyright", "credits" or "license" for more information.
>>> import first_bind
>>> first_bind.simple_thresh()
[-1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0]
>>>
```
