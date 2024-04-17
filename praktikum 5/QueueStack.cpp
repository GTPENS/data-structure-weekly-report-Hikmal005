#include <iostream>
#include <stack>

class QueueUsingStack {
private:
    std::stack<int> stk1;
    std::stack<int> stk2;

public:
    void add(int value) {
        stk1.push(value);
    }

    int remove() {
        int value;
        if (!stk2.empty()) {
            return stk2.top();
        }
        while (!stk1.empty()) {
            value = stk1.top();
            stk1.pop();
            stk2.push(value);
        }
        return stk2.top();
    }
};

int main() {
    QueueUsingStack que;
    que.add(1);
    que.add(11);
    que.add(111);
    std::cout << que.remove() << '\n';
    que.add(2);
    que.add(21);
    que.add(211);
    std::cout << que.remove() << '\n';
    std::cout << que.remove() << '\n';

    return 0;
}