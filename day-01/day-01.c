#include <stdio.h>

#define LIST_SIZE 1000

int convert_to_int(char str[5]){
    int out = 0;
    out += 10000 * (str[0] - 48);
    out += 1000 * (str[1] - 48);
    out += 100 * (str[2] - 48);
    out += 10 * (str[3] - 48);
    out += str[4] - 48;

    return out;
}

void sort_list(int list[LIST_SIZE]){
    size_t end = LIST_SIZE - 1;
    
    while(end > 0){
        int swap;
        for(size_t i = 0; i < end; i++){
            if (list[i] > list[i + 1]){
                swap = list[i];
                list[i] = list[i + 1];
                list[i + 1] = swap;
            }
        }
        end -= 1;
    }
}

int add_differences(int list1[LIST_SIZE], int list2[LIST_SIZE]){
    int out = 0;

    for(int i = 0; i < LIST_SIZE; i++){
        if (list1[i] > list2[i]) {
            out += list1[i] - list2[i];
        } else {
            out += list2[i] - list1[i];
        }
    }

    return out;
}

int find_score(int list1[LIST_SIZE], int list2[LIST_SIZE]){
    int out = 0;

    for(size_t i = 0; i < LIST_SIZE; i++){
        int match = 0;
        for(size_t j = 0; j < LIST_SIZE; j++){
            if(list1[i] == list2[j]) {
                match++;
            }
        }
        out += list1[i] * match;
    }

    return out;
}


int main(void) {

    int list1[LIST_SIZE] = {0};
    int list2[LIST_SIZE] = {0};

    FILE *fp = fopen("day-01/input.txt", "r");
    
    int ch;

    char num[5];
    size_t i = 0;

    char swap_list = 0;
    size_t add_list = 0;

    int value;
    
    while ((ch = fgetc(fp)) != EOF) {
        if(ch >= 48 && ch <= 57){
            num[i] = ch;
            i += 1;
            if (i == 5) {
                value = convert_to_int(num);
                i = 0;
                if (swap_list == 0){
                    list1[add_list] = value;
                    swap_list = 1;
                } else {
                    list2[add_list] = value;
                    add_list += 1;
                    swap_list = 0;
                }
            }
        }
    }
    sort_list(list1);
    sort_list(list2);

    int total = add_differences(list1, list2);
    printf ("%d\n", total);

    int similarity_score = find_score(list1, list2);
    printf ("%d\n", similarity_score);

    return 0;
}