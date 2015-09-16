#include <lua.hpp>
#include <iostream>

#include "../common/util.hpp"

int main() {
	// 1. Create a lua_State instance
	lua_State* L = luaL_newstate();

	// 2. Open all standard libraries.
	luaL_openlibs(L);

	luaL_dofile(L, "hello.lua");

	// ��ȷ�������
	/*
	lua_getglobal(L, "add");
	lua_pushinteger(L, 22);
	lua_pushinteger(L, 33);
	DumpStack(L, "================��������֮ǰ");

	lua_pcall(L, 2, 1, 0);
	DumpStack(L, "================��������֮��");
	*/

	/*
	lua_pcall�������ݴ���Ĳ�������������function��λ�ã���˲���Ҫָ��������λ�ã�
	�����top-argc������λ�����Ҳ��������������������
	*/

	// ����������
	/*
	lua_settop(L, 0);
	lua_getglobal(L, "add");
	lua_pushinteger(L, 22);
	lua_pushinteger(L, 33);
	lua_pushinteger(L, 44);
	lua_pcall(L, 2, 1, 0);
	DumpStack(L, "������ú���ʵ��====================");
	*/

	/*
	// ����table
	lua_getglobal(L, "gettable");
	lua_pushinteger(L, 1);
	lua_pcall(L, 1, 1, 0);
	DumpStack(L, "����Lua����������table");
	// �õ���֮�󣬾Ϳ�����getfield����ȡtable��Ԫ����
	lua_getfield(L, -1, "name");
	lua_getfield(L, -2, "level");
	DumpStack(L);
	*/

	/*
	lua_getglobal(L, "getmultivalue");
	lua_pcall(L, 0, 3, 0);
	DumpStack(L, "���ض��ֵ");
	*/

	// 4. Close lua_State.
	lua_close(L);

	std::getchar();

	return 0;
}