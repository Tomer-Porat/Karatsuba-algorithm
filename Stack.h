#pragma once
namespace krtsb {
    class stackItem {
    private:
        vector<int> num1;
        vector<int> num2;
        vector<int> res;

        
        int line = 0;
        int n = 0;
    public:
        vector<int> res1;
        vector<int> res2;
        vector<int> res3;
        vector<int> resA;
        vector<int> resB;
        vector<int> resC;
        vector<int> resD;
        stackItem() = default;
        stackItem(vector<int> _num1, vector<int> _num2, vector<int> _res, int _line, int _n);
        void setLine(int _line) { line = _line; };
        void setSize(int _n) { n = _n; };
        vector<int>& getNum1() { return num1; };
        vector<int>& getNum2() { return num2; };
        vector<int>& getRes() { return res; };
        int getLine() { return line; };
        int getSize() { return n; };
    };

    class stackListNode {
        friend class Stack;
    private:
        stackItem data;
        stackListNode* next;
    public:
        stackListNode(stackItem& _data, stackListNode* _next) : data(_data), next(_next) {};
        
    };

    class Stack {
    private:
        stackListNode* top;
    public:
        Stack() : top(nullptr) { MakeEmpty(); };
        ~Stack() { MakeEmpty(); };
        stackItem pop();
        void push(stackItem data);
        bool isEmpty() { return top == nullptr; };
        void MakeEmpty();
    };

}