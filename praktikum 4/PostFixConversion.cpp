#include <iostream>
#include <stack>
#include <string>

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

std::string infixToPostfix(const std::string& expn)
{
    std::stack<char> stk;
    std::string output;

    for (char ch : expn)
    {
        if (std::isdigit(ch))
        {
            output += ch;
        }
        else
        {
            switch (ch)
            {
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while (!stk.empty() && precedence(ch) <= precedence(stk.top()))
                    {
                        output += " ";
                        output += stk.top();
                        stk.pop();
                    }
                    stk.push(ch);
                    output += " ";
                    break;
                case '(':
                    stk.push(ch);
                    break;
                case ')':
                    while (!stk.empty() && stk.top() != '(')
                    {
                        output += " ";
                        output += stk.top();
                        stk.pop();
                    }
                    stk.pop(); // Pop the from stack
                    break;
            }
        }
    }

    while (!stk.empty())
    {
        output += " ";
        output += stk.top();
        stk.pop();
    }

    return output;
}

int main()
{
    std::string expn = "10+((3))*5/(16-4)";
    std::string value = infixToPostfix(expn);
    std::cout << "Infix Expn: " << expn << std::endl;
    std::cout << "Postfix Expn: " << value << std::endl;

    return 0;
}