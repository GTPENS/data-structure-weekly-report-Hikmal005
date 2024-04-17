#include <iostream>

class ListStack
{
private:
    struct Node
    {
        int value;
        Node* next;
        Node(int v, Node* n) : value(v), next(n) {}
    };

    Node* head = nullptr;
    int count = 0;

public:
    int size() const
    {
        return count;
    }

    bool Empty() const
    {
        return count == 0;
    }

    int peek() const
    {
        if (Empty())
        {
            throw std::runtime_error("ListStackEmptyException");
        }
        return head->value;
    }

    void Push(int value)
    {
        head = new Node(value, head);
        count++;
    }

    int Pop()
    {
        if (Empty())
        {
            throw std::runtime_error("ListStackEmptyException");
        }
        int value = head->value;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return value;
    }

    void insertAtBottom(int value)
    {
        if (Empty())
        {
            Push(value);
        }
        else
        {
            int temp = Pop();
            insertAtBottom(value);
            Push(temp);
        }
    }

    void print() const
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    ListStack s;
    for (int i = 1; i <= 100; i++)
        s.Push(i);
    for (int i = 1; i <= 50; i++)
        s.Pop();
    s.print();

    return 0;
}