# The Platformer

Have questions/comments/concerns? Check Gitter:

[![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/UAF-CS372-Spring-2015/the-platformer?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)

Have feature ideas or want to report progress? Check Waffle.io:

[![Pending](https://badge.waffle.io/UAF-CS372-Spring-2015/the-platformer.svg?label=pending&title=Pending)](http://waffle.io/UAF-CS372-Spring-2015/the-platformer)
[![Ongoing](https://badge.waffle.io/UAF-CS372-Spring-2015/the-platformer.svg?label=ongoing&title=Ongoing)](http://waffle.io/UAF-CS372-Spring-2015/the-platformer)
[![Critical](https://badge.waffle.io/UAF-CS372-Spring-2015/the-platformer.svg?label=critical&title=Critical)](http://waffle.io/UAF-CS372-Spring-2015/the-platformer)

# SFML

This project will be using SFML:

http://www.sfml-dev.org/

If using Mac, get SFML with Homebrew (it's easiest). If you don't have Homebrew, get it:

http://brew.sh/

Then: `brew update && brew install sfml`

If using Windows, download the binary from the main website.

# Files

`main.cpp` is the release suite.

`test.cpp` is the test/debug suite.

# Building

You can compile with: `clang++ -lsfml-graphics -lsfml-window -lsfml-system -std=c++14`.

(If using other SFML modules, put them after graphics, before window and system.)

We also have a Makefile, which will build things automatically for you:

`make` will build the release suite.

`make test` will build the test suite.

`make clean` will remove the executables.

# Catch

The test/debug suite uses Catch, a C++ unit-testing framework, which is a submodule of this repo. Find it at: https://github.com/philsquared/Catch.

Because of this, make sure you clone this repo with `git clone --recursive`.

# SFML Examples/Tutorials

Some cool SFML examples:

https://github.com/jhpy1024/sfPong

https://github.com/jhpy1024/sfSnake

Tutorials can be found at:

http://www.sfml-dev.org/tutorials/2.2/

# Attributions

Player sprite: http://nyaneoneko.deviantart.com/art/Mini-Morphea-Sprite-Sheet-322112525

Some rights reserved. This work is licensed under a
[Creative Commons Attribution-Noncommercial-No Derivative Works 3.0 License](http://creativecommons.org/licenses/by-nc-nd/3.0/).
