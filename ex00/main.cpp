#include "Bureaucrat.hpp"


int main() {
    try {
        Bureaucrat bob("Bob", 0);
        std::cout << bob << std::endl;
        bob.incrementGrade(); 
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat alice("Alice", 150);
        std::cout << alice << std::endl;
        alice.decrementGrade(); 
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat john("John", 75);
        std::cout << john << std::endl;
        john.incrementGrade();
        std::cout << john << std::endl;
        john.decrementGrade();
        std::cout << john << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}