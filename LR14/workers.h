#ifndef WORKERS_H
#define WORKERS_H

#include <string>

class Worker {
protected:
	std::string name;
	unsigned int id;
	unsigned int salary;

public:
	Worker() : name(""), id(0) {}
	
	Worker(const std::string& name, unsigned int id) {
		this->name = name;
		this->id = id;
	}

	std::string getName() const {
		return name;
	}

	unsigned int getId() const {
		return id;
	}

	unsigned int getSalary() const {
		return salary;
	}

	void setSalary(const unsigned int salary) {
		this->salary = salary;
	}

	void setName(const std::string& name) {
		this->name = name;
	}

	void setId(unsigned int id) {
		this->id = id;
	}

	virtual double calculateSalary() const { return salary; }

	virtual void printSalary() const {
		double total_salary = calculateSalary();
		std::cout << total_salary << '$' << std::endl;
	}
};

class Tester : public Worker {
private:
	int bugs_count;

public:
	Tester() : Worker() {}

	Tester(const std::string& name, unsigned int id) : Worker(name, id) {}

	unsigned int getBugsCount() {
		return bugs_count;
	}

	void setBugsCount(const unsigned int bugs_count) {
		this->bugs_count = bugs_count;
	}

	double calculateSalary() const override {
		return salary + salary * 0.01 * bugs_count;
	}
};

class DigitalMarketer : public Worker {
private:
	unsigned int ad_campaign_count;
	unsigned int bonus_coeff;

public:
	DigitalMarketer() : Worker() {}
	
	DigitalMarketer(const std::string& name, unsigned int id) {
		this->name = name;
		this->id = id;
	}

	unsigned int getAdCampaignCount() const {
		return ad_campaign_count;
	}

	unsigned int getBonusCoeff() const {
		return bonus_coeff;
	}

	void setAdCampaignCount(unsigned int count) {
		ad_campaign_count = count;
	}

	void setBonusCoeff(unsigned int coeff) {
		bonus_coeff = coeff;
	}

	double calculateSalary() const override {
		return salary + ad_campaign_count * bonus_coeff;
	}
};

class Programmer : public Worker {
private:
	unsigned int experience;
	double qualification;
	bool is_bonus;
	const unsigned int sum_bonus = 3000;

public:
	unsigned int getExperience() const {
		return experience;
	}

	double getQualification() const {
		return qualification;
	}

	bool getIsBonus() const {
		return is_bonus;
	}

	void setExperience(unsigned int exp) {
		experience = exp;
	}

	void setQualification(double qual) {
		if (qual >= 1.0 && qual <= 2.0) {
			qualification = qual;
		}
		else {
			std::cerr << "Qualification must be between 1.0 and 2.0" << std::endl;
			return;
		}
	}

	void setIsBonus(bool bonus) {
		is_bonus = bonus;
	}

	double calculateSalary() const override{
		double total_salary = salary + qualification * 1000;
		total_salary = (is_bonus) ? (total_salary + sum_bonus) : total_salary;

		return total_salary;
	}

};

#endif //WORKERS_H
