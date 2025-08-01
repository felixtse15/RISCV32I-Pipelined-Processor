/* Copyright 2025 Felix Tse

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "state.h"
#include "types.h"  


// Read the file into instruction memory
void read_file(cpu_t *state, char *filename) {
	FILE *f = fopen(filename, "r");
	if (f == NULL) {
		printf("Error opening file!\n");
		return;
	}
	
	char buf[20];
	int i = 0;
	
	// replace the newline character with null terminated character
	while(fgets(buf, sizeof(buf), f)) {
		buf[strcspn(buf, "\n")] = '\0';			
		state->imem[i] = (uint32_t)strtoul(buf, NULL, 16);	
		i++;
	}
	
	// dont forget to close the file
	fclose(f);	
}

// Main
int main(int args, char **argv) {
	cpu_t state;
	init_cpu(&state);
	printf("INSTRNM: %d\n", INSTRNUM);
	if (args < 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}
	
	read_file(&state, argv[1]);
	uint32_t i = 0;
	while (state.pc < 4 * INSTRNUM) {
		i = (state.pc) / 4;
		printf("%08X, ", state.imem[i]);
		decode_instr(&state, state.imem[i]);
	}

	return 0;
}

