#include <stdio.h>
#include <string.h>

void getName(char*, size_t size);

int main() {

    char firstName[30];
    char middleName[30];
    char lastName[30];
    char fullName[100];
    char symbol;
    int counter;

    printf("Enter your first name: ");
    getName(firstName, sizeof(firstName) / sizeof(firstName[0]));
    printf("Enter your middle name: ");
    getName(middleName, sizeof(middleName) / sizeof(middleName[0]));
    printf("Enter your last name: ");
    getName(lastName, sizeof(lastName) / sizeof(lastName[0]));

    sprintf(fullName, "%s %s %s", firstName, middleName, lastName);

    printf("Your full name is: ");
    fputs(fullName, stdout);

    size_t fullNameSize = strlen(fullName);
    printf("\nfull name size is %zu", fullNameSize);

    printf("\nEnter a symbol: ");
    scanf("%c", &symbol);

    for (int i = 0; i < strlen(fullName); i++)
        if (fullName[i] == symbol)
            counter++;
    
    printf("full name containes %d '%c's", counter, symbol);

    return 0;
}

void getName(char *pName, size_t size) {
    fgets(pName, size, stdin);
    pName[strlen(pName) - 1] = '\0';
}