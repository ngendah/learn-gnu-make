Tutorial 1
================

In this tutorial I will introduce the following concepts;
1. User-defined, automatic and in-built variables,
2. wild-card rules, substitution references and how to specify object dependency.

But first in make context what is a variable? its a memory region where a value, which could be a scalar or a complex object, is stored. This region is aliased by a name; a variable name, and this name is referenced in our computations.

Depending on the variable assignment operator, make will set its value, at different points of its execution phase;
1. When the makefile is being parsed, referred as immediate and
2. When the makefile is being executed, referred as deferred.

## Example 1:
This tutorial example is primarily aimed at introducing make variables, but it will also introduce wild-card rules.

### Makefile Structure
The [makefile](./exp1/makefile) in this example is made of 3 implicit rules and 2 static rules but also in-built, automatic and user-defined variables.

The rules are laid out in a 'natural order', as dependency are required to be being built.
The execution will proceed as follows;

```
all requires main, it does not exist how is it built, go to the main rule
main requires OBJECTS, but they do not exist, how are they built, go use the wild-card rules
wild card rules say, this how you build OBJECTS, it will build them
```

once the objects are built, it will work its way backwards;

```
OBJECTS have been built, go to main rule, use its commands to build the main target
main target has been built, go to the all rule,
all dependency have been built, no commands, therefore nothing to do here, exit
```

The short story, :-).

### How does it use variables?
The first variable we observe is the user-defined variable `OBJECT`, whose value is assigned with the immediate operator `:=`.

Next, are the in-built variables `CC`, `LDFLAGS` and `CFLAGS`.
The `CC` variable evaluates to the set default C-compiler, in my case the gcc compiler while the `LDFLAGS` and `CFLAGS` have by default have no values, so they will be just empty strings.


  
 
 
 