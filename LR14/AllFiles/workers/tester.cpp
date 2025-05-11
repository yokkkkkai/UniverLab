#include "tester.h"
#include <iostream>
#include <string>

Tester::Tester() : Worker(), bugs_count(0) {}

Tester::Tester(const std::string& name, unsigned int id, unsigned int salary) : Worker(name, id, salary) {}

Tester::Tester(const std::string& name, unsigned int id, unsigned int salary, unsigned int bugs_count)
	: Worker(name, id, salary)
{
	this->bugs_count = bugs_count;
}

unsigned int Tester::getBugsCount() const { return bugs_count; }

void Tester::setBugsCount(unsigned int bugs_count) { this->bugs_count = bugs_count; }

double Tester::calculateSalary() const {
	return salary + salary * 0.01 * bugs_count;
}

void Tester::printInfo() const {
	std::cout << "Tester Info:\n"
		<< "Name: " << name << '\n'
		<< "ID: " << id << '\n'
		<< "Base Salary: " << salary << "$\n"
		<< "Bugs Found: " << bugs_count << '\n'
		<< "Final Salary: " << calculateSalary() << "$\n";
}