#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

#include "sort.h"

int main(int argc, char *argv[]) {

	using namespace std::chrono;

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,2000);
	std::vector<int> list;

	int totle = 100000000;
	for (int i = 0; i < totle; i++) {
		list.push_back(distribution(generator));
	}

	steady_clock::time_point t1 = steady_clock::now();
	//alg::HeapSort(list);
	std::sort(list.begin(), list.end());
	steady_clock::time_point t2 = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	std::cout << "Time: " << time_span.count() << std::endl;

#if 0
	for (int i = 0; i < static_cast<int>(list.size()); i++) {
		std::cout << list[i] << ",";
		if (i % 100 == 0) {
			std::cout << std::endl;
		}
	}
#endif

	return 0;
}
