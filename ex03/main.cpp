#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main() {
    AForm* rrf = nullptr;
    AForm* ppf = nullptr;
    AForm* scf = nullptr;
    try {
    Intern someRandomIntern;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    ppf = someRandomIntern.makeForm("presidential pardon", "What");
    scf = someRandomIntern.makeForm("shrubbery creation", "garden");

    Bureaucrat bob("Bob", 1);
    bob.signForm(*rrf);
    bob.executeForm(*rrf);
    bob.signForm(*ppf);
    bob.executeForm(*ppf);
    bob.signForm(*scf);
    bob.executeForm(*scf);

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        delete rrf;
        delete ppf;
        delete scf;
        return 1;
    }

    delete rrf;
    delete ppf;
    delete scf;

}