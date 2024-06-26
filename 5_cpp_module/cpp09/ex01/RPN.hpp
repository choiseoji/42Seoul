#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <sstream>
# include <fstream>
# include <vector>

class RPN
{
private:
    int result;
    int operand_size;
    std::stack<int> st;

public:
    RPN();
    RPN(const RPN &rpn);
    RPN& operator=(const RPN &rpn);
    ~RPN();

    // calculate
    int getOperand();
    void calAdd();
    void calSub();
    void calDiv();
    void calMul();
    void isOperand(std::string op);

    // error check
    int checkValidOp(std::string op);
    void checkError();

    // main func
    void calculate(std::string str);

    // getter, setter
    int getResult();
    void setResult(int res);


};

#endif