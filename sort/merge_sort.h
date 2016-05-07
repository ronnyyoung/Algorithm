#ifndef __ALGORITHM_SORT_MERGE_SORT_H
#define __ALGORITHM_SORT_MERGE_SORT_H

namespace alg {

#include <vector>

template <typename T>
void merge (std::vector<T> &array, std::vector<T> &temp, int start, int len) {
	int size = array.size();
	int i = start, j = start + len; 
	int k = start;
	int end_pos1 = std::min(size, start + len);
	int end_pos2 = std::min(size, start + 2 * len);

	while (i < end_pos1 && j < end_pos2) {
		if (array[i] < array[j]) {
			temp[k++] = array[i++];
		} else {
			temp[k++] = array[j++];
		}
	}
	while (i < end_pos1) {
		temp[k++] = array[i++];
	}
	while (j < end_pos2) {
		temp[k++] = array[j++];
	}
	for (int i = start; i < end_pos2; i++) {
		array[i] = temp[i];
	}
}

template <typename T>
void MergeSort (std::vector<T> &array) {
	int size = array.size();
	std::vector<T> temp(array);
	for (int i = 1;  i < size; i = i * 2) {
		for (int k = 0; k <= size / (2 * i); k++) {
			merge(array, temp, k * 2 * i, i);
		}
	}
}


} // namespace alg

#endif // __ALGORITHM_SORT_MERGE_SORT_H
