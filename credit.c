#include <cs50.h>
#include <math.h>
#include <stdio.h>

void calculate_checksum(long number);

int main(void)
{
    // Prompts user for card number (w/o hashes and no letters)
    long number = get_long("Number: ");
    calculate_checksum(number);
}

// Checks if card number is legit
void calculate_checksum(long number)
{
    long copy_number = number;
    int sum_products = 0;
    int sum_remainder = 0;
    int total = 0;
    int count = 0;
    do
    {
        // Ensures every other digit is multiplied by 2 and summed
        if (count % 2 == 0)
        {
            // Sums digits that weren't multiplied by 2
            sum_remainder = sum_remainder + (copy_number % 10);
            copy_number = floor(copy_number / 10);
            count++;
        }
        else
        {
            // Sums digits that were multiplied by 2 starting from second-to-last
            if ((copy_number % 10) * 2 >= 10)
            {
                sum_products = sum_products + (((copy_number % 10) * 2) % 10) +
                               floor(((copy_number % 10) * 2) / 10);
                copy_number = floor(copy_number / 10);
                count++;
            }
            else
            {
                sum_products = sum_products + ((copy_number % 10) * 2);
                copy_number = floor(copy_number / 10);
                count++;
            }
        }
    }
    while (copy_number != 0);

    // Checks to see if card number is valid
    total = total + sum_products + sum_remainder;
    if (total % 10 == 0)
    {
        // "count" has counted the # of digits in "number"
        if (count == 15)
        {
            if (floor(number / 10000000000000) == 34 || floor(number / 10000000000000) == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (count == 13)
        {
            if (floor(number / 1000000000000) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (count == 16)
        {
            if (floor(number / 1000000000000000) == 4)
            {
                printf("VISA\n");
            }
            else if (floor(number / 100000000000000) == 51 ||
                     floor(number / 100000000000000) == 52 ||
                     floor(number / 100000000000000) == 53 ||
                     floor(number / 100000000000000) == 54 || floor(number / 100000000000000) == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
