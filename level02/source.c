#include <fcntl.h>
#include <stdio.h>

int main() {
	char userPass[101];
	char passFileContent[42];
	char userName[101];
	int i;

	for (i = 0; i < 42; i++) {
		passFileContent[i] = '\0';
	}
	for (i = 0; i < 101; i++) {
		userName[i] = '\0';
	}
	for (i = 0; i < 101; i++) {
		userPass[i] = '\0';
	}
	FILE *passFD = fopen("/home/users/level03/.pass", O_RDONLY);
	fread(passFileContent, 1, 41, passFD);
	fclose(passFD);
	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\***************************************/");
	printf("--[ Username: ");
	fgets(userName, 100, stdin);
	printf("--[ Password: ");
	fgets(userPass, 100, stdin);
	puts("*****************************************");
	if (strncmp(userPass, passFileContent, 41) == 0) {
		printf("Greetings, %s!\n", &format);
    		system("/bin/sh");
	} else {
		printf(&format);
        	puts(" does not have access!");
        	exit(1);
	}
}

