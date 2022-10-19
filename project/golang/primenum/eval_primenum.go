// Reference: https://gobyexample.com/testing-and-benchmarking
// Reference: https://blog.logrocket.com/benchmarking-golang-improve-function-performance/

// declare the package
package main

// TODO: import the required modules
import "fmt"
import "os"
import "strconv"

// declare the primeNumbers function
func primeNumbers(inputNum int) []int {
	var outputList []int
	// iterate through all of the numbers up to and including the input
	for i := 2; i < inputNum; i++ {
		prime := true
		for j := 2; j < i; j++ {
			// if the number is prime
			if i%j == 0 {
				prime = false
			}
		}
		if prime == true {
			outputList = append(outputList, i)
		}
	}
	// return the list
	return outputList
}

// declare the main function that calls the primeNumbers function
func main() {
	var outputList []int
	// take in the input number as command line input
	// and convert it from string to integer
	inputNum, err := strconv.Atoi(os.Args[1])
	if err != nil {
		panic(err)
	}
	// pass it into the prime number function
	outputList = primeNumbers(inputNum)
	// return the output to the user
	fmt.Println("Prime numbers:", outputList)
}
