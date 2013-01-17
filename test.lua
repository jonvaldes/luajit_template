function superFunction( num , str )
    io.write("Lua function received a number : " , num , "\nand a string : '" , str , "'\n" )
    return 42
end

function printfunc( param )
    io.write("printfunc received this: '" , tostring(param) ,"'\n")
end
