cmake_minimum_required(VERSION 3.10)
project(test)
set(OpenCV_DIR "C:\\Users\\admin\\Documents\\BaiduSyncdisk\\games101_makefile\\Framework\\compile-opencv\\install\\x64\\mingw\\lib")
find_package(OpenCV 4.9.0 REQUIRED)
add_executable(test ./Main/Test1.cpp ./Main/rasterizer.cpp ./Main/Triangle.cpp)
set(CMAKE_CXX_STANDARD 17)

#添加头文件
include_directories(${OpenCV_INCLUDE_DIRS} "C:\\Users\\admin\\Documents\\BaiduSyncdisk\\games101_makefile\\Framework\\eigen-3.4.0")
#链接库文件
target_link_libraries(test ${OpenCV_LIBS})

link_directories("C:\\Program Files\\mingw64\\lib")

message(------>${OpenCV_LIBS})