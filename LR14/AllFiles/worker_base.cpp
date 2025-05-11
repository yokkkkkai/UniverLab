#include "worker_base.h"

void WorkerBase::add(Worker* worker) {
    workers.append(worker);
}

void WorkerBase::erase(unsigned int id) {
    for (size_t i = 0; i < workers.get_size(); i++) {
        if (workers[i]->getId() == id) {
            workers.remove(workers[i]);
            return;
        }
    }
    std::cerr << "Worker with ID " << id << " not found." << std::endl;
}

Worker* WorkerBase::find(unsigned int id) {
    for (size_t i = 0; i < workers.get_size(); i++) {
        if (workers[i]->getId() == id) {
            return workers[i];
        }
    }
    std::cerr << "Worker with ID " << id << " not found!" << std::endl;
    return nullptr;
}

double WorkerBase::calcTotalSalary() {
    double totalSalary = 0;
    for (size_t i = 0; i < workers.get_size(); ++i) {
        totalSalary += workers[i]->calculateSalary();
    }
    return totalSalary;
}

void WorkerBase::printAllInfo() {
    for (size_t i = 0; i < workers.get_size(); ++i) {
        workers[i]->printInfo();
    }
}

WorkerBase::~WorkerBase() {
    for (size_t i = 0; i < workers.get_size(); ++i) {
        delete workers[i];
    }
}
