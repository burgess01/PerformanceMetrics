# Performance Benchmarking

[![Language: C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Language: Python](https://img.shields.io/badge/Language-Python-blue.svg)](https://www.python.org/)
[![Language: Go](https://img.shields.io/badge/Language-Go-blue.svg)](https://go.dev/)
[![Commits: Conventional](https://img.shields.io/badge/Commits-Conventional-blue.svg)](https://www.conventionalcommits.org/en/v1.0.0/)

Performance Benchmarking shows basic examples of test cases and benchmarking cases in Go, Python, and C.

## Introduction

This project is a resouce and training guide in order to understand the basics of creating test cases and benchmarking in Go, Python, and C. This project also has Makefile command shortcuts in order to assist in speeding up the process of compiling and running Go and C code.

## Performance Benchmarking Overview

After cloning this repository to your computer, please take the following
steps in order to run the code included:

### Program Setup

- Make sure that you have installed the following programs on your laptop:
  - Gcc toolchain, especially `make` command for running Makefiles.
  - Go programming language
  - C programming language

### Program Output

When you are finished, you can run the Go programs, for example, and see output like this:

- `./bin/eval_intmin 10 560`

```text
Minimum value: 10
```

- `./bin/eval_primenum 22`

```text
Prime numbers: [2 3 5 7 11 13 17 19]
```

When you run the test suite for the `eval_intmin` with `make test` it will look like this:

```text
go test -v
=== RUN   TestIntMinBasic
--- PASS: TestIntMinBasic (0.00s)
=== RUN   TestIntMinTableDriven
=== RUN   TestIntMinTableDriven/0,1
=== RUN   TestIntMinTableDriven/1,0
=== RUN   TestIntMinTableDriven/2,-2
=== RUN   TestIntMinTableDriven/0,-1
=== RUN   TestIntMinTableDriven/-1,0
--- PASS: TestIntMinTableDriven (0.00s)
    --- PASS: TestIntMinTableDriven/0,1 (0.00s)
    --- PASS: TestIntMinTableDriven/1,0 (0.00s)
    --- PASS: TestIntMinTableDriven/2,-2 (0.00s)
    --- PASS: TestIntMinTableDriven/0,-1 (0.00s)
    --- PASS: TestIntMinTableDriven/-1,0 (0.00s)
PASS
ok      eval_intmin     0.001s
```

When you run an experiment for the `eval_intmin` with `make benchmark-memory` it
will look something like this:

```text
go test -bench=. -benchmem
goos: linux
goarch: amd64
pkg: eval_intmin
cpu: Intel(R) Core(TM) i7-1065G7 CPU @ 1.30GHz
BenchmarkIntMin-8       1000000000               0.2688 ns/op          0 B/op          0 allocs/op
PASS
ok      eval_intmin     0.301s
```
