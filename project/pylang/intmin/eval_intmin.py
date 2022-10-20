"""Program to evaluate the smaller out of two numbers."""

import sys


def intMin(numOne: int, numTwo: int) -> int:
    if numOne < numTwo:
        return numOne
    else:
        return numTwo


def main():
    numOne = int(sys.argv[1])
    numTwo = int(sys.argv[2])
    min = intMin(numOne, numTwo)

    print("Minimum Value: ", min)


if __name__ == "__main__":
    main()
