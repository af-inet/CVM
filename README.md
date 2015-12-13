# CVM (WIP)

Cpu Virtual Machine

A virtual machine which emulates my WIP CPU 

https://github.com/DavidHargat/LogisimCpu

### clone/build/run

`git clone https://github.com/DavidHargat/CVM`

`cd CVM`

`make`

`./cvm <filename>`

## Instruction Set

See DOCS.md for a full documentation of the instruction set.

## Assembler

Python script which parses and assembles an instruction file.


For example if you have an instruction file:


**add.instr**


And you want to assemble it, simply run:


`python assembler add.instr`


and it will output a file `add.instr.asm` which contains your assembled bytecode.


You can specify the output filename with `-o <filename>`.


