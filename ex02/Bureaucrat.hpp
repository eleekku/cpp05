#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;


class	Bureaucrat {
	private: 
		const std::string	_name;
		int					_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &source);
		Bureaucrat &operator=(const Bureaucrat &other);


		const	std::string & getName() const;
		int		getGrade() const;

		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form &form);


		class GradeTooHighException : public std::exception {
			public:
			virtual const char*	what() const noexcept; 	
		};

		class GradeTooLowException : public std::exception {
			public:
			virtual const char* what() const noexcept;
		};
};

		std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif