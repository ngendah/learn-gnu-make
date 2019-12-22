Tutorial 1
================

In this tutorial I will introduce the following concepts;

1. User-defined, automatic and in-built variables,
2. Implicit (wild card) rules, substitution references, object dependency and
3. Special in-built targets.

A make variable is a region in memory where a value, whether a scalar or a complex object, is stored. This region is aliased by a name; a variable name, and this name is referenced in the makefile.

Depending on the variable assignment operator, make will set its value, at different points of its execution phase;

1. When the makefile is being parsed, it is referred to as immediate and
2. When the makefile is being executed, it is referred to as deferred.

In certain cases, instead of listing out dependencies or targets directly, we want them to be evaluated based on some existing condition.
In these cases substitution references come to our aid. Given a string, the macro will search for the occurrence of the search 'string' and replace it with the replacement 'string'.
However, the replacement is not a complete word/string replacement, but rather a character replacement, and instead of replacing all occurrences of the character, it only replaces its last occurrence.

The syntax is:

```
${<variable to be evaluated>: <what to search for>=<what to replace with>}
```

for instance `${src:.c=.o}`, will replace all occurences of character `c` with `o`, on the list of words stored on the variable `src`.
If more than one word needs to be evaluated, the list should be space separated.

An object dependency rule asserts the relationships between various objects being built and their build order.

## Example 1

This tutorial example demonstrates:

1. make variables,
2. wild card and special in-built rules.

### Makefile Structure
The [makefile](./exp1/makefile) in this example is made of;

1. 3 implicit rules and 2 static rules.
2. in-built, automatic and user-defined variables.
3. a special built-in target.

The rules are laid out in the order of dependency requirements. Its build execution will proceed as follows;

1. make will start by evaluating the `all` rule. The rule has one dependency, `main`, which initially, does not exist.
    However, there is a rule which tells make how to build it; the `main` rule.

2. the main rule, has further dependencies, assigned to the `OBJECTS` variable.
    These dependencies also do not exist, to build them make will require a rule. The rule is the wild-card rule;
    make will match the pattern on the objects and invoke it.

3. using the wild-card rules, make will build `OBJECTS`.

Once the objects are built, it will work its way upwards;

1. the main rule required `OBJECT`, and since it now exists make will try and the run command on the main rule. The command will build the main target.
2. the main target now exists and will finally try and evaluate the commands on the `all` to try and build it. There are no commands here, so it will exit with success.

If we are to think of the dependency requirements as being laid out in a binary tree, the execution flow would be depth-first.

The makefile also has a special rule target named `.PHONY`, with the dependency target `clean`. The `clean` rule is used to remove built objects.

#### make variables
The first variable we observe is the user-defined variable `OBJECT`, whose value is assigned with the immediate operator `:=`.

Next, are the in-built variables `CC`, `LDFLAGS` and `CFLAGS`.
The `CC` variable evaluates to the set default C-compiler, while the `LDFLAGS` and `CFLAGS` have no values,and will evaluate to empty strings.
Variable can also be overridden, for example the empty variable CFLAGS can be set a valid value by simply using the variable assignment operator, for instance `CFLAGS=-g`.

#### wild card rules
As the project C-sources increases, the number of objects required to be built increases proportionately.
We would probably want to give make the objects we want built and a rule, made up of search and replace patterns, on how to build them from the sources files.
In this example I have used it to tell make how to build objects from its sources;

```
%.o: %.c
    commands
```

whenever make comes across an object dependency ending with the characters `.o`, it will locate its equivalent object name ending with `.c` and use it on its commands.
The `%` is the wild-card character, a set of characters which in this case are not to be substituted.

#### special in-built rules
What would happen if there was a command which would create a file named `all`?

lets try it.
Alter the `all` rule as follows:

```
all: main
	touch all
```

execute `make clean` before executing `make`. As usual everything will proceed as expected and the `main` target will be built.
Update the C-source file timestamp's to mimic some changes on it, by executing the command `touch main.c`, and re-execute `make`.
With some changes having taken place you expect the rebuild process to proceed as normally, but instead you are met with the message;

```
make: 'all' is up to date.
```

Before, make builds a target it checks if;

1. it exists and
2. its up to date, that is, the built file includes the most current changes. 

In this case the target `all` exists and its up to date.If you remove the `all` file, everything proceeds normally.

## Example 2

This tutorial example demonstrates;

1. substitution references and
2. object dependency.

The example we create function that will use to `add` two numbers. This functionality is contained on the header file `add.h` and implemented on the source file `add.c`.
`main.c` uses this function to add two numbers.

The overall structure follow that of `example1`;

- Variables
- Rules

### Substitution references

In this example we use substitution references to specify the objects that we would want `make` to build.

```
SRCS := main.c add.c
OBJECTS := $(SRCS:.c=.o)
``` 

The variable `SRC` holds the list of source files we have in the project,
while `OBJECTS` will hold the objects to be linked into the final executable.

`make` by default builds objects corresponding to the source file, we use su

### Object dependency
