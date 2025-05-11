#ifndef WORKERS_H
#define WORKERS_H

#include <string>
#include <iostream>

class Worker {
protected:
	std::string name;
	unsigned int id;
	unsigned int salary;

public:
	Worker()
		: name(""), id(0), salary(0) {
	}

	Worker(
		const std::string& name,
		unsigned int id,
		unsigned int salary
	) {
		this->name = name;
		this->id = id;
		this->salary = salary;
	}

	std::string getName() const { return name; }
	unsigned int getId() const { return id; }
	unsigned int getSalary() const { return salary; }

	void setSalary(unsigned int salary) { this->salary = salary; }
	void setName(const std::string& name) { this->name = name; }
	void setId(unsigned int id) { this->id = id; }

	virtual double calculateSalary() const { return salary; }

	virtual void printSalary() const {
		std::cout << calculateSalary() << '$' << std::endl;
	}

	virtual void printInfo() const {
		std::cout << "Worker Info:\n"
			<< "Name: " << name << '\n'
			<< "ID: " << id << '\n'
			<< "Salary: " << calculateSalary() << "$\n";
	}

	virtual ~Worker() {}
};

class Tester : public Worker {
private:
	unsigned int bugs_count;

public:
	Tester()
		: Worker(), bugs_count(0) {
	}

	Tester(
		const std::string& name,
		unsigned int id,
		unsigned int salary,
		unsigned int bugs_count
	)
		: Worker(name, id, salary)
	{
		this->bugs_count = bugs_count;
	}

	unsigned int getBugsCount() const { return bugs_count; }
	void setBugsCount(unsigned int bugs_count) { this->bugs_count = bugs_count; }

	double calculateSalary() const override {
		return salary + salary * 0.01 * bugs_count;
	}

	void printInfo() const override {
		std::cout << "Tester Info:\n"
			<< "Name: " << name << '\n'
			<< "ID: " << id << '\n'
			<< "Base Salary: " << salary << "$\n"
			<< "Bugs Found: " << bugs_count << '\n'
			<< "Final Salary: " << calculateSalary() << "$\n";
	}
};

// DigitalMarketer
class DigitalMarketer : public Worker {
private:
	unsigned int ad_campaign_count;
	unsigned int bonus_coeff;

public:
	DigitalMarketer()
		: Worker(), ad_campaign_count(0), bonus_coeff(0) {
	}

	DigitalMarketer(
		const std::string& name,
		unsigned int id,
		unsigned int salary,
		unsigned int ad_campaign_count,
		unsigned int bonus_coeff
	)
		: Worker(name, id, salary)
	{
		this->ad_campaign_count = ad_campaign_count;
		this->bonus_coeff = bonus_coeff;
	}

	unsigned int getAdCampaignCount() const { return ad_campaign_count; }
	unsigned int getBonusCoeff() const { return bonus_coeff; }

	void setAdCampaignCount(unsigned int count) { ad_campaign_count = count; }
	void setBonusCoeff(unsigned int coeff) { bonus_coeff = coeff; }

	double calculateSalary() const override {
		return salary + ad_campaign_count * bonus_coeff;
	}

	void printInfo() const override {
		std::cout << "Digital Marketer Info:\n"
			<< "Name: " << name << '\n'
			<< "ID: " << id << '\n'
			<< "Base Salary: " << salary << "$\n"
			<< "Campaigns: " << ad_campaign_count << '\n'
			<< "Bonus Coeff: " << bonus_coeff << '\n'
			<< "Final Salary: " << calculateSalary() << "$\n";
	}
};

class Programmer : public Worker {
private:
	unsigned int experience;
	double qualification; // 1.0 - 2.0
	bool is_bonus;
	const unsigned int sum_bonus = 3000;

public:
	Programmer()
		: Worker(), experience(0), qualification(1.0), is_bonus(false) {
	}

	Programmer(
		const std::string& name,
		unsigned int id,
		unsigned int salary,
		unsigned int experience,
		double qualification,
		bool is_bonus
	)
		: Worker(name, id, salary)
	{
		this->experience = experience;
		this->is_bonus = is_bonus;

		if (qualification >= 1.0 && qualification <= 2.0) {
			this->qualification = qualification;
		}
		else {
			this->qualification = 1.0;
			std::cerr << "Qualification must be between 1.0 and 2.0. Set to default (1.0).\n";
		}
	}

	unsigned int getExperience() const { return experience; }
	double getQualification() const { return qualification; }
	bool getIsBonus() const { return is_bonus; }

	void setExperience(unsigned int exp) { experience = exp; }

	void setQualification(double qual) {
		if (qual >= 1.0 && qual <= 2.0) {
			qualification = qual;
		}
		else {
			std::cerr << "Qualification must be between 1.0 and 2.0\n";
		}
	}

	void setIsBonus(bool bonus) { is_bonus = bonus; }

	double calculateSalary() const override {
		double total_salary = salary + qualification * 1000;
		if (is_bonus) {
			total_salary += sum_bonus;
		}
		return total_salary;
	}

	void printInfo() const override {
		std::cout << "Programmer Info:\n"
			<< "Name: " << name << '\n'
			<< "ID: " << id << '\n'
			<< "Base Salary: " << salary << "$\n"
			<< "Experience: " << experience << " years\n"
			<< "Qualification: " << qualification << '\n'
			<< "Has Bonus: " << (is_bonus ? "Yes" : "No") << '\n'
			<< "Final Salary: " << calculateSalary() << "$\n";
	}
};

#endif // WORKERS_H
