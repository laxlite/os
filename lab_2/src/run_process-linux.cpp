#include<iostream>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<errno.h>

#include"run_process-linux.hpp"

using std::cout, std::cerr, std::endl, std::string;


int run_process(int time, char* path_to_file, char* options[]){ // options - NULL-terminated
    pid_t pid = fork();
    if(pid == 0){
        cout << "Hello from child process\n" << endl;
        sleep(time);
        int status = execv(path_to_file, options); // Вернет -1, если есть ошибка
        if(status == -1){                          // если всё прошло успешно, ничего не возвращает (замещает код)
            cerr << strerror(errno) << endl;
            exit(-1);
        }
    }
    else if (pid > 0)
    {
        cout << "Hello from parent process\n" << endl;
        int status = NULL;
        waitpid(pid, &status, 0);
        if(WIFEXITED(status)){  // если дочерний процесс завершился нормально (exit())
            cout << "Child process complete with status=" << WEXITSTATUS(status) << endl; // статус завершения дочернего процесса
        }
        else if(WIFSIGNALED(status)){ // если завершился отправкой сигнала
            cout << "Child process ended with a signal=" << WTERMSIG(status) << endl; // выводим сигнал
        }
        else{
            cout << "Child process complete" << endl;
        }
        exit(0);
    }
    else{
        cerr << "Error in fork(): " << strerror(errno) << endl;
        exit(-1);
    }
    return 0;
}