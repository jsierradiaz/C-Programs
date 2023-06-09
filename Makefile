# Juan Sierra Diaz
all: arrays tests

arrays: search_sorting_arrays.cpp
	g++ search_sorting_arrays.cpp -Wall -o ArrayOps

tests: test_scores.cpp
	g++ test_scores.cpp -Wall -o Tests	



