#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void log_wrapper(FILE *arg1, char *arg2, char **arg3) {
    char log_string[256];
    
    strcpy(log_string, arg2);
    snprintf(log_string, sizeof(log_string), arg3);
    log_string[strcspn(log_string, "\n")] = '\0';
    fprintf(arg1, "LOG: %s\n", log_string);
}


int main(int argc, char **argv) {
    FILE *log_fd;
    FILE *original_df;
    int backup_fd;
    char ptr[100];
    int c;

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    
    log_fd = fopen("./backups/.log", "w");
    if (log_fd == NULL) {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        return 1;
    }
    
    log_wrapper(log_fd, "Starting back up: ", argv + 1);
    
    original_df = fopen(argv[1], "r");
    if (original_df == NULL) {
        printf("ERROR: Failed to open %s\n", argv[1]);
        return 1;
    }

    snprintf(ptr, sizeof(ptr), "%s%s", "./backups/", argv[1]);
    backup_fd = open(ptr, O_WRONLY | O_CREAT, 0600);
    if (backup_fd < 0) {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        return 1;
    }
    
    while ((c = fgetc(original_df)) != EOF) {
        write(backup_fd, &c, 1);
    }
    
    log_wrapper(log_fd, "Finished back up ", argv + 1);
    
    fclose(original_df);
    close(backup_fd);
    
    return 0;
}
