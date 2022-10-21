#include <stdio.h>
#include <stdlib.h>

int intMin(int numOne, int numTwo)
{
    if (numOne < numTwo)
    {
        return numOne;
    }
    else
    {
        return numTwo;
    }
}

int main(int argc, char *argv[])
{
    int numOne = atoi(argv[1]);
    int numTwo = atoi(argv[2]);

    int result = intMin(numOne, numTwo);

    printf("Minimum Value: %d\n", result);
}
