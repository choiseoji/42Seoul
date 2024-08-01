#include "RPN.hpp"

RPN::RPN()
{
    result = 0;
}

RPN::RPN(const RPN &rpn)
{
    this->result = rpn.result;
    this->st = rpn.st;
}

RPN& RPN::operator=(const RPN &rpn)
{
    if (this != &rpn)
    {
        this->result = rpn.result;
        this->st = rpn.st;
    }
    return (*this);
}

RPN::~RPN()
{
    
}

int RPN::getResult(void)
{
    return (result);
}

void RPN::setResult(int res)
{
    result = res;
}

int RPN::getOperand(void)
{
    int operand;

    operand = st.top();
    st.pop();

    return (operand);
}

void RPN::calAdd(void)
{
    int operand1, operand2;

    operand2 = getOperand();
    operand1 = getOperand();
    st.push(operand1 + operand2);
}

void RPN::calSub()
{
    int operand1, operand2;

    operand2 = getOperand();
    operand1 = getOperand();
    st.push(operand1 - operand2);
}

void RPN::calDiv()
{
    int operand1, operand2;

    operand2 = getOperand();
    operand1 = getOperand();
    if (operand2 == 0)
        throw std::runtime_error("Error: you can't divide it by 0");
    st.push(operand1 / operand2);
}

void RPN::calMul()
{
    int operand1, operand2;

    operand2 = getOperand();
    operand1 = getOperand();
    st.push(operand1 * operand2);
}

int RPN::checkValidOp(std::string op)
{
    // operand 유효성 검사
    int num;
    char *ptr;

    num = strtod(op.c_str(), &ptr);
    if (*ptr)
        throw std::runtime_error("Error: invalid argument");

    if (num < 0 || num > 9)
        throw std::runtime_error("Error: input must be decimal number");
    return (num);
}

void RPN::isOperand(std::string op)
{
    int num;

    num = checkValidOp(op);
    st.push(num);
}

// 1. 피연산자는 stack에 삽입
// 2. 연산자 나오면 stack에 있는 원소 2개 빼서 연산
void RPN::calculate(std::string str)
{
    std::string argument;
    std::istringstream str_stream(str);

    while (getline(str_stream, argument, ' '))
    {
        if (argument == "+")
            calAdd();
        else if (argument == "-")
            calSub();
        else if (argument == "/")
            calDiv();
        else if (argument == "*")
            calMul();
        else   // 피연산자
            isOperand(argument);
    }

    // 연산이 안되는 경우 -> stack에 2개 이상의 원소가 있을 때 연산이 다 안된 것임
    if (st.size() != 1)
        throw std::runtime_error("Error: can't calculate");
    setResult(st.top());
}