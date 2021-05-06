#include <stdlib.h> // include a library
#include <stdio.h> // include a standard I/O library
#include <string.h> // include a library for manipulating strings
void findLine(char readFrom[300], int *end, char character);
int main(int argc, char *argv[]) { // define the function that automatically runs
	char read_file[300]; // make a string of 300 characters or less named "read_file"
	char types[10][20] = {"# ", "## ", ""}; // make a array of strings named "types"
	char converted_types[10][20] = {"<h1>", "</h1>", "<h2>", "</h2>"}; // make another array of strings named "converted_types"
	if (argc > 2) { // if there are two or more parameters then...
		FILE *file; // create a pointer to a file
		int value; // create a integer varible
		file = fopen(argv[1], "rb"); // open the file the user specifies
		if (file) { // if the file was opened successfully then...
			while (1) { // repeat this forever (unless you type "break")
				value = fgetc(file); // set the value varible to a character in the file
				if (value == EOF) break; // if it is the end of the file exit the loop
				else sprintf(read_file, "%s%c", read_file, value); // otherwise add the character to the varible "read_file"
			}
			fclose(file); // close the file
		} else { // otherwise...
			printf("Error: incorrect path to file\n"); // print an error message
		}
		if (strlen(read_file) != 0) { // if the varible "read_file" has text in it then...
			file = fopen(argv[2], "wb"); // open a file to write to
			if (!file) { // if the file wasn't opened successfully then...
				printf("Error: incorrect path to file\n"); // print an error message
				exit(1); // exit with an error
			} else { // otherwise...
				int endOfLine = 0; // create a integer varible named "endOfLine" set to zero
				char c; // create a character varible name "c"
				findLine(read_file, &endOfLine, c);
				char *type = types[0]; // create a pointer to a pointer
				int i = 0; // create a integer varible named "i" set to zero
				char line[255]; // create a string named "line"
				do { // do...
					strncpy(line, read_file, endOfLine); // set line to the line 
					line[endOfLine] = 0; // add a zero to the end of the line
					if (!strncmp(type, line, strlen(type))) { // if type is in the line then...
						printf("Found a '%s' in '%s'!\n", type, &line[strlen(type)]); // print something
						fprintf(file, "<!DOCTYPE html><html><body>%s%s%s</body></html>\n", converted_types[0], &line[strlen(type)], converted_types[0 + 1]); // write to a file
					}
					i++; // increase i
					type = types[i]; // increase type
				} while(*type); // ...while *type is true
				fclose(file); // close the file
			}
		}
	} else { // otherwise...
		printf("Error: needs paths to files\n"); // print a error
	}
	return 0; // return zero
}
void findLine(char readFrom[300], int *end, char character) {
	int j = 0;
	while(character = readFrom[j]) { // while c = read_file's j character do...
		if(character == '\n') { // if c is the end of the line then...
			*end = j; // set endOfLine to j
			break; // exit the loop
		}
		j++; // increase j
	}
}