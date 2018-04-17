# Introduction
When I first learnt to write my first program in C, it was a single C source file and constituted of a main function that printed to the screen the words 'hello world!'. It was compiled and built by executing the command `$cc -o <outputfile-name> <source file name>`. I have included it as my [first tutorial](tutorial0/hello_world.c).
This was a simple program, later on, to build something more useful and with a couple of more source files, i required a more efficient approach. And that is why and when I learned the use of GNU make. 
It simplifies the compilation, building and maintaince of a project. Think of it as a chef who is given a recipe and ingredients and the goal is to make a culinary delicacy. The recipe is called a makefile, ingredients the various source files and dependent libraries, referred to as prerequisites, required to make the delights, our targets.GNU make, is therefore, a build automation tool which follows a set of rules telling it how, from a list of input source files and dependencies its to build targets.

# Key concepts

Make, which I use to mean GNU Make, requires a makefile. 
A makefile is text file consisting of rules; in a predefined format, comments, variables, conditional statements and functions.

## Rules
Make rules is a set of instructions telling it what to do and are classified into:

* Static rules
    This are rules that specify mutiple targets(filenames with extensions) to be built by the commands. The rule format is;
    ```
    targets: target-pattern: prerequisites-pattern
        ->command; command
        ->command
    ```
    The target pattern matches the target output to its prerequisites.

* Implicit rules
    This are rules composed of patterns for both targets and prerequisites. The rule format is;
    ```
    targets: prerequisites
       ->command; command
       ->command
    ```
   since implicit rules work without specific filenames, commands make use of automatic variables to process pre-requisites and produce targets.

In general, a rule is composed of 3 key elements:

1. Targets, classified into:


    * file targets

        Consisting of a list of file names that are to be generated.
        Targets can be a single target or mutiple targets. In cases where its more than one target a space is used to separate them.

    * phony targets

        A single target which is a command that is to be executed when make is executed. However, if a file with a similar name as the command exists, executing the command would fail.

    * built-in targets

        They are targets understood by make and have a special meaning. Examples are .PHONY, .SUFFIXES.

2. Prerequisites are a set of input files that are required to be able to generate the targets.

    Where more that one prerequisite is required a space is used to separate them.

3. Commands which are a list of actions to be taken on the input files in order to generate the target files.

    Commands are listed on a new line and must be preceded by a single tab space, indicated by the use of the symbol '->'. When mutiple commands are to be listed on a single line they are separated by a semi-colon.

Apart from rules makefiles can also include comments, variables, conditional statements and functions.
When make is invoked on a directory it searches for the receipe file with the name, makefile or Makefile. Therefore its only appropriate to name make files as a such.

## Comments

Comments are text preceded by a hash(#) upto but not including the beginning of a newline. They are ignored by the make process.

## Variables

There are 3 type of variables:

* User defined

	They are variables defined by the makefile author and be categorized into:
	
	* Recursive variables
	
		They contain reference to other variables, and the values are set using the recursive operator `=`. The variable value is evaluated when the makefile is being executed.
		```
			VAR_NAME = value
		```
		
	* Simple variables
	
		They contain single values determined at parse time. Its values are set using the simple operator `:=` or using the `define` keyword.
		```
			VAR_NAME := value #format 1

			define VAR_NAME #format 2
			value
			endef
		```
	Variable also can altered using the append operator, `=+`, or truncate operator, `=-`. 

* Predefined variables

	Predefined variables are variables inbuilt in make, and have special meanings. Some of this variable refer to programs whilst other are common arguments to this programs.
	
	Relevant for this tutorials, mostly commonly used are:
	
	|variable name | description  |
	|---- | ---- |
	|CC | C compiler |
	|CXX | C++ compiler |
	|CPP | C pre-processor |
	|AS | Assembly compiler |
	|CFLAGS | Flags passed to the C compiler |
	|CXXFLAGS | Flags passed to the C++ compiler |
	|CPPFLAGS | Flags passed to the C pre-processor compiler |
	|LDFLAGS | Flags passed to the linker |
	
	To view a listing of predefined variable execute make with -p option on a directory without a makefile.

* Automatic Variable
    
	This are variables set during implicit rules processing, when a rule has been matched to its prerequisites and targets.
	
	Relevant for this tutorials, mostly commonly used are:
	
	|variable name | description |
	|---- |  ----- |
	|$@ | The target file name. |
	|$< | The file name of the first prerequisite in the rule. |
	|$^ | Space separated list of all the prerequisites. |
	|$* | The file name without its extension, referred to as stem, of the target. |

## Conditional statements

They are control statements altering the linear make flow execution, and are evaluated during the makefile execution phase.
Make defines the following conditional statements;
* ifdef and ifndef
    These statements are used to test if a variable has been defined or alternaltely has not been defined.
    ```
        ifdef (variable-name)
            statements
        else
            statements
        endif
    ```
* ifeq and ifneq
    They are used to test if two values are equal or alternately not equal.
    ```
        ifeq (arg1, arg2)
            statements
        else
            statements
        endif
    ```

## Functions

Functions provide an efficient way to encapsulate a group of make statements supposed to acomplish a task and can be cassified into pre-defined(in-built) and user-defined.
Pre-defined functions are invoked by enclosing its name and arguments with the operators `$()`, while user defined functions are invoked using the pre-defined function `call`.
When invoking a function with more than one argument, they are separated by a comma.
* User functions defination
    They are defined in a manner similar to recursive variable defination. For example,
    ```
        my_function = @echo $(1)
    ```
    Is a simple function which would print to the standard output its argument. Its argument values are accessed by the macro expansion, `$(number)`.
    The function is invoked as follows,
    ```
        $(call my_function, "Hallo, world")
    ```