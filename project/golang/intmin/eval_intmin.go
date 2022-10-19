// Reference: https://gobyexample.com/testing-and-benchmarking

// the benchmark and the test suite should not be declared in this file

// declare package
package main

// import modules
import "fmt"
import "os"
import "strconv"
import "strings"

// define IntMin function
func IntMin(numOne int, numTwo int) int {
	// if the first is smaller return it
	if numOne < numTwo {
		return numOne
	} else {
		// if it is not bigger the second is smaller, so return it
		return numTwo
	}
}

// define main function
func main() {
	// take in the two numbers from command line
	// and assign them to variables
	numOne, err := strconv.Atoi(os.Args[1])
	numTwo, err := strconv.Atoi(strings.TrimSpace(os.Args[2]))
	if err != nil {
		panic(err)
	}

	// call the function and get back the result
	result := IntMin(numOne, numTwo)

	// print out the answer to the users
	fmt.Println("Minimum Value:", result)
}
