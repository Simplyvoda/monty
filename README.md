# monty 🧮 🧮
Basis of task is to create an interpreter for Monty ByteCodes files. Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Usage
The monty interpreter would be used this way `monty <file>`
- where <file> is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to the program, the program prints an error message and exites with status `EXIT_FAILURE`
- If, for any reason, it’s not possible to open the file,the program prints the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
- If the file contains an invalid instruction, the program prints the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`. 

## Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

## General
- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables
