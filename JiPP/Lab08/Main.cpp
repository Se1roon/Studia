#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <optional>
#include <tuple>


constexpr int factorial(int n) {
	return (n <= 1) ? 1 : n * factorial(n - 1);
}

std::optional<int> get_max(std::vector<int> &numbers) {
	if (numbers.size() == 0)
		return std::nullopt;

	auto max = std::max_element(numbers.begin(), numbers.end());
	return *max;
}

int main() {
	std::shared_ptr<std::vector<int>> numbers { new std::vector<int> {3, 5, 2, 12, 0} };
	
	for (int n : *numbers) {
		std::tuple<int, int> f(n, factorial(n));
		std::cout << std::get<0>(f) << "! = " << std::get<1>(f) << '\n';
	}

	int odd = 0;
	int even = 0;

	std::for_each(numbers->begin(), numbers->end(), [&odd, &even] (int n) {
		if (n % 2 == 0) even++;
		else odd++;
	});

	std::cout << "Parzystych: " << even << "\nNieparzystych: " << odd << '\n';

	auto max = get_max(*numbers);
	if (max)
		std::cout << "Max = " << *max << '\n';
	else
		std::cout << "Empty List\n";
}

