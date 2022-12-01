#include <iostream>
#include <algorithm>
#include <forward_list>
template <typename ForwardIterator, typename Compare>

void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	if (comp == '<') {
		while (last == first) {
			if(*)
			last--;
		}
	}
}

class compGreater { // 오름차순 정렬에 사용
public:
	compGreater(int threshold) : threshold_(threshold) {}
	bool operator()(int x) const {
		return x > threshold_;
	}
private:
	int threshold_;
};

class compLess { // 내림차순 정렬에 사용
public:
	compLess(int threshold) : threshold_(threshold) {}
	bool operator()(int x) const {
		return x < threshold_;
	}
private:
	int threshold_;
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };
	std::cout << "오름차순 정렬" << std::endl;
	bubble_sort(values.begin(), values.end(), '>');
	// bubble sort 사용하여 오름차순 정렬 후 결과 출력
	std::cout << std::endl;
	std::cout << "내림차순 정렬" << std::endl;
	bubble_sort(values.begin(), values.end(), '<');
	// bubble sort 사용하여 내림차순 정렬 후 결과 출력
	std::cout << std::endl;
	return 0;
}