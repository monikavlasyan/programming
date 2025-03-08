#include <stdio.h>
//prob1
int main() {
    double num1, num2, result;
    char op;

    // Input: Read an arithmetic expression (number operation number)
    printf("Enter an arithmetic expression (e.g., 5 + 6): ");
    scanf("%lf %c %lf", &num1, &op, &num2);

    // Perform the operation using switch
    switch (op) {
        case '+':
            result = num1 + num2;
            printf("%.2f %c %.2f = %.2f\n", num1, op, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2f %c %.2f = %.2f\n", num1, op, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2f %c %.2f = %.2f\n", num1, op, num2, result);
            break;
        case '/':
            if (num2 != 0) {  // Check for division by zero
                result = num1 / num2;
                printf("%.2f %c %.2f = %.3f\n", num1, op, num2, result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Error: Invalid operator. Use +, -, *, or /.\n");
    }

    return 0;
}
//prob2
#include <stdio.h>

int main() {
    int grade;

    while (1) {  // Infinite loop until the user enters -1
        // Prompt the user for input
        printf("Enter your grade (0-100) or -1 to exit: ");
        scanf("%d", &grade);

        // Check for exit condition
        if (grade == -1) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Validate input range
        if (grade < 0 || grade > 100) {
            printf("Invalid input. Please enter a grade between 0 and 100.\n");
            continue; // Ask again
        }

        // Determine the letter grade using switch-case structure
        char letter;
        switch (grade / 10) {  // Integer division to get tens place
            case 10:
            case 9: letter = 'A'; break;
            case 8: letter = 'B'; break;
            case 7: letter = 'C'; break;
            case 6: letter = 'D'; break;
            default: letter = 'F';
        }

        // Print the result
        printf("Your grade is %c\n", letter);
    }

    return 0;
}

//prob3
#include <stdio.h>

int main() {
    int N, sum = 0;

    // Input validation
    do {
        printf("Enter a number (1-1000): ");
        scanf("%d", &N);

        if (N < 1 || N > 1000) {
            printf("Invalid input. Please enter a number between 1 and 1000.\n");
        }
    } while (N < 1 || N > 1000);

    // Calculate sum of multiples of 3 or 5 below N
    for (int i = 1; i < N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    // Print the result
    printf("Sum of multiples of 3 and 5 below %d is: %d\n", N, sum);

    return 0;
}

//prob4
#include <stdio.h>

int main() {
    int num, sum = 0, digit;

    // Prompt user for input
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Take absolute value to handle negative numbers
    if (num < 0) {
        num = -num;
    }

    // Calculate sum of digits
    while (num > 0) {
        digit = num % 10;  // Extract last digit
        sum += digit;      // Add to sum
        num /= 10;         // Remove last digit
    }

    // Print the result
    printf("Sum of digits: %d\n", sum);

    return 0;
}

//prob5
#include <stdio.h>

int main() {
    int num, reversed = 0, digit;

    // Prompt user for input
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Handle negative numbers
    int isNegative = (num < 0);
    if (isNegative) {
        num = -num;  // Convert to positive for processing
    }

    // Reverse the number
    while (num > 0) {
        digit = num % 10;              // Extract last digit
        reversed = reversed * 10 + digit;  // Append digit to reversed number
        num /= 10;                     // Remove last digit
    }

    // Restore negative sign if the input was negative
    if (isNegative) {
        reversed = -reversed;
    }

    // Print the result
    printf("Reversed number: %d\n", reversed);

    return 0;
}


//prob7
#include <stdio.h>

int main() {
    int num, original, reversed = 0, digit;

    // Prompt user for input
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Store original number to compare later
    original = num;

    // Handle negative numbers (negative numbers can't be palindromes)
    if (num < 0) {
        printf("%d is not a palindrome.\n", num);
        return 0;
    }

    // Reverse the number
    while (num > 0) {
        digit = num % 10;              // Extract last digit
        reversed = reversed * 10 + digit;  // Append to reversed number
        num /= 10;                     // Remove last digit
    }

    // Check if the reversed number matches the original
    if (original == reversed) {
        printf("%d is a palindrome.\n", original);
    } else {
        printf("%d is not a palindrome.\n", original);
    }

    return 0;
}

//prob8
#include <stdio.h>
#include <math.h>

int main() {
    int num1, num2, concatNum, digits = 0, temp;

    // Input two numbers
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Find number of digits in num2
    temp = num2;
    while (temp > 0) {
        temp /= 10;
        digits++;
    }

    // If num2 is 0, it has 1 digit
    if (num2 == 0) {
        digits = 1;
    }

    // Concatenate by shifting num1 left (multiplying by 10^digits) and adding num2
    concatNum = num1 * pow(10, digits) + num2;

    // Print the result
    printf("Concatenated number: %d\n", concatNum);

    return 0;
}

//prob9
#include <stdio.h>

int isPowerOfTwo(int num) {
    // A number is a power of 2 if it is greater than 0 and has only one '1' bit in binary.
    return (num > 0) && ((num & (num - 1)) == 0);
}

int main() {
    int num;

    // Prompt user for input
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Check if the number is a power of 2
    if (isPowerOfTwo(num)) {
        printf("%d is a power of 2.\n", num);
    } else {
        printf("%d is not a power of 2.\n", num);
    }

    return 0;
}

//prob10
#include <stdio.h>

int main() {
    int N, M;
    char ch;

    // Get inputs
    printf("Enter width (N): ");
    scanf("%d", &N);
    
    printf("Enter height (M): ");
    scanf("%d", &M);
    
    printf("Enter drawing character: ");
    scanf(" %c", &ch); // Space before %c to ignore newline character

    // Draw rectangle
    for (int i = 0; i < M; i++) {  // Rows
        for (int j = 0; j < N; j++) {  // Columns
            // Print character at borders, space inside
            if (i == 0 || i == M - 1 || j == 0 || j == N - 1) {
                printf("%c", ch);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

//prob11
#include <stdio.h>

int main() {
    int N;

    // Get input for triangle height
    printf("Enter height (N): ");
    scanf("%d", &N);

    // First right-angled triangle (left-aligned)
    printf("\nLeft-Aligned Triangle:\n");
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Second right-angled triangle (right-aligned)
    printf("\nRight-Aligned Triangle:\n");
    for (int i = 1; i <= N; i++) {
        // Print leading spaces
        for (int j = 0; j < N - i; j++) {
            printf(" ");
        }
        // Print stars
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

//prob12
#include <stdio.h>

int main() {
    int N;

    // Input the integer N
    printf("Enter an integer N: ");
    scanf("%d", &N);

    // Loop to print the triangle
    for (int i = 1; i <= N; i++) {
        // Print leading spaces
        for (int j = i; j < N; j++) {
            printf(" ");
        }
        // Print stars
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        // Move to the next line
        printf("\n");
    }

    return 0;
}

//prob13
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;

    // Initialize random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    number = rand() % 100 + 1;

    // Prompt the user to guess the number
    printf("Guess the number (between 1 and 100):\n");

    // Continue guessing until the user guesses correctly
    do {
        // Take user input
        scanf("%d", &guess);
        attempts++;

        // Provide feedback based on the user's guess
        if (guess < number) {
            printf("Too low! Try again: ");
        } else if (guess > number) {
            printf("Too high! Try again: ");
        } else {
            printf("Correct! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != number);

    return 0;
}

//prob14
#include <stdio.h>

int main() {
    int low = 1, high = 100, guess, response;

    printf("Think of a number between 1 and 100 and I will try to guess it.\n");

    // Repeat until the computer guesses the number
    int attempts = 0;
    while (low <= high) {
        attempts++;
        guess = low + (high - low) / 2;  // Binary search guess
        printf("Is your number %d? (Enter 1 for correct, 2 for too high, 3 for too low): ", guess);
        scanf("%d", &response);

        if (response == 1) {
            printf("Yay! I guessed your number %d in %d attempts.\n", guess, attempts);
            break;
        } else if (response == 2) {
            high = guess - 1;  // Guess was too high
        } else if (response == 3) {
            low = guess + 1;  // Guess was too low
        } else {
            printf("Invalid input. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}

//prob15
#include <stdio.h>

int main() {
    int numbers[10];
    int min, max;

    // Input 10 numbers
    printf("Enter 10 numbers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
    }

    // Initialize min and max as the first number
    min = numbers[0];
    max = numbers[0];

    // Find the minimum and maximum numbers
    for (int i = 1; i < 10; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    // Output the results
    printf("The minimum number is: %d\n", min);
    printf("The maximum number is: %d\n", max);

    return 0;
}

//prob16
#include <stdio.h>

int main() {
    int numbers[10] = {0};  // Array to count occurrences of numbers 1-10
    int input;

    printf("Enter numbers between 1 and 10 (enter -1 to stop):\n");

    // Loop to take user inputs
    while (1) {
        scanf("%d", &input);

        if (input == -1) {
            break;  // Stop when -1 is entered
        }

        if (input >= 1 && input <= 10) {
            numbers[input - 1]++;  // Increment the count for the number
        } else {
            printf("Please enter a number between 1 and 10, or -1 to stop.\n");
        }
    }

    // Print the results
    printf("\nOccurrences of numbers 1 to 10:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: %d times\n", i + 1, numbers[i]);
    }

    return 0;
}

//prob17
#include <stdio.h>
#include <stdlib.h>

void printBinary(int n, int bits) {
    unsigned mask = 1 << (bits - 1);  // Create a mask to get the leftmost bit

    // Print each bit starting from the most significant bit
    for (int i = 0; i < bits; i++) {
        if (n & mask)
            printf("1");
        else
            printf("0");
        
        n <<= 1;  // Shift the number to the left
    }
    printf("\n");
}

int main() {
    int num;

    // Input the number from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Determine if the number is negative
    if (num < 0) {
        // For negative numbers, calculate 2's complement representation
        num = (1 << 4) + num;  // This calculates the 2's complement for a 4-bit representation
    }

    // Print the binary representation
    printf("Binary representation (in 4 bits): ");
    printBinary(num, 4);

    return 0;
}

//prob18
#include <stdio.h>
#include <string.h>
#include <math.h>

int binaryToDecimal(char binary[]) {
    int decimal = 0;
    int length = strlen(binary);

    // Traverse through the binary string from left to right
    for (int i = 0; i < length; i++) {
        // If the current character is '1', add the corresponding power of 2 to decimal
        if (binary[i] == '1') {
            decimal += pow(2, length - i - 1);  // Calculate power of 2
        }
    }
    
    return decimal;
}

int main() {
    char binary[33];  // To store the binary input (maximum 32 bits)

    // Input the binary number as a string
    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Convert binary to decimal
    int decimal = binaryToDecimal(binary);

    // Print the decimal result
    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}

//prob19
#include <stdio.h>

int main() {
    int arr[10];
    int N, i, j;

    // Input 10 integers for the array
    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the number to remove (N)
    printf("Enter the number to remove: ");
    scanf("%d", &N);

    // Search for the first occurrence of N and remove it
    int found = 0;
    for (i = 0; i < 10; i++) {
        if (arr[i] == N) {
            found = 1;
            // Shift elements to the left
            for (j = i; j < 9; j++) {
                arr[j] = arr[j + 1];
            }
            // Set the last element to 0
            arr[9] = 0;
            break;
        }
    }

    // If N was found and removed, print the modified array
    if (found) {
        printf("Array after removing %d:\n", N);
        for (i = 0; i < 10; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Number %d not found in the array.\n", N);
    }

    return 0;
}

//prob20
#include <stdio.h>

int main() {
    int N;

    // Input the number of elements in the sequence
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];  // Create an array of size N

    // Input the numbers into the array
    printf("Enter the sequence of %d numbers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the numbers in reverse order
    printf("The sequence in reverse order is:\n");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

//prob21
#include <stdio.h>

int main() {
    int N, sum = 0;

    // Input the number of elements in the sequence
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];  // Create an array of size N

    // Input the numbers into the array
    printf("Enter the sequence of %d numbers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];  // Add each number to sum
    }

    // Output the sum of all numbers
    printf("The sum of all the numbers is: %d\n", sum);

    return 0;
}

//prob22
#include <stdio.h>

int main() {
    int N;

    // Input the number of elements in the sequence
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];  // Create an array of size N

    // Input the numbers into the array
    printf("Enter the sequence of %d numbers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Check if the sequence is sorted in ascending order
    int ascending = 1, descending = 1;
    for (int i = 0; i < N - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            ascending = 0;  // The sequence is not ascending
        }
        if (arr[i] < arr[i + 1]) {
            descending = 0;  // The sequence is not descending
        }
    }

    // Output the result
    if (ascending || descending) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

//prob23
#include <stdio.h>

void sortAscending(int arr[], int N) {
    int temp;
    // Sorting the array in ascending order using bubble sort
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortDescending(int arr[], int N) {
    int temp;
    // Sorting the array in descending order using bubble sort
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N, choice;

    // Input the number of elements in the sequence
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];  // Create an array of size N

    // Input the numbers into the array
    printf("Enter the sequence of %d numbers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask the user for the sorting order
    printf("Choose sorting order:\n1. Ascending\n2. Descending\n");
    scanf("%d", &choice);

    // Sort the array based on the user's choice
    if (choice == 1) {
        sortAscending(arr, N);
        printf("Sorted in Ascending order:\n");
    } else if (choice == 2) {
        sortDescending(arr, N);
        printf("Sorted in Descending order:\n");
    } else {
        printf("Invalid choice.\n");
        return 0;
    }

    // Output the sorted array
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

//prob24
#include <stdio.h>

int main() {
    int N, M;

    // Input the number of elements in the sequence
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];  // Create an array of size N

    // Input the numbers into the array
    printf("Enter the sequence of %d numbers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the M-th element to delete (1-based index)
    printf("Enter the position of the element to delete (1-based index): ");
    scanf("%d", &M);

    // Check if M is a valid index
    if (M < 1 || M > N) {
        printf("Invalid position. M should be between 1 and %d.\n", N);
        return 0;
    }

    // Shift elements to the left to delete the M-th element
    for (int i = M - 1; i < N - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Output the array after deletion
    printf("Array after deleting the %d-th element:\n", M);
    for (int i = 0; i < N - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

//prob25
#include <stdio.h>

int main() {
    int N, M, K, choice;

    // Input the number of elements in the sequence
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N + 1];  // Create an array of size N+1 (to allow for one insertion)

    // Input the numbers into the array
    printf("Enter the sequence of %d numbers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the number to insert
    printf("Enter the number K to insert: ");
    scanf("%d", &K);

    // Ask the user where to insert the number
    printf("Choose the position to insert K:\n1. Beginning\n2. End\n3. M-th position\n");
    scanf("%d", &choice);

    if (choice == 1) {
        // Insert at the beginning (shift elements to the right)
        for (int i = N; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = K;
        N++;  // Increment N since we added one element

    } else if (choice == 2) {
        // Insert at the end
        arr[N] = K;
        N++;  // Increment N since we added one element

    } else if (choice == 3) {
        // Insert at the M-th position (1-based index)
        printf("Enter the M-th position to insert K (1-based index): ");
        scanf("%d", &M);

        // Check if M is valid
        if (M < 1 || M > N + 1) {
            printf("Invalid position.\n");
            return 0;
        }

        // Shift elements to the right to make space for the new element
        for (int i = N; i >= M; i--) {
            arr[i] = arr[i - 1];
        }
        arr[M - 1] = K;  // Insert K at the M-th position (1-based)
        N++;  // Increment N since we added one element

    } else {
        printf("Invalid choice.\n");
        return 0;
    }

    // Output the array after insertion
    printf("Array after inserting the number K:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

//prob26
#include <stdio.h>
#include <ctype.h>  // For toupper() and tolower()

int main() {
    char str[100];  // Array to hold the input string
    int choice;

    // Input the word/string
    printf("Enter a word/string: ");
    fgets(str, sizeof(str), stdin);  // Read the entire line including spaces

    // Ask the user for the conversion choice
    printf("Choose the conversion:\n1. To Uppercase\n2. To Lowercase\n");
    scanf("%d", &choice);

    // Convert based on user's choice
    if (choice == 1) {
        // Convert each character to uppercase
        for (int i = 0; str[i] != '\0'; i++) {
            str[i] = toupper(str[i]);
        }
        printf("String in Uppercase: %s\n", str);
    } else if (choice == 2) {
        // Convert each character to lowercase
        for (int i = 0; str[i] != '\0'; i++) {
            str[i] = tolower(str[i]);
        }
        printf("String in Lowercase: %s\n", str);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

//prob27
#include <stdio.h>
#include <string.h>
#include <ctype.h>  // For tolower()

// Function to sort the string
void sortString(char* str) {
    int n = strlen(str);
    char temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str1[100], str2[100];

    // Input two strings
    printf("Enter the first word: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second word: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove the trailing newline character if present
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Convert both strings to lowercase to make comparison case-insensitive
    for (int i = 0; str1[i] != '\0'; i++) {
        str1[i] = tolower(str1[i]);
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        str2[i] = tolower(str2[i]);
    }

    // If the lengths of the strings are different, they cannot be anagrams
    if (strlen(str1) != strlen(str2)) {
        printf("The words are not anagrams.\n");
        return 0;
    }

    // Sort both strings
    sortString(str1);
    sortString(str2);

    // Compare the sorted strings
    if (strcmp(str1, str2) == 0) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }

    return 0;
}

//prob28
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    // Input two strings
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove the trailing newline character if present
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Check if str2 is a substring of str1
    if (strstr(str1, str2) != NULL) {
        printf("\"%s\" is a substring of \"%s\".\n", str2, str1);
    } else {
        printf("\"%s\" is not a substring of \"%s\".\n", str2, str1);
    }

    return 0;
}
