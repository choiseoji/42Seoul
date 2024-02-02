#include "Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat A("A", 5);
        Form a("first_form", 5, 2);  // sign_grade, execute_grade

        A.signForm(a);
        A.signForm(a);


        Bureaucrat B("B", 10);
        Form b("second_form", 5, 2);

        B.signForm(b);

        Bureaucrat C("C", 151);
        Form c("third_form", 1, 1);

        C.signForm(c);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
