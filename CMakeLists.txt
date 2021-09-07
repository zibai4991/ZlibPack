cmake_minimum_required(VERSION 3.20)
project(ZlibPack)

set(CMAKE_CXX_STANDARD 17)

#设置链接库
link_libraries(z)
aux_source_directory(. SRC_LIST)        #搜索当前目录下的所有.cpp文件

add_executable(ZlibPack ${SRC_LIST})
