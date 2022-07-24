#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_cents();
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
int count_1;
int count_2;
int count_3;
int count_4;

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();
    printf("No. of total Cents: %d\n", cents);

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents()
{
    int cent = 0;
    do
    {
        cent = get_float("Enter no. Cents: ");
    }
    while (cent < 0);

    printf("\n");
    return cent;
}

int calculate_quarters(int cents)
{
    while (cents >= 25)
    {
        count_1 = cents / 25;
        break;
    }
    printf("%i\n", count_1);
    return count_1;
}

int calculate_dimes(int cents)
{
    while (cents >= 10)
    {
        count_2 = cents / 10;
        break;
    }
    printf("%i\n", count_2);
    return count_2;
}

int calculate_nickels(int cents)
{
    while (cents >= 5)
    {
        count_3 = cents / 5;
        break;
    }
    printf("%i\n", count_3);
    return count_3;
}

int calculate_pennies(int cents)
{
    while (cents >= 1)
    {
        count_4 = cents / 1;
        break;
    }
    printf("%i\n", count_4);
    return count_4;
}