#include <iostream>

template <typename T>
auto sum(T x) {
	return x;
}

template <typename T, typename... Args>
auto sum(T x, Args...args) {
	return x + sum(args...); // 재귀적으로 뒤에서 부터 더한다.
}

template <typename... Args>
auto average(Args...args) {
	// numArgs 인자의 개수, x 인자의 합
	int numArgs = sizeof...(args);
	auto x = sum(args...);
	return x / numArgs;
	// average함수로 인자들을 받으면 size와 sum값을 구해서 sum/size 즉 평균을 return한다.
} 

int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl;
	return 0;
}
