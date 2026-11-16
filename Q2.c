#include <stdio.h>
#include <string.h>

int main() {
    char list[10][50], t[50];
    int r, c;

    printf("Enter 10 names:\n");
    for (r = 0; r < 10; r++) {
        printf("Name %d: ", r + 1);
        scanf(" %[^\n]", list[r]);
    }
  
    for (r = 0; r < 9; r++) {
        for (c = 0; c < 9 - r; c++) {
            if (strcmp(list[c], list[c + 1]) > 0) {
                strcpy(t, list[c]);
                strcpy(list[c], list[c + 1]);
                strcpy(list[c + 1], t);
            }
        }
    }

    printf("\nSorted list:\n");
    for (r = 0; r < 10; r++) {
        printf("%d. %s\n", r + 1, list[r]);
    }

    return 0;
}
