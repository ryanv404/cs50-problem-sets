#include <stdio.h>
#include <cs50.h>

void build_pyramid(int height);

int main(void)
{
    // Prompt for an integer between 1-8, inclusive.
    int size;
    do
    {
        size = get_int("Height: ");
    }
    while (size < 1 || size > 8);

    // Print pyramid
    build_pyramid(size);
};

void build_pyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        };
        for (int k = 1; k < i + 1; k++)
        {
            printf("#");
        };
        printf("  ");
        for (int m = 1; m < i + 1; m++)
        {
            printf("#");
        };
        printf("\n");
    };
};