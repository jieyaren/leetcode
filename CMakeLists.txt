
cmake_minimum_required(VERSION 3.5)
set(src_list 
main.cpp
get_min_stack/getMin.cpp
impl_queue_with_stack/queue.cpp
)
add_executable(run_test ${src_list})
add_definitions("-Wall -std=c++11 -g -O2 ")
enable_testing()
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(run_test ${GTEST_BOTH_LIBRARIES})
target_link_libraries(run_test pthread)
add_test(AllTestsInFoo run_test)
