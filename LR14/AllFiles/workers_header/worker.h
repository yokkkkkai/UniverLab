#ifndef WORKER_H
#define WORKER_H

#include <string>

class Worker {
protected:
	std::string name;
	unsigned int id;
	unsigned int salary;

public:
	Worker();
	Worker(const std::string& name, unsigned int id, unsigned int salary);

	std::string getName() const;
	unsigned int getId() const;
	unsigned int getSalary() const;

	void setSalary(unsigned int salary);
	void setName(const std::string& name);
	void setId(unsigned int id);

	virtual double calculateSalary() const;
	virtual void printSalary() const;
	virtual void printInfo() const;

	virtual ~Worker();
};

#endif // WORKER_H
