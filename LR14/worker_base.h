#ifndef WORKER_BASE_H
#define WORKER_BASE_H

#include "list.h"
#include "worker.h"

class WorkerBase {
private:
	List<Worker*> workers;
public:
	void add(Worker* worker) {
		workers.append(worker);
	}

	~WorkerBase() {
		for (size_t i = 0; i < workers.get_size(); i++) {
			delete workers[i];
		}
	}

	void erase(unsigned int id) {
		for(size_t i = 0; i < workers.get_size(); i++) {
			if (workers[i]->getId() == id) {
				workers.remove(workers[id]);
				return;
			}
		}
		std::cerr << "Worker with ID" << id << " not found." << std::endl;
	}

	Worker* find(unsigned int id) {
		for (size_t i = 0; i < workers.get_size(); i++) {
			if (workers[i]->getId() == id) {
				return workers[i];
			}
		}
		std::cerr << "Worker with ID " << id << " not found!" << std::endl;
		return nullptr;
	}

	double calcTotalSalary() {
		double totalSalary = 0;
		for (size_t i = 0; i < workers.get_size(); ++i) {
			totalSalary += workers[i]->calculateSalary();
		}
		return totalSalary;
	}

	void printAllInfo() {
		for (size_t i = 0; i < workers.get_size(); ++i) {
			workers[i]->printInfo();
		}
	}
};

#endif //WORKER_BASE_H
