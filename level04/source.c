#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();
	pid_t waitStatus;
	char buffer[128];

	if (pid == 0) {
		prctl(1, 1);
		ptrace(0, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(buffer);
	} else {
// CHECK IF THE CHILD WAS REPLACED BY EXECVE
		while (ptrace(3, pid, 0x2c, 0) != 0xb) {
			waitStatus = wait(pid);
// WE DIDN'T UNDERSTOOD THIS COMPARAISON BUT IT KIND OF CHECK IF THE CHILD IS ENDED
			if (1 == 1) { // ??
				puts("child is exiting...");
				return (0);
			}
		}
		puts("no exec() for you");
		kill(pid, 9);
	}
	return (0);
}
