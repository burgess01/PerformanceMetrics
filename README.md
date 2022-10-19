# Performance Benchmarking

[![build](../../actions/workflows/build.yml/badge.svg)](../../actions/)
[![Language: Python](https://img.shields.io/badge/Language-Python-blue.svg)](https://www.python.org/)
[![Language: Go](https://img.shields.io/badge/Language-Go-blue.svg)](https://go.dev/)
[![Commits: Conventional](https://img.shields.io/badge/Commits-Conventional-blue.svg)](https://www.conventionalcommits.org/en/v1.0.0/)
[![Discord](https://img.shields.io/discord/1013818801281839184?logo=discord)](https://discord.gg/9VfCdqffu6)

## Introduction

This project introduces the benefits associated with having the operating
system scheduler run processes on your behalf as you execute test cases and run
a performance benchmark to measure time and memory efficiency. You will build on
existing tutorials to create your own test cases and benchmarks for two
functions called `IntMin` and `primeNumbers`. You will then run these
benchmarks and record and interpret the results so as to learn how different
input sizes influence CPU scheduling and execution time and memory allocation.

## Seeking Assistance

Even though the course instructor will have covered all of the concepts central
to this project before you start to work on it, please note that not every
detail needed to successfully complete the assignment will have been covered
during prior classroom sessions. This is by design as an important skill that
you must practice as you explore the depth and breadth in the field of operating
systems. If you have questions about this project, please schedule a meeting
with the course instructor during office hours.

## Project Overview

After cloning this repository to your computer, please take the following
steps:

### Program Setup

- Make sure that you have installed the following programs on your laptop:
  - Gcc toolchain, especially the `make` command for running Makefiles.
  - Go programming language
  - C programming language
- Use the `cd` command to change into the directory for this repository.
- Review the `Makefile`s in the `project/golang/` directory to see the targets
  for the version of this project implemented in the Go programming language.
- Both of these `Makefile`s will work on the Linux and MacOS operating systems
  and, additionally, on GitHub Actions and inside of the OS-Sketch Docker
  container. You may need to revise portions of these `Makefile`s so that they
  work correctly on the Windows operating system.
- Make sure that you review the purpose of the files that you must implement in
  the `intmin` and `primenum` directories that are sub-directories of the
  `golang` directory. Specifically, you will need to add source code to the
  following files:
  - `intmin/eval_intmin.go`: provides the `IntMin` function and a command-line interface
  - `intmin/eval_intmin_test.go`: provides the test suite and benchmark for `IntMin`
  - `primenum/eval_primenum.go`: provides the `primeNumbers` function and a command-line interface
  - `primenum/eval_primenum_test.go`: provides the test suite and benchmark for `primeNumbers`
- To build, test, and benchmark the Go programs you need to run the appropriate
  targets inside of the Makefile. For instance, if you want to build the
  `primeNumbers` project you would type the following command `make
  eval_primenum` in the `golang/primenum/` directory. Please note that this
  project will require you to run the command `make mod` before you can run the
  test suite and the benchmarking framework for the provided function.
- If you are still learning more about the Go programming language you can refer
  to the tutorials that are available on the [Go](https://go.dev/) and [Go by
  Example](https://gobyexample.com/) web sites.

### Program Implementation

Please check the referenced web site(s) in all of the provided source code so
that you know more about the Go programs that you have to write. Please note
that you will need to carefully divide the referenced functions into multiple
files so that the targets inside of the `Makefile`s will work correctly. If you
run the GatorGrader checks then you will see that they provide you with a guide
for where certain functions should be included in certain files. For instance,
none of the testing or benchmarking functions for the `intmin` project should
go inside of the `intmin/eval_intmin.go` file; instead they should appear in
the `intmin/eval_intmin_test.go`file!

When you are finished, you can run the programs and see output like this:

- `./bin/eval_intmin 10 560`

```text
Minimum value: 10
```

- `./bin/eval_primenum 22`

```text
Prime numbers: [2 3 5 7 11 13 17 19]
```

When you run the test suite for the `eval_intmin` with `make test` it will look something like this:

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

Please make sure that you can also run the other non-memory benchmark for the
`eval_intmin` and you can run all of the `Makefile` targets for the
`eval_primenum` program as well. You should carefully read the web sites
referenced in the provided source code so that you can understand all of the
output produced by the various `Makefile` targets. After completing this
project, you better should understand how your operating system virtualizes your
computer's CPU and memory when running each of the performance benchmarks.

### Project Reflection

As you work on this project, you should regularly take time to reflect on the
steps that you are taking and why you are taking them. Each time you run a
program you should think about the inputs, outputs, and behavior of that
program, jotting down notes to help you remember these insights. When you are
writing Go programs, please reserve time to reflect on the features of the
language that you are learning and how the language is similar to and different
from other languages you have used in the past, like Python. Finally, as you
complete this project, make sure that you reflect on your own strengths and
weaknesses and how you can improve in advance of the next project.

### Automated Assessment

Please review the following notes about the way in which your project will be
automatically assess in GitHub Actions:

- If you have already installed the
  [GatorGrade](https://github.com/GatorEducator/gatorgrade) program that runs
  the automated grading checks provided by
  [GatorGrader](https://github.com/GatorEducator/gatorgrader) you can, from the
  repository's base directory, run the automated grading checks by typing
  `gatorgrade --config config/gatorgrade.yml`.
- You may also review the output from running GatorGrader in GitHub Actions.
- Don't forget to provide all of the required responses to the technical writing
  prompts in the `writing/reflection.md` file.
- Please make sure that you completely delete the `TODO` markers and their
  labels from all of the provided source code. This means that instead of only
  deleting the `TODO` marker from the code you should delete the `TODO`
  marker and the entire prompt and then add your own comments to demonstrate
  that you understand all of the source code in this project.
- Please make sure that you also completely delete the `TODO` markers and their
  labels from every line of the `writing/reflection.md` file. This means that
  you should not simply delete the `TODO` marker but instead delete the entire
  prompt so that your reflection is a document that contains polished technical
  writing that is suitable for publication on your professional web site.
