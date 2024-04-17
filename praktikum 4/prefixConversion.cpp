#include <iostream>
#include <cstring>

void reverseString(char expn[], int length) {
    int lower = 0;
    int upper = length - 1;
    char tempChar;
    while (lower < upper) {
        tempChar = expn[lower];
        expn[lower] = expn[upper];
        expn[upper] = tempChar;
        lower++;
        upper--;
    }
}

void replaceParanthesis(char a[], int length) {
    for (int i = 0; i < length; i++) {
        if (a[i] == '(') {
            a[i] = ')';
        } else if (a[i] == ')') {
            a[i] = '(';
        }
    }
}

char* infixToPostfix(char infix[]) {
    
}

char* infixToPrefix(char infix[]) {
    int length = strlen(infix);
    reverseString(infix, length);
    replaceParanthesis(infix, length);
    char* postfix = infixToPostfix(infix);
    reverseString(postfix, strlen(postfix));
    return postfix;
}

int main() {
    char expn[] = "10+((3))*5/(16-4)";
    char* value = infixToPrefix(expn);
    std::cout << "Infix Expn: " << expn << std::endl;
    std::cout << "Prefix Expn: " << value << std::endl;

    return 0;
}