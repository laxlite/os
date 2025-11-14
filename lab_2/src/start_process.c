#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    pid_t pid = fork();
    if(pid == 0){
        printf("Hello from child process\n");
        sleep(2);
        int status = execl(argv[1], argv[2], argv[3], NULL);
        if(status == -1){
            return -1;
        }
    }
    else if (pid > 0)
    {
        printf("Hello from parent process\n");
        int* status = (int*)malloc(sizeof(int));
        waitpid(pid, status, 0);
        printf("Child process complete with status=%d", *status);
        free(status);
    }
    else{
        printf("Ошибка!!!");
    }   
}