#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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

		const std::string & getName() const;
		int getGrade() const;



		class GradeTooHighException : public std::exception {

		};

		class GradeTooLowException : public std::exception {

		};


};

#endif