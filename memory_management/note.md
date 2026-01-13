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

## 4. malloc()

### 4.1 Definition

The **malloc()** function is used to allocate memory in heap area in the process. It is declared in head file <stdlib.h>.

### 4.2 Behavior

Allocate memory in the heap area dynamically, usually used to accomplish some complicated tasks which need advanced memory management. It receives the parameter indicates the number of bytes it is going to allocate for the program.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void){
        int *p = (int*)malloc(sizeof(int));
        *p = 10;
        printf("%d\n", *p);
        free(p);
        return 0;
}
```

### 4.3 Note

Note that this function may be failed to allocate the memory for us if there is not sufficient heap memories for us. Also, we must be aware of *memory leak* problem, which means we forget to call *free()* to deallocate the memory allocated by *malloc()*. Then we will no longer be able to access those memories because we lost the address of that chunk of memory...

## 5. calloc()

### 5.1 Definition

**calloc()** is similar to **malloc()**, which is used to allocate heap memory for our program.

### 5.2 Behavior

**calloc()** accepts two parameters, the first indicates how many cells we would like to allocate, while the second indicates how much size per cell. Then it will return the pointer to that chunk of memory. It may also failed to allocate memory if there is not sufficient heap memory for us, either.

### 5.3 Note

Note that this function will set all the bits to 0 for us automatically after allocating the memory for us. And the memory it allocates should also be deallocated by *free()*, too.
