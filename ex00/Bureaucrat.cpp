#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("no name"), _grade(150) {

}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade) {

}

Bureaucrat::Bureaucrat(const Bureaucrat &source): _name(source._name), _grade(source._grade) {
	*this = source;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source) {
	if (this != &source) {
		this->_grade = source._grade;
	}

}

const std::string &Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}


Bureaucrat::~Bureaucrat() {

}