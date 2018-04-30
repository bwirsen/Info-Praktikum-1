#include <iostream>
#include "Student.h"
/**
 * @brief constructor which hase to be filled at least with the matNr
 * @param matNr
 * @param name
 * @param dateOfBirth
 * @param address
 */
Student::Student(unsigned int matNr, std::string name, std::string dateOfBirth,
		std::string address) :
		matNr(matNr), name(name), dateOfBirth(dateOfBirth), address(address)
{
}

/**
 * @brief empty constructor
 */
Student::Student() :
		matNr(0), name(""), dateOfBirth(""), address("")
{
}
/**
 * @brief gets propties of the given class element
 * @return matNr
 */
unsigned int Student::getMatNr() const
{
	return this->matNr;
}

/**
 * @brief gets propties of the given class element
 * @return name
 */
std::string Student::getName() const
{
	return this->name;
}

/**
 * @brief gets propties of the given class element
 * @return date of birth
 */
std::string Student::getDateOfBirth() const
{
	return this->dateOfBirth;
}
/**
 * @brief gets propties of the given class element
 * @return address
 */

std::string Student::getAddress() const
{
	return this->address;
}

/**
 * @brief Class-function to print the class-elements
 * @param out: reference of std::cout
 * @return out
 */
std::ostream& Student::print(std::ostream& out) const
{
	out << name << ", MatNr. " << matNr
			<< " geb. am " << dateOfBirth << " wohnhaft in "
			<< address;

	return out;
}


/**
 * @brief overloading of ==-operator to compare matNr of objects of the class student
 * @param student
 * @return true if "Matrikel-Nummern" are the same, false if not
 */
bool Student::operator ==(const Student& student) const
{

	if (this->matNr == student.matNr)
		return true;

	else
		return false;
}
/**
 * @brief overloading of <-operator to compare matNr of objects of the class student
 * @param student
 * @return true if matNr from student 1 < the one of student 2, false if not
 */
bool Student::operator <(const Student& student) const
{

	if (this->matNr < student.matNr)
		return true;

	else
		return false;

}
/**
 * @brief overloading of >-operator to compare matNr of objects of the class student
 * @param student
 * @return true if matNr from student 1 > the one of student 2, false if not
 */
bool Student::operator >(const Student& student) const
{
	if(this->matNr > student.matNr)
		return true;

	else
		return false;
}
