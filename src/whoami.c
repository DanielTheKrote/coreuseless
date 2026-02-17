#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <stdio.h>
#define EXIT_ERROR 1

int main(void)
{
    int user_id;
    struct passwd* p;
    if ((p = getpwuid(user_id = getuid())) == NULL)
    {
	char buffer[200];
	sprintf(buffer, "Could not get a user with a '%d' uid! Exiting...", user_id);
	write(2, buffer, strlen(buffer));
	return EXIT_ERROR;
    }
    write(1, p->pw_name, strlen(p->pw_name));
}
