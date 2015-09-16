#include <lua.hpp>
#include <iostream>

#include "../common/util.hpp"

/*
当注册的C/C++函数被Lua调用时，这个C函数享有一个独有的stack，这个stack是函数私有的
 */
int calc_sum(lua_State* L) {
	double sum = 0;
	int top = lua_gettop(L);
	for (int i = 1; i <= top; ++i) {
		if (!lua_isnumber(L, i)) {
			lua_pushstring(L, "argument error!");
			lua_error(L);
		}
		sum += lua_tonumber(L, i);
	}

	DumpStack(L);

	// 将返回值压入栈中
	lua_pushnumber(L, sum);
	// 将加数的个数压入栈中
	lua_pushnumber(L, top);

	DumpStack(L);

	return 2; // 有一个返回值  (sum, num)
}


int main() {
	// 1. Create a lua_State instance
	lua_State* L = luaL_newstate();

	// 2. Open all standard libraries.
	luaL_openlibs(L);

	// 将函数注册给Lua
	lua_register(L, "sum_func", calc_sum);

	luaL_dofile(L, "hello.lua");

	// 4. Close lua_State.
	lua_close(L);

	std::getchar();

	return 0;
}