#include <iostream>
#include "workers_all.h"

int main() {
    WorkerBase company;

    company.add(new Tester("John", 1, 3000, 20));
    company.add(new Programmer("Alice", 2, 5000, 3, 1.8, true));
    company.add(new DigitalMarketer("Bob", 3, 4000, 5, 500));

    company.printAllInfo();

    double totalSalary = company.calcTotalSalary();
    std::cout << "\nTotal Salary: " << totalSalary << "$\n";

    unsigned int searchId = 2;
    Worker* foundWorker = company.find(searchId);
    if (foundWorker) {
        std::cout << "\nFound worker with ID " << searchId << ":\n";
        foundWorker->printInfo();
    }
    else {
        std::cout << "\nWorker with ID " << searchId << " not found.\n";
    }

    unsigned int eraseId = 1;
    std::cout << "\nErasing worker with ID " << eraseId << ":\n";
    company.erase(eraseId);
    company.printAllInfo();

    return 0;
}
