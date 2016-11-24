#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LGT 50
#define MAX_PERSONS 10

/* Strucks */
struct person
{
    char fornavn[MAX_NAME_LGT];
    char efternavn[MAX_NAME_LGT];
    char vejnavn[MAX_NAME_LGT];
    int vejnummer;
    int postnummer;
    char bynavn[MAX_NAME_LGT];
};

/* Typedef */
typedef struct person person;

/* Prototypes */
person define_person(char *fornavn, char *efternavn, char *vejnavn, int vejnummer, int postnummer, char *bynavn)

/* Main function */
int main(void){
    person persons[MAX_PERSONS];
}

/* Functions */
person define_person(char *fornavn, char *efternavn, char *vejnavn, int vejnummer, int postnummer, char *bynavn){
    person result;

    strcpy(result.fornavn, fornavn);
    strcpy(result.efternavn, efternavn);
    strcpy(result.vejnavn, vejnavn);
    strcpy(result.vejnummer, vejnummer);
    strcpy(result.postnummer, postnummer);
    strcpy(result.bynavn, bynavn);

    return result;
}

