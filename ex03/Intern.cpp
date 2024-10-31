#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern() {
}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern::~Intern() {
}

Intern &Intern::operator=(const Intern &src) {
	(void)src;
	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target) {
    return (formName == "shrubbery creation") ? makeShrubberyCreationForm(target) :
           (formName == "robotomy request") ? makeRobotomyRequestForm(target) :
           (formName == "presidential pardon") ? makePresidentialPardonForm(target) :
		   (std::cerr << "Intern cannot create form: " << formName << std::endl, throw std::invalid_argument("Invalid form name"), nullptr);
}

AForm *Intern::makeShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

