#include <lua.hpp>

#include <cstdlib>
#include <iostream>

void DumpStack(lua_State* L) {
	int top = lua_gettop(L);
	std::cout << "[Dump from " << __FILE__ ":" << __LINE__ << "] Lua Stack Size: " << top << std::endl;
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
			std::cout << " [" << lua_typename(L, type) << "]\n";
			break;
		}
	}
}

int main() {
	// 1. Create a lua_State instance
	lua_State* L = luaL_newstate();

	// 2. Open all standard libraries.
	luaL_openlibs(L);

	////////////////////////////////////////////////////////
	lua_pushboolean(L, 1);
	lua_pushinteger(L, 1000);
	lua_pushnumber(L, 9.998);
	lua_pushstring(L, "hello");
	lua_pushnil(L);
	lua_pushstring(L, "top");

	DumpStack(L);

	// 将指定索引上的值再次压入栈
	lua_pushvalue(L, 4);
	DumpStack(L);

	// 字符串操作
	lua_pushstring(L, "string1");
	lua_pushlstring(L, "string2", 0);
	lua_pushfstring(L, "%s %d", "Lua", 5);
	//lua_pushvfstring(L, )

	for (int size = 1; size <= 30; ++size) {
		std::cout << "check " << size << ": " << lua_checkstack(L, size) << std::endl;
	}

	/*
	lua_isboolean(L, 1);
	lua_toboolean(L, 1);
	lua_pushboolean(L, false);
	*/

	/**
	 lua_is*  (lua_State* L, int index);
	 lua_to*  (lua_State* L, int index);
	 lua_push*(lua_State* L, int index);
	 */

	// 获取栈中元素个数
	lua_gettop(L);

	// 设置栈中元素个数，如果当前栈中元素个数小于设定的值，其他元素被设置为nil
	lua_settop(L, 10);
	DumpStack(L);

	lua_settop(L, 3);
	DumpStack(L);

	// 将栈顶元素插入到index索引指定的位置，其他元素逐个上移
	lua_insert(L, 1);
	DumpStack(L);

	// 在指定索引处插入一个新元素，而保持栈顶元素不变的情况，要先将值压入栈中，再执行insert
	std::cout << "===================" << std::endl;
	lua_pushstring(L, "second");
	lua_insert(L, 2);
	DumpStack(L);

	// 弹出栈顶元素，并用栈顶元素替换index指定的元素
	std::cout << "=========Switch top with index 1=======" << std::endl;
	lua_replace(L, 1);
	DumpStack(L);

	// 如果要用一个新的值替换栈中已有的元素，需要先将元素压入栈中，再执行replace
	std::cout << "======= replace second with SECOND" << std::endl;
	lua_pushstring(L, "SECOND");
	lua_replace(L, 2);
	DumpStack(L);

	// 删除index指定的元素
	//lua_remove(L, 1);
	//DumpStack(L);

	// 4. Close lua state.
	lua_close(L);

	std::getchar();

	return 0;
}