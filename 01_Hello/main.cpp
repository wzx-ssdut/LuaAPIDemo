#include <lua.hpp>
#include <iostream>

int main() {
	// 1. Create a lua_State instance
	lua_State* L = luaL_newstate();

	// 2. Open all standard libraries.
	luaL_openlibs(L);

	// 3. 
	const char* source{ R"(
		print("Hello Lua " .. _VERSION)
	)" };
	luaL_dostring(L, source);

	luaL_dofile(L, "hello.lua");

	// 4. Close lua state.
	lua_close(L);

	std::getchar();

	return 0;
}