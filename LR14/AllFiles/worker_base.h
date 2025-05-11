#ifndef WORKER_BASE_H
#define WORKER_BASE_H

#include "list.h"
#include "worker.h"
#include <iostream>

class WorkerBase {
private:
    List<Worker*> workers;

public:
    void add(Worker* worker);
    void erase(unsigned int id);
    Worker* find(unsigned int id);
    double calcTotalSalary();
    void printAllInfo();
    ~WorkerBase();
};

#endif // WORKER_BASE_H
