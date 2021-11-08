cmake_minimum_required(VERSION 3.10)
project(Torii_1_0_1103)
include_directories(./Ctest-master)
set(SRC Ctest-master/Myserver.cpp Ctest-master/MyAnalysisNew.cpp
        Ctest-master/MyCThreadTest.cpp Ctest-master/MyFuncTest.c Ctest-master/ThreadPool.c
        Ctest-master/Analyse.cpp Ctest-master/Analyse_two.cpp Ctest-master/Config.cpp Ctest-master/do_analyse.cpp Ctest-master/do_servlet.cpp
        Ctest-master/epoll.cpp Ctest-master/File.cpp Ctest-master/ReadHtml.cpp Ctest-master/redis.cpp
        Ctest-master/ServerSocket.cpp Ctest-master/servlet.cpp Ctest-master/spellresponse.cpp
        Ctest-master/Time.cpp Ctest-master/MyController.cpp)
set(HEAD Ctest-master/InitConfig.cpp Ctest-master/InitConfig.h Ctest-master/simple_thread_pool.cpp Ctest-master/simple_thread_pool.h Ctest-master/doepoll.cpp Ctest-master/doepoll.h Ctest-master/mythread.cpp Ctest-master/mythread.h)
set(CMAKE_CXX_STANDARD 11)

add_executable(Torii_1_0_1103 main.cpp ${SRC} ${HEAD})
TARGET_LINK_LIBRARIES(Torii_1_0_1103 pthread )