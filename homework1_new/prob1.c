#include <stdio.h>

int main() {
    double num1, num2, result; // Variables for the numbers and result
    char operator; // Variable for the arithmetic operator

    // Prompt the user for input
    printf("Enter an arithmetic expression (e.g., 5 + 6): ");
    
    // Read user input (number, operator, number)
    scanf("%lf %c %lf", &num1, &operator, &num2);

    // Perform the operation using switch
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("%.0f %c %.0f = %.3f\n", num1, operator, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.0f %c %.0f = %.3f\n", num1, operator, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.0f %c %.0f = %.3f\n", num1, operator, num2, result);
            break;
        case '/':
            switch (num2 == 0) {  // Handling division by zero within switch
                case 1:
                    printf("Error: Division by zero is not allowed.\n");
                    return 1; // Exit with an error code
                case 0:
                    result = num1 / num2;
                    printf("%.0f %c %.0f = %.3f\n", num1, operator, num2, result);
                    break;
            }
            break;
        default:
            printf("Error: Invalid operator. Use +, -, *, or /.\n");
            return 1; // Exit with an error code
    }

    return 0; // Indicate successful execution
}
