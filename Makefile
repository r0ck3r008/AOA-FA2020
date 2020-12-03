COMPILER := g++
COMPILER_FLAGS := -g
COMPILE_PATH := ${shell pwd}/include

ALL_OBJS := *.o

all: AlgoTowers

AlgoTowers: algorithms_objs timer_objs main_obj
	${COMPILER} ${ALL_OBJS} -o AlgoTowers
	$(MAKE) clean_objs

main_obj: main.cc
	${COMPILER} -I${COMPILE_PATH} ${COMPILER_FLAGS} -c main.cc

algorithms_objs:
	${COMPILER} -I${COMPILE_PATH} ${COMPILER_FLAGS} -c alg*.cc

timer_objs:
	${COMPILER} -I${COMPILE_PATH} ${COMPILER_FLAGS} -c timer.cc

clean_objs:
	rm -f *.o

clean: clean_objs
	rm -rf AlgoTowers
