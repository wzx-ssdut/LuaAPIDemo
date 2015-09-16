set(APPNAME 05_LuaCallCpp)

set(SOURCE
	../common/util.hpp
	../common/util.cpp
	main.cpp

	# lua
	hello.lua
)


add_executable(${APPNAME}
	${SOURCE}
)
target_link_libraries(${APPNAME}
	liblua
)

add_custom_command(TARGET ${APPNAME}
	PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/hello.lua
		${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}
)