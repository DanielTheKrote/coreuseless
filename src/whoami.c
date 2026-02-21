#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int user_id;
    struct passwd* p;
    if ((p = getpwuid(user_id = getuid())) == NULL)
    {
		char buffer[200];

		sprintf(buffer, "Could not get a user with a '%d' uid! Exiting...", user_id);
		write(2, buffer, strlen(buffer));
		_exit(EXIT_FAILURE);
    }
    write(1, p->pw_name, strlen(p->pw_name));
    _exit(EXIT_SUCCESS);
}
