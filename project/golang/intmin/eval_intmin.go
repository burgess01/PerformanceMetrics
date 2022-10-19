// Reference: https://gobyexample.com/testing-and-benchmarking

// the benchmark and the test suite should not be declared in this file!

// declare the package
package main

// import the needed modules
import "fmt"
import "os"

// define the IntMin function
func IntMin(numOne int, numTwo int) {
	// if the first is bigger return it
	if numOne > numTwo {
		return numOne
	}
	else {
		// if it is not bigger it is smaller, so return it
		return numTwo
	}
}

// define the required main function
func main() {
	// take in the two numbers from command line
	// and assign them to variables
	numOne := os.Args[1]
	numTwo := os.Args[2]

	// call the function and get back the result
	result := IntMin (numOne, numTwo)

	// print out the answer to the users
	fmt.Println("Minimum Value: %t", result)
}
