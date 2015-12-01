# CVM (WIP)

Cpu Virtual Machine

A virtual machine which emulates my WIP CPU 

https://github.com/DavidHargat/LogisimCpu

### clone/build/run

**NOTE: cvm does not accept input files yet**

`git clone https://github.com/DavidHargat/CVM`

`make`

`./cvm <filename>`

## Instruction Set


Each instruction is made up of two bytes.


The first byte is the instruction, and the second is a value or address.


Example:


`Add 1`


Which might have the binary equivalent:


`00000011 00000001`


## Assembler

Python script which parses and assembles an instruction file.


For example if you have an instruction file:


**add.instr**


```
ptrv 0
setv 64

ptrv 1
setv 32

ptrv 2
adda 0
adda 1

halt 0
```


And you want to assemble it, simply run:


`python assembler test.instr`


and it will output a file `test.instr.asm` which contains your assembled file.


You can specify the output filename with `-o <filename>`.


