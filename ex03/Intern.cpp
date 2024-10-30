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
	std::pair<std::string, AForm *(Intern::*)(std::string)> formTypes[] = {
		{"shrubbery creation", &Intern::makeShrubberyCreationForm},
		{"robotomy request", &Intern::makeRobotomyRequestForm},
		{"presidential pardon", &Intern::makePresidentialPardonForm}
	};

	for (const auto &formType : formTypes) {
		if (formType.first == formName) {
			return (this->*(formType.second))(target);
		}
	}

	std::cerr << "Intern cannot create form: " << formName << std::endl;
	return NULL;
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

