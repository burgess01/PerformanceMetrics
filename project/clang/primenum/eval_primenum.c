#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int primeNum(int max)
{
    // create the outputlist
    int outputList[max / 2];
    int index = 0 for (int i = 2; i < max; i++)
    {
        bool prime = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                prime = false;
                break;
            }
            if (prime == true)
            {
                int outputList[index] = i;
                index++;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int inputNum = atoi(argv[1]);

    int result = primeNum(inputNum);

    printf("Prime Numbers:", result);
}