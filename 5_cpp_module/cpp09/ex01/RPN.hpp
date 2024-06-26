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
    int operand_size;
    std::stack<int> st;
    std::vector<std::string> argu;

public:
    RPN();
    // RPN(const RPN &rpn);
    // RPN& operator=(const RPN &rpn);
    ~RPN();

    void parsing(std::string str);
    void calculate();

};

#endif