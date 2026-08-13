// This program simulates an ATM with balance, deposit, withdraw and last 5 transactions

#include <stdio.h>

int main() {
    int choice;
    float balance = 1000, amount;
    float transactions[5];
    int count = 0, i;

    while(1) {
        printf("\n1.Check Balance 2.Deposit 3.Withdraw 4.Last 5 Transactions 5.Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Balance = %.2f\n", balance);
        }

        else if(choice == 2) {
            printf("Enter amount: ");
            scanf("%f", &amount);

            balance += amount;

            transactions[count % 5] = amount;
            count++;
        }

        else if(choice == 3) {
            printf("Enter amount: ");
            scanf("%f", &amount);

            if(amount > balance) {
                printf("Insufficient balance\n");
            } else {
                balance -= amount;
                transactions[count % 5] = -amount;
                count++;
            }
        }

        else if(choice == 4) {
            printf("Last transactions:\n");

            int start = count - 5;
            if(start < 0) start = 0;

            for(i = start; i < count; i++) {
                printf("%.2f\n", transactions[i % 5]);
            }
        }

        else if(choice == 5) {
            break;
        }
    }

    return 0;
}