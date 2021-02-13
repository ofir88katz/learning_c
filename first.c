#include <stdio.h>
#include <errno.h>
#define BOARD_SIZE 3
#define WINNING_SIZE 3
#define X_OR_O(turn_num) ((turn_num)%2==0 ? 'X' : 'O')

void print_board(const char[BOARD_SIZE][BOARD_SIZE]);
void player_turn(char board[BOARD_SIZE][BOARD_SIZE], char turn);
int  check_input(const int input, int scanf_s_output);
char check_winning(const char board[BOARD_SIZE][BOARD_SIZE]);
char check_winning_rows(const char board[BOARD_SIZE][BOARD_SIZE]);
char check_winning_columns(const char board[BOARD_SIZE][BOARD_SIZE]);
char check_winning_digonals(const char board[BOARD_SIZE][BOARD_SIZE]);
void initial_board(char board[BOARD_SIZE][BOARD_SIZE]);


void initial_board(char board[BOARD_SIZE][BOARD_SIZE]) 
{
    /// <summary>
    /// init the board to all -.
    /// </summary>
    /// <param name="board"> the game board </param
    for (size_t rows = 0; rows < sizeof(*board); rows++)
        for (size_t column = 0; column < sizeof(board[rows]); column++)
            board[rows][column] = '-';
}

int check_input(int input, int scanf_s_output)
{
    /// <summary>
    /// 
    /// </summary>
    /// <param name="input"></param>
    /// <returns></returns>
    while ((!(0 <= input && input < BOARD_SIZE)) || scanf_s_output != 1) {
        printf(stdin);
        printf("\n");
        fflush(stdin);
        printf("Please enter a number bitween 0 to %d - ", (BOARD_SIZE-1));
        scanf_s_output = scanf_s("%d", &input);
    }
    return input;
}

char check_winning_rows(const char board[BOARD_SIZE][BOARD_SIZE]) 
{
    /// <summary>
    /// check if there is a win in all the rows
    /// </summary>
    /// <param name="board"> the board game </param>
    /// <returns> return 'X' if X won, return 'O' if O won, return '-' if no one won</returns>
    int o_nums = 0;
    int x_nums = 0;
    for (size_t rows = 0; rows < sizeof(*board); rows++)
    {
        o_nums = 0;
        x_nums = 0;
        for (size_t colums = 0; colums < sizeof(board[rows]); colums++)
        {
            if (board[rows][colums] == 'X')
                x_nums += 1;
            else if (board[rows][colums] == 'O')
                o_nums += 1;
        }
        if (x_nums == WINNING_SIZE)
            return 'X';           
        else if (o_nums == WINNING_SIZE)
            return 'O';
    }
    return '-';
}


char check_winning_columns(const char board[BOARD_SIZE][BOARD_SIZE]) 
{
    /// <summary>
    /// check if there is a win in all the columns
    /// </summary>
    /// <param name="board"> the board game </param>
    /// <returns> return 'X' if X won, return 'O' if O won, return '-' if no one won</returns>
    int o_nums = 0;
    int x_nums = 0;
    for (size_t i = 0; i < sizeof(*board); i++)
    {
        o_nums = 0;
        x_nums = 0;
        for (size_t j = 0; j < sizeof(board[i]); j++)
        {
            if (board[j][i] == 'X')
                x_nums += 1;
            else if (board[j][i] == 'O')
                o_nums += 1;
        }
        if (x_nums == WINNING_SIZE)
            return 'X';
        else if (o_nums == WINNING_SIZE)
            return 'O';
    }
    return '-';
}


char check_winning_digonals(const char board[BOARD_SIZE][BOARD_SIZE])
{
    /// <summary>
    /// check if there is a win in all the digonals
    /// </summary>
    /// <param name="board"> the board game </param>
    /// <returns> return 'X' if X won, return 'O' if O won, return '-' if no one won </returns>
    int o_nums = 0;
    int x_nums = 0;
    // Check digonal top right to butt left.
    for (size_t i = 0; i < sizeof(*board); i++)
    {
        if (board[i][i] == 'X')
            x_nums += 1;
        else if (board[i][i] == 'O')
            o_nums += 1;
    }
    if (x_nums == WINNING_SIZE)
        return 'X';
    else if (o_nums == WINNING_SIZE)
        return 'O';

    o_nums = 0;
    x_nums = 0;
    // Check digonal top left to butt right.
    for (size_t i = 0; i < sizeof(*board); i++)
    {
        if (board[i][sizeof(*board) - (i+1)] == 'X')
            x_nums += 1;
        else if (board[i][sizeof(*board) - (i + 1)] == 'O')
            o_nums += 1;
    }
    if (x_nums == WINNING_SIZE)
        return 'X';
    else if (o_nums == WINNING_SIZE)
        return 'O';
    return '-';
}

/* <summary>
*   ask the player for there turn, and check there intput
*   </summary>
*   <param name="board">the board of the game</param>
*   <param name="turn">wich player is playing right now</param>
*/
void player_turn(char board[BOARD_SIZE][BOARD_SIZE], char turn) {
    
    
    int row = 0;
    int column = 0;
    int scanf_s_output;
    printf("\nChoose row - ");
    scanf_s_output = scanf_s("%d", &row);
    row = check_input(row, scanf_s_output);
    printf("Choose column - ");
    scanf_s_output = scanf_s("%d", &column);
    column = check_input(column, scanf_s_output);

    while (!(board[row][column] == '-'))
    {
        fflush(stdin);
        fflush(stdin);
        printf("\n111111111111111111111111111 - [%d,,,,%d ,,,,%d]\n",row, column, scanf_s_output);
        printf("ernno = %d\n", errno);
        printf("Please choose an empty place!!!!\n\n");
        printf("Choose row - ");
        scanf_s_output = scanf_s("%d", &row);
        printf("\noutput of scanf_s -------- %d\n", scanf_s_output);
        row = check_input(row, scanf_s_output);
        printf("Choose column - ");
        scanf_s_output = scanf_s("%d", &column);
        printf("\noutput of scanf_s -------- %d\n", scanf_s_output);
        column = check_input(column, scanf_s_output);
    }

    board[row][column] = turn;

}



char check_winning(const char board[BOARD_SIZE][BOARD_SIZE]) {
    /// <summary>
    /// check if there is a win in the game
    /// </summary>
    /// <param name="board"> the board of the game </param>
    /// <returns></returns>
    char win_rows = check_winning_rows(board);
    char win_columns = check_winning_columns(board);
    char win_digonals = check_winning_digonals(board);
//    printf("Check winnings: rows - %c, colums - %c, digonals - %c\n", win_rows, win_columns, win_digonals);
    if (win_rows == 'X' || win_columns == 'X' || win_digonals == 'X')
    {
        printf("X is winning");
        return 'X';
    }
        
    else if (win_rows == 'O' || win_columns == 'O' || win_digonals == 'O')
        return 'O';
    else
        return '-';
}

void print_board(const char board[BOARD_SIZE][BOARD_SIZE]) {
    /// <summary>
    /// print the board pretty
    /// </summary>
    /// <param name="board">the board of the game </param>
    printf("  ");
    for (size_t i = 0; i < BOARD_SIZE; i++)
        printf("  %d  ", i);
    printf("\n  ---------------\n");

    for (int i = 0; i < sizeof(*board); i++) 
    {
        printf("%d ", i);
        for (int j = 0; j < sizeof(board[i]); j++) 
            printf("| %c |",board[i][j]);
        printf("\n  ---------------\n");
    }
}

int main(){

    char board[BOARD_SIZE][BOARD_SIZE];
    initial_board(board);
    print_board(board);
    for (size_t i = 0; i < ((BOARD_SIZE * BOARD_SIZE)); i++)
    {
        char player = X_OR_O(i);
        printf("Player turn - %c\n", player);
        player_turn(board, player);
        print_board(board);
        printf("\n\n\n");
        
//        printf("%d ---------- %d\n", ((BOARD_SIZE * BOARD_SIZE) - 1), i);
        if (i >= (BOARD_SIZE * 2) - 3)
        {
            char player_won = check_winning(board);
            if (player_won != '-') {
                printf("%c wonnnnnn !!!!!!!!", player_won);
                break;
            }
        }
        else if (i == ((BOARD_SIZE * BOARD_SIZE) - 1))
            printf("It is a tie!!");
    }

    return 0;
}