#include "D:\UniverC++\LR14\worker.h"
#include <string>
#include <iostream>

Worker::Worker() : name(""), id(0), salary(0) {}

Worker::Worker(const std::string& name, unsigned int id, unsigned int salary) {
	this->name = name;
	this->id = id;
	this->salary = salary;
}

std::string Worker::getName() const { return name; }
unsigned int Worker::getId() const { return id; }
unsigned int Worker::getSalary() const { return salary; }

void Worker::setSalary(unsigned int salary) { this->salary = salary; }
void Worker::setName(const std::string& name) { this->name = name; }
void Worker::setId(unsigned int id) { this->id = id; }

double Worker::calculateSalary() const { return salary; }

void Worker::printSalary() const {
	std::cout << calculateSalary() << "$" << std::endl;
}

void Worker::printInfo() const {
	std::cout << "Worker Info:\n"
		<< "Name: " << name << '\n'
		<< "ID: " << id << '\n'
		<< "Salary: " << calculateSalary() << "$\n";
}

Worker::~Worker() {}
