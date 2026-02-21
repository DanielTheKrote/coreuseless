#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 1000

void show_help()
{
}


long convert_arg(char* arg)    
{
    char* end;
    errno = 0;
    
    long result = strtol(arg, &end, 10);

    bool is_invalid_number = errno != 0 || end == arg;
    
    if (is_invalid_number)
    {
		char buffer[1000];
		sprintf(buffer, "Error: Invalid Value. Trying to convert %s to a long!", arg);
		write(1, buffer, strlen(buffer));
		_exit(EXIT_FAILURE);
    }
    return result;
}	

int main(int argc, char** argv)
{
    size_t count;
    
    if (argc < 2)
    {
	show_help();
	_exit(EXIT_FAILURE);
    }
    
    count = 0;
    while (++count < argc)
	sleep(convert_arg(argv[count]));
}
