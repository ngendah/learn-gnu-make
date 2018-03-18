# Introduction
When I first learnt to write my first program in C, it was a single C source file and constituted of a main function that printed to the screen the words 'hello world!'. It was compiled and built by executing the command `$cc -o <outputfile-name> <source file name>`. I have included it as my [first tutorial](tutorial0/hello_world.c).
This was a simple program, later on, to build something more useful and with a couple of more source files, an efficient approach would be required. 
Use of GNU make is an example of an efficient approach, to compilation, building and maintaince of a project. Think of it as a chef who is given a recipe and ingredients and the goal is to make a culinary delicacy. The recipe is called a makefile, ingredients the various source files and dependent libraries required to make the delights, our targets.
GNU make, is therefore, a build automation tool which follows a set of rules telling it how, from a list of input source files and dependencies its to build targets.

# Key concepts

Make, which I use to mean GNU Make, requires a makefile. 
A makefile is text file consisting of rules; in a predefined format, comments, variables, conditional statements and functions.

## Rules
Make rules is a set of instructions telling it what to do and are classified into:

* Static rules
    This are rules that specify mutiple targets to be built by the commands. The rule format is;
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

	They are variables defined by the user, and be categorized into:
	
	* Recursive variables
	
		They contain reference to other variables, and the values are set using the recursive operator `=`. The variable value is evaluated when its used.
		```
			VAR_NAME = value
		```
		
	* Simple variables
	
		They contain single values determined at the time of declaration. Its values are set using the simple operator `=` or using the `define` keyword.
		```
			VAR_NAME := value
			
			define VAR_NAME
			value
			endef
		```
	Variable also can altered using the append operator, `=+`, or truncate operator, `=-`. 

* Common variables

* Automatic

	
	