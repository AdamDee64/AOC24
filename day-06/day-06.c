#include <time.h>
#include <stdio.h>

#define SIZE 130

#define UP -SIZE
#define RIGHT 1
#define DOWN SIZE
#define LEFT -1

void change_direction(int *dir){
    switch(*dir){
        case UP:
        *dir = RIGHT;
        break;
        case RIGHT:
        *dir = DOWN;
        break;
        case DOWN:
        *dir = LEFT;
        break;
        case LEFT:
        *dir = UP;
        break;
    }
}

int main(void){

    clock_t start, end;
    double total_time;

    start = clock(); // start timer

    FILE *fp = fopen("day-06/input.txt", "r");

    int ch;

    char board[SIZE * SIZE];
    int index = 0;

    while ((ch = fgetc(fp)) != EOF) {
        board[index] = ch;
        if (ch != 10) index++;
    }
    fclose(fp);    

    int start_point = 0;
    for(size_t i = 0; i < SIZE * SIZE; i++){
        if(board[i] != '#' && board[i] != '.') {
            start_point = i;
            break;
        }
    }

    index = start_point;
    int dir = UP;

    while(1){
        board[index] = 'X';
        if (index % SIZE == 0 && dir == LEFT) break;
        if (index % SIZE == SIZE - 1 && dir == RIGHT) break;
        if (index + dir >= SIZE * SIZE || index + dir < 0) break;
        if(board[index + dir] == '#') change_direction(&dir);
        else index += dir;
    }

    int count = 0;

    for(size_t i = 0; i < SIZE * SIZE; i++) count += board[i] == 'X' ? 1 : 0;
    
    end = clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", total_time);
    printf("%d\n", count); // part 1 answer



    return 0;
}