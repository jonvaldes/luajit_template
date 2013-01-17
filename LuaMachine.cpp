//
//  LuaMachine.cpp
//
//  Created by Jon Valdes on 17/01/13.
//
//

#include "LuaMachine.h"

LuaMachine::LuaMachine() : m_lua( lua_open() )
{
	luaopen_io    (m_lua) ;
	luaopen_base  (m_lua) ;
	luaopen_string(m_lua) ;
}

bool LuaMachine::loadFile( const char * filename )
{
	if( luaL_loadfile(m_lua, "test.lua") )
	{
		printf( "Error loading lua file: %s\n" , lua_tostring(m_lua,-1) ) ;
		return false;
	}

	if( lua_pcall(m_lua, 0, LUA_MULTRET, 0) )
	{
		printf( "Error executing lua program: %s\n" , lua_tostring(m_lua,-1) ) ;
		return false ;
	}

    return true ;
}

LuaMachine::~LuaMachine()
{
	lua_close(m_lua) ;
}

// ----------------------------------------
// Specializations of pop for several types
// ----------------------------------------

template <> bool LuaMachine::pop<bool>()
{
	const bool result = lua_toboolean(m_lua,-1) ;
    lua_pop(m_lua,1) ;
    return result ;
}

template <>	lua_Number LuaMachine::pop<lua_Number>() 
{
	const lua_Number result = lua_tonumber(m_lua,-1) ;
    lua_pop(m_lua,1) ;
    return result ;
}

template <> const char * LuaMachine::pop<const char *>()
{
	const char * result = lua_tostring(m_lua,-1); 
    lua_pop(m_lua,1);
    return result ;
}

template <> lua_Integer LuaMachine::pop<lua_Integer>()
{
	const lua_Integer result = lua_tointeger(m_lua,-1);
    lua_pop(m_lua,1);
    return result ;
}

template <> void LuaMachine::pop<void>()
{
}

