#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void board1(void);
void play_game(void);
void comp_move(void);
void player_move(void);
int choice(void);
int find_win(char);
int middle(void);
int corner(void);
int side(void);
int symbol_won(char);
int square_valid(int);
void board2();
int checkwinner();

char board[3][3];
char computer, user;
char matrix[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void main(void)
{ system("color 74");// change color of foreground and background
    int a;
    printf("\t\t\t\t *WELCOME TO TIC TAC TOE GAME* \n \t\t enter 1 to play against computer or enter 2 to play against a player: ");
    scanf("%d",&a);
    if (a==1)
	{int row,col;
		for (row = 0; row < 3; row++) // filling of board with blank spaces

		    for (col = 0; col < 3; col++)

			board[row][col] = ' ';

	     		if (choice())
			{
			  	computer = 'O';
				user = 'X';
			}
	      		else
			{
		  		computer = 'X';
		  		user = 'O';
			}
	      		play_game();


	}
else if( a==2)
{



 int player = 1, i, choice;

    char m;
    do
    {
        board2();
        player = (player % 2) ? 1 : 2; //alternating player moves with ternary operator

        printf("Player %d, enter a square number:  ", player);
        scanf("%d", &choice);

        m = (player == 1) ? 'X' : 'O';

        if (choice == 1 &&  matrix[1] == '1')
            matrix[1] = m;

        else if (choice == 2 && matrix[2] == '2')
            matrix[2] = m;

        else if (choice == 3 && matrix[3] == '3')
            matrix[3] = m;

        else if (choice == 4 && matrix[4] == '4')
            matrix[4] = m;

        else if (choice == 5 && matrix[5] == '5')
            matrix[5] = m;

        else if (choice == 6 && matrix[6] == '6')
            matrix[6] = m;

        else if (choice == 7 && matrix[7] == '7')
            matrix[7] = m;

        else if (choice == 8 && matrix[8] == '8')
            matrix[8] = m;

        else if (choice == 9 && matrix[9] == '9')
            matrix[9] = m;

        else
        {
            printf("Invalid move try again ");

            player--;
            getch();
        }
        i = checkwinner();

        player++;
    }while (i ==  - 1);

    board2();

    if (i == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");

    getch();

}
else printf("wrong choice");
}
void play_game(void)
{
  	int i;
  	for (i = 1; i <= 9; i++)
    	{ board1();
		if (i % 2 == 1)
		{
	  		if (computer == 'X')
	    			comp_move();
	  		else
	    			player_move();
		}
      		else
		{
	  		if (computer == 'O')
				comp_move();
	  		else
				player_move();

		}

      		if (symbol_won(computer))
		{board1();
			printf("\n\aComputer Win...better luck next time:( \n\n");
			return;
      		}
      		else if (symbol_won(user))
		{board1();
			printf("\n\aCongratulation,You  win!\n\n");
			return;
      		}
    	}
    	board1();
  	printf("\n\aThe game is a draw.\n\n");
  	return;
}

void board1(void)
{

   	system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Computer (%c)  -  Player  (%c)\n\n\n",computer,user);


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);

    printf("     |     |     \n\n");


}

int choice(void)
{
	char response;
  	printf("Do you want to go first? (y/n) ");
  	do
    	{
		response = getchar();
    	} while ((response != 'y') && (response != 'Y') && (response != 'n') && (response != 'N'));

	if ((response == 'y') || (response == 'Y'))
    		return 1;
  	else
  		return 0;
}

int middle(void)
{
  	if (board[1][1] == ' ')
    		return 5;
  	else
    		return 0;
}

int corner(void)
{
  	if (board[0][0] == ' ')
    		return 1;
  	if (board[0][2] == ' ')
    		return 3;
  	if (board[2][0] == ' ')
    		return 7;
  	if (board[2][2] == ' ')
    		return 9;
  	return 0;
}

int side(void)
{
  	if (board[0][1] == ' ')
    		return 2;
  	if (board[1][0] == ' ')
    		return 4;
  	if (board[1][2] == ' ')
    		return 6;
  	if (board[2][1] == ' ')
    		return 8;
  	return 0;
}

int find_win(char symbol)
{
  	int square, row, col;
  	int result=0 ;
	for (square = 1; square <= 9; square++)
    	{
      		row = (square - 1) / 3;
      		col = (square - 1) % 3;
      		if (board[row][col] == ' ')
		{
	  		board[row][col] = symbol;
			if (symbol_won(symbol))
	    			result = square;
	  			board[row][col] = ' ';
		}
    	}
	return result;
}

int symbol_won(char symbol)
{
  	int row, col;
	for (row = 0; row < 3; row++)
    	{
      		if ((board[row][0] == symbol) && (board[row][1] == symbol) && (board[row][2] == symbol))
			return 1;
    	}
  	for (col = 0; col < 3; col++)
    	{
      		if ((board[0][col] == symbol) && (board[1][col] == symbol) && (board[2][col] == symbol))
			return 1;
    	}
  	if ((board[0][0] == symbol) && (board[1][1] == symbol) && (board[2][2] == symbol))
		return 1;
	if ((board[0][1] == symbol) && (board[1][1] == symbol) && (board[2][1] == symbol))
    		return 1;
  	if ((board[0][2] == symbol) && (board[1][1] == symbol) && (board[2][0] == symbol))
    		return 1;
	if ((board[1][0] == symbol) && (board[1][1] == symbol) && (board[1][2] == symbol))
    		return 1;
  	return 0;
}

void comp_move(void)
{
  	int square;
  	int row, col;
  	square = find_win(computer);
  	if (!square)
    		square = find_win(user);
  	if (!square)
		square = corner();
  	if (!square)
		square = middle();
  	if (!square)
    		square = side();

	row = (square - 1) / 3;
  	col = (square - 1) % 3;
  	board[row][col] = computer;
	return;
}

void player_move(void)
{
  	int square;
  	int row, col;
  	do
    	{
      		printf("Enter a square (numbered 1-9 row-wise): ");
      		scanf("%d", &square);
    	} while (!square_valid(square));
  	row = (square - 1) / 3;
  	col = (square - 1) % 3;
  	board[row][col] = user;
  	return;
}

int square_valid(int square)// checking for valid square number inputted by user
{
  	int row, col;
	row = (square - 1) / 3;
  	col = (square - 1) % 3;
	if ((square >= 1) && (square <= 9))
	{
      		if (board[row][col] == ' ')
			return 1;
    	}
	return 0;
}

int checkwinner()
{
if (matrix[1] == matrix[2] && matrix[2] == matrix[3])
        return 1;

    else if (matrix[4] == matrix[5] && matrix[5] == matrix[6])
        return 1;

    else if (matrix[7] == matrix[8] && matrix[8] == matrix[9])
        return 1;

    else if (matrix[1] == matrix[4] && matrix[4] == matrix[7])
        return 1;

    else if (matrix[2] == matrix[5] && matrix[5] == matrix[8])
        return 1;

    else if (matrix[3] == matrix[6] && matrix[6] == matrix[9])
        return 1;

    else if (matrix[1] == matrix[5] && matrix[5] == matrix[9])
        return 1;

    else if (matrix[3] == matrix[5] && matrix[5] == matrix[7])
        return 1;

    else if (matrix[1] != '1' && matrix[2] != '2' && matrix[3] != '3' &&
        matrix[4] != '4' && matrix[5] != '5' && matrix[6] != '6' && matrix[7]
        != '7' && matrix[8] != '8' && matrix[9] != '9')

        return 0;
    else
        return  - 1;
}


void board2()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", matrix[1], matrix[2], matrix[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", matrix[4], matrix[5], matrix[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", matrix[7], matrix[8], matrix[9]);

    printf("     |     |     \n\n");
}
