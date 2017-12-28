    #cmake要求的最小版本
    cmake_minimum_required(VERSION 3.4.1)

    #声明一个dir路径
    set(SO_DIR ${CMAKE_SOURCE_DIR}/libs)

    #设置当前工程需要编译的动态库名称和编译文件名称
    add_library(javacallc
                SHARED
                src/main/cpp/JavaCallC.cpp)
    #设置当前工程要生成的动态库目录
    set_target_properties(javacallc PROPERTIES
                          LIBRARY_OUTPUT_DIRECTORY ${SO_DIR}/${ANDROID_ABI})
    #找到系统提供的支持库
    find_library( log-lib
                   log)
    #将log库链接到javacallc
    target_link_libraries(javacallc
                          ${log-lib}
                          )