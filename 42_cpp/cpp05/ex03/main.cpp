#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Intern      intern;

    AForm        *form = intern.makeForm("shrubbery creation", "Form");
    AForm        *form2 = intern.makeForm("robotomy request", "Form2");
    AForm        *form3 = intern.makeForm("presidential pardon", "Form3");

    std::cout << *form << std::endl;
    std::cout << *form2 << std::endl;
    std::cout << *form3 << std::endl;

    delete form;
    delete form2;
    delete form3;
    return (0);
}