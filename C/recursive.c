#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int i = 0;
int error = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

int main() {
    printf("Enter input string: ");
    gets(input);  // use with caution (lab version)
    E();

    if (strlen(input) == i && error == 0) {
        printf("Input accepted.\n");
    } else {
        printf("Error!\nInput rejected.\n");
    }

    return 0;
}

void E() {
    T();
    Eprime();
}

void Eprime() {
    if (input[i] == '+') {
        i++;
        T();
        Eprime();
    }
}

void T() {
    F();
    Tprime();
}

void Tprime() {
    if (input[i] == '*') {
        i++;
        F();
        Tprime();
    }
}

void F() {
    if (isalpha(input[i])) {
        i++;
    } else if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')') {
            i++;
        } else {
            error = 1;
        }
    } else {
        error = 1;
    }
}
