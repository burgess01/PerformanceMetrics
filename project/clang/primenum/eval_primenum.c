#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int isPrime(int num)
{
    int inum = sqrt(num), prime = true, count;

    for (count = 2; count <= inum; count++)
    {
        if (num % count == 0)
        {
            prime = false;
            break;
        }
    }
    return prime;
}

int main(int argc, char *argv[])
{
    int inputNum = atoi(argv[1]);

    int numPrimes = 0;

    for (int i = 2; i < inputNum; i++)
    {
        if (isPrime(i) == true)
        {
            numPrimes++;
        }
    }
    int primesList[numPrimes];
    int index = 0;
    for (int i = 2; i < (inputNum + 1); i++)
    {
        if (isPrime(i))
        {
            primesList[index] = i;
            index++;
        }
    }

    printf("Prime Numbers: ");
    for (int j = 0; j < numPrimes + 1; j++)
    {
        printf("%d ", primesList[j]);
    }
    printf("\n");
}