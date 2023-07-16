cmake_minimum_required(VERSION 3.21)
project(2labcpp)

set(CMAKE_CXX_STANDARD 17)

set(libcurl_INCLUDE_DIR "C:/Users/tttee/CLionProjects/2labcpp/curl-7.84.0_9-win64-mingw/include")
include_directories(${libcurl_INCLUDE_DIR})

add_executable(2labcpp main.cpp CurrencyObject/Currency.cpp CurrencyObject/Currency.h utility/MedianHeap.cpp utility/MedianHeap.h Manager/CurrencyManager.cpp Manager/CurrencyManager.h include/simple_include.h)

target_link_libraries(2labcpp C:/Users/tttee/CLionProjects/2labcpp/curl-7.84.0_9-win64-mingw/lib/libcurl.dll.a)