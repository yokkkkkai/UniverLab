#ifndef TESTER_H
#define TESTER_H

#include "worker.h"

class Tester : public Worker {
private:
	unsigned int bugs_count;

public:
	Tester();
	Tester(const std::string& name, unsigned int id, unsigned int salary);
	Tester(const std::string& name,
		unsigned int id,
		unsigned int salary,
		unsigned int bugs_count);

	unsigned int getBugsCount() const;
	void setBugsCount(unsigned int bugs_count);

	double calculateSalary() const override;
	void printInfo() const override;
};

#endif // TESTER_H
