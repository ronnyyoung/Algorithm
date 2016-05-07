#ifndef __ALGORITHM_SORT_INSERT_SORT_H
#define __ALGORITHM_SORT_INSERT_SORT_H

#include <vector>

namespace alg {

// best situation: O(N)
// worset situation: O(N^2)
// stable

template<typename T>
void InsertSort(std::vector<T> &array)  {
	int size = array.size();
	for (int i = 1; i < size; i++) {
		T temp = array[i];
		int j;
		// insert temp into the sorted part.
		for (j = i - 1; j >= 0 && array[j] > temp; j--) {
				array[j + 1] = array[j];
		}
		// now array[j] <= temp, so insert temp after j.
		array[j + 1] = temp;
	}
}

} //namespace alg

#endif // __ALGORITHM_SORT_INSERT_SORT_H
