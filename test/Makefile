all: test_matrix test_stack

test_matrix: ../src/matrix/matrix.o

test_stack: ../src/stack/stack.o

test: all
	./test_matrix
	./test_stack

clean:
	$(MAKE) -C ../src/matrix/ clean
	$(MAKE) -C ../src/stack/ clean

cleaner: clean
	rm -f ./test_matrix
	rm -f ./test_stack
