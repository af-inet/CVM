#  VM

# Instruction Set Specification



### All Instructions

| name | code | translation                             |
| ---- | ---- | --------------------------------------- |
| HALT | 0x00 | **HALT**s the program.                  |
| ADDA | 0x01 | **ADD** **A**ddress                     |
| ADDV | 0x02 | **ADD** **V**alue.                      |
| SUBA | 0x03 | **SUB**tract **A**ddress                |
| SUBV | 0x04 | **SUB**tract **V**alue.                 |
| JMPA | 0x05 | **J**u**MP** to **A**ddress             |
| JMPV | 0x06 | **J**u**MP** to **V**alue.              |
| JMPI | 0x07 | **J**u**MP** to **I**nstruction Pointer |
| SETA | 0x08 | **SET** to **A**ddress                  |
| SETV | 0x09 | **SET** to **V**alue                    |
| PTRA | 0x0A | Set **P**oin**TR** to **A**ddress       |
| PTRV | 0x0B | Set **P**oin**TR** to **V**alue         |

### Structure

| name | parameter |
| ---- | --------- |

**name** is simply the instruction you're calling, `ADDV`, for example.

**parameter** determines how that instruction executes.

for example:

| ADDV | 4 |
| ---- | --------- |

### Model

In order to understand the instruction set, it's important to understand
the model of resources you're dealing with.

| value                   | type                         |
| ----------------------- | ---------------------------- |
| **Program**             | 2 byte array of instructions |
| **Instruction Pointer** | 1 byte register              |
| **Memory**              | 256 byte RAM                 |
| **Memory Pointer**      | 1 byte register              |

**Program** is simply the list of instructions we're executing.

**Instruction Pointer** is the index of the next instruction to be executed.

**Memory** is a 256 byte array.

### Example Program

```
; assembly             ; psuedo  ; description
PTRV 0, SETV 2         ; [0] = 2 ; (pointer to cell 0, set value to 2)
PTRV 1, SETV 3         ; [1] = 3 ; (pointer to cell 1, set value to 3) 
PTRV 2                 ; [2]     ; (pointer to cell 2)
ADDA 0                 ; +=*[0]  ; (add [address 0] to pointer)
ADDA 1                 ; +=*[1]  ; (add [address 1] to cell 2)
; First four bytes of memory are now:
; index : | 0 | 1 | 2 | 3 |
; value : | 2 | 3 | 6 | 0 |

```

**Visualization**
|-|-|-|-|-|-|
|-                    |  -|  -|  -|  -|  -|
|**PTRV 0**|          |   |   |   |   |
| Memory Pointer      | **V** |   |   |   |   |
| Memory              | 0 | 0 | 0 | 0 | 0 |
|  **SETV 2**         |   |   |   |   |   |
| Memory Pointer      | **V** |   |   |   |   |
| Memory              | 2 | 0 | 0 | 0 | 0 |
| **PTRV 1**          |   |   |   |   |   |
| Memory Pointer      |   | **V** |   |   |   |
| Memory              | 2 | 0 | 0 | 0 | 0 |
| **SETV 3**          |   |   |   |   |   |
| Memory Pointer      |   | **V** |   |   |   |
| Memory              | 2 | 3 | 0 | 0 | 0 |
| **PTRV 2**          |   |   |   |   |   |
| Memory Pointer      |   |   | **V** |   |   |
| Memory              | 2 | 3 | 0 | 0 | 0 |
| **ADDA 0**          |   |   |   |   |   |
| Memory Pointer      |   |   | **V** |   |   |
| Memory              | 2 | 3 | 2 | 0 | 0 |
| **ADDA 1**          |   |   |   |   |   |
| Memory Pointer      |   |   | **V** |   |   |
| Memory              | 2 | 3 | 5 | 0 | 0 |









---


