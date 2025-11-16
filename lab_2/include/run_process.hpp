/*
- time - child process sleep time (in seconds)
- path_to_file - path to executed binary file
- options - program options (name + args)
*/ 

int run_process(int time, char* path_to_file, char* options[]); // здесь options должен заканчиваться NULL