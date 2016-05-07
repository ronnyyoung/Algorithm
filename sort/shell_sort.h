#ifndef __ALGORITHM_SORT_SHELL_SORT_
#define __ALGORITHM_SORT_SHELL_SORT_

#include <vector>

namespace alg {

// T_{avg} = O(N^{7/6})
// T_{worst} = O(N^{4/3})
// unstable

template <typename T>
void ShellSort(std::vector<T> &array) {
	// formula: 9 * pow(4, i) - 9 * pow(2, i) + 1
	// or pow(4, i) - 3 * pow(2, i) + 1
	std::vector<int> sedgewick_sequence = {
		1073643521, 603906049, 268386305, 150958081, 67084289,
		37730305, 16764929, 9427969, 4188161, 2354689,
		1045505, 587521, 260609, 146305, 64769,
		36289, 16001, 8929, 3905, 2161, 929, 505,
		209, 109, 41, 19, 5, 1};
	int size = array.size();
	for (auto s : sedgewick_sequence) {
		if (s >= size) {
			continue;
		}
		for (int i = s; i < size; i += s) {
			T temp = array[i];
			int j;
			// insert temp into the sorted part.
			for (j = i - s; j >=0 && array[j] > temp; j -= s) {
				array[j + s] = array[j];
			}
			array[j + s] = temp;
		}
	}
}

} // namespace alg


#endif // __ALGORITHM_SORT_SHELL_SORT_
