#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{
    
}

// RPN::RPN(const RPN &rpn)
// {

// }

// RPN& RPN::operator=(const RPN &rpn)
// {

// }

void RPN::parsing(std::string str)
{
    std::string argument;
    std::istringstream str_stream(str);

    while (getline(str_stream, argument, ' '))
    {
        argu.push_back(argument);

        if (!(argument == "+" || argument == "-"
                || argument == "/" || argument == "*"))
            operand_size++;
    }

    if (operand_size >= 10)
        throw std::runtime_error("Error: Too many operand");
}

// 1. 피연산자는 stack에 삽입
// 2. 연산자 나오면 stack에 있는 원소 2개 빼서 연산
void RPN::calculate(void)
{
    int operand1, operand2;
    int num;

    for(size_t i = 0; i < argu.size(); i++)
    {
        if (argu[i] == "+")
        {
            operand2 = st.top();
            st.pop();
            operand1 = st.top();
            st.pop();

            st.push(operand1 + operand2);
        }
        else if (argu[i] == "-")
        {
            operand2 = st.top();
            st.pop();
            operand1 = st.top();
            st.pop();

            st.push(operand1 - operand2);
        }
        else if (argu[i] == "/")
        {
            operand2 = st.top();
            st.pop();
            operand1 = st.top();
            st.pop();

            st.push(operand1 / operand2);
        }
        else if (argu[i] == "*")
        {
            operand2 = st.top();
            st.pop();
            operand1 = st.top();
            st.pop();

            st.push(operand1 * operand2);
        }
        else   // 피연산자
        {
            num = strtod(argu[i].c_str(), NULL);
            st.push(num);
        }
    }

    std::cout << st.top() << std::endl;
}