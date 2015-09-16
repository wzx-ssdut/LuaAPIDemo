cmake_minimum_required(VERSION 3.3)
project(LuaDemo)


include_directories(
	lua/include
)
link_directories(
	lua/lib
)


add_subdirectory(01_Hello)
add_subdirectory(02_Stack)
add_subdirectory(03_GlobalVariable)
add_subdirectory(04_Function)
