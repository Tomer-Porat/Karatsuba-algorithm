    #pragma once
namespace krtsb {
    class Karatsuba
    {
    public:
        vector<int> multiplyRec(vector<int> num1, vector<int> num2);
        vector<int> MakeShifting(vector<int> num1, int stepnum);
        vector<int> vectorSum(vector<int> a, vector<int> b);
        vector<int> Subtraction(vector<int> num1, vector<int> num2);
        vector<int> multiplyIter(vector<int> X, vector<int> Y);
    };
}