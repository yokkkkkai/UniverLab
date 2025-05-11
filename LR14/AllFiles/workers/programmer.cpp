#include "programmer.h"
#include <iostream>
#include <string>

Programmer::Programmer()
	: Worker(), experience(0), qualification(1.0), is_bonus(false) {
}

Programmer::Programmer(const std::string& name, unsigned int id, unsigned int salary) : Worker(name, id, salary) {}

Programmer::Programmer(const std::string& name,
	unsigned int id,
	unsigned int salary,
	unsigned int experience,
	double qualification,
	bool is_bonus)
	: Worker(name, id, salary)
{
	this->experience = experience;
	this->is_bonus = is_bonus;

	if (qualification >= 1.0 && qualification <= 2.0) {
		this->qualification = qualification;
	}
	else {
		this->qualification = 1.0;
		std::cerr << "Qualification must be between 1.0 and 2.0. Set to 1.0.\n";
	}
}

unsigned int Programmer::getExperience() const { return experience; }
double Programmer::getQualification() const { return qualification; }
bool Programmer::getIsBonus() const { return is_bonus; }

void Programmer::setExperience(unsigned int exp) { experience = exp; }

void Programmer::setQualification(double qual) {
	if (qual >= 1.0 && qual <= 2.0) {
		qualification = qual;
	}
	else {
		std::cerr << "Qualification must be between 1.0 and 2.0\n";
	}
}

void Programmer::setIsBonus(bool bonus) { is_bonus = bonus; }

double Programmer::calculateSalary() const {
	double total = salary + qualification * 1000;
	if (is_bonus) total += sum_bonus;
	return total;
}

void Programmer::printInfo() const {
	std::cout << "Programmer Info:\n"
		<< "Name: " << name << '\n'
		<< "ID: " << id << '\n'
		<< "Base Salary: " << salary << "$\n"
		<< "Experience: " << experience << " years\n"
		<< "Qualification: " << qualification << '\n'
		<< "Has Bonus: " << (is_bonus ? "Yes" : "No") << '\n'
		<< "Final Salary: " << calculateSalary() << "$\n";
}
