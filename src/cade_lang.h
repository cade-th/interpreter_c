#pragma once
typedef enum {
	Shell,
	File
} Config_t;

typedef struct {
	Config_t type;
	char *file_path;
	int num_args;
} Config ;

Config config_build(int argc, char *argv[]);
void run(Config config);
void run_shell();
char *run_file(char *file_path);
