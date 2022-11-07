#include <cs50.h>
#include <stdio.h>

int main(void)
{
 // get int to accept integer for height value
 // then create logic to accept input from 1-8 only
 // use a do while loop for accepting integer and then use for loop for printing the bricks
 // use appropriate logic if else
    int h;
    do{
       h = get_int("Please enter the height from 1 to 8: \n");
      }
    while ((h < 1 || h > 8));

    for (int i=0; i<h; i++){
        for (int j=0; j<h; j++)
        {
            if (i + j >= h - 1)
            printf("#");

            else
            printf(" ");
        }
        printf("\n");
    }
}