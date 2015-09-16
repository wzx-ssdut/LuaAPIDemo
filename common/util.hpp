#ifndef _LUA_UTIL_HPP_
#define _LUA_UTIL_HPP_

#include <lua.hpp>

void DumpStack(lua_State* L, const char* message = "");

#endif // _LUA_UTIL_HPP_