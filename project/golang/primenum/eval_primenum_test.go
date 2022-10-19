// Reference: https://gobyexample.com/testing-and-benchmarking
// Reference: https://blog.logrocket.com/benchmarking-golang-improve-function-performance/
// Reference: https://stackoverflow.com/questions/28157891/testing-lists-in-go

// Add the package
package main

// Import the required modules
import "fmt"
import "testing"
import "reflect"

// Declare the TestPrimeNumBasic function
func TestPrimeNumBasic(t *testing.T) {
	// this function should give primeNumbers the input 22
	// and then confirm that it produces the expected list of output values
	ans := primeNumbers(22)
	expected := []int{2, 3, 5, 7, 11, 13, 17, 19}
	if reflect.DeepEqual(ans, expected) != true {
		t.Errorf("primeNumbers(22) = %v; want [2 3 5 7 11 13 17 19]", ans)
	}

}

// define the BenchmarkPrimeNumbers function
func BenchmarkPrimeNumbers(b *testing.B) {
	for i := 0; i < b.N; i++ {
		primeNumbers(i)
	}
}

// Define the BenchmarkPrimeNumbersTable function
var table = []struct {
	input int
}{
	{input: 5},
	{input: 10},
	{input: 30},
	{input: 22},
}

func BenchmarkPrimeNumbersTable(b *testing.B) {
	for _, v := range table {
		b.Run(fmt.Sprintf("input_size_%d", v.input), func(b *testing.B) {
			for i := 0; i < b.N; i++ {
				primeNumbers(v.input)
			}
		})
	}
}
