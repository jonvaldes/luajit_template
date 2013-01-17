//
//  LuaMachine.h
//
//  Created by Jon Valdes on 17/01/13.
//
//

#pragma once

#include "lua.hpp"
#include <string>

class LuaMachine
{
    public:
        LuaMachine();
        ~LuaMachine();

        bool loadFile( const char * filename ) ;

        template <typename T , typename ...Args>
            T callFunction( const std::string & name , Args... args)
            {
                pushfunc(name);
                return callFunction_int<T>(name , sizeof...(args), args...);
            }

    private :

        lua_State * m_lua;

        // ----------------
        // Internal methods
        // ----------------

        template <typename T>
            T callFunction_int( const std::string & name , int nargs )
            {
                if( lua_pcall(m_lua, nargs, 1 , 0))
                {
                    printf("Error calling lua function %s: %s\n",name.c_str() , lua_tostring(m_lua,-1));
                    return T() ;
                }
                return pop<T>();
            }

#define LUACALL_INT(ctype,callname) \
        template <typename T , typename ...Args> \
        T callFunction_int( const std::string & name , int numargs , ctype arg1 ,  Args... args){\
            lua_push##callname(m_lua, arg1);\
            return callFunction_int<T>(name ,numargs , args...);\
        }

        LUACALL_INT(bool       ,boolean )
        LUACALL_INT(lua_Number,number)
        LUACALL_INT(const char * , string )
        LUACALL_INT(lua_Integer , integer )

#undef LUACALL

        inline void pushfunc( const std::string & name ){ lua_getglobal( m_lua , name.c_str() ) ; }

        template <class T> T pop();
};

