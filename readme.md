Learn GNU make
===============

The goal is to share my knowledge about GNU make and in the process help others who are trying to learn it.
My hope is that by the end of the tutorials you will have sufficient knowledge of make and makefile to be 
able to use it to build your own programs.

# Prerequisites
The tutorials assumes you have a modest working knowledge of the Linux operating system commands and the version control system, Git.
You will also need to clone the tutorials onto your computer.

# Requirement 
In order to go through the tutorials you will require to install the following programs;
* `C`,
* `gnu make`,
* `nasm` and 
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

Tutorial 7 has an extra requirement, which would prefer an rpm based distribution, such as Fedora.


Tutorials
===========

[Introduction: The syntax](./intro/readme.md)

[Tutorial 1: Basics](./tutorial1/readme.md)

[Tutorial 2: Variables and rules](./tutorial2/readme.md)

[Tutorial 3: Shell and wildcard functions](./tutorial3/readme.md)

[Tutorial 4: Building executables](./tutorial4/readme.md)

[Tutorial 5: Building shared libraries](./tutorial5/readme.md)

[Tutorial 6: Building an installable package with RPM](./tutorial6/readme.md)

[Tutorial 7: Assembly and embedded](./tutorial7/readme.md)

[References](./references/readme.md)


LICENSE
==========

All code is licensed under the Apache License, Version 2.0. See [LICENSE](LICENSE) for the full license text.
All non-source code licensed under the Creative Commons BY-NC-SA 4.0 license.
