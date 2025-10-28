#include <stdio.h>
#include <ctype.h>
#include <string.h>

char input[100];
int i = 0;

// Function declarations
int E();
int EP();
int T();
int TP();
int F();

int main() {
    printf("\nRecursive Descent Parsing for the grammar:\n");
    printf("E  -> T E'\n");
    printf("E' -> + T E' | ε\n");
    printf("T  -> F T'\n");
    printf("T' -> * F T' | ε\n");
    printf("F  -> (E) | id\n");

    printf("\nEnter the string to be checked: ");
    scanf("%s", input);

    if (E() && input[i] == '\0')
        printf("\nString is accepted\n");
    else
        printf("\nString is not accepted\n");

    return 0;
}

// E → T E'
int E() {
    if (T()) {
        if (EP())
            return 1;
        else
            return 0;
    } else
        return 0;
}

// E' → + T E' | ε
int EP() {
    if (input[i] == '+') {
        i++;
        if (T()) {
            if (EP())
                return 1;
            else
                return 0;
        } else
            return 0;
    }
    return 1; // epsilon
}

// T → F T'
int T() {
    if (F()) {
        if (TP())
            return 1;
        else
            return 0;
    } else
        return 0;
}

// T' → * F T' | ε
int TP() {
    if (input[i] == '*') {
        i++;
        if (F()) {
            if (TP())
                return 1;
            else
                return 0;
        } else
            return 0;
    }
    return 1; // epsilon
}

// F → (E) | id
int F() {
    if (input[i] == '(') {
        i++;
        if (E()) {
            if (input[i] == ')') {
                i++;
                return 1;
            } else
                return 0;
        } else
            return 0;
    } else if (isalpha(input[i])) { // id
        i++;
        return 1;
    } else
        return 0;
}
