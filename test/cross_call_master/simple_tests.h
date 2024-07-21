#pragma once
#include <functional>
#include <string>
#include <vector>
#include <memory>

class SimpleTests {
public:
	class Test {
		friend SimpleTests;

	public:
		void Fail(std::string error);

		const std::string& GetName() const;
		bool IsFailed() const;
		const std::vector<std::string>& GetErrors() const;

	private:
		Test(std::string name, std::function<void(Test&)> func);
		void Run();

	private:
		std::string _name;
		std::function<void(Test&)> _func;
		std::vector<std::string> _errors;
	};

public:
	void Add(std::string name, std::function<void(Test&)> func);
	void Run();
	void Reset();

private:
	std::vector<std::unique_ptr<Test>> _tests;
};
