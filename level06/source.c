#include <stdio.h>
#include <string.h>

int auth(char *s, int code) {
    int sLen = strnlen(s, 0x20);
    int sIndex;
    int x;

    s[strcspn(s, "\n")] = '\0';
    x = (s[3] ^ 0x1337U) + 0x5eeded;
    for (sIndex = 0; sIndex < sLen; sIndex = sIndex + 1) {
        if (s[sIndex] < ' ') {
            break;
        }
        x += (x ^ (unsigned int)s[sIndex]) % 0x539;
    }
    // printf("result = [%d]\n", x);
    if (x == code) {
        return (0);
    }
    return (1);
}

int main() {
    char buf[100];
    unsigned int code;

    puts ("***********************************");
    puts ("*\t\tlevel06\t\t  *");
    puts ("***********************************");
    puts ("-> Enter login: ");
    fgets(buf, 100, stdin);
    puts ("***********************************");
    puts ("***** NEW ACCOUNT DETECTED ********");
    puts ("***********************************");
    puts ("-> Enter Serial: ");
    scanf("%u", &code);
    // printf("buf = [%s]\n", buf);
    // printf("code = [%u]\n", code);
    if (auth(buf, code) == 0) {
        puts("Authenticated!");
        system("/bin/sh");
    } else {
        return (1);
    }
}
