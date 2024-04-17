 #include <iostream>
#include <stack>
#include <string>

bool isPalindrome(const std::string& str) {
std::stack<char> stack;
int length = str.length();
int i, mid = length / 2;
    for (i = 0; i < mid; i++) {
        stack.push(str[i]);
    }
    for (i = mid + length % 2; i < length; i++) {
        if (stack.top() != str[i]) {
            return false;
        }
        stack.pop();
    }
    return true;
}

int main() {
    std::string input = "malam";
    bool result = isPalindrome(input);
    if (result) {
        std::cout << input << " is a palindrome." << std::endl;
    } else {
        std::cout << input << " is not a palindrome." << std::endl;
    }
    return 0;
}