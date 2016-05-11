According to Wikipedia:

**Insertion sort** iterates, consuming one input element each repetition, and
growing a sorted output list. Each iteration, insertion sort removes one
element from the input data, finds the location it belongs within the sorted
list, and inserts it there. It repeats until no input elements remain.

**Merge sort** works as follows: Divide the unsorted list into N sublists, each
containing 1 element (a list of 1 element is considered sorted). Then
repeatedly merge two adjacent sublists to produce new sorted sublists until
there is only 1 sublist remaining.

Now given the initial sequence of integers, together with a sequence which is a
result of several iterations of some sorting method, can you tell which sorting
method we are using?

**Input Specification:**

Each input file contains one test case. For each case, the first line gives a
positive integer N (<= 100). Then in the next line, N integers are given
as the initial sequence. The last line contains the partially sorted sequence
of the N numbers. It is assumed that the target sequence is always ascending.
All the numbers in a line are separated by a space.

**Output Specification:**

For each test case, print in the first line either "Insertion Sort" or "Merge
Sort" to indicate the method used to obtain the partial result. Then run this
method for one more iteration and output in the second line the resuling
sequence. It is guaranteed that the answer is unique for each test case. All
the numbers in a line must be separated by a space, and there must be no extra
space at the end of the line.

**Sample Input 1:**
```
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
```
**Sample Output 1:**
```
Insertion Sort
1 2 3 5 7 8 9 4 6 0
```
**Sample Input2:**
```
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
```
**Sample Output 2:**
```
Merge Sort
1 2 3 8 4 5 7 9 0 6
```

**Solution**

``` c++
#include <iostream>
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

void Print(std::vector<int> &array) {
	int size = array.size();
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			std::cout << array[i];
		} else {
			std::cout << " " << array[i];
		}
	}
	std::cout << std::endl;
}

int main (int argc, char *argv[]) {
	int N = 0;
	std::cin >> N;
	std::vector<int> input(N, 0);
	std::vector<int> sorted(N, 0);
	for (int i = 0; i <  N; i++) {
		std::cin >> input[i];
	}
	for (int i = 0; i <  N; i++) {
		std::cin >> sorted[i];
	}

	std::vector<int> temp(input);
	std::vector<int> origin = input;
	bool print = false;
	for (int i = 1; i < N; i *= 2) {
		if (input == sorted) {
			std::cout << "Merge Sort" << std::endl;
			print = true;
		}
		for (int k = 0; k <= N / (2 * i); k++) {
			merge (input, temp, k * 2 * i, i);
		}
		if (print)	{Print(input); break;}
	}
	print = false;
	input = origin;

	for (int i = 1; i < N; i++) {
		if (input == sorted) {
			std::cout << "Insertion Sort" << std::endl;
			print = true;
		}
		int temp = input[i];
		int j;
		// insert temp into the sorted part.
		for (j = i - 1; j >= 0 && input[j] > temp; j--) {
			input[j + 1] = input[j];
		}
		// now array[j] <= temp, so insert temp after j.
		input[j + 1] = temp;
		if (print) {Print(input); break;}
	}

	return 0;
}
```
