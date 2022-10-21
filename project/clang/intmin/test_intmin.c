#include <CUnit/CUnit.h>
// import eval file

void test_primeNumBasic(void)
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