//David Ranney
//April 22nd, 2025
//Final Project

#include <stdio.h>
#define READ_FILE "mystery.txt"
#define WRITE_FILE "guesses.txt"
#define READUSER_FILE "guesses.txt"

void readAnswer(char answer[]);
int checkLetter(char guessChar, char answer[], int pos);
void guessFeedback(char guess[], char answer[]);
void printGuesses(char guesses[][100], int count);
int isCorrect(char guess[], char answer[]);
	
int main(){
	char answer[100];
	char guesses[6][100];
	int guessNumber = 0;
	readAnswer(answer);
	
	while (guessNumber < 6){
	printf("\nGUESS %d! Enter your guess: ", guessNumber + 1);
	scanf("%s", &guesses[guessNumber]);
	
	guessFeedback(guesses[guessNumber], answer);

        if (isCorrect(guesses[guessNumber], answer)) {
            printf("Congratulations! You guessed the word in %d tries!\n", guessNumber + 1);
            break;
        }
        printGuesses(guesses, guessNumber + 1);
        guessNumber++;
    }

    if (guessNumber == 6 && !isCorrect(guesses[guessNumber - 1], answer)) {
        printf("Out of guesses. The word was: %s\n", answer);
    }

    return 0;
   }

void readAnswer(char answer[]){
	FILE* readFileP = fopen(READ_FILE, "r");
	fscanf(readFileP, "%s", answer);
	fclose(readFileP);
}

int checkLetter(char guessChar, char answer[], int pos){
	if(guessChar == answer[pos]) return 1;
	for (int i = 0; answer[i] != '\0'; i++){
		if (answer[i] == guessChar) return 2;
	}
	return 0;
}

void guessFeedback(char guess[], char answer[]){
	char underline[6];
	for(int i = 0; i < 5; i++){
	int result = checkLetter(guess[i], answer, i);
	if (result == 1) {
		char upper = guess[i];
		char lower = upper;
		if (lower >= 'a' && lower <= 'z') {
    			upper = lower - 32;
		}
		printf("%c", upper);
		underline[i] = ' ';
	}
	else if (result == 2) {
		printf("%c", guess[i]);
		underline[i] = '^';
	}
	else {
		printf("%c", guess[i]);
		underline[i] = ' ';
	}
	
	}
	underline[5] = '\0';
	printf("\n%s\n", underline);
}

void printGuesses(char guess[][100], int count){
	for (int i = 0; i < count; i++){
		printf("%s\n", guess[i]);
	}
}

int isCorrect(char guess[], char answer[]){
	for (int i = 0; i < 5; i++){
		if(guess[i] != answer[i]){
		return 0;
		}
	}
	return 1; 
}








	
