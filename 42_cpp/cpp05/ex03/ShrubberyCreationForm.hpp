#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
        void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &shrub);

#endif