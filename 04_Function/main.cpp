#include <lua.hpp>
#include <iostream>

#include "../common/util.hpp"

int main() {
	// 1. Create a lua_State instance
	lua_State* L = luaL_newstate();

	// 2. Open all standard libraries.
	luaL_openlibs(L);

	luaL_dofile(L, "hello.lua");

	// 正确调用情况
	/*
	lua_getglobal(L, "add");
	lua_pushinteger(L, 22);
	lua_pushinteger(L, 33);
	DumpStack(L, "================函数调用之前");

	lua_pcall(L, 2, 1, 0);
	DumpStack(L, "================函数调用之后");
	*/

	/*
	lua_pcall函数根据传入的参数个数决定出function的位置，因此不需要指定函数的位置，
	如果在top-argc的索引位置上找不到函数，则会引发错误
	*/

	// 错误调用情况
	/*
	lua_settop(L, 0);
	lua_getglobal(L, "add");
	lua_pushinteger(L, 22);
	lua_pushinteger(L, 33);
	lua_pushinteger(L, 44);
	lua_pcall(L, 2, 1, 0);
	DumpStack(L, "错误调用函数实例====================");
	*/

	/*
	// 返回table
	lua_getglobal(L, "gettable");
	lua_pushinteger(L, 1);
	lua_pcall(L, 1, 1, 0);
	DumpStack(L, "调用Lua函数，返回table");
	// 得到表之后，就可以用getfield来获取table中元素了
	lua_getfield(L, -1, "name");
	lua_getfield(L, -2, "level");
	DumpStack(L);
	*/

	/*
	lua_getglobal(L, "getmultivalue");
	lua_pcall(L, 0, 3, 0);
	DumpStack(L, "返回多个值");
	*/

	// 4. Close lua_State.
	lua_close(L);

	std::getchar();

	return 0;
}