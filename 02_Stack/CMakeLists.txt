set(APPNAME 02_Stack)

set(SOURCE
	main.cpp
)


add_executable(${APPNAME}
	${SOURCE}
)
target_link_libraries(${APPNAME}
	liblua
)