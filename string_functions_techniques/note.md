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

## 3. gets_s()

### 3.1 Definition

C11’s optional **gets_s()** function, like **fgets()**, uses an argument to limit the number of 
characters read. 

*gets_s(words, STLEN);*

### 3.2 Behavior

The three main differences from fgets() are these:

1. **gets_s()** just reads from the standard input, so it doesn’t need a third argument.

2. If **gets_s()** does read a newline; it discards it rather than storing it.

3. If **gets_s()** reads the maximum number of characters and fails to read a newline, it 
   takes several steps. It sets the first character of the destination array to the null character. It reads and discards subsequent input until a newline or end-of-file is encountered. It returns the null pointer. It invokes an implementation-dependent “handler” function (or else one you’ve selected), which may cause the program to exit or abort.

### 3.3 Note

The second feature means that, as long as the input line isn’t too long, **gets_s()** behaves like **gets()**, making it easier to replace **gets()** with **gets_s()** rather than with **fgets()**. The third feature means there’s a learning curve to using this function. Let’s compare the suitability of **gets()**, **fgets()**, and **gets_s()**. If the input line fits into the target storage, all three work fine. But **fgets()** does include the newline as part of the string, and you may need to provide code to replace it with a null character.

What if the input line doesn’t fit? Then **gets()** isn’t safe; it can corrupt your data and compromise security. The **gets_s()** function is safe, but, if you don’t want the program to abort or otherwise exit, you’ll need to learn how to write and register special “handlers.” Also, if you manage to keep the program running, **gets_s()** disposes of the rest of the input line whether you want to or not. The **fgets()** function is the easiest to work with if the line doesn’t fit, and it leaves more choices up to you. 

> **Comment:** So **gets_s()**, when input fails to meet expectations, is less convenient and flexible than **fgets()**. Perhaps that’s one reason that **gets_s()** is just an optional extension of the C library. And given that **gets_s()** is optional, using **fgets()** usually is the better choice.

## Extra: s_gets()

Read a whole line and replace the newline character with a null character, or read the part of a line that fits and discard the rest—sort of a **gets_s()** function without the extra baggage. No standard function meets that description, but we can create one. It’ll come in handy in later examples.

```c
 char* s_gets(char* dst, int n){
        if(!dst)
                return NULL;
        char* res = fgets(dst, n, stdin);
        int i = 0;
        if(res){
                while(dst[i] != '\n' && dst[i] != '\0')
                        ++i;
                if(dst[i] == '\n')
                        dst[i] = '\0';
                else{
                        while(getchar() != '\n')
                                continue;
                }
        }
        return res;
}
```

> **Note:** There are some flaws about this function.
> 
> 1. If it encounters the input that does not fit the buffer, it keeps silent and user will not be informed.
> 
> 2. It doesn't cope with the misuse situation such as setting n as 1 or less.

## 4. scanf()

Definition ? Usage or bahavior? Note ? I think I do not need to repeat these content anymore. We are all familiar with this famous input function. I think I just need to present something we ought to note.

**Comment:** **scanf()** uses *%s* format specifier to indicate it would like to read a string. BUT, rather than read a whole string line, it prefers to read a single word. It will start at the first non-space character and terminate at the first whitespace character it encounters (not including that whitespace character !!!). Also, if we indicates the field width such as *%5s*. Then it will just read the first 5 characters in the string or it will ends when it meets whitespace character, it depends on which comes first.

## 5. strlen()

### 5.1 Definition

The **strlen()** function is usually used to calculate the length of a string. 

### 5.2 Behavior

This function ends with the null character, and return the size of the string which passed to it as argument.

### 5.3 Note

Just note that when the function meets null character, it is finished.

> ```c
> #include <stdio.h>
> #include <stdlib.h>
> #include <string.h>
> 
> int main(void){
>         const char* str = "hello";
>         printf("The length of str is: %lu\n", strlen(str));
>         return 0;
> }
> ```

## 6. strcat()

### 6.1 Definition

**strcat()** is used to concatenate the second string which is indicated in the second parameter to the first string which is indicated in the first parameter.

### 6.2 Behavior

Concatenate the second string in the second parameter to the first string in the first parameter. It will precedingly ends if it encounters the null character in the second string. Also, it will eliminate the null character in the first string and directly append the second string to there as the starting point.

### 6.3 Note

We must make sure the memory size is sufficient to contain both of them and an extra null character. Or it will cause buffer overflow problem just like **gets()**

## 7. strncat()

### 7.1 Definition

**strncat()** is a safe edition of **strcat()**, it receives the third parameter as the maximum size of the second string appended to the first string, avoiding overflow problem.

### 7.2 Behavior

Concatenate the second string in the second parameter to the first string in the first parameter. It will precedingly ends if it encounters the null character in the second string or if it meets the maximum number in the third parameter, whichever comes first. Also, it will eliminate the null character in the first string and directly append the second string to there as the starting point.

### 7.3 Note

This edition of string concatenate function is safer. Recommend using it rather than **strcat()**.

## 8. strcmp() and strncmp()

### 8.1 Definition

Both of them are used to compare two string contents to determine whether they are the same or not. 

### 8.2 Behavior

If the first string is less than the second string (alphabetical order), then it returns a negative value, or else return a positive value. If they are the same, it returns 0.

### 8.3 Note

Note that there is also a safer edition of this function **strncmp()**, it receives the third parameter as size, indicating the number of character in both strings it is going to compare.

## 9. strcpy() and strncpy()

### 9.1 Definition

Both of them are used to copy the second string to the first string, in fact, it is a memory space which is used to store the contents of the second string.

### 9.2 Behavior

Copy the second string content to the first string (memory space), it won't modify the contents of the second string.

### 9.3 Note

Note that **strncpy()** is a safer edition of this function, whose third parameter indicates how many characters to copy in second string.

## 10. sprintf()

### 10.1 Definition

In fact, it is almost the same as **printf()**, it just does not need to display the contents to our screen, it stores the contents in a sequence indicated by the first parameter.

### 10.2 Behavior

Like **printf()**, it stores the formatted string in the memory space which is indicated by its first parameter.

### 10.3 Note

Ummm...I do not know yet....
