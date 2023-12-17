#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generateRandomPassword(int length, int useLetters, int useNumbers, int useSymbols) {
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+";
    char password[length + 1];

    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < length; i++) {
        int choice = rand() % 3;
        if (useLetters && (choice == 0 || (!useNumbers && !useSymbols))) {
            password[i] = letters[rand() % strlen(letters)];
        } else if (useNumbers && (choice == 1 || !useSymbols)) {
            password[i] = numbers[rand() % strlen(numbers)];
        } else if (useSymbols) {
            password[i] = symbols[rand() % strlen(symbols)];
        }
    }

    password[length] = '\0';
    printf("Senha Gerada: %s\n", password);
}

int main() {
    int length, useLetters, useNumbers, useSymbols;

    printf("insira o comprimento da senha: ");
    scanf("%d", &length);
    printf("Usar letras? (0 para não, 1 para sim): ");
    scanf("%d", &useLetters);
    printf("Usar números? (0 para não, 1 para sim): ");
    scanf("%d", &useNumbers);
    printf("Usar símbolos? (0 para não, 1 para sim): ");
    scanf("%d", &useSymbols);

    generateRandomPassword(length, useLetters, useNumbers, useSymbols);
    return 0;
}
