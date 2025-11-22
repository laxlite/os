#include<stdio.h>
#include<string.h>

#if defined(_WIN32)
    #include"run_process-windows.hpp"
#elif defined(__linux__)
    #include"run_process-linux.hpp"
#endif

char** get_options_array(char options[]){
    char** options_array = new char*[11]; // количество слов в команде
    int options_it = 0;
    int symbol_it = 0; // позиция текущего символа в options
    char buffer[200]; // длина одного слова
    int buffer_it = 0;
    while (true)
    {
        if(options[symbol_it] == '\0' || options[symbol_it] == ' '){
            buffer[buffer_it] = '\0';
            char* word = new char[buffer_it + 1];   // выделяем память под слово
            memcpy(word, buffer, buffer_it + 1);    // копируем символы из буфера в слово
            options_array[options_it++] = word;
            
            if(options[symbol_it] == '\0'){
                break; 
            }
            buffer_it = 0;
        }
        else{
            buffer[buffer_it++] = options[symbol_it];
        }
        symbol_it++;
    }
    options_array[options_it] = NULL;
    return options_array;
}

int main(int argc, char* argv[]){
    char* path_to_file = new char[1000];
    char* options = new char[1000];
    int time = 0;
    printf("Enter the sleep time: ");
    scanf("%d", &time);
    printf("Enter the program path:");
    scanf("%s", path_to_file);
    printf("Enter the program options (one line separated by space):");
    getchar();                              // Считывает с буфера \n. он остался, т.к. scanf считывает до пробельного символа НЕ включительно
    fgets(options, sizeof(options) * 1000, stdin); // считает строку до /n включительно или до sizeof(options) символов. 
                                            // scanf читает до пробельного символа
                                            // если символы вместились - добавляет в конец 
    options[strcspn(options, "\r\n")] = '\0';   // убираем последний символ, если он попал в строку

    #ifdef _WIN32
        // logic for changing options_array - if its win, then options_array is char*. Otherwise - use get_options_array
        // macros must be define in cmakelists.txt
        LPSTR options_array = options;
    #elif defined(__linux__)
        char** options_array = get_options_array(options);
    #endif

    int status = run_process(time, path_to_file, options_array);

    return status;
}