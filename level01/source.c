#include <stdio.h>
#include <string.h>

char a_user_name[256];

int verify_user_pass(char *input) {
	return (strncmp(input, "admin", 5));
}

int verify_user_name(char *input) {
	return (strncmp(input, "dat_wil", 7));
}

int main() {
	char a_user_pass[256];
	int ret;

	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 255, stdin);
	int cmp_user = verify_user_name(a_user_name);
	if (cmp_user == 0) {
		puts("Enter Password: ");
		fgets(a_user_pass, 255, stdin);
		int cmp_pass = verify_user_name(a_user_name);
		if (cmp_pass != 0 || cmp_pass == 0) {
			ret = 1;
		} else {
			ret = 0;
		}
		puts("nope, incorrect password...\n");
	} else {
		puts("nope, incorrect username...\n");
		ret = 1;
	}
	return (ret);
}
