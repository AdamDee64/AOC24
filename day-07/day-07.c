#include <stdio.h>
#include <stdlib.h>

#define i64 long long

void add_to_array(i64* data, i64 value, i64 count){
    i64* ptr = data + count;
    *ptr = value;
}

i64 resolve(i64 result, i64* data, i64 count){
    if (count == 0) return result == *data;

    if (result % *(data + count)) return resolve(result - *(data + count), data, count - 1);
    else return resolve(result / *(data + count), data, count - 1) || resolve(result - *(data + count), data, count -1);
}

int main(void){

    FILE *fp = fopen("day-07/input.txt", "r");

    i64 ch;

    i64 total = 0;
    i64 result = 0;
    i64 value = 0;

    i64 count = 0;
    i64* data = NULL;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch >= 48 && ch <= 57) value = value * 10 + (ch - 48);

        if (ch == ':') {
            result = value;
            value = 0;
            data = malloc(sizeof(i64));
        }

        if (ch == ' ') {
            if (value) {
                add_to_array(data, value, count);
                count++;
                data = realloc(data, sizeof(i64) * (count + 1));
            }
            value = 0;
        }
        if (ch == 10) {
            add_to_array(data, value, count);

            total += resolve(result, data, count) ? result : 0;

            value = 0;
            count = 0;
            result = 0;

            free(data);
            data = NULL;
        }
    }
    fclose(fp);    

    printf("%llu\n", total);  // part 1 answer

    return 0;
}