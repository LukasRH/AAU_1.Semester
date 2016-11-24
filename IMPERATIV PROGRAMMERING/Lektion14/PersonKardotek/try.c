#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME_LGT 50

struct person
{
    char fornavn[MAX_NAME_LGT];
    char efternavn[MAX_NAME_LGT];
    char vejnavn[MAX_NAME_LGT];
    int vejnummer;
    int postnummer;
    char bynavn[MAX_NAME_LGT];
};

typedef struct person person;
person read_personkartotek(FILE *fp);

int main(void)
{
    FILE *fp = fopen("personer-ind.txt", "r");
    person persons[11];
    int ch, number_of_lines = 0;

    do
    {
        ch = fgetc(fp);
        if (ch == '\n')
            number_of_lines++;
    } while (ch != EOF);
    if(ch != '\n' && number_of_lines != 0) 
    number_of_lines++;

    

    for (int i = 0; i <= 10; i++)
    {
        persons[i] = read_personkartotek(fp);
        printf("Fornavn: %-10s Efternavn: %-10s Vejnavn: %-23s Vejnummer: %-4d Postnummer: %-5d By: %-10s\n", persons[i].fornavn, persons[i].efternavn, persons[i].vejnavn, persons[i].vejnummer, persons[i].postnummer, persons[i].bynavn);
    }

    fclose(fp);

    return 0;
}

person read_personkartotek(FILE *fp)
{
    person rec;
    fscanf(fp, " %s %[A-Za-z], %[A-Za-z ] %d, %d %[A-Za-z].", rec.fornavn, rec.efternavn, rec.vejnavn, &rec.vejnummer, &rec.postnummer, rec.bynavn);

    return rec;
}
