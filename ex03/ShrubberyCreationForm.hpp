#ifndef SHRUUBBERYCREATIONFORM_HPP
#define SHRUUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		const std::string	_target;
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &source);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &source);

		void execute(Bureaucrat const & executor) const;
};

#endif