#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) { 
    return strcmp(a, b); 
}

int main(int argc, char *argv[]){
    char roles[18][24] ={
        {"Linux Guru"},
        {"Python Coder"},
        {"SQL"},
        {"C Coder"},
        {"C# Coder"},
        {"Lua Coder"},
        {"WEB (HTML,CSS,PHP) Coder"},
        {"JavaScript Coder"},
        {"C++ Coder"},
        {"Java Coder"},
        {"CCNA"},
        {"CCNP"},
        {"Windows Server Guru"},
        {"Girl"},
        {"Boy"},
        {"Trello Usr"},
        {"GitHub Usr"},
        {"LaTeX Usr"}
        };

    qsort(roles, 18, 24, compare);

    for (int i = 0; i < 24; i++)
    {
        printf("%s\n",roles[i]);
    }
}