all: eval_primenum

maketest: test_primenum

clean: 
		rm -f bin/eval_primenum
		rm -f bin/test_primenum

bin:
		mkdir bin

eval_prime: eval_primenum.c bin
		gcc -o bin/eval_primenum

test: test_primenum.c bin
	gcc -o bin/test_primenum