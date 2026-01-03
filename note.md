# C String Functions' Techniques

## 1. gets()

### 1.1 Definition

The function **gets()** belongs to the standard I/O function familiy in <stdio.h>. And it is usually used to read in a string from user input such as keyboard..etc..

### 1.2 Behavior

**gets()** will read in the input from user's input device such as keyboard and copy the content to its argument. It's parameter is a destination where stores the user input string, and it is a pointer type parameter. First, it is going to read the whole line which is terminated by a newline character-'\n', and discard the newline character,leaving the remain characters in the buffer where its parameter indicates. Finally, it will add an extra null character-'\0' into the buffer to construct a complete string.

### 1.3 Note

The **gets()** function is dangerous! And theoretically it should not be used in our important program! Because the **gets()** just need the parameter which just indicates the location where stores the actual data, it is not able to judge if the buffer size is sufficient or not. So if you use this function in some wrong way, it will raise the stack overflow problem and sometimes its drawback probably won't show up instantly. But it may modify the data of other objects or data structures, finally undermining the process. The concrete outcome of doing this is undefined, but from my experience it usually causes the program to abort (core dumped) (In Linux: Ubuntu22.04LTS). 

> **Anecdotes:** Although **gets()** is some kind of evil, the standard commitee still decided to reserve it in the library because it is actually very ease to use if you use it correctly, and another reason is that it has already occupied many locations in nowadays programs...So it costs much to remove them out of these programs.

## 2. puts()

### 2.1 Definition

**puts()** is also a I/O function which belongs to the standard I/O functions familiy just like **gets()**. And it is used to output a string (*line*) to the screen.

### 2.2 Behavior

Its parameter indicates where the string data locates and copy that to display on the screen. It will append an extra newline character-'\n' to the end of the line.

### 2.3 Note

Note that this function is not as dangerous as **gets()**. Well, in fact, it is not dangerous at all from my point of view. It will append an extra newline character to the end of the string so we don't need to type '\n' by ourselves like we usually do in **printf()** function...So, it is quite convenient for us to use it!

## 3. fgets() and fputs()

### 3.1 Definition

The function **fgets()** is also a standard input function which belongs to the standard I/O function familiy in <stdio.h>. And it is usually used for processing file input. It can be used to solve the overflow problem which exists in **gets()** by transmitting extra parameters.

The **fputs()** also likes **fgets()**, which is used to output the contents to specific location, file or stdout...etc. 

### 3.2 Behavior

The first parameter indicates where to store the string data, just like **gets()**. The second parameter is for size, in fact, suppose the size is n, then it is going to read up to n - 1 characters and add an extra '\0' to the buffer which stores the string data, or, if it encounters a newline character, it will still read the newline character and store it in the buffer, adding an extra '\0' to it. It depends on which comes first...

**fputs()** is a litte different from **puts()**,too. It won't automatically add an extra newline character to the output line, while **puts()** will.

Both of their last parameter indicates the I/O stream. If we want to interact with our keyboard and screen. We could set *stdin* as the input stream in **fgets()** and *stdout* as the output stream in **fputs()**. 

### 3.3 Note

Note that this function is a bit different from **gets()** which discards the newline character in the input. It keeps the newline character and store it in the buffer. So its presence or absence is both advantage or disadvantage for us, it depends on the circumstance. 

> For example. If we want to eliminate the newline character in our input and replace it with '\0'. Here is a solution:
> 
> ```c
>  while (words[i] != '\n') // assuming \n in words
>      i++;
>  words[i] = '\0;
> ```

> Futhermore, if we want to discard the remaining contents in our input which do not fit into the buffer, we may do this:
> 
> ```c
>  while (getchar() != '\n')     // read but don't store
>      continue;                 // input including \n
> ```

> So, here is a concrete example. It shows how to replace the newline character we don't like in the input line, and discard all the remaining characters in the input line that do not fit into the buffer:
> 
> ```c
>  #include <stdio.h>
>  
>  #define STLEN 10
>  
>  int main(void){
>      char words[STLEN];
>      int i;
>      puts("Enter strings (empty line to quit):");
>      while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n'){
>          i = 0;
>          while (words[i] != '\n' && words[i] != '\0')
>              i++;
>          if (words[i] == '\n')
>              words[i] = '\0';
>          else // must have words[i] == '\0'
>              while (getchar() != '\n')
>                  continue;
>          puts(words);
>      }
>      puts("done");
>      return 0;
>  }
> ```
