#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	
	public:
		AForm();
		AForm(const std::string name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();
		AForm(const AForm &source);
		AForm &operator=(const AForm &other);

		const std::string &getName() const;
		bool	getSigned() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;

		void	beSigned(const Bureaucrat &b);
		void	signForm();
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
			virtual const char*	what() const noexcept; 	
		};

		class GradeTooLowException : public std::exception {
			public:
			virtual const char* what() const noexcept;
		};

		class FormNotSignedException : public std::exception {
			public:
			virtual const char* what() const noexcept;
		};

};


		std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif