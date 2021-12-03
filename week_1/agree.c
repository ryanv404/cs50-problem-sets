#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char c = get_char("Do you agree? ");

    if (c == 'y' || c == 'Y')
    {
        printf("You agreed!\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("You disagreed!\n");
    }
    else
    {
        printf("Please enter y or n\n");
        return main();
    }

};