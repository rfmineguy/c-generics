# c_generics
A library for my own projects that require common datastructures. Very work in progress

# Why?
One of the things I really like about higher level languages is their generics systems.
C doesn't have native generic support, so I decided I would try my hand at making a set of common datastructure `templates` for C that make generics easier.

# How?
Macros

# Usage
This library is NOT a single header. The usage is that you still have a seperate translation unit per generic type, but making those translation units is streamlined via the C macro system.

| See examples/ directory for a few premade templates |
|-----------------------------------------------------|

# Contributing
It would be amazing if there are bugs that you submit a Github Issue about it. Please try t be specific about the issue.
