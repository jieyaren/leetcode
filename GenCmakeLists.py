#!/usr/bin/python3
#coding=utf-8

EXCEPT_FOLDERS = ['CMakeFiles','.git']

CMakeRequireBegin = '''
cmake_minimum_required(VERSION 3.5)
set(src_list 
main.cpp
'''


CMakeRequireEnd=''')
add_executable(run_test ${src_list})
add_definitions("-Wall -std=c++11 -g -O2 ")
enable_testing()
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(run_test ${GTEST_BOTH_LIBRARIES})
target_link_libraries(run_test pthread)
add_test(AllTestsInFoo run_test)
'''

import os
if __name__ == '__main__':
    src_list=""
    for root,dirs,files in os.walk('.'):
        for name in files:
            l= os.path.join(root,name).split('\\');
            if len(l) > 2:
                if l[1] not in EXCEPT_FOLDERS:
                    src_list+=os.path.join(root,name)[2:]
                    src_list+="\r\n"
                    #print(l)
                
    try:
        h = open(".\CMakeLists.txt",'w+')
        h.write(CMakeRequireBegin+src_list.replace('\\','/')+CMakeRequireEnd)
        
    except:
        pass
    finally:
        h.close()
        
