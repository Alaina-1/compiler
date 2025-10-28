#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = -1, i = 0;

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void printRow(const char *action) {
    printf("%-15s %-15s %-20s\n", stack, input + i, action);
}

void reduce() {
    int changed;
    do {
        changed = 0;
        if (top >= 1 && stack[top] == 'd' && stack[top - 1] == 'i') {
            top--; stack[top] = 'E'; stack[top + 1] = '\0';
            printRow("Reduce id→E");
            changed = 1;
        } else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E') {
            top -= 2; stack[top] = 'E'; stack[top + 1] = '\0';
            printRow("Reduce E+E→E");
            changed = 1;
        } else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '-' && stack[top - 2] == 'E') {
            top -= 2; stack[top] = 'E'; stack[top + 1] = '\0';
            printRow("Reduce E-E→E");
            changed = 1;
        }else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '*' && stack[top - 2] == 'E') {
            top -= 2; stack[top] = 'E'; stack[top + 1] = '\0';
            printRow("Reduce E*E→E");
            changed = 1;
        } else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '/' && stack[top - 2] == 'E') {
            top -= 2; stack[top] = 'E'; stack[top + 1] = '\0';
            printRow("Reduce E/E→E");
            changed = 1;
        }
    } while (changed);
}

int main() {
    printf("Enter input (example: id+id*id/id): ");
    scanf("%s", input);

    printf("\n%-15s %-15s %-20s\n", "STACK", "INPUT", "ACTION");
    printf("---------------------------------------------------\n");

    while (i < strlen(input)) {
        // Handle 'id' as a single token
        if (input[i] == 'i' && input[i + 1] == 'd') {
            push('i');
            push('d');
            printRow("Shift: id");
            i += 2;
        } else {
            push(input[i]);
            char msg[20];
            sprintf(msg, "Shift: %c", input[i]);
            printRow(msg);
            i++;
        }
        reduce();
    }

    if (strcmp(stack, "E") == 0)
    printf("String Accepted\n");
else
    printf("String Rejected\n");

return 0;

}