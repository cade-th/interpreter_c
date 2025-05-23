#include "../include/cade_lang.h"
#include "stdio.h"
#include "stdlib.h"
#include <stdbool.h>
#include <string.h>

void run(Config config) {
	if (config.type == Shell) {
		run_shell();
	}
	else {
		run_file(config.file_path);
	}
}

void run_shell() {

	bool should_quit = false;
	char input[20];

	while (!should_quit) {
		printf("cade_lang> ");

		if (fgets(input, sizeof(input), stdin) == NULL) {
		    break;
		}

		size_t len = strlen(input);
		if (len > 0 && input[len - 1] == '\n') {
		    input[len - 1] = '\0';
		}

		if (strlen(input) == 0) continue;

		if (strcmp(input, ".quit") == 0) {
		    should_quit = true;
		    continue;
		}

	}
}

char *run_file(char *file_path) {
	FILE *file = fopen(file_path, "rb");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char *buffer = malloc(size + 1); // +1 for null terminator
    if (!buffer) {
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, size, file);
    buffer[size] = '\0'; // Null-terminate the string
    fclose(file);
    return buffer;
}

Config config_build(int argc, char *argv[]) {
	Config config;
	switch(argc) {
		case 1:
			printf("Running Shell...\n");
			config = (Config){ 
				Shell, 
				NULL, 
				argc 
			};
			return config;		
		case 2:
			printf("Running File with file path: %s\n", argv[1]);
			config = (Config) {
				File,
				argv[1],
				argc
			};
			return config;
		default:
			printf("Usage: idk [script]\n");
			exit(1);
			break;
	}
}
