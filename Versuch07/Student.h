#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>

class Student
{
public:
	Student();
	Student(unsigned int matNr, std::string name = "", std::string dateOfBirth = "", std::string address = "");

	//overloading needed operators
	bool operator == (const Student& student) const;
	bool operator < (const Student& student) const;
	bool operator > (const Student& student) const;

	//matching global overloading can be found in main.cpp -- just the class related print function
	std::ostream& print(std::ostream& out) const;

	unsigned int getMatNr() const;
	std::string getName() const;
	std::string getDateOfBirth() const;
	std::string getAddress() const;


private:
    unsigned int matNr;
    std::string name;
    std::string dateOfBirth;
    std::string address;


};

#endif
