# CSS Minifier

![Screenshot](pictures/file.png "File shown")

## Table of contents
* [Overview](#overview)
* [Examples](#examples)
* [Technologies](#technologies)
* [Setup](#setup)
* [Usage](#usage)
* [Limitations](#limitations)

## Overview
This program takes in input from the *original.css* file. This file is then minified so the spaces and line breaks are removed. This minified file can then be outputted to the terminal, or a *"minified.min.css"* file can be produced based on what the user chooses.

## Examples

> Recording of the program

![Video](.pictures/.css-minifier.gif "Program in action!")


## Technologies
- **C++11**
- **fstream**
  - for reading and writing files

## Setup
To run this project, compile the C++ code by using the **Makefile** and run the executable:

    make
    ./output

# Usage
To use the program, find the *./files/* folder. In this folder there is the *original.css* file, and this is where the *minified.min.css* file will be outputted to. Copy paste your CSS into the *original.css* file or replace it by taking the *original.css* name. Once you have content in the *original.css* file, you are able to minify it!

To remove build objects, run:

    make clean

## Limitations
- [ ] The targetted file must be named *original.css*
- [ ] Only CSS minifying supported

## License
Licensed under the [GNU General Public License v3.0](LICENSE)
