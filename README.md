# Reproduce an PyInstaller issue

https://github.com/pyinstaller/pyinstaller/issues/2357

1. Install CMake 3.18.2, gcc/g++/c++ 7.5.0, boost 1.71.0, Python 3.7.9 and PyInstaller 4.0.0.
2. Open `cpp/CmakeLists.txt` and replace `${CMAKE_CURRENT_SOURCE_DIR}/../../downloads/boost_1_71_0` with the actual path to your boost folder.
3. Run `./build.sh` then `./run.sh`.
4. You should see something like `[19373] Cannot open self /.../dist/appname or archive /.../dist/appname.pkg`