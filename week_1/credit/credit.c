#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt for credit card number
    long card_num = get_long("Number: ");

    // Store a copy of the number for checksum math operations
    long card_num_copy = card_num;

    // Determine length of the number
    int length = 0;

    while (card_num >= 1)
    {
        card_num /= 10;
        length++;
    }

    // Determine card type:
    // American Express => 15-digit number AND starts with 34 or 37.
    // MasterCard => 16-digit number AND starts with 51, 52, 53, 54, or 55.
    // Visa => 13- OR 16-digit numbers AND starts with 4.
    string output;
    int first_two_digits;
    int first_digit;

    if (length == 15)
    {
        first_two_digits = card_num_copy / 10000000000000;
        if (first_two_digits == 34 || first_two_digits == 37)
        {
            output = "AMEX\n";
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else if (length == 13)
    {
        first_digit = card_num_copy / 1000000000000;

        if (first_digit == 4)
        {
            output = "VISA\n";
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else if (length == 16)
    {
        first_two_digits = card_num_copy / 100000000000000;
        first_digit = first_two_digits / 10;

        if (first_digit == 4)
        {
            output = "VISA\n";
        }
        else if (first_two_digits == 51 || first_two_digits == 52 ||
                 first_two_digits == 53 || first_two_digits == 54 ||
                 first_two_digits == 55)
        {
            output = "MASTERCARD\n";
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }

    // Determine if checksum is valid

    // Declare sums that will track the sum of the multiplied
    // and non-multiplied nums for the checksum
    long sum_multiplied_nums = 0;
    long sum_unchanged_nums = 0;

    // Extract each digit starting at the end
    int index = 0;
    int temp_num;

    while (card_num_copy >= 1)
    {
        // Obtain the right-most digit
        temp_num = card_num_copy % 10;
        card_num_copy /= 10;

        if (index % 2 != 0)
        {
            // Beginning with 2nd num from end, multiply it and
            // every 2nd num before it by 2
            temp_num *= 2;

            if (temp_num >= 10)
            {
                // Double digit nums have to be split into 2 digits that are then summed together
                // Since 10 <= temp_num <= 19, subtracting 9 does this in 1 step.
                temp_num -= 9;
            }

            // Add the temp_num to the sum
            sum_multiplied_nums += temp_num;
            index++;
        }
        else
        {
            // All other nums just get added to the other sum unchanged
            sum_unchanged_nums += temp_num;
            index++;
        }
    }
    //printf("Unchanged nums sum: %li\n", sum_unchanged_nums);
    //printf("Multiplied nums sum: %li\n", sum_multiplied_nums);

    // Then, add sum_multiplied_nums + sum_unchanged_nums and check if modulo 10 is 0.
    long total_sum = sum_multiplied_nums + sum_unchanged_nums;
    if (total_sum % 10 == 0)
    {
        // VALID checksum
        printf("%s", output);
    }
    else
    {
        // INVALID checksum
        printf("INVALID\n");
    }
}