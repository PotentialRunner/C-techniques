# Memory Management

## 1. static

*static* keyword indicates a variable is **internal-linkage** which means it can be used only in current file. There are two types of *static* variable:

1. **file-scope static variable**: File scope indicates the variable can be used in the current file. And *static* keyword indicates that the variable is **internal-linkage**, which means it can not be used by other files. Also, *static* indicates its duration. The *static* variable exists from the begining of the program to the end of the entire program.

2. **block-scope static variable**: Block scope, almost like file scope, its duration and linkage property are the same with file scope static variable. But, it will only be access in the block where it exists.  

## 2. auto

*auto* keyword indicates a variable is allocated on the stack or register (if it is modified by *register* keyword). It can exist in file scope or block scope. In fact, the code like: 

*int a = 10;* defaultly we define a int variable in auto mode. It has the same effect like this: *auto int a = 10;* 

> Note: In fact I recommend not to use *auto* keyword to define a normal variable.**Two reasons**: 
> 
> **First**, it has the same effect if you don't use *auto* keyword to modify a variable.
> 
> **Second**, it may have collusion with *auto* keyword in C++ 11, which regards *auto* as totally different function comparing with C.

## 3. register

The *register* keyword give a **propostion** to compiler to make a specific variable to be stored in registers in CPU. Because CPU access registers very fast, more than RAM or ROM, so we may consider to put objects we usually use to registers, just add a *register* keyword when we define a specific variable. Like:

*register int a = 10;*

> Note: This keyword is not to require the compiler but to recommend the compiler to put the objects to registers. In fact, the compiler will consider if it is really suitable to adopt your opinion. Also, we can't get a register variable's address, because it is not in memory.
