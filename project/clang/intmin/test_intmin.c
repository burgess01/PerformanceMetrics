#include <CUnit/CUnit.h>

#include <time.h>

// import eval file
#include "eval_intmin.c"

void test_intMinBasic(void)
{
    // this test function puts a number into my intMin function
    // this function will take in the numbers 2 and -2 and
    // should return -2 meaning that it is able to both
    // handle negative numbers and finding the smaller number
    // in general

    int numOne = 2;
    int numTwo = -2;
    int ans = intMin(numOne, numTwo);

    // checks if the function returned the correct answer
    CU_ASSERT_EQUAL(ans, numTwo);
}

void test_intMinBenchmark(void)
{
    // this test will run multiple iterations
    // of the intMin function, returning the
    // overall time it took to run certain amounts
    // of intMin runs.

    // first trial run
    float startTime1 = (float)clock() / CLOCKS_PER_SEC;
    for (int x = 0; x < 10; x++)
    {
        // return the amount of time it took to run 10 iterations
        bool ans = intMin(x, 5);
    }
    // calculate the time elapsed and return it to the user
    float endTime1 = (float)clock() / CLOCKS_PER_SEC;
    float timeElapsed1 = endTime1 - startTime1;
    printf("10 iterations of intMin() took %f to run.", timeElapsed1);

    // second trial run
    float startTime2 = (float)clock() / CLOCKS_PER_SEC;
    for (int x = 0; x < 25; x++)
    {
        // return the amount of time it took to run 25 iterations
        bool ans = isPrime(x, 15);
    }
    // calculate the time elapsed and return it to the user
    float endTime2 = (float)clock() / CLOCKS_PER_SEC;
    float timeElapsed2 = endTime2 - startTime2;
    printf("25 iterations of intMin() took %f to run.", timeElapsed2);

    // third trial run
    float startTime3 = (float)clock() / CLOCKS_PER_SEC;
    for (int x = 0; x < 50; x++)
    {
        // return the amount of time it took to run 50 iterations
        bool ans = isPrime(x, 25);
    }
    // calculate the time elapsed and return it to the user
    float endTime3 = (float)clock() / CLOCKS_PER_SEC;
    float timeElapsed3 = endTime3 - startTime3;
    printf("50 iterations of intMin() took %f to run.", timeElapsed3);
}
