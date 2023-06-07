#include <stdio.h>

int main() {
	char buf[100];
	int len;
	int i = 0;

	fgets(buf, 100, stdin);
	len = strlen(buf);
	while (i < len) {
		if (buf[i] >= 'A' && buf[i] <= 'Z') {
			buf[i] += 32;
		}
		i++;
	}
	printf(buf);
	exit(1);
}
