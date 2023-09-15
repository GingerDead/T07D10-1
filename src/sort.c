#include <stdio.h>
#include <stdlib.h>

int input(int n, int* data);
void output(int n, int* data);
void bubbleSort(int n, int* data);
void swap(int* a, int* b);

int main() {
    int n;
    if ((scanf("%d", &n) == 1) && (getc(stdin) == '\n') && (n > 0)) {
        int* data = calloc(n, sizeof(int));
        if (input(n, data)) {
            bubbleSort(n, data);
            output(n, data);
        } else printf("n/a");
        free(data);
    } else printf("n/a");

    return 0;
}

int input(int n, int* data) {
    int flag = 1;    
    for (int* p = data; p - data < n; p++)
        if (scanf("%d", p) != 1) {
            flag = 0;
            break;
        }
    if (getc(stdin) != '\n') flag = 0;

    return flag;
}

void output(int n, int* data) {
    for (int* p = data; p - data < n; p++)
        (p - data != n - 1) ? printf("%d ", *p) : printf("%d", *p);
}

void bubbleSort(int n, int* data) {
    for (int i = 0; i < n - 1; i++) 
        for (int* p = data; p - data < n - i - 1; p++) {
            if (*p > *(p + 1))
                swap(p, p + 1);
        }
    
}

void swap(int* a, int* b) {
    int var = *a;
    *a = *b;
    *b = var;
}
