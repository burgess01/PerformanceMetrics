all: eval_primenum

clean:
	rm -f bin/eval_primenum

bin:
	mkdir bin

mod: eval_primenum.go bin
	go mod init eval_primenum
	go mod tidy

eval_primenum: eval_primenum.go bin
	go build --o bin eval_primenum.go

test: eval_primenum.go bin
	go test -v

benchmark-time: eval_primenum.go bin
	go test -bench=.

benchmark-memory: eval_primenum.go bin
	go test -bench=. -benchmem
