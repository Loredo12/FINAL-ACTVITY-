#include <stdio.h>
#include <string.h>

int main() {
    char username[20], password[20];
    char correctUser[] = "admin";
    char correctPass[] = "admin123";
    int attempts = 3;
    char choice;
	char confirm;
    int rounds;
	int  player;
	int computer;
	int pScore;
	int cScore;




    do {
        printf("\n------ LOGIN --------------\n");
        printf("|                         |\n");
        printf("|     Username: ");
        scanf("%s", username);
        printf("|                         |\n");
        printf("|     Password: ");
        scanf("%s", password);
        printf("---------------------------\n");

        if (strcmp(username, correctUser) == 0 && strcmp(password, correctPass) == 0) {
            printf("\nLogin successful! Welcome, %s.\n", username);
            break;
        } else {
            attempts--;
            printf("Invalid login! Attempts left: %d\n", attempts);
        }

        if (attempts == 0) {
            printf("Too many failed attempts. Exiting program.\n");
            return 0;
        }
    } while (attempts > 0);



    do {
        printf("\n--- ROCK PAPER SCISSOR GAME----\n");
        printf("|          (S)tart              |\n");
        printf("|          (A)bout              |\n");
        printf("|          (E)xit               |\n");
        printf("---------------------------------\n");
        printf("Enter choice: ");
        scanf(" %c", &choice); 

        if (choice == 's' || choice == 'S') {
        	
        	
        	
            pScore = 0;
            cScore = 0;

            printf("\nEnter number of rounds: ");
            scanf("%d", &rounds);

            for (int i = 1; i <= rounds; i++) {
                printf("\nRound %d\n", i);
                printf("Choose: [1]Rock [2]Paper [3]Scissors: ");
                scanf("%d", &player);

                if (player < 1 || player > 3) {
                    printf("Invalid choice! Try again.\n");
                    i--;
                    continue;
                }





                const char *moves[] = {"Rock", "Paper", "Scissors"};
                printf("Computer chose %s\n", moves[computer - 1]);

                if (player == computer) {
                    printf("Draw!\n");
                } else if ((player == 1 && computer == 3) ||
                           (player == 2 && computer == 1) ||
                           (player == 3 && computer == 2)) {
                    printf("You win this round!\n");
                    pScore++;
                } else {
                    printf("Computer wins this round!\n");
                    cScore++;
                }
            }






            printf("\nFinal Scores:\n");
            printf("Player: %d\n", pScore);
            printf("Computer: %d\n", cScore);
            if (pScore > cScore) {
                printf("Congratulations! You win the game.\n");
            } else if (cScore > pScore) {
                printf("Sorry! Computer wins the game.\n");
            } else {
                printf("It's a tie game!\n");
            }

        } else if (choice == 'a' || choice == 'A') {
            printf("\nINSTRUCTIONS:\n");
            printf("- Rock beats Scissors\n- Scissors beats Paper\n- Paper beats Rock\n");
            printf("Play against the computer and see who wins more rounds.\n");

        } else if (choice == 'e' || choice == 'E') {
            printf("Do you want to exit? (Y/N): ");
            scanf(" %c", &confirm);
            if (confirm == 'y' || confirm == 'Y') {
                printf("Exiting program... Goodbye!\n");
                break;
            }
        }

    } while (1);

    return 0;
}

