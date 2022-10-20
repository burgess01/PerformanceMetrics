"""Program to find all of the prime numbers lesser and equal to that number."""

import math
import sys


def primeNum(maxNum):
    outputList = []
    for i in range(2, maxNum + 1):
        prime = True
        for j in range(2, i):
            if i % j == 0:
                prime = False
                break
        if prime == True:
            outputList.append(i)
    return outputList


def main():
    max = int(sys.argv[1])
    results = primeNum(max)
    print("Prime Numbers:", results)


if __name__ == "__main__":
    main()
