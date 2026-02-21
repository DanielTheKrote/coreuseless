#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 64
#endif


void show_help()
{
}


void  set_hostname(char* hostname)
{
    size_t hostname_length = strlen(hostname);
    if (sethostname(hostname, hostname_length) == 0)
        _exit(EXIT_SUCCESS);

    char*  error;
    switch (errno)
    {
    case EPERM:
        error = "Error! The user does not have the right to change the hostaname!";
        break;
    case EINVAL:
        error = "Size is negative!";
        break;
    case ENAMETOOLONG:
        error  = "Name too long!";
        break;
    default:
        error = "IDK";
        break;
    }
    write(2, error, strlen(error));
    _exit(EXIT_SUCCESS);
}


int main(int argc, char** argv)
{
    if  (argc < 2)
    {
        show_help();
        _exit(EXIT_SUCCESS);
    }

    if (strcmp(argv[1], "set") == 0)
    {
        if (argc < 3 )
        {
            _exit(EXIT_FAILURE);
        }
        set_hostname(argv[2]);
    }
    
    char* name = malloc(sizeof(char) * HOST_NAME_MAX);
    if (gethostname(name, HOST_NAME_MAX) != 0)
        _exit(EXIT_FAILURE);
    
    char buffer[HOST_NAME_MAX];
    sprintf(buffer, "%s", name);
    write(1, buffer, strlen(buffer));
}
