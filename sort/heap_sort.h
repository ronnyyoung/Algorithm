#ifndef __ALGORITHM_SORT_HEAP_SORT_H
#define __ALGORITHM_SORT_HEAP_SORT_H

#include <vector>
#include <queue>

namespace alg {

template <typename T>
void HeapSort(std::vector<T> &array) {
	std::priority_queue<T> heap(array.begin(), array.end());
	int size = array.size();
	for (int i = size - 1; i >= 0; i--) {
		array[i] = heap.top();
		heap.pop();
	}
}

} // namespace alg

#endif // __ALGORITHM_SORT_HEAP_SORT_H
