The Basics
===========
 
Before executing any of the commands on this tutorial you will first need to start up your terminal program,
and change your working directory to this directory.

In this tutorial we build a simple program that prints to the standard output the words `hello, world`.

It consists of,

1. A single C source [file](./hello_world.c) and
2. [makefile](./makefile).

To build, execute the make command as follows;
```
$ make
```

It will generate a set of files but importantly a binary file named `hello_world`, which can be executed as follows,
```
$./hello_world
```
and this should print to screen the words `hello, world`.

# The makefile structure

The file is made of one implicit rule.
This rule has a single file target `hello_world` with 1 prerequisite C source file, and its built by the command `cc -o hello_world hello_world.c`. The command is a C language compilation command.
While this is not a tutorial into the C-programming language, it would be rude of me not to explain it, :-).
The command invokes the GNU C-compiler and instructs it to compile the C-source file `hello_world.c` and generate a binary output (`-o` option) file `hello_world`.  

The makefile, while being very simple to write has the following shortcomings;
1. There are repetitions, for example the rule input file, `hello_world.c` is repeated on prerequisites and on the command.
2. If we are to build more than one binary file or building the binary requiring more than just the source file, this approach would become a maintenance nightmare.

To reduce on the repetition you could argue I could probably leave out the pre-requisites and write the rule as follows,
```
hello_world:
    cc -o hello_world hello_world.c
```
Well, its that easy because this is a single source file 'project'.

To improve on our makefile, making it more expressive and easily maintainable, in the next tutorial we explore the use of variables and implicit rules.