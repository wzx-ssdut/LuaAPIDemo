#include <lua.hpp>
#include <iostream>

#include "../common/util.hpp"

int main() {
	// 1. Create a lua_State instance
	lua_State* L = luaL_newstate();

	// 2. Open all standard libraries.
	luaL_openlibs(L);

	luaL_dofile(L, "hello.lua");

	// number
	lua_getglobal(L, "arg_number");
	DumpStack(L);
	lua_pop(L, 1);

	// string
	lua_getglobal(L, "arg_string");
	DumpStack(L);
	lua_pop(L, 1);


	// ȷ����ʱջΪ��
	lua_settop(L, 0);

	// table
	lua_getglobal(L, "role");
	DumpStack(L);

	/*
	int lua_getfield(lua_State* L, int index, const char* k);

	Pushes onto the stack the value t[k], where t is the value at the given index. As in Lua,
	this function may trigger a metamethod for the "index" event.
	Returns the type of the pushed value.
	*/

	// ��ȡ����Ԫ��
	lua_getfield(L, 1, "male");
	DumpStack(L);

	lua_getfield(L, 1, "level");
	DumpStack(L);

	lua_getfield(L, 1, "name");
	DumpStack(L);
	
	// ���ָ��������λ�ò���table�������ֱ����������������ʹ�øú���֮ǰһ��Ҫȷ����Ӧλ���Ƿ�Ϊtable
	//lua_getfield(L, 2, "name");
	//DumpStack(L);
	if (lua_istable(L, 2)) {
		lua_getfield(L, 2, "name");
		DumpStack(L);
	}


	// --------------------------- table in table ----------------------------
	lua_settop(L, 0);
	lua_getglobal(L, "role");
	int type = lua_getfield(L, 1, "attr");
	std::cout << "[TYPE] role.attr = " << lua_typename(L, type) << std::endl;
	DumpStack(L);

	lua_getfield(L, 2, "value");
	DumpStack(L);

	lua_getfield(L, 2, "type");
	DumpStack(L);

	std::cout << "########################################################" << std::endl;
	lua_settop(L, 0);
	lua_getglobal(L, "vector");
	lua_geti(L, 1, 2);
	DumpStack(L, "��ȡtable������");


	// 4. Close lua_State.
	lua_close(L);

	std::getchar();

	return 0;
}