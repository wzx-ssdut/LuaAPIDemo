set(APPNAME 02_Stack)

set(SOURCE
	../common/util.hpp
	../common/util.cpp
	main.cpp
)


add_executable(${APPNAME}
	${SOURCE}
)
target_link_libraries(${APPNAME}
	liblua
)