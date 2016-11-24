#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void code_spliter(char *barcode, int length);

int main(void){
    char barcode[] = "ATL1203S14";
    char *warehouse, *id, *qualifiers;
    int length = strlen(barcode), pos;

    strncpy(warehouse, barcode, 3);

    qualifiers = strrchr(barcode, 'S');

    pos = length - strlen(warehouse) - strlen(qualifiers);
    id = strnchr(barcode, pos);

    printf("Warehouse: %s\nID: %s\nQualifiers %s\n",warehouse,id,qualifiers);
}
