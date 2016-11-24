#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[2], "r");

    if (file != NULL)
    {
        char line[1000];
        while (fgets(line, sizeof line, file) != NULL) /* read a line from a file */
        {
            fprintf(stdout, "%s", line); //print the file contents on stdout.
            if (strstr(line, argv[1]) == 0)
            {
                fprintf(stdout, "%s bob", line); //print the file contents on stdout.
            }
        }

        fclose(file);
    }
    else
    {
        perror(argv[2]); //print the error message on stderr.
    }

    return 0;
}
