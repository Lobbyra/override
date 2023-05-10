#include <stdio.h>

int main(void)
{
    int passcode;
    
    puts("***********************************");
    puts("* \t     -Level00 -\t\t  *");
    puts("***********************************");
    printf("Password:");
    scanf("%d", &passcode);
    if (passcode != 0x149c) {
        puts("\nInvalid Password!");
    } else {
        puts("\nAuthenticated!");
        system("/bin/sh");
    }
    return (passcode != 0x149c);
}

