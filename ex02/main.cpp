#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1); // High-ranking bureaucrat

        PresidentialPardonForm presidentialForm("Alice");
        RobotomyRequestForm robotomyForm("Charlie");
        ShrubberyCreationForm shrubberyForm("Garden");
        RobotomyRequestForm test("Peter");
        Bureaucrat tim("Tim", 150);

        std::cout << "Executing Presidential Pardon Form:" << std::endl;
        bob.signForm(presidentialForm);
        bob.executeForm(presidentialForm);

        std::cout << "\nExecuting Robotomy Request Form:" << std::endl;
        bob.signForm(robotomyForm);
        bob.executeForm(robotomyForm);

        std::cout << "\nExecuting Shrubbery Creation Form:" << std::endl;
        bob.signForm(shrubberyForm);
        bob.executeForm(shrubberyForm);

        bob.signForm(test);
        tim.executeForm(test);


    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}