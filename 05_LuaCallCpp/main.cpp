#include <lua.hpp>
#include <iostream>

#include "../common/util.hpp"

/*
��ע���C/C++������Lua����ʱ�����C��������һ�����е�stack�����stack�Ǻ���˽�е�
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

	// ������ֵѹ��ջ��
	lua_pushnumber(L, sum);
	// �������ĸ���ѹ��ջ��
	lua_pushnumber(L, top);

	DumpStack(L);

	return 2; // ��һ������ֵ  (sum, num)
}


int main() {
	// 1. Create a lua_State instance
	lua_State* L = luaL_newstate();

	// 2. Open all standard libraries.
	luaL_openlibs(L);

	// ������ע���Lua
	lua_register(L, "sum_func", calc_sum);

	luaL_dofile(L, "hello.lua");

	// 4. Close lua_State.
	lua_close(L);

	std::getchar();

	return 0;
}