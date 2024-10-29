#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
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


    try {
        Bureaucrat charlie("Charlie", 50);
        Form formA("FormA", 45, 30);
        Form formB("FormB", 55, 30);

        std::cout << charlie << std::endl;
        charlie.signForm(formA);
        charlie.signForm(formB);
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }


    try {
        Form formC("FormC", 100, 50);
        Bureaucrat dave("Dave", 100);

        std::cout << formC << std::endl;
        dave.signForm(formC);
        dave.decrementGrade();
        dave.signForm(formC); 
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}