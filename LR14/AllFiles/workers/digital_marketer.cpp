#include "digital_marketer.h"
#include <iostream>
#include <string>

DigitalMarketer::DigitalMarketer()
	: Worker(), ad_campaign_count(0), bonus_coeff(0) {
}

DigitalMarketer::DigitalMarketer(const std::string& name, unsigned int id, unsigned int salary) : Worker(name, id, salary) {}

DigitalMarketer::DigitalMarketer(
	const std::string& name,
	unsigned int id,
	unsigned int salary,
	unsigned int ad_campaign_count,
	unsigned int bonus_coeff)

	: Worker(name, id, salary)
{
	this->ad_campaign_count = ad_campaign_count;
	this->bonus_coeff = bonus_coeff;
}

unsigned int DigitalMarketer::getAdCampaignCount() const { return ad_campaign_count; }
unsigned int DigitalMarketer::getBonusCoeff() const { return bonus_coeff; }

void DigitalMarketer::setAdCampaignCount(unsigned int count) { ad_campaign_count = count; }
void DigitalMarketer::setBonusCoeff(unsigned int coeff) { bonus_coeff = coeff; }

double DigitalMarketer::calculateSalary() const {
	return salary + ad_campaign_count * bonus_coeff;
}

void DigitalMarketer::printInfo() const {
	std::cout << "Digital Marketer Info:\n"
		<< "Name: " << name << '\n'
		<< "ID: " << id << '\n'
		<< "Base Salary: " << salary << "$\n"
		<< "Campaigns: " << ad_campaign_count << '\n'
		<< "Bonus Coeff: " << bonus_coeff << '\n'
		<< "Final Salary: " << calculateSalary() << "$\n";
}
