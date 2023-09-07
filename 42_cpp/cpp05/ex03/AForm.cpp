#include "AForm.hpp"

AForm::AForm() : _name("Default"), _gradeToSign(5), _gradeToExecute(6)
{
    _signed = false;
    std::cout << "Default constructor called" << std::endl;
}

AForm::AForm( const std::string& name, int gradeToSign, int gradeToExecute ) : _name( name ), _gradeToSign( gradeToSign ), _gradeToExecute( gradeToExecute ) {
	_signed = false;
	if ( gradeToSign < 1 )
        throw AForm::GradeTooHighException();
    if ( gradeToSign > 150 )
        throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm& src ) : _name( src.getName() ), _signed(src._signed), _gradeToSign( src.getGradeToSign() ), _gradeToExecute( src.getGradeToExecute() ) {}

AForm::~AForm() {}

AForm&   AForm::operator=( const AForm& rhs ) {
    if ( this != &rhs )
        _signed = rhs.getSigned();
    return *this;
}

std::string AForm::getName() const {
    return _name;
}

bool   AForm::getSigned() const {
    return _signed;
}

int   AForm::getGradeToSign() const {
    return _gradeToSign;
}

int   AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void    AForm::beSigned(const Bureaucrat& bureaucrat) {
    if ( bureaucrat.getGrade() > _gradeToSign )
        throw AForm::GradeTooLowException();
    _signed = true;
}

std::ostream& operator<<(std::ostream &out, const AForm &form)
{
    out << "------------- AForm Info -------------" << std::endl;
    out << "Form name: " << form.getName() << std::endl;
    out << "Grade to sign: " << form.getGradeToSign() << std::endl;
    out << "Grade to execute: " << form.getGradeToExecute() << std::endl;
    out << "Signed: " << form.getSigned() << std::endl;
    return (out);
}