#ifndef __ALGORITHM_SORT_QUICK_SORT_H
#define __ALGORITHM_SORT_QUICK_SORT_H

#include <vector>

namespace alg {

template <typename T>
T med3(const std::vector<T> &array, int start, int end) {
	int mid = (start + end) / 2;
	if (array[start] > array[mid]) {
		std::swap(array[start], array[mid]);
	}
	if (array[start] > array[end]) {
		std::swap(array[start], array[end]);
	}
	if (array[mid] > array[end]) {
		std::swap(array[mid], array[end]);
	}
	std::swap(array[mid], array[end - 1]);
	return array[end - 1];
}

template <typename T>
void QuickSort(std::vector<T> &array, int start, int end) {
	const int cutoff = 1000;
	if (end - start < 1000) {
		InsertSort(array, start, end);
		return;
	}
	int privot = med3(array, start, end);
	int i = start;
	int j = end - 1;
	while (true) {
		while (array[++i] < privot) { }
		while (array[++j] > privot) { }
		if ( j <= i) {
			break;
		}
		std::swap(array[i++], array[j--]);
	}
	std::swap(array[i], array[end - 1]);
	QuickSort(array, start, i - 1);
	QuickSort(array, i + 1, end);
}

template <typename T>
void QuickSort(std::vector<T> &array) {
	int size = array.size();
	QuickSort(array, 0, size - 1); 
}

}

#endif // __ALGORITHM_SORT_QUICK_SORT_H
