#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char read_file[300];
	if (argc > 2) {
		FILE *file;
		int value;
		file = fopen(argv[1], "rb");
		if (file) {
			while (1) {
				value = fgetc(file);
				if (value == EOF) break;
				else sprintf(read_file, "%s%c", read_file, value);
			}
			fclose(file);
		} else {
			printf("Error: incorrect path to file\n");
			printf("%s", argv[1]);
		}
		if (strlen(read_file) != 0) {
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