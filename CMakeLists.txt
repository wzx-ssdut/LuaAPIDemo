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
