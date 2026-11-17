#include <stdio.h>
#include <string.h>
int main(){
    char name[50];
    int accNo;
    float amount;
    FILE *fptr;
    printf("Enter customer name: ");
    scanf(" %[^\n]", name);
    printf("Enter account number: ");
    scanf("%d", &accNo);
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    fptr = fopen("bank_log.txt", "a");
    if (fptr == NULL){
        printf("Error: Could not open file!\n");
        return 1;
    }
    fprintf(fptr, "Name: %s, Account No: %d, Amount: %.2f\n", name, accNo, amount);
    fclose(fptr);
    printf("Transaction saved successfully.\n");
    return 0;
}
