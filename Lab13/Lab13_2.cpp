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

class compGreater { // �������� ���Ŀ� ���
public:
	compGreater(int threshold) : threshold_(threshold) {}
	bool operator()(int x) const {
		return x > threshold_;
	}
private:
	int threshold_;
};

class compLess { // �������� ���Ŀ� ���
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
	std::cout << "�������� ����" << std::endl;
	bubble_sort(values.begin(), values.end(), '>');
	// bubble sort ����Ͽ� �������� ���� �� ��� ���
	std::cout << std::endl;
	std::cout << "�������� ����" << std::endl;
	bubble_sort(values.begin(), values.end(), '<');
	// bubble sort ����Ͽ� �������� ���� �� ��� ���
	std::cout << std::endl;
	return 0;
}