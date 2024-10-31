#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("no name"), _grade(150) {

}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &source): _name(source._name), _grade(source._grade) {
	*this = source;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source) {
	if (this != &source) {
		this->_grade = source._grade;
	}
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

Bureaucrat::~Bureaucrat() {

}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}