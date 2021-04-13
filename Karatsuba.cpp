#include "GlobalHeader.h"
namespace krtsb {
    class Stack;

    void fitRes(vector<int>& res)
    {
        int Idx = 0;
        while (res[Idx] == 0 && Idx < res.size() - 1)
        {
            Idx++;
        }

        res.erase(res.begin(), res.begin() + Idx);
    }

    int lengthController(vector<int>& num1, vector<int>& num2)
    {
        int len1 = num1.size();
        int len2 = num2.size();

        if (len1 < len2)
        {
            for (int i = 0; i < len2 - len1; i++)
                num1.insert(num1.begin(), 0);
            return len2;
        }

        if (len1 > len2)
        {
            for (int i = 0; i < len1 - len2; i++)
                num2.insert(num2.begin(), 0);
            return len1;
        }

        return len1;
    }
    vector<int> Karatsuba::multiplyRec(vector<int> num1, vector<int> num2)
    {


        int size = lengthController(num1, num2);

        vector<int> res;
        int Idx = 0;

        if (size == 1)
        {
            int result = num1[0] * num2[0];
            if (result == 0)
            {
                res.push_back(0);
                return res;
            }

            if ((result >= 10))
            {

                res.push_back((result / 10));
                res.push_back((result % 10));
                return res;
                while (res[Idx] == 0)
                {
                    Idx++;
                }
                res.erase(res.begin(), res.begin() + Idx);
                return res;
            }

            else
            {
                res.push_back((result));
                while (res[Idx] == 0 && Idx < res.size() - 1)
                {
                    Idx++;
                }
                res.erase(res.begin(), res.begin() + Idx);
                return res;
            }
        }

        else
        {
            vector<int>::iterator x_a = num1.begin();
            vector<int>::iterator x_b = num1.begin() + (size / 2);
            vector<int>::iterator y_c = num2.begin();
            vector<int>::iterator y_d = num2.begin() + (size / 2);
            vector<int> a(num1.begin(), x_b);
            vector<int> b(x_b, num1.end());
            vector<int> c(num2.begin(), y_d);
            vector<int> d(y_d, num2.end());


            vector<int> res0 = multiplyRec(a, c);
            vector<int> res1 = multiplyRec(b, d);
            vector<int> res2 = multiplyRec(vectorSum(a, b), vectorSum(c, d));
            vector<int> res3 = Subtraction(Subtraction(res2, res1), res0);

            for (int i = 0; i < 2 * (size - (size / 2)); i++)
                res0.push_back(0);

            for (int i = 0; i < (size - (size / 2)); i++)
                res3.push_back(0);
            res = vectorSum(vectorSum(res0, res1), res3);

            fitRes(res);

            return (res);
        }
    }

    vector<int> Karatsuba::Subtraction(vector<int> num1, vector<int> num2)
    {
        int length = lengthController(num1, num2);
        int diff;
        vector<int> result;

        for (int i = length - 1; i >= 0; i--)
        {
            diff = num1[i] - num2[i];
            if (diff >= 0)
            {
                result.insert(result.begin(), diff);
            }
            else
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    num1[j] = (num1[j] - 1) % 10;
                    if (num1[j] != 9)
                    {
                        break;
                    }
                }
                result.insert(result.begin(), diff + 10);
            }
        }
        result.shrink_to_fit();
        return result;
    }

    vector<int> Karatsuba::MakeShifting(vector<int> num1, int stepnum)
    {
        vector<int> shifted = num1;
        for (int i = 0; i < stepnum; i++)
            shifted.push_back(0);
        return shifted;
    }
    vector<int> Karatsuba::vectorSum(vector<int> a, vector<int> b)
    {
        int size = lengthController(a, b);
        int carry = 0;
        int sum;
        vector<int> res;

        for (int i = size - 1; i >= 0; i--)
        {
            sum = a[i] + b[i] + carry;
            carry = sum / 10;
            res.insert(res.begin(), (sum % 10));
        }
        if (carry)
        {
            res.insert(res.begin(), carry);
        }
        res.shrink_to_fit();
        return res;
    }

    vector<int> Karatsuba::multiplyIter(vector<int> X, vector<int> Y)
    {
        Stack S;
        vector<int> returnValue;
        stackItem Curr(X, Y, returnValue, START, lengthController(X, Y));
        S.push(Curr);
        while (!S.isEmpty()) {
            Curr = S.pop();
            if (Curr.getLine() == START) {
                if (Curr.getSize() == 1) {
                    int result = Curr.getNum1()[0] * Curr.getNum2()[0];
                    Curr.getRes().push_back((result / 10));
                    Curr.getRes().push_back((result % 10));
                    returnValue = Curr.getRes();
                }
                else {

                    Curr.setLine(AFTER_FIRST);

                    int len = Curr.getSize();

                    vector<int>::iterator x_a = Curr.getNum1().begin();
                    vector<int>::iterator x_b = Curr.getNum1().begin() + (len / 2);
                    vector<int> aVec(Curr.getNum1().begin(), x_b);

                    vector<int>::iterator y_c = Curr.getNum2().begin();
                    vector<int>::iterator y_d = Curr.getNum2().begin() + (len / 2);
                    vector<int> cVec(Curr.getNum2().begin(), y_d);

                    Curr.resA = aVec;
                    Curr.resB = cVec;
                    S.push(Curr);
                    vector<int> nextRes1(Curr.getLine());
                    stackItem Next(aVec, cVec, nextRes1, START, len / 2);
                    S.push(Next);
                }
            }
            else if (Curr.getLine() == AFTER_FIRST)
            {
                Curr.res1 = returnValue;
                Curr.setLine(AFTER_SECOND);
                S.push(Curr);
                int len = Curr.getSize();
                vector<int>::iterator x_a = Curr.getNum1().begin();
                vector<int>::iterator x_b = Curr.getNum1().begin() + (len / 2);
                vector<int> bVec(x_b, Curr.getN
                um1().end());

                vector<int>::iterator y_c = Curr.getNum2().begin();
                vector<int>::iterator y_d = Curr.getNum2().begin() + (len / 2);
                vector<int> dVec(y_d, Curr.getNum2().end());

                Curr.resB = bVec;
                Curr.resD = dVec;
                vector<int> nextRes2(Curr.getLine());
                stackItem Next(bVec, dVec, nextRes2, START, len / 2);
                S.push(Next);

            }
            else if (Curr.getLine() == AFTER_SECOND) {
                Curr.res2 = returnValue;
                Curr.setLine(AFTER_SECOND);
                S.push(Curr);

                vector<int> AsumB = vectorSum(Curr.resA, Curr.resB);
                vector<int> CsumD = vectorSum(Curr.resC, Curr.resD);
                lengthController(AsumB, CsumD);

                vector<int> MULT_ABCD(2 * AsumB.size());
                stackItem Next(AsumB, CsumD, MULT_ABCD, AsumB.size(), START);
                S.push(Next);
            }
            else if (Curr.getLine() == AFTER_THIRD) {

                Curr.res3 = returnValue;

                vector<int> Res1sumRes2;
                vector<int> ACMult = Curr.res1;
                vector<int> BDMult = Curr.res2;

                //sum (a*c) + (b*d)

                vectorSum(vectorSum(ACMult, BDMult), Res1sumRes2);

                Curr.res1 = ACMult;
                Curr.res2 = BDMult;

                //sub
                vector<int> vecSub;
                vector<int>  ABMultCD = Curr.res3;

                Subtraction(Subtraction(ABMultCD, Res1sumRes2), vecSub);

                // (a*c)*(10^n)
                MakeShifting(ACMult, Curr.getSize());

                Curr.res3 = ABMultCD;

                // (a*c)*(10^(n/2))
                MakeShifting(vecSub, Curr.getSize() / 2);

                //sum a*c + b*d
                vector<int> ACsumBD;
                vectorSum(vectorSum(ACMult, BDMult), ACsumBD);

                //sum (a*c + b*d) + sub
                vector<int> finalSum;
                vectorSum(vectorSum(ACsumBD, vecSub), finalSum);

                Curr.getRes() = finalSum;
                returnValue = finalSum;

            }
        }
        return returnValue;
    }


}