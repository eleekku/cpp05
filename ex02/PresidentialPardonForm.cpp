#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &source) : AForm(source), _target(source._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &source) {
	if (this == &source)
		return *this;
	AForm::operator=(source);
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &f) {
	out << "Form " << f.getName() << " is ";
	if (!f.getSigned())
		out << "not ";
	out << "signed." << std::endl;
	return out;
}

