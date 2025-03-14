#include <stdio.h>
#define MAX_TRANSACTIONS 100

// Global variables
float balance = 0.0;
char transactions[MAX_TRANSACTIONS][50];
int transaction_count = 0;

void depositMoney()
{
    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    if (amount > 0)
    {
        balance += amount;
        printf("Amount successfully deposited!\n");
        printf("Updated Balance: $%.2f\n", balance);
        // Storing transaction
        sprintf(transactions[transaction_count], "Deposit: +$%.2f", amount);
        transaction_count++;
    }
    else
    {
        printf("Invalid deposit amount!\n");
    }
}

void withdrawMoney()
{
    float amount;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        printf("Amount successfully withdrawn!\n");
        printf("Updated Balance: $%.2f\n", balance);
        // Storing transaction
        sprintf(transactions[transaction_count], "Withdrawal: -$%.2f", amount);
        transaction_count++;
    }
    else
    {
        printf("Insufficient funds or invalid amount! Transaction failed.\n");
    }
}

void checkBalance()
{
    printf("Current Balance: $%.2f\n", balance);
}

void viewTransactionHistory()
{
    printf("Transaction History:\n");
    if (transaction_count == 0)
    {
        printf("No transactions available.\n");
    }
    else
    {
        for (int i = 0; i < transaction_count; i++)
        {
            printf("%s\n", transactions[i]);
        }
    }
}

int main()
{
    int choice;
    printf("Enter initial balance: ");
    scanf("%f", &balance);

    do
    {
        printf("\nBank Account System\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Check Balance\n");
        printf("4. View Transaction History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            depositMoney();
            break;
        case 2:
            withdrawMoney();
            break;
        case 3:
            checkBalance();
            break;
        case 4:
            viewTransactionHistory();
            break;
        case 5:
            printf("Exiting the system...\n");
            printf("Thank you for using our banking service!\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    while (choice != 5);

    return 0;
}

