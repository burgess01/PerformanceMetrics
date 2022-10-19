# File Manipulation

Please remove and rewrite all of the markers and the sentences in
this document. Ultimately, you should have a professional report suitable for
publication of your own web site or in a journal about operating systems.

## Katie Burgess

## Program Output

### What is the output from running the following commands?

#### Run the `eval_intmin` program with two integer inputs of `10` and `5`

```text
command: 
go run eval_intmin.go 10 5
results:
Minimum Value: 5
```

#### Run the `eval_primenum` program with the integer inputs of `22`

```text
command: 
go run eval_primenum.go 22
results:
Prime numbers: [2 3 5 7 11 13 17 19]
```

#### Run the benchmarks and test cases for the `eval_intmin` program without memory performance results

```text
go test -bench=.
goos: darwin
goarch: amd64
pkg: eval_intmin
cpu: Intel(R) Core(TM) i5-8257U CPU @ 1.40GHz
BenchmarkIntMin-8       1000000000               0.2694 ns/op
PASS
ok      eval_intmin     0.506s
```

#### Run the benchmarks and test cases for the `eval_intmin` program with memory performance results

```text
go test -bench=. -benchmem
goos: darwin
goarch: amd64
pkg: eval_intmin
cpu: Intel(R) Core(TM) i5-8257U CPU @ 1.40GHz
BenchmarkIntMin-8       1000000000               0.2705 ns/op          0 B/op          0 allocs/op
PASS
ok      eval_intmin     0.416s
```

#### Run the benchmarks and test cases for the `eval_primenum` program without memory performance results

```text
go test -bench=.
goos: darwin
goarch: amd64
pkg: eval_primenum
cpu: Intel(R) Core(TM) i5-8257U CPU @ 1.40GHz
BenchmarkPrimeNumbers-8            10000            443355 ns/op
BenchmarkPrimeNumbersTable/input_size_5-8         20374152                58.18 ns/op
BenchmarkPrimeNumbersTable/input_size_10-8         8095804               148.4 ns/op
BenchmarkPrimeNumbersTable/input_size_30-8         2189659               544.0 ns/op
BenchmarkPrimeNumbersTable/input_size_22-8         3289336               382.3 ns/op
PASS
ok      eval_primenum   10.553s
```

#### Run the benchmarks and test cases for the `eval_primenum` program with memory performance results

```text
go test -bench=. -benchmem
goos: darwin
goarch: amd64
pkg: eval_primenum
cpu: Intel(R) Core(TM) i5-8257U CPU @ 1.40GHz
BenchmarkPrimeNumbers-8            10000            441977 ns/op           15133 B/op         10 allocs/op
BenchmarkPrimeNumbersTable/input_size_5-8               19908542                63.64 ns/op           24 B/op            2 allocs/op
BenchmarkPrimeNumbersTable/input_size_10-8               7986810               148.0 ns/op            56 B/op            3 allocs/op
BenchmarkPrimeNumbersTable/input_size_30-8               2201283               532.5 ns/op           248 B/op            5 allocs/op
BenchmarkPrimeNumbersTable/input_size_22-8               3443978               358.2 ns/op           120 B/op            4 allocs/op
PASS
ok      eval_primenum   10.567s
```

## Performance Evaluation

### Characterize the computer hardware and software that you used to conduct all of the performance benchmarks

TODO: provide as many details as is possible, including information about the
number of CPUs, number of CPU cores, the amount of physical memory and, if
possible, details about, for instance, the CPU scheduler and the memory allocator.

The computer hardware and software that I used to conduct all of my performance benchmarks:

goos: darwin
goarch: amd 64
pkg: eval_primenum
cpu information: Intel (R) Core (TM) i5-8257U CPU is at 1.40GHz

### Identify and explain at least three performance trends that are evident in your data set

TODO: identify and explain the performance trends in the following subsections

#### Performance Trend One

TODO: Provide at least one paragraph that identifies and explains a performance trend.

#### Performance Trend Two

TODO: Provide at least one paragraph that identifies and explains a performance trend.

#### Performance Trend Three

TODO: Provide at least one paragraph that identifies and explains a performance trend.

## Source Code and Configuration Files

### Describe in detail how the program source code or Go programming tool works

#### What happens if you use `go build` and the program does not have a `main` function? Why?

TODO: Provide the command output in a fenced code block and then explain it in detail

#### Go source code that provides the command-line interface for the `eval_intmin.go` program

```go
numOne, err := strconv.Atoi(os.Args[1])
numTwo, err := strconv.Atoi(strings.TrimSpace(os.Args[2]))
if err != nil {
panic(err)
}
```

This source code works by using the os import in order to take in the command line input. This code takes this in and using strconv Atoi converts it into an integer and puts it in numOne and numTwo while also grabbing an err variable in case anything goes wrong. If err does not exist, the rest of the program is run.

#### Go source code that provides the command-line interface for the `eval_primenum.go` program

```go
inputNum, err := strconv.Atoi(os.Args[1])
if err != nil {
panic(err)
}
```

This source code is very similar to the one above. It takes in the user input as a string and turns it into an integer before putting it into the inputNum variable with a err variable created as well in case something went wrong. If the err variable does not exist, then the rest of the program runs.

#### How does the Go programming language support program testing?

The Go programming language supports testing by having a similar testing format as Python has. You are able to create a test file with functions that start with test and have go run it when you run go test. You can also do python's parameterized testing by using table information and running that through a test function. While go does not have python's assert, you are able to write your test files through having actual and expected values and throwing an error if the two are not equal to each other.

#### How does the Go programming langauge support performance benchmarking?

TODO: Provide a one-paragraph response to this question, using source code as needed

The go programming language supports performance benchmarking through allowing you to write benchmarking test cases. These look pretty similar to a test case, but have a new syntax where you use a 'b' testing parameter instead of a 'f' testing function. This sends out the stats for the computer and says how long it took for the different input cases took to run if it is a table benchmark function. You can see an example of a tale benchmark function below:

```go
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
```

## Project Reflection

### How do the programs that you implemented connect to the content in all of the recently covered modules?

TODO: Provide a one-paragraph response that answers this question in your own words.

### What was the greatest challenge that you faced when completing this project? How did you resolve it?

The greatest challenge that I faced in this project was trying to get the benchmarking for the primenum to work. For some reason at first I was not able to get it to work as my tests were working but my benchmarking was not. I was finally able to get this to work

### What external resources did you examine while completing this project? How did you find them? How did they help you?

I used the resources listed on the top of all of the program files, as well as looking up basic syntax in go. I found the latter resources by looking up the kinds of data structures I needed and writing golang after in Google.

### What steps would you take if you were asked to re-implement this project in Python or C?

If I was to re-implement this project in Python or C, I would use my same general format while changing syntax and the imports used. So, for example, I would write the same general test case format in python, but instead of using the table syntax in Go, I would change it out for the parameterized testing in pytest for Python.
