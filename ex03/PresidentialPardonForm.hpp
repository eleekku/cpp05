#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string	_target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &source);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &source);

		void execute(Bureaucrat const & executor) const;
};

#endif