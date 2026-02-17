#define EXIT_FAILURE 1

#ifndef EXIT_CODE
#define EXIT_CODE EXIT_FAILURE
#endif

int main()
{
    return EXIT_CODE;
}
