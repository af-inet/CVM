#include <stdlib.h>
#include <stdio.h>

#include "readfile.h"

enum CODES{
	HALT,ADDA,ADDV,SUBA,SUBV,JMPA,
	JMPV,JMPI,SETA,SETV,PTRA,PTRV,
	LOAD,STOR		
};

// STATE
char PROGRAM[256];

char REGISTER[8];
char RAM[256];

char POINTER = 0;
char INST    = 0;
char RUNNING = 1;
int  CYCLES  = 0;

// Maths
void adda(char v) { REGISTER[POINTER] += REGISTER[v];}
void addv(char v) { REGISTER[POINTER] += v;}
void suba(char v) { REGISTER[POINTER] -= REGISTER[v];}
void subv(char v) { REGISTER[POINTER] -= v;}

// Jumps
void jmpv(char v) { INST = ((v-1)*2);}
void jmpa(char v) { jmpv(REGISTER[v]);}
void jmpi(char v) { if(REGISTER[POINTER] == 0)jmpv(v);}

// Stop
void halt(char v) { RUNNING = 0;}

// Set Memory
void seta(char v) { REGISTER[POINTER] = REGISTER[v];}
void setv(char v) { REGISTER[POINTER] = v;}

// Set Pointer
void ptra(char v) { POINTER = REGISTER[v];}
void ptrv(char v) { POINTER = v;}

// RAM
void load(char v) { REGISTER[POINTER] = RAM[v]; }
void stor(char v) { RAM[v] = REGISTER[POINTER]; }

void interpret(){
	char ins = PROGRAM[INST];
	char val = PROGRAM[INST+1];
	
	if( ins == HALT ) halt(val);
	if( ins == ADDV ) addv(val);
	if( ins == ADDA ) adda(val);
	if( ins == SUBV ) subv(val);
	if( ins == SUBA ) suba(val);
	if( ins == PTRA ) ptra(val);
	if( ins == PTRV ) ptrv(val);
	if( ins == JMPA ) jmpa(val);
	if( ins == JMPV ) jmpv(val);
	if( ins == JMPI ) jmpi(val);	
	if( ins == SETA ) seta(val);
	if( ins == SETV ) setv(val);
	if( ins == LOAD ) load(val);
	if( ins == STOR ) stor(val);

	INST += 2;
}

void run(){
	while(RUNNING){
		CYCLES = CYCLES + 1;
		interpret();
	}
}

void load_program(char *buffer, int length){
	if(length < 256){
		int i;
		for(i=0;i<length;i++){
			PROGRAM[i] = buffer[i];
		}
	}else{
		printf("[!] assembly file exceeds maximum length [256].\n");
	}
}

// TESTING
void prnt(char v){
	printf("[CVM] %d::%d\n", v, REGISTER[v]);
}

void dump(){
	int x;
	
	printf("%s\n","[CMV] \nDUMP\n");
	
	printf("POINTER = %d\n", POINTER);

	printf("CYCLES = %d\n",CYCLES);

	printf("REGISTERS = \n");
	for(x=0;x<8;x++){
		printf("%d ",REGISTER[x]);
	}printf("\n");

	printf("RAM (first 16 bytes) = \n");
	for(x=0;x<16;x++){
		printf("%d ",RAM[x]);
	}printf("\n");
}

char *parse_args(char argc, char **argv){
	if(argc>=1){	
		char *arg_filename = argv[1];
		return arg_filename;
	}else{
		return NULL;
	}
}

int main(char argc, char **argv){	
	char *filename = parse_args(argc,argv);
	
	if(filename==NULL){
		printf("Usage: cvm <filename>\n");
		return 0;
	}

	struct FileBuffer *fb = readfile(filename);

	if(fb==NULL){
		printf("Could not open file: '%s'\n",filename);
		return 0;
	}
	
	load_program(fb->data,fb->size);
	run();
	dump(2);

	return 0;
}


