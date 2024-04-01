# Fucos Programming Language

Fucos is a basic programming language built using C++. It utilizes semicolons (`;`) and dots (`.`) to denote the start and end of lines of code respectively. The execution begins from a `mainFOk` function, where the code block is enclosed within curly braces `{}`.

## Syntax

### Main Function Definition
```
mainFOk(){
  (code).
};
```
- `;` denotes the end of a function.

### Print Statement
`COm("Hello,World!!).`

- The `COm` statement is used to print a message to the console. The message to be printed is enclosed within double quotes.

## Special Characters
- The language includes exceptions for escape characters, currently skipping them during execution.

## Repository Structure

### FOCUS
- **code**: Contains files with `.foc` extension where the Fucos code exists. If the file extension is not `.foc`, an option to rename the file is provided.
- **src**: Contains the source code for the Fucos compiler with the following files:
  - `foc.cpp`: Main compiler file.
  - `testComponents.h`: For testing the validity of code.
  - `keywords.h`: For execution of keywords.

## Getting Started

To start coding in Fucos, follow these steps:

1. **Compilation**: Compile the source code using the following command:
   ```bash
   g++ foc.cpp testComponents.h keywords.h -o foc
This will create an executable file named foc.

2. **Execution**: Run the compiled file with the Fucos code file as an argument:
   ```bash
   ./foc fileName.foc
Only one .foc file can be run at a time. Running ./foc without specifying a file will result in an error for no file found.

## Note
At the moment, only one .foc file can be executed at a time.


This `README.md` file provides an overview of the Fucos programming language, its syntax, repository structure, and instructions for getting started with coding in Fucos. Feel free to customize it further to meet your specific needs or preferences.


