#include <stdio.h>
#include <string.h>

// Define possible states of the FSM
typedef enum {
    STATE_IDLE,
    STATE_WAIT_FOR_CARD,
    STATE_CARD_VALIDATED,
    STATE_ENTRY_GRANTED,
    STATE_ENTRY_DENIED
} State;

int main() {
    State currentState = STATE_IDLE;
    char input[20];

    printf("Subway Entry System Simulation\n");
    printf("--------------------------------\n");

    while (1) {
        printf("\nCurrent State: ");
        switch (currentState) {
            case STATE_IDLE: printf("IDLE\n"); break;
            case STATE_WAIT_FOR_CARD: printf("WAIT_FOR_CARD\n"); break;
            case STATE_CARD_VALIDATED: printf("CARD_VALIDATED\n"); break;
            case STATE_ENTRY_GRANTED: printf("ENTRY_GRANTED\n"); break;
            case STATE_ENTRY_DENIED: printf("ENTRY_DENIED\n"); break;
        }

        printf("Enter input (scan_card / valid_card / invalid_card / enter_gate / timeout / exit): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            printf("Exiting simulation.\n");
            break;
        }

        switch (currentState) {
            case STATE_IDLE:
                if (strcmp(input, "scan_card") == 0) {
                    currentState = STATE_WAIT_FOR_CARD;
                    printf("Card scanned. Validating...\n");
                } else {
                    printf("Invalid action. Waiting for card scan.\n");
                }
                break;

            case STATE_WAIT_FOR_CARD:
                if (strcmp(input, "valid_card") == 0) {
                    currentState = STATE_ENTRY_GRANTED;
                    printf("Card is valid. Gate opened. Please enter.\n");
                } else if (strcmp(input, "invalid_card") == 0) {
                    currentState = STATE_ENTRY_DENIED;
                    printf("Invalid card. Entry denied.\n");
                } else {
                    printf("Still waiting for card validation.\n");
                }
                break;

            case STATE_ENTRY_GRANTED:
                if (strcmp(input, "enter_gate") == 0) {
                    currentState = STATE_IDLE;
                    printf("User entered. Gate closing...\n");
                } else if (strcmp(input, "timeout") == 0) {
                    currentState = STATE_ENTRY_DENIED;
                    printf("Timeout! Entry denied. Gate closing.\n");
                } else {
                    printf("Waiting for user to enter or timeout.\n");
                }
                break;

            case STATE_ENTRY_DENIED:
                printf("Returning to idle state.\n");
                currentState = STATE_IDLE;
                break;

            case STATE_CARD_VALIDATED:
                // (This state is unused in this version; could be used if separating validation from granting)
                break;
        }
    }

    return 0;
}
