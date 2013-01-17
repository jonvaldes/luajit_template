#include "LuaMachine.h"

int main()
{
    LuaMachine lua;

    lua.loadFile("test.lua");

    // Testing several param types
    lua.callFunction<void>("printfunc", 128);
    lua.callFunction<void>("printfunc", 0.432);
    lua.callFunction<void>("printfunc", true);
    lua.callFunction<void>("printfunc", "Hey!");



    // Testing a typical function call
    int funcResult = lua.callFunction<lua_Integer>("superFunction", 28 , "templates for headaches" );
    printf("C++ code got %d\n", funcResult );

}
