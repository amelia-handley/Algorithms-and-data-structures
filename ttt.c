#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define MAX 8
// Set the player function to crosses
char player = 'X';

// // A function to show the current status of the board
void showBoard(char* board)
{
	printf("\n");
	printf("Game Board:");
	printf("\n\n");
	printf(" %c | %c | %c \n", board[0],board[1],board[2]);
	printf("----------- \n");
	printf(" %c | %c | %c \n", board[3],board[4],board[5]);
	printf("----------- \n");
	printf(" %c | %c | %c \n", board[6],board[7],board[8]);
	printf("\n");
	
	return;
}

// // Function to display the rules
void displayRules()
{
	printf("\n");
	printf("\t\t\t  ******INSTRUCTIONS******\n");
	printf("\n");
	printf("\t\t\t\t 1 | 2 | 3 \n");
	printf("\t\t\t\t----------- \n");
	printf("\t\t\t\t 4 | 5 | 6 \n");
	printf("\t\t\t\t----------- \n");
	printf("\t\t\t\t 7 | 8 | 9 \n");
	printf("\n");
	printf("\t 1. The first player to move will be 'X' and the second will be 'O' \n");
	printf("\t 2. Players will alternate turns until one player gets 3 in a row \n\t or the match ends in a draw.\n");
	printf("\t 3. To play, enter the number in the grid above in the position you\n\t would like to enter. \n");
	printf("\n\n");
	return;
}

// Game Board Functions

// initialisation
void initialiseBoard(char* board)
{
	int idx;
	for(idx=0; idx <= MAX; idx++)
	{
		// Sets each element in the array to a blank space
		board[idx] = ' ';
	}
}

// Set the first player to X and the second player to O
void playerMove()
{
	// If previous player is X, switch to O
	if (player== 'X')
	{
		player = 'O';
	}
	// Else if player is O, switch to X
	else
	{
		player = 'X';
	}
}

// Stores players move in array
void getMove(char* board)
{
	int a;
	printf("Player %c Please enter a number: ", player);
	scanf("%d", &a);
	bool checkMove = true;

	// alpha characters
	
	// Checks each element in the array and if theres a space
	if(a==1 && board[0] == ' ')
	{
		board[0] = player;
		checkMove = true;
	}
	else if(a==2 && board[1] == ' ')
	{
		board[1] = player;
		checkMove = true;
	}
	else if(a==3 && board[2] == ' ')
	{
		board[2] = player;
		checkMove = true;
	}
	else if(a==4 && board[3] == ' ')
	{
		board[3] = player;
		checkMove = true;
	}
	else if(a==5 && board[4] == ' ')
	{
		board[4] = player;
		checkMove = true;
	}
	else if(a==6 && board[5] == ' ')
	{
		board[5] = player;
		checkMove = true;
	}
	else if(a==7 && board[6] == ' ')
	{
		board[6] = player;
		checkMove = true;
	}
	else if(a==8 && board[7] == ' ')
	{
		board[7] = player;
		checkMove = true;
	}
	else if(a==9 && board[8] == ' ')
	{
		board[8] = player;
		checkMove = true;
	}
	else if(a<1 || a>9)
	{
		printf("The numbers entered must be between 1 and 9 \n");
		getMove(board);
	}
	else if(isalpha(a) == 0)
	{
		printf("You must enter a number between 1 and 9\n");
		getMove(board);
	}
	else 
	{
		// If an element in the array has already been used, ask the player to player another square
		printf("Square has already been played. Please try again. \n");
		getMove(board);
	}
}

// How players can win the game
char winGame(char* board)
{	
	bool winner = true;
	// Player 'X'
	// Check the first row for a winner
	if(board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
	{
		winner = true;
		return player;
	}
	// Check the second row for a winner
	if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
	{
		winner = true;
		return player;
	}
	// Check the third row for a winner
	if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
	{
		winner = true;
		return player;
	}
	
	//Check the first column for a winner
	if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
	{
		winner = true;
		return player;
	}
	//Check the second column for a winner
	if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
	{
		winner = true;
		return player;
	}
	//Check the third column for a winner
	if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
	{
		winner = true;
		return player;
	}
	
	//Check diagonals
	if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
	{
		winner = true;
		return player;
	}
	if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
	{
		winner = true;
		return player;
	}
	
	//Player 'O'
	// Check the first row for a winner
	if(board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
	{
		winner = true;
		return player;
	}
	// Check the second row for a winner
	if(board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
	{
		winner = true;
		return player;
	}
	// Check the third row for a winner
	if(board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
		return player;
	
	//Check the first column for a winner
	if(board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
	{
		winner = true;
		return player;
	}
	//Check the second column for a winner
	if(board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
	{
		winner = true;
		return player;
	}
	//Check the third column for a winner
	if(board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
	{
		winner = true;
		return player;
	}
	
	//Check diagonals
	if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
	{
		winner = true;
		return player;
	}
	if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
	{
		winner = true;
		return player;
	}
	return('\n');
}

// Stack Functions

struct stack
{
	char array[MAX][MAX]; // [rows][columns]
	int top;
};

// initialise stack
void initialiseStack(struct stack *s)
{
	int row;
	int column;
	
	for(row=0; row <= MAX; row++)
	{
		for(column=0; column <= MAX; column++)
		{
			// Sets each element in the array to a blank space
			s->array[row][column]= ' ';	
		}
	}
	s->top = -1;
}

/*
int isEmpty(struct stack *s)
{
	return !s;
}
*/

// Push to a stack
void push(struct stack *s, char* board)
{
	int row;
	int column;
	// Add to the top of the stack
	s->top++;
	// loop through array
	for(row=0; row <= MAX; row++)
	{
		for(column=0; column <= MAX; column++)
		{
			s->array[s->top][row] = board[row];
		}

	}	
}
/*
//display function for stack
void showStack(struct stack *s)
{
	int row;
	//showBoard
	for(row=0; row<=MAX; row++)
	{
		showBoard(s->array[row]);
	}
}
*/

// pop the stack
void pop(struct stack *s, char* board)
{
	int row;
	// decrement top of the stack to go back
	s->top--;
	for(row=0; row<=MAX; row++)
	{
		board[row] = s->array[s->top][row];
	}
	showBoard(board);
	
}

int main(void)
{
	// Create board array
	char board[8];
	// Create stack
	struct stack s;
	// Initialise stack
	initialiseStack(&s);
	// Display the rules of the game
	displayRules();
	// Initialise board
	initialiseBoard(board);
	// Counter for the moves
	int count;
	count = 0;
	// While the game is still not won
	while(winGame(board)!= true)
	{
		
		// Get players move
		getMove(board);
		// Show the current board
		showBoard(board);
		// If X has three in a row, output they have won
		if(winGame(board) == 'X')
		{
			printf("Player X wins!\n ... Exiting Game ...\n");
			break;
		}
		// If X has three in a row, output they have won
		if(winGame(board) == 'O') 
		{
			printf("Player O wins!\n ... Exiting Game ...\n");
			break;
		}
		// when the counter =8, match is a draw
		if(count == 8)
		{
			printf("Match is a draw.\n ... Exiting Game ...\n");
			break;
		}
		// Switch the player
		playerMove(board);
		// Add each board to the stack
		push(&s, board);
		count++;
	}
	
	// Pop each board
	printf("*****Replay of Game*****\n");
	pop(&s, board);
	pop(&s, board);
	pop(&s, board);
	pop(&s, board);
	pop(&s, board);
	pop(&s, board);
	pop(&s, board);
	pop(&s, board);
	pop(&s, board);
	
	return 0;
}
