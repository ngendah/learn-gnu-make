Autotools, Autoconf
========================================

This tutorial uses Autotools, autoconf to extend our makefiles.

Autotools is capable of generating makefiles but sometimes you may want to use self authored makefile and at same time use `autoconf` to add configurations.

`autoconf` generates a `configure` script that is used to checks the characteristics of the host system.

This tutorial uses `autoconf` to search for specific compilers and whichever one that is found is used to make a placeholder substitution and generating the file set on the macro `AC_CONFIG_FILES`.

The placeholder substituted is `@CC@` on `configure` input file `makefile.config.in`.

To run the tutorial, execute the commands,

```
$ autoconf
$ ./configure
$ make
```
