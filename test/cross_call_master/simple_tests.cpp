#include "simple_tests.h"
#include <format>
#include <iostream>
#include <numeric>

void SimpleTests::Test::Fail(std::string error) {
	_errors.push_back(std::move(error));
}

const std::string& SimpleTests::Test::GetName() const {
	return _name;
}

bool SimpleTests::Test::IsFailed() const {
	return !_errors.empty();
}

const std::vector<std::string>& SimpleTests::Test::GetErrors() const {
	return _errors;
}

SimpleTests::Test::Test(std::string name, std::function<void(Test&)> func) : _name(std::move(name)), _func(std::move(func)) {
}

void SimpleTests::Test::Run() {
	_errors.clear();
	_func(*this);
}

void SimpleTests::Add(std::string name, std::function<void(Test&)> func) {
	_tests.push_back(std::unique_ptr<Test>(new Test(std::move(name), std::move(func))));
}

void SimpleTests::Run() {
	const size_t count = _tests.size();
	const auto count_len = std::to_string(count).length();
	const std::string number_template = std::format("[{{:0{}d}}/{{}}]", count_len);
	const auto name_max_length = std::accumulate(_tests.begin(), _tests.end(), size_t{0}, [](size_t prev_max, const std::unique_ptr<Test>& next) {
		const auto next_length = next->GetName().length();
		return next_length > prev_max ? next_length : prev_max;
	});
	const std::string name_template = std::format("{{:{}s}}", name_max_length);

	size_t success = 0, failed = 0;

	for (size_t i = 0; i < count; ++i) {
		Test& test = *(_tests[i].get());
		const auto n = i + 1;
		const auto number = std::vformat(number_template, std::make_format_args(n, count));
		const auto name = test.GetName();
		const auto formatted_name = std::vformat(name_template, std::make_format_args(name));
		std::cout << std::format("{} {}    ", number, formatted_name) << std::flush;
		test.Run();
		if (test.IsFailed()) {
			++failed;
			std::cerr << "Failed\n";
			for (const auto& error : test.GetErrors()) {
				std::cerr << "    " << error << "\n";
			}
			std::cerr << std::flush;
		} else {
			++success;
			std::cout << "Success" << std::endl;
		}
	}
	
	std::cout << std::format("Tests finished: {} success, {} failed, {} total", success, failed, count) << std::endl;
}

void SimpleTests::Reset() {
    _tests.clear();
}
