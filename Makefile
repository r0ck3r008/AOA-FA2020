COMPILER := g++
COMPILER_FLAGS := -g
COMPILE_PATH := ${shell pwd}/include

ALL_OBJS := algorithms/*.o timer/*.o main.o

all: AlgoTowers

AlgoTowers: algorithms_objs timer_objs main_obj
	${COMPILER} ${ALL_OBJS} -o AlgoTowers
	$(MAKE) clean_objs

main_obj: main.cc
	${COMPILER} -I${COMPILE_PATH} ${COMPILER_FLAGS} -c main.cc

algorithms_objs:
	COMPILER=${COMPILER} COMPILE_PATH=${COMPILE_PATH} \
		   COMPILER_FLAGS=${COMPILER_FLAGS} $(MAKE) -C algorithms/

timer_objs:
	COMPILER=${COMPILER} COMPILE_PATH=${COMPILE_PATH} \
		   COMPILER_FLAGS=${COMPILER_FLAGS} $(MAKE) -C timer/

clean_objs:
	$(MAKE) -C algorithms/ clean
	$(MAKE) -C timer/ clean
	rm -f main.o

clean: clean_objs
	rm -rf AlgoTowers
