#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &source) : _name(source._name), _signed(source._signed), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute) {}

AForm &AForm::operator=(const AForm &other) {
	if (this == &other)
		return *this;
	_signed = other._signed;
	return *this;
}

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::signForm() {
	if (_signed)
		std::cout << "Form " << _name << " is already signed." << std::endl;
	else
		std::cout << "Form " << _name << " is not signed." << std::endl;
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "Grade is too low.";
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
	out << "Form " << f.getName() << " is ";
	if (f.getSigned())
		out << "signed.";
	else
		out << "not signed.";
	out << " Grade to sign: " << f.getGradeToSign() << ". Grade to execute: " << f.getGradeToExecute() << ".";
	return out;
}


