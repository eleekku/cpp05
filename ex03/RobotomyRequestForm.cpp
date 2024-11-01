#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source) : AForm(source), _target(source._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &source) {
	if (this == &source)
		return *this;
	AForm::operator=(source);
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (this->getGradeToExecute() < executor.getGrade())
			throw AForm::GradeTooLowException();
	std::cout << "*drilling noises*" << std::endl;
	std::srand(std::time(nullptr));
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomization failed." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &f) {
	out << "Form " << f.getName() << " is ";
	if (!f.getSigned())
		out << "not ";
	out << "signed." << std::endl;
	return out;
}