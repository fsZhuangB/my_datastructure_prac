# makefile
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (doubly_linked_list)

aux_source_directory(/Users/fszhuangb/Documents/my_datastructure_prac/list/doubly_linked_list/src DIR_SRCS)
# 指定生成目标
add_executable(list2 ${DIR_SRCS})

add_definitions(-std=c++11)