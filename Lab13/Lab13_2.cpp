#include <iostream>
#include <algorithm>
#include <forward_list>
template <typename ForwardIterator, typename Compare>

void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	// tempFirst 비교할 앞의 원소, tempSecond 비교할 뒤의 원소, num 리스트의 길이
	auto tempFirst = first;
	auto tempSecond = first;
	int size = 0;
	
	// list의 길이를 측정한다.
	while (tempFirst != last) {
		size++;
		tempFirst++;
	}
	// 첫 비교를 num-1회 하므로 1을 뺐다.
	size--;

	for (int i = 0; i < size; i++) {
		tempFirst = first;
		tempSecond = first;
		tempSecond++;
		for (int j = 0; j < size - i; j++) {
			int x = *tempFirst, y = *tempSecond;
			// comp가 오름차순일 경우 앞의 숫자가 커서, 내림차순일 경우 앞의 숫자가 작아서
			// true가 return되고, true일 경우 iterator들을 swap 시켜준다.
			if (comp(x, y)) {
				std::iter_swap(tempFirst, tempSecond);
			}
			tempFirst++;
			tempSecond++;
		}
	}
}

class CompGreater { 
// 앞의 인자가 크면 true, 작으면 false를 return한다.
// 오름차순 정렬을 할 때 사용한다.
public:
	bool operator()(int x, int y) {
		return x > y;
	}

};

class CompLess { 
// 앞의 인자가 작으면 true, 크면 false를 return한다.
// 내림차순 정렬을 할 때 사용한다.
public:
	bool operator()(int x, int y) {
		return x < y;
	}
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };
	
	std::cout << "오름차순 정렬" << std::endl;
	CompGreater compGreater;
	// bubble sort를 사용하여 오름차순 정렬을 실행한다.
	bubble_sort(values.begin(), values.end(), compGreater);
	//정렬된 리스트를 출력한다.
	for (auto it = values.begin(); it != values.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	std::cout << "내림차순 정렬" << std::endl;
	CompLess compLess;
	// bubble sort를 사용하여 내림차순 정렬을 실행한다.
	bubble_sort(values.begin(), values.end(), compLess);
	// 정렬된 리스트를 출력한다.
	for (auto it = values.begin(); it != values.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}
