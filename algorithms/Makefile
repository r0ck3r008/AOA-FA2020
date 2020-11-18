all: alg1.o alg2.o alg3.o

alg1.o: alg1.cc
	${COMPILER} -I${COMPILE_PATH} ${COMPILER_FLAGS} -c alg1.cc

alg2.o: alg2.cc
	${COMPILER} -I${COMPILE_PATH} ${COMPILER_FLAGS} -c alg2.cc

alg3.o: alg3.cc
	${COMPILER} -I${COMPILE_PATH} ${COMPILER_FLAGS} -c alg3.cc

clean:
	rm -rf *.o
