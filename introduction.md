Introduction
==============

When I first learnt to write my first program in C, it was a single C source file and constituted of a main function that printed to the screen the words 'hello world!'.
It was compiled and built by executing the command `$cc -o <outputfile-name> <source file name>`.
I have included a modified version of it as my [first tutorial](tutorial0/readme.md).
This was a simple program, later on, to build something more useful and with a couple of more source files, I required a more efficient approach.
And this is why and when I learned the use of GNU make which simplified the compilation, building and maintenance of a project.
Think of it as a chef who is given a recipe and ingredients and whose goal is to make a culinary delicacy. Analogically, the recipe is called a makefile; ingredients the various source files and dependent libraries which are (collectively referred to as prerequisites) required to make the delicacy. GNU make is therefore a build automation tool that follows a set of rules telling it how, from a list of input source files and dependencies, to build targets.

# Key concepts

Make, which I use to mean GNU make, requires a makefile. 
A makefile is a text file consisting of rules in a predefined format that contains comments, variables, conditional statements and functions.
When make is invoked on a directory it searches for the recipe file with the name makefile or Makefile.

## Rules
Make rules are a set of instructions telling it what to do and are classified into:

* Static rules:
    These are rules that specify multiple targets(filenames with extensions) to be built by the commands. The rule format is;
    ```
    targets: target-pattern: prerequisites-pattern
        ->command; command
        ->command
    ```
    The target pattern matches the target output to its prerequisites.

* Implicit rules:
    These are rules composed of patterns for both targets and prerequisites. The rule format is;
    ```
    targets: prerequisites
       ->command; command
       ->command
    ```
   since implicit rules work without specific filenames, commands make use of automatic variables to process prerequisites and produce targets.

In general, a rule is composed of 3 key elements:

1. Targets, that are classified into:


    * File targets

        Consisting of a list of file names that are to be generated.
        Targets can be a single target or multiple targets. In cases where its more than one target a space is used to separate them.

    * Phony targets

        A single target which is a command that is to be executed when make is executed. However, if a file with a similar name as the command exists, executing the command would fail.

    * Built-in targets

        They are targets understood by make and have a special meaning. Examples are .PHONY, .SUFFIXES.

2. Prerequisites that are a set of input files required to be able to generate the targets.

    Where more than one prerequisite is required a space is used to separate them.

3. Commands that are a list of actions to be taken on the input files in order to generate the target files.

    Commands are listed on a new line and must be preceded by a single tab space, indicated by the use of the symbol '->'. When multiple commands are to be listed on a single line they are separated by a semi-colon.

Apart from rules, makefiles can also include comments, variables, conditional statements and functions.

## Comments

Comments are explanations added to the make file in order to aid in the understanding what the purpose of the entire program or sections of it.
They are ignored by the make process.
Comments are preceded by a hash(#) and end with a newline.

## Variables

There are 3 type of variables:

* User defined

	They are variables defined by the makefile author and are categorized into:
	
	* Recursive variables
	
		They contain references to other variables, and the values are set using the recursive operator `=`. The variable value is evaluated when the makefile is being executed.
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
	Variable can also be altered using the append operator, `=+`, or truncate operator, `=-`. 

* Predefined variables

	Predefined variables are variables inbuilt within make, and have special meanings. Some of these variables refer to programs whilst others are common arguments to these programs.
	
	Pertaining to these tutorials, the mostly commonly used are:
	
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
	
	To view a listing of predefined variables, execute make with the -p option on a directory without a makefile.

* Automatic Variable
    
	These are variables set during implicit rules processing, when a rule has been matched to its prerequisites and targets.
	
	Pertaining to these tutorials, the mostly commonly used are:
	
	|variable name | description |
	|---- |  ----- |
	|$@ | The target file name |
	|$< | The file name of the first prerequisite in the rule |
	|$^ | Space separated list of all the prerequisites |
	|$* | The file name without its extension, referred to as the stem of the target |

## Conditional statements

They are control statements altering the linear make flow execution, and are evaluated during the makefile execution phase.
Make defines the following conditional statements;
* ifdef and ifndef
    These statements are used to test if a variable has been defined or alternately has not been defined.
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

Functions provide an efficient way to encapsulate a group of make statements supposed to accomplish a task and can be classified into pre-defined (inbuilt) and user-defined.
Pre-defined functions are invoked by enclosing its name and arguments with the operators `$()`, while user-defined functions are invoked using the pre-defined function `call`.
When invoking a function with more than one argument, they are separated by a comma.
* User functions definition
    They are defined in a manner similar to recursive variable definition. For example,
    ```
        my_function = @echo $(1)
    ```
    This a simple function which would print to the standard output its argument. Its argument values are accessed by the macro expansion, `$(number)`.
    The function is invoked as follows,
    ```
        $(call my_function, "hello, world")
    ```