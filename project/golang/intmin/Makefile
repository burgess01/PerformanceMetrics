all: eval_intmin

clean:
	rm -f bin/eval_intmin

bin:
	mkdir bin

mod: eval_intmin.go bin
	go mod init eval_intmin
	go mod tidy

eval_intmin: eval_intmin.go bin
	go build --o bin eval_intmin.go

test: eval_intmin.go bin
	go test -v

benchmark-time: eval_intmin.go bin
	go test -bench=.

benchmark-memory: eval_intmin.go bin
	go test -bench=. -benchmem
