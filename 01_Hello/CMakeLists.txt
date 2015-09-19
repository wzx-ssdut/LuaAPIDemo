set(APPNAME 01_Hello)

set(SOURCE
	main.cpp
)


add_executable(${APPNAME}
	${SOURCE}
)
target_link_libraries(${APPNAME}
	lua
)

add_custom_command(TARGET ${APPNAME}
	PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/hello.lua
		${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}
)
