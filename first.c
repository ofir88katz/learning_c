#include <stdio.h>
#define BOARD_SIZE 3

void print_board(const char[BOARD_SIZE][BOARD_SIZE]);
int check_input(const int input);
//char check_winning(const char board[BOARD_SIZE][BOARD_SIZE]);
char check_winning_rows(const char board[BOARD_SIZE][BOARD_SIZE]);
void initial_board(char board[BOARD_SIZE][BOARD_SIZE]);

void initial_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (size_t i = 0; i < sizeof(*board); i++)
    {
        for (size_t j = 0; j < sizeof(board[i]); j++)
        {
            board[i][j] = '-';
        }
    }
}

int check_input(const int input) {
    /// <summary>
    /// 
    /// </summary>
    /// <param name="input"></param>
    /// <returns></returns>
    int if_true = 0 < input && input < 10;
    return if_true;
}

char check_winning_rows(const char board[BOARD_SIZE][BOARD_SIZE]) {
    int o_nums = 0;
    int x_nums = 0;

}


void print_board(const char board[BOARD_SIZE][BOARD_SIZE]) {
    /// <summary>
    /// print the board pretty
    /// </summary>
    /// <param name="board">the board of the game </param>
    char* nums = "";
    for (size_t i = 0; i < BOARD_SIZE; i++)
    {
        
    }
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
//    char board[BOARD_SIZE][BOARD_SIZE] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    char board[BOARD_SIZE][BOARD_SIZE];
    initial_board(board);
    print_board(board);

    //char dest[20] = "Hello";
    //char src[20] = "World";
    //strncat(dest, src, 3);
    //printf("%s\n", dest);
    //strncat(dest, src, 20);
    //printf("%s\n", dest);
    //
    //
//  //  printf("hello word\n");
    //int testInteger;
    //int* xx;
    //xx = &testInteger;
    //printf("Enter an integer: ");
    //scanf_s("%d", &testInteger);
    //printf("Number = %d\n", testInteger);
    //printf("xx = %d\n", *xx);
    //testInteger = 23;
    //printf("Number = %d\n", testInteger);
    //printf("xx = %d\n", *xx);
    return 0;
}