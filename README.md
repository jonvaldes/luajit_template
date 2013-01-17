luajit_template
===============

Simple example showing how to use C++11 variadic templates to easily call Lua functions in a type-safe manner.

Only tested on OSX, but should work on every platform.

Syntax for calling lua functions (with 0 or 1 return values) becomes:


    LuaMachine lua;
    lua.loadFile("myfile.lua");

    lua.callFunction<MyReturnType>("myFunctionName", param1,param2,...);


For example, this is how you'd call a Lua function named "superFunction", which takes 2 parameters and returns an int:

    int funcResult = lua.callFunction<int>("superFunction", 28 , "templates for headaches" );
