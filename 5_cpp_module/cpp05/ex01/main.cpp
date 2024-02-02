#include "Form.hpp"

int main(void)
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

    C.signForm(c);   // 예외의 경우 이상한 에러 남....고쳐보기

    return (0);
}
