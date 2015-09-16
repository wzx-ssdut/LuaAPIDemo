#include <lua.hpp>
#include <iostream>

#include "../common/util.hpp"


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

	// ��ָ�������ϵ�ֵ�ٴ�ѹ��ջ
	lua_pushvalue(L, 4);
	DumpStack(L);

	// �ַ�������
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

	// ��ȡջ��Ԫ�ظ���
	lua_gettop(L);

	// ����ջ��Ԫ�ظ����������ǰջ��Ԫ�ظ���С���趨��ֵ������Ԫ�ر�����Ϊnil
	lua_settop(L, 10);
	DumpStack(L);

	lua_settop(L, 3);
	DumpStack(L);

	// ��ջ��Ԫ�ز��뵽index����ָ����λ�ã�����Ԫ���������
	lua_insert(L, 1);
	DumpStack(L);

	// ��ָ������������һ����Ԫ�أ�������ջ��Ԫ�ز���������Ҫ�Ƚ�ֵѹ��ջ�У���ִ��insert
	std::cout << "===================" << std::endl;
	lua_pushstring(L, "second");
	lua_insert(L, 2);
	DumpStack(L);

	// ����ջ��Ԫ�أ�����ջ��Ԫ���滻indexָ����Ԫ��
	std::cout << "=========Switch top with index 1=======" << std::endl;
	lua_replace(L, 1);
	DumpStack(L);

	// ���Ҫ��һ���µ�ֵ�滻ջ�����е�Ԫ�أ���Ҫ�Ƚ�Ԫ��ѹ��ջ�У���ִ��replace
	std::cout << "======= replace second with SECOND" << std::endl;
	lua_pushstring(L, "SECOND");
	lua_replace(L, 2);
	DumpStack(L);

	// ɾ��indexָ����Ԫ��
	lua_remove(L, 1);
	DumpStack(L);

	// ��ջ�е���n��Ԫ��
	lua_pop(L, 1);
	DumpStack(L);

	// 4. Close lua state.
	lua_close(L);

	std::getchar();

	return 0;
}