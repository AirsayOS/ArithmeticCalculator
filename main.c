#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_valid_operand(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool parse_input(char* input, double* num1, double* num2, char* operand) {
    char* endptr;

    // parse first number
    *num1 = strtod(input, &endptr);

    // check if input is valid
    if (endptr == input) {
        printf("Invalid input. Please try again.\n");
        return false;
    }

    // skip any white spaces
    while (*endptr == ' ') {
        endptr++;
    }

    // check if operand is valid
    if (!is_valid_operand(*endptr)) {
        printf("Invalid input. Please try again.\n");
        return false;
    }
    *operand = *endptr;

    // use strtod to parse second number
    *num2 = strtod(endptr+1, &endptr);

    // check if input is valid
    if (endptr == input || *endptr != '\n') {
        printf("Invalid input. Please try again.\n");
        return false;
    }

    return true;
}

void perform_operation(double num1, double num2, char operand) {
    switch (operand) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: division by zero\n");
            } else {
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            }
            break;
        default:
            printf("Invalid operand. Please try again.\n");
            break;
    }
}

int main() {
    char* input = NULL;
    double num1, num2;
    char operand;
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

        // parse input
        valid_input = parse_input(input, &num1, &num2, &operand);

        // free memory
        free(input);
    }

    // perform arithmetic operation based on operand
    perform_operation(num1, num2, operand);

    return 0;
}
