
# Simple Shell 









![Logo](https://e1.pxfuel.com/desktop-wallpaper/373/969/desktop-wallpaper-linux-tux-tux-linux.jpg)





## Explaination

##### This repository contains the files to implement a basic Unix Shell with its respective commands. It is made to carry out the 0x16. C - Simple Shell project in SE programe at [ALX AFRICA](https://www.alxafrica.com/)

This simple shell is a Shell interface written in C programming language that gives to the user a prompt *Shell$ *, after it accepts, it executes a user inputted command in a separate process called child process. 

## What this Shell do?

* This program displays a prompt and waits that the user types a command. A command line always ends with a new line (when the user presses the ENTER key).
* The prompt is displayed again each time a command has been executed.
* When the user enters exit, Shell$ will end and return the status 0.
* When the user enters exit,Shell$ will end and return the input status.
* The user could stop the program using Ctrl+D (end of file “EOF”).
* The shell handles the command lines with arguments and pathways.
* The program prints the current environment when the user types env.
* This program executes common shell commands as ls, pwd, exit, env.

## What this Shell do not do?

* The Shell$ does NOT support wildcard characters.
* This shell$ does NOT support pipes |, shell logical operators as && or ||, neither commands separator ;.

## Compilation

```javascript
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```



## Authors

- [@Toqa Zidan](https://github.com/ToqaZidan)
- [@Nourhan Youssef](https://github.com/EngNourhanYoussef)

