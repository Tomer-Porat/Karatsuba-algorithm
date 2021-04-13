#include "GlobalHeader.h"
namespace krtsb {
    void Stack::push(stackItem data)
    {
        stackListNode* temp;
        temp = new stackListNode(data, top);
        top = temp;
    }
    stackItem Stack::pop()
    {
        stackItem temp;
        if (!isEmpty())
        {
            temp = top->data;
            top = top->next;
            return temp;
        }
    }
    void Stack::MakeEmpty() {
        while (!this->isEmpty()) {
            this->pop();
        }
    }

    stackItem::stackItem(vector<int> _num1, vector<int> _num2, vector<int> _res, int _line, int _n)
    {
        num1 = _num1;
        num2 = _num2;
        res = _res;
        line = _line;
        n = _n;
    }
}