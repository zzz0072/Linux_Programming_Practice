# IFS
set(xxx a b c d)
message(${xxx})
set(xxx e;f;g;h)
message(${xxx})

# Condition
if ( NOT DEFINED test)
    message("Use: cmake -Dtest:STRING=val to test")
elseif(${test} STREQUAL yes)
    message("if: ${test}")
elseif(${test} STREQUAL test1)
    message("else if: ${test}")
else()
    message("else: ${test}")
endif()

cmake_minimum_required(VERSION 2.8)
# foreach
foreach(i ${xxx})
    message(${i})
endforeach()

# while
set(i 0)
while(i LESS 10)
    message(${i})
    math(EXPR i "${i} + 1")
endwhile()

# macro and function
macro(mac_print msg)
    set(mac "macro")
    message("${mac}: ${msg}")
endmacro(mac_print)

function(func_print msg)
    set (func "func")
    message("${func}: ${msg}")
endfunction(func_print)
# run and check variable
mac_print("test macro")
message("check var in macro: ${mac}")
func_print("test function")
message("check var in function: ${func}")
