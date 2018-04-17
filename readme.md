Learn GNU make
===============
This is work in progress; bear with me.
The goal is to share my knowledge about GNU make and in the process help others who are trying to learn it.
My hope is that by the end of the tutorials you will have sufficient knowledge of make and makefile to be able to use it to build your own programs.

# Prerequisites
The tutorials assumes you have a modest working knowledge of the Linux operating system commands and the version control system, Git, :-).
You will also need to clone the project onto your computer.

# Requirement 
In order to go through the tutorials you will require to install the following programs;
* `C`,
* `gnu make` and 
* `install`.

On debian based distributions they can be installed as follows,
```
$sudo apt-get install build-essentials
```

while on red-hat based distributions,
```
$sudo yum groups install -y  "Development Tools"
```
or
```
$sudo dnf groups install -y  "Development Tools"
```

Tutorial 7 has an extra requirement, which would prefer an rpm based distribution, such as Fedora, ;-).

# whats covered

1. Introduction to GNU make.
2. Build an executable.
3. Building an executable with sources structured in sub-directories.
4. Building shared libraries.
5. Putting it all together.
6. Building rpm files.


LICENSE
==========
Licensed under the Apache License, Version 2.0. See [LICENSE](LICENSE) for the full license text.
