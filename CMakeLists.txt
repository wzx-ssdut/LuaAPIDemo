cmake_minimum_required(VERSION 3.3)
project(LuaDemo)


include_directories(
	lua/include
)
link_directories(
	lua/lib
)


if(MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS)
else()
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall -Wextra -std=c++11")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()


add_subdirectory(01_Hello)
add_subdirectory(02_Stack)
add_subdirectory(03_GlobalVariable)
add_subdirectory(04_Function)
add_subdirectory(05_LuaCallCpp)
