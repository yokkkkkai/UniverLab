#ifndef DIGITALMARKETER_H
#define DIGITALMARKETER_H

#include "Worker.h"

class DigitalMarketer : public Worker {
private:
	unsigned int ad_campaign_count;
	unsigned int bonus_coeff;

public:
	DigitalMarketer();
	DigitalMarketer(const std::string& name, unsigned int id, unsigned int salary);
	DigitalMarketer(const std::string& name,
		unsigned int id,
		unsigned int salary,
		unsigned int ad_campaign_count,
		unsigned int bonus_coeff);

	unsigned int getAdCampaignCount() const;
	unsigned int getBonusCoeff() const;

	void setAdCampaignCount(unsigned int count);
	void setBonusCoeff(unsigned int coeff);

	double calculateSalary() const override;
	void printInfo() const override;
};

#endif // DIGITALMARKETER_H