#include <stdlib.h>
#include <stdio.h>

#include "readfile.h"

enum CODES{
		HALT,ADDA,ADDV,SUBA,SUBV,JMPA,
		JMPV,JMPI,SETA,SETV,PTRA,PTRV
};

// STATE
char PROGRAM[256];
char MEMORY[256];
char POINTER = 0;
char INST = 0;
char RUNNING = 1;

// Maths
void adda(char v) { MEMORY[POINTER] += MEMORY[v];}
void addv(char v) { MEMORY[POINTER] += v;}
void suba(char v) { MEMORY[POINTER] -= MEMORY[v];}
void subv(char v) { MEMORY[POINTER] -= v;}
// Jumps
void jmpv(char v) { INST = ((v-1)*2);}
void jmpa(char v) { jmpv(MEMORY[v]);}
void jmpi(char v) { if(MEMORY[POINTER] == 0)jmpv(v);}
// Stop
void halt(char v) { RUNNING = 0;}
// Set Memory
void seta(char v) { MEMORY[POINTER] = MEMORY[v];}
void setv(char v) { MEMORY[POINTER] = v;}
// Set Pointer
void ptra(char v) { POINTER = MEMORY[v];}
void ptrv(char v) { POINTER = v;}

// TESTING
void prnt(char v){
	printf("[CVM] %d::%d\n", v, MEMORY[v]);
}

void dump(char height){
	int x,y;
	
	printf("%s\n","[CMV] \nDUMP\n");
	
	printf("POINTER = %d\n", POINTER);

	printf("MEMORY = \n");

	for(x=0;x<height;x++){
		for(y=0;y<16;y++){
			printf("%d ",MEMORY[y+(x*16)]);
		}
		printf("\n");
	}
}

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
	
	INST += 2;
}

void run(){
	while(RUNNING){
		interpret();
	}
}

void load(){
	
	char p[256] = {
		// Variables
		PTRV, 0, SETV, 9,
		PTRV, 1, SETV, 6, 

		// Temps
		PTRV, 2, SETA, 0,
		PTRV, 3, SETA, 1,

		// If Temp=0, goto end
		JMPI, 15,
			PTRV, 3, SUBV, 1,
			PTRV, 0, ADDA, 2,
			PTRV, 3,
		JMPV, 8,

		// Clear Temp Variables
		PTRV, 2, SETV, 0,
		PTRV, 1, SETV, 0,

		// End
		HALT, 0	
	};

	int i;
	for(i=0;i<256;i++){
		PROGRAM[i] = p[i];
	}

}

int main(char argc, char **argv){	

	load();
	run();
	dump(1);

	return 0;
}


