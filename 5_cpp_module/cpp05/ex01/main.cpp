#include "Form.hpp"

int main(void)
{
    Bureaucrat A("A", 5);
    Form a("security_form", 5, 2);  // sign_grade, execute_grade

    A.signForm(a);
    A.signForm(a);


    Bureaucrat B("B", 10);
    Form b("just_form", 5, 2);

    B.signForm(b);
    B.signForm(b);

    return (0);
}