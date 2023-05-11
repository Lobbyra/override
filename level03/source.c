#include<stdio.h>
#include<fcntl.h>

void decrypt(int n) {
	// DO A LOT OF CRAZY STUFF THAT I DON'T UNDERSTAND
	if (n == 18) {
		system("/bin/sh");
	} else {
		puts("Invalid password");
	}
}

void test(int userInputN, int seed) {
	int sub = seed - userInputN;
	if ((sub >= 1 && sub <= 9) || (sub >= 0x10 && sub <= 0x15)) {
		decrypt(sub);
	} else {
		decrypt(rand());
	}
}

int main() {
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	puts("Password:");
	int userInputN;
	scanf("%d", &userInputN);
	test(userInputN, 0x1337d00d);
}
