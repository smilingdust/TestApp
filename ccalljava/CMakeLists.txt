 #cmake要求的最小版本
    cmake_minimum_required(VERSION 3.4.1)

    #声明一个dir路径
    set(SO_DIR ${CMAKE_SOURCE_DIR}/libs)

    #设置当前工程引用外部动态库
        # set add lib
        add_library(javacallc SHARED IMPORTED)
        #设置引用外部动态库so的引用路径
        set_target_properties(javacallc PROPERTIES IMPORTED_LOCATION
                              jni/libs/libjavacallc.so)
        #设置外部动态库so需要引用的头文件路径
        #include_directories(javacallc jni/include)

    #设置当前工程需要编译的动态库名称和编译文件名称
    add_library(ccalljava
                SHARED
                src/main/jni/CCallJava.cpp)
    #设置当前工程要生成的动态库目录
    set_target_properties(ccalljava PROPERTIES
                          LIBRARY_OUTPUT_DIRECTORY ${SO_DIR}/${ANDROID_ABI})
    #找到系统提供的支持库
    find_library( log-lib
                   log)
    #将log库链接到javacallc
    target_link_libraries(ccalljava
                          ${log-lib}
                          )