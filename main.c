#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char *input = NULL;
    char operand;
    double num1, num2;
    bool valid_input = false;

    while (!valid_input) {
        printf("Enter an arithmetic expression (e.g. 2 + 2): ");

        // dynamically allocate memory for input buffer
        input = (char*)malloc(100 * sizeof(char));
        if (input == NULL) {
            printf("Error: memory allocation failed\n");
            return 1;
        }

        // read input string from stdin
        fgets(input, 100, stdin);

        // use strtod to convert input string to double
        char *endptr;
        num1 = strtod(input, &endptr);

        // check if input is valid
        if (endptr == input) {
            printf("Invalid input. Please try again.\n");
            free(input);
            continue;
        }

        // skip any white spaces
        while (*endptr == ' ') {
            endptr++;
        }

        // check if operand is valid
        operand = *endptr;
        if (operand == '\0' || operand == '\n') {
            printf("Invalid input. Please try again.\n");
            free(input);
            continue;
        }

        // use strtod to convert second number
        num2 = strtod(endptr+1, &endptr);

        // check if input is valid
        if (endptr == input || *endptr != '\n') {
            printf("Invalid input. Please try again.\n");
            free(input);
            continue;
        }

        // perform arithmetic operation based on operand
        switch (operand) {
            case '+':
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
                valid_input = true;
                break;

            case '-':
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
                valid_input = true;
                break;

            case '*':
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
                valid_input = true;
                break;

            case '/':
                if (num2 == 0) {
                    printf("Error: division by zero\n");
                } else {
                    printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
                }
                valid_input = true;
                break;

            default:
                printf("Invalid operand. Please try again.\n");
                free(input);
                break;
        }
    }

    //free(input);

    return 0;
}
