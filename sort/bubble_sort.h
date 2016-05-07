#ifndef __ALGORITHM_SORT_BUBBLE_SORT_H
#define __ALGORITHM_SORT_BUBBLE_SORT_H

#include <vector>

namespace alg {

// best situation: T = O(N)
// worest situation: T = O(N^2),
// element are in order from big to small, swapping in every loop.
// stable

template<typename T>
void BubbleSort (std::vector<T> &array) {
	int size = array.size();
	bool sorted = false;

	for (int i = size - 1; i >= 0; i--) {
		// the element whose index greater than i are in order.
		for (int j = 0; j < i; j++) {
			if (array[j] > array[j + 1]) {
				std::swap(array[j], array[j + 1]);
				sorted = true;
			}
		}
		// if there is no element swapped in this loop,
		// the array must be in order, stop the loop.
		if (!sorted) {
			break;
		}
	}
}

} // namespace alg


#endif // __ALGORITHM_SORT_BUBBLE_SORT_H
