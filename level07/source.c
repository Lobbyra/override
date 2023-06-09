#include <string.h>
#include <stdio.h>

void clear_stdin(void)
{
    char cStdin;

    do {
        cStdin = getchar();
        if (cStdin == '\n') {
            return;
        }
    } while (cStdin != -1);
    return;
}

unsigned int get_unum() {
	unsigned int num;

	fflush(stdout);
	scanf("%u", &num);
	clear_stdin();
	return num;
}

int read_number(int arr[100]) {
	unsigned int index;
	printf(" Index: ");
    	index = get_unum();
   	printf(" Number at data[%u] is %u\n", index, arr[index * 4]);
    	return 0;
}

int store_number(int arr[100]) {
	unsigned int index;
	unsigned int number;

	printf(" Index: ");
	index = get_unum();
	printf(" Number: ");
	number = get_unum();
	if ((index % 3 == 0) || (number >> 0x18 == 0xb7)) {
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return (1);
	} else {
		arr[index * 4] = number;
		return (0);
	}
}

int main(int argc, char **argv, char **envp) {
	int arr[100];
	int i;
	int envpSize;
	char commandBuf[20];
	int cmdStatus = 0;

	for(i = 1; i < argc; i++) {
		memset(argv[i], 0, strlen(argv[i]));
	}
	for(envpSize = 0; envp[envpSize] != NULL; envpSize++) {}
	for(i = 0; i < envpSize; i++) {
		memset(envp[i], 0, strlen(envp[i]));
	}
	puts(
			"----------------------------------------------------\n  Welcome to wil\'s crappy number storage service!   \n----------------------------------------------------\n Commands:                                          \n    store - store a number into the data storage    \n    read  - read a number from the data storage     \n    quit  - exit the program                        \n----------------------------------------------------\n   wil has reserved some storage :>                 \n----------------------------------------------------\n"
	    );
	while (1) {
		printf("Input command: ");
		fgets(commandBuf, 20, stdin);
		if (strncmp(commandBuf, "store", 5) == 0) {
			cmdStatus = store_number(arr);
		} else if (strncmp(commandBuf, "read", 4) == 0) {
			cmdStatus = read_number(arr);
		} else if (strncmp(commandBuf, "quit", 4) == 0) {
			printf("quit");
			break;
		} else {
			printf("Invalid command\n");
			cmdStatus = 1;
		}
		if (cmdStatus == 0) {
			printf(" Completed %s command successfully\n", commandBuf);
		} else {
			printf(" Failed to do %s command\n", commandBuf);
		}
	}
	return 0;
}
