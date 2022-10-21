#include <CUnit/CUnit.h>
#include <stdbool.h>
#include <time.h>

// import eval file
#include "eval_primenum.c"

void test_primeNumBasicPrime(void)
{
    // this test function puts a number into my IsPrime function
    // this function will take in the number 3 and should return true
    // meaning that 3 is in fact a prime number.
    int inputNum = 3;
    bool ans = isPrime(inputNum);

    // checks if the function returned the correct answer, true
    CU_ASSERT_EQUAL(ans, true)
}

void test_primeNumBasicNonPrime(void)
{
    // this test function puts a number into my IsPrime function
    // this function will take in the number 4 and should return false
    // meaning that 4 is in fact not a prime number.
    int inputNum = 4;
    bool ans = isPrime(inputNum);

    // checks if the function returned the correct answer, false
    CU_ASSERT_EQUAL(ans, false)
}

void test_primeNumBenchmark(void)
{
    // this test will run multiple iterations
    // of the isPrime function, returning the
    // overall time it took to run certain amounts
    // of isPrime runs.

    // first trial run
    float startTime1 = (float)clock() / CLOCKS_PER_SEC;
    for (int x = 0; x < 10; x++)
    {
        // return the amount of time it took to run 10 iterations
        bool ans = isPrime(x);
    }
    // calculate the time elapsed and return it to the user
    float endTime1 = (float)clock() / CLOCKS_PER_SEC;
    float timeElapsed1 = endTime1 - startTime1;
    printf("10 iterations of isPrime() took %f to run.", timeElapsed1);

    // second trial run
    float startTime2 = (float)clock() / CLOCKS_PER_SEC;
    for (int x = 0; x < 25; x++)
    {
        // return the amount of time it took to run 25 iterations
        bool ans = isPrime(x);
    }
    // calculate the time elapsed and return it to the user
    float endTime2 = (float)clock() / CLOCKS_PER_SEC;
    float timeElapsed2 = endTime2 - startTime2;
    printf("25 iterations of isPrime() took %f to run.", timeElapsed2);

    // third trial run
    float startTime3 = (float)clock() / CLOCKS_PER_SEC;
    for (int x = 0; x < 50; x++)
    {
        // return the amount of time it took to run 50 iterations
        bool ans = isPrime(x);
    }
    // calculate the time elapsed and return it to the user
    float endTime3 = (float)clock() / CLOCKS_PER_SEC;
    float timeElapsed3 = endTime3 - startTime3;
    printf("50 iterations of isPrime() took %f to run.", timeElapsed3);
}