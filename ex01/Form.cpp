#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &source) : _name(source._name), _signed(source._signed), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute) {}

Form &Form::operator=(const Form &other) {
	if (this == &other)
		return *this;
	_signed = other._signed;
	return *this;
}

const std::string &Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

void Form::signForm() {
	if (_signed)
		std::cout << "Form " << _name << " is already signed." << std::endl;
	else
		std::cout << "Form " << _name << " is not signed." << std::endl;
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "Grade is too low.";
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
	out << "Form " << f.getName() << " is ";
	if (f.getSigned())
		out << "signed.";
	else
		out << "not signed.";
	out << " Grade to sign: " << f.getGradeToSign() << ". Grade to execute: " << f.getGradeToExecute() << ".";
	return out;
}


