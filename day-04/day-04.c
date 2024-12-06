#include <stdio.h>

#define SIZE 140

int look_left(int i, unsigned char board[SIZE*SIZE]){
    if (board[i-1] == 'M' 
    && board[i-2] == 'A' 
    && board[i-3] == 'S'){
        return 1;
    }
    return 0;
}

int look_right(int i, unsigned char board[SIZE*SIZE]){
    if (board[i+1] == 'M' 
    && board[i+2] == 'A' 
    && board[i+3] == 'S'){
        return 1;
    }
    return 0;
}

int look_up(int i, unsigned char board[SIZE*SIZE]){
    if (board[i-SIZE] == 'M' 
    && board[i-SIZE*2] == 'A' 
    && board[i-SIZE*3] == 'S'){
        return 1;
    }
    return 0;
}

int look_down(int i, unsigned char board[SIZE*SIZE]){
    if (board[i+SIZE] == 'M' 
    && board[i+SIZE*2] == 'A' 
    && board[i+SIZE*3] == 'S'){
        return 1;
    }
    return 0;
}

int look_uleft(int i, unsigned char board[SIZE*SIZE]){
    if (board[i-SIZE-1] == 'M' 
    && board[i-SIZE*2-2] == 'A' 
    && board[i-SIZE*3-3] == 'S'){
        return 1;
    }
    return 0;
}

int look_dleft(int i, unsigned char board[SIZE*SIZE]){
    if (board[i+SIZE-1] == 'M' 
    && board[i+SIZE*2-2] == 'A' 
    && board[i+SIZE*3-3] == 'S'){
        return 1;
    }
    return 0;
}

int look_uright(int i, unsigned char board[SIZE*SIZE]){
    if (board[i-SIZE+1] == 'M' 
    && board[i-SIZE*2+2] == 'A' 
    && board[i-SIZE*3+3] == 'S'){
        return 1;
    }
    return 0;
}

int look_dright(int i, unsigned char board[SIZE*SIZE]){
    if (board[i+SIZE+1] == 'M' 
    && board[i+SIZE*2+2] == 'A' 
    && board[i+SIZE*3+3] == 'S'){
        return 1;
    }
    return 0;
}

int find_x(int i, unsigned char board[SIZE*SIZE]){
    if (i % SIZE > 0 && i % SIZE < SIZE - 1 && i >= SIZE && i < SIZE * SIZE - SIZE){
        if (board[i + SIZE + 1] + board[i - SIZE - 1] == 160
        && board[i - SIZE + 1] + board[i + SIZE - 1] == 160){
            return 1;
        }        
    }
    return 0;
}





int main(void) {

    FILE *fp = fopen("day-04/input.txt", "r");

    int ch;

    unsigned char board[SIZE * SIZE];

    size_t index = 0;

    while ((ch = fgetc(fp)) != EOF) {
        board[index] = ch;
        if (ch != 10) {
            index++;
        }
    }

    fclose(fp);

    int p1_count = 0;

    for(size_t i = 0; i < SIZE*SIZE; i++){
        if(board[i] == 'X') {
            if(i % SIZE >= 3) {
                p1_count += look_left(i, board);
                if(i >= SIZE * 3) {
                    p1_count += look_uleft(i, board);
                }
                if(i < SIZE * SIZE - 3 * SIZE) {
                    p1_count += look_dleft(i, board);
                }
            }
            if(i % SIZE <= SIZE - 4) {
                p1_count += look_right(i, board);
                if(i >= SIZE * 3) {
                    p1_count += look_uright(i, board);
                }
                if(i < SIZE * SIZE - 3 * SIZE) {
                    p1_count += look_dright(i, board);
                }
            }
            if(i >= SIZE * 3) {
                p1_count += look_up(i, board);
            }
            if(i < SIZE * SIZE - 3 * SIZE) {
                p1_count += look_down(i, board);
            }
        }

    }

    printf("%d\n", p1_count); // part 1 answer

    int p2_count = 0;

    for(size_t i = 0; i < SIZE*SIZE; i++){
        if(board[i] == 'A') {
            p2_count += find_x(i, board);
        }
    }

    printf("%d\n", p2_count); // part 2 answer

    return 0;
}