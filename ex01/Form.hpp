#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	
	public:
		Form();
		Form(const std::string name, int gradeToSign, int gradeToExecute);
		~Form();
		Form(const Form &source);
		Form &operator=(const Form &other);

		const std::string &getName() const;
		bool	getSigned() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;

		void	beSigned(const Bureaucrat &b);
		void	signForm();

		class GradeTooHighException : public std::exception {
			public:
			virtual const char*	what() const noexcept; 	
		};

		class GradeTooLowException : public std::exception {
			public:
			virtual const char* what() const noexcept;
		};

};


		std::ostream &operator<<(std::ostream &out, const Form &f);

#endif