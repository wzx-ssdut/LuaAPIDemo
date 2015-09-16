#include "util.hpp"

#include <iostream>

void DumpStack(lua_State* L, const char* message) {
	int top = lua_gettop(L);
	std::cout << "[Dump from " << __FILE__ ":" << __LINE__ << "]\n"
		<< message << '\n'
		<< " Stack Size: " << top << std::endl;
	for (int i = 1; i <= top; ++i) {
		int type = lua_type(L, i);
		switch (type) {
		case LUA_TNIL:
			std::cout << i << " [" << lua_typename(L, type) << "]\n";
			break;

		case LUA_TBOOLEAN:
			std::cout << i << " [" << lua_typename(L, type) << "] " << lua_toboolean(L, i) << std::endl;
			break;

		case LUA_TNUMBER:
			std::cout << i << " [" << lua_typename(L, type) << "] " << lua_tonumber(L, i) << std::endl;
			break;

		case LUA_TSTRING:
			std::cout << i << " [" << lua_typename(L, type) << "] " << lua_tostring(L, i) << std::endl;
			break;

		default:
			std::cout << i << " [" << lua_typename(L, type) << "]\n";
			break;
		}
	}
}