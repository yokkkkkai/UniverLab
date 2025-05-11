#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include "Worker.h"

class Programmer : public Worker {
private:
	unsigned int experience;
	double qualification;
	bool is_bonus;
	const unsigned int sum_bonus = 3000;

public:
	Programmer();
	Programmer(const std::string& name, unsigned int id, unsigned int salary);
	Programmer(const std::string& name,
		unsigned int id,
		unsigned int salary,
		unsigned int experience,
		double qualification,
		bool is_bonus);

	unsigned int getExperience() const;
	double getQualification() const;
	bool getIsBonus() const;

	void setExperience(unsigned int exp);
	void setQualification(double qual);
	void setIsBonus(bool bonus);

	double calculateSalary() const override;
	void printInfo() const override;
};

#endif // PROGRAMMER_H