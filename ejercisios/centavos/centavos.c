#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{

    int cents = get_cents();

    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    int coins = quarters + dimes + nickels + pennies;

    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("How many cents do you have?: ");

    }
    while (cents < 0);

    return cents;
}

int calculate_quarters(int cents) // 25 c
{
    cents = cents / 25;

    return cents;
}

int calculate_dimes(int cents) // 10 c
{
    cents = cents / 10;

    return cents;
}

int calculate_nickels(int cents) // 5 c
{
    cents = cents / 5;

    return cents;
}

int calculate_pennies(int cents) // 1 c
{
    cents = cents / 1;

    return cents;
}
