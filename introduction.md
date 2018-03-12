# Introduction
When i first learnt to write my first program in C, it was a single C source file and constituted of a main function that printed to the screen the words 'hello world!'. It was compiled and built by executing the command `$cc -o <outputfile-name> <source file name>`. I have include it as my [first tutorial](tutorial0/hello_world.c).
This was a simple program, to build something more useful, with a couple of more source files, this approach would be fraught with peril; an efficient approach would be required. 
Use of GNU make is an example of an efficient approach, to compilation, building and maintaince of a project. Think of it as a chef who is given a recipe and ingredients and the goal is to make a culinary delicacy. The recipe is called a makefile, ingredients the various source files and dependent libraries required to make the delights, our targets.
It's therefore a build automation tool, which follows a set of rules telling it how from a list of input source files and dependencies its to build target files.

# Key concepts
Make, which i use to mean GNU Make, requires a makefile. A makefile is text file consisting of rules, in a predefined format and classified into:
* Static
    This are rules that specify mutiple targets to be built by the commands. The rule format is as follows:
    ```
    targets: target-pattern: prerequisites-pattern
        ->command; command
        ->command
    ```
    The target pattern matches the target output to its prerequisites.
* Implicit
    This are rules composed of patterns for both targets and prerequisites.
    ```
    targets: prerequisites
       ->command; command
       ->command
    ```
A rule is composed of 3 key elements:
* Targets, classified into:
    * file targets
        Consisting of a list of file names that are to be generated.
        Targets can be a single target or mutiple targets. In cases where its more than one target a space is used to separate them.
    * phony targets
        A single target which is a command that is to be executed when make is executed. However, if a file exists with the a name similar to the command, executing such a command fails, since make detects that the target already exists.
    * built-in targets
        They are targets understood by make and have a special meaning. Examples are .PHONY, .SUFFIXES.
* Prerequisites which is a set of input files that are required to be able to generate the targets.
    Where more that one prerequisite is required a space is used to separate them.
* Commands which are a list of actions to be taken on the input files in order to generate the target files.
    Commands are listed on a new line and must be preceded by a single tab space, indicated by the use of the symbol '->'. When mutiple commands are to be listed on a single line they are separated by a semi-colon.
Apart from rules makefiles can also include comments, variables, conditional statements and functions.
Comments are text preceded by a hash(#) upto but not including the beginning of a newline. They are ignored by the make process.
When make is invoked on a directory it searches for the receipe file with the name, makefile or Makefile. Therefore its only appropriate to name make files as a such.
