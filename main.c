#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


    int main(void)
    {
    char *full_command = NULL, *copy_command = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    char *token;
    const char *delim = " \n";
    char **argv;
    int i = 0;
    int num_tokens = 0;

    printf("$ ");

    nchars_read = getline(&full_command, &n, stdin);

    copy_command = malloc(sizeof(char) * nchars_read);

    if (copy_command == NULL){
        perror("tsh: memory allocation error");
        return (-1);
    }

    strcpy(copy_command, full_command);

    if (nchars_read == -1){
        printf("Exiting shell...\n");
        return (-1);
    }
    else {
        token = strtok(full_command, delim);


    while (token != NULL){
        num_tokens++;
        token = strtok(NULL, delim);
    }
    num_tokens++;
    
    argv = malloc(sizeof(char *) *num_tokens);

    token = strtok(copy_command, delim);

    for (i = 0; token != NULL; i++){
        argv[i] = malloc(sizeof(char) * strlen(token));
        strcpy(argv[i], token);

        token = strtok(NULL, delim);
    }
    argv[i] = NULL;


   


free(argv);
free(full_command);
free(copy_command);
}


return(0);

}