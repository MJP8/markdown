#include <stdio.h> // include a standard I/O library
#include <string.h> // include a library for manipulating strings
int main(int argc, char *argv[]) { // define the function that automatically runs
	char read_file[300]; // make a string of 300 characters or less named "read_file"
	char types[10][20] = {"# ", "## ", ""}; // make a array of strings named "types"
	char converted_types[10][20] = {"<h1>", "<h2>"}; // make another array of strings named "converted_types"
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
		} else {
			printf("Error: incorrect path to file\n");
		}
		if (strlen(read_file) != 0) {
			char *type = types[0];
			int i = 0;
			do {
				if (!strncmp(type, read_file, strlen(type))) {
					printf("Found a '%s'!\n", type);
				}
				i++;
				type = types[i];
			} while(*type);
			file = fopen(argv[2], "wb");
			if (file) {
				fprintf(file, "<!DOCTYPE html><html><body><pre>%s</pre></body></html>\n", read_file);
				fclose(file);
			} else {
				printf("Error: incorrect path to file\n");
			}
		}
	} else {
		printf("Error: needs paths to files\n");
	}
	return 0;
}