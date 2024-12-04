#include <stdio.h>


int compare(int a, int b, int* inc, int* dec) {
    printf("%d,%d  ", a, b);
    
    if (a > b) *dec = 1;
    if (a < b) *inc = 1;

    if (*inc && *dec) return 1;

    if(a == b) return 1;

    if (a - b > 3 || a - b < -3) return 1;

    return 0;
}



int main(void) {

    FILE *fp = fopen("day-02/input.txt", "r");
    
    int ch;

    int a = 0;
    int b = 0;

    int inc = 0;
    int dec = 0;

    int fail = 0;

    int safe_lines = 0;
    
    while ((ch = fgetc(fp)) != EOF) {
        if(ch >= 48 && ch <= 57){
            b = b * 10 + (ch - 48);

        } else {
            if (a) {
                fail += compare(a, b, &inc, &dec);
            }

            a = b;
            b = 0;
        }

        if (ch == 10){
            printf("  fail state: %d\n", fail);
            if (!fail) {
                safe_lines++;
            }
            a = 0;
            b = 0;
            inc = 0;
            dec = 0;
            fail = 0;
        }
    }

    fclose(fp);
    printf("%d\n", safe_lines);

    return 0;
}