#include "GlobalHeader.h"
using namespace krtsb;

int main()
{
    string numberLengthStr, getNum1, getNum2;
    int *firstNumber, *secondNumber;
    int numberLength, dig;
    ofstream myfile("Measure.txt"); // The name of the file

    // Get n from user //
    //cout<<"Please enter the length of the numbers: ";
   cin >> numberLengthStr;

    //Input check for n //
    //Check if n has leading zero:
    for (int i = 0; i < numberLengthStr.length(); i++)
    {
        if (numberLengthStr[i] > '0' && numberLengthStr[i] < '9')
            break;
        if (numberLengthStr[i] == '0') {
            cout << "wrong output" << endl;
            return 0;
        }
    }
    numberLength = stoi(numberLengthStr);
    if (numberLength <= 0) {
        cout << "wrong output" << endl;
        return 0;
    }

    // Get the numbers from user //
    cin >> getNum1;
    cin >> getNum2;
    //Insert the number into array and check input:
    if (getNum1.length() > numberLength || getNum2.length() > numberLength) {
        cout << "wrong output" << endl;
        return 0;
    }
    if (getNum1.length() < numberLength || getNum2.length() < numberLength) {
    cout << "wrong output" << endl;
    return 0;
    }
    if (numberLength < 0 || cin.fail()) {
        cout << "wrong output" << endl;
        return 0;
    }
    for (int i = 0; i < numberLength; i++) {
        if (getNum1[i] < '0' || getNum1[i]>'9') {
            cout << "wrong output" << endl;
            return 0;
        }
        if (getNum2[i] < '0' || getNum2[i]>'9') {
            cout << "wrong output" << endl;
            return 0;
        }
    }
    int resSize = numberLength * 2;
    firstNumber = new int[numberLength];
    secondNumber = new int[numberLength];
    //put the inputs into an array
    for (int i = 0; i < numberLength; i++)
    {
        firstNumber[i] = getNum1[i] - '0';
    }
    for (int i = 0; i < numberLength; i++)
    {
        secondNumber[i] = getNum2[i] - '0';
    }
    //print timers to Measure.txt:
    //<MESURE FIRST ALGORITHM>
    cout << "Long multiplication: x * y = ";
    schoolMultiplication classic;
    auto start1 = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    //#1 START
    int* classicOutput = classic.schoolMultiply(firstNumber, secondNumber, numberLength,&resSize);
    auto end1 = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    double time_taken1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
    time_taken1 *= 1e-9;
    myfile << "Time taken by function Classic Multiply is : " << fixed
        << time_taken1 << setprecision(9);
    myfile << " sec" << endl;
    for (int i = 0; i<resSize ; i++)
    {
        cout << classicOutput[i];
    }
    //Convert array to vector.
    vector<int> vNum1, vNum2;
    for (int i = 0; i < numberLength; i++)
    {
        vNum1.push_back(firstNumber[i]);
        vNum2.push_back(secondNumber[i]);
    }
    //<MESURE SECOND ALGORITHM>
    cout << endl << "Karatsuba (recursive): x * y = ";
    Karatsuba karatsubaRec;
    auto start2 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    //#2 START
    vector<int> karatsubaRecOutput = karatsubaRec.multiplyRec(vNum1, vNum2);
    auto end2 = chrono::high_resolution_clock::now();
    double time_taken2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
    time_taken2 *= 1e-9;
    myfile << "Time taken by function Karatsuba Recursive Multiply is : " << fixed
        << time_taken2 << setprecision(9);
    myfile << " sec" << endl;
    for (int i = 0; i<karatsubaRecOutput.size() ; i++)
    {
        cout << karatsubaRecOutput[i];
    }
    //<MESURE THIRD ALGORITHM>
    Stack mahsanit_tova;
    stackItem bdika(vNum1, vNum2, vNum2, 1, 1);
    mahsanit_tova.push(bdika);
    cout<<endl<<"Karatsuba (iterative): x * y = ";
    Karatsuba karatsubaIter;
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    //#3 START
    vector<int> karatsubaIterOutput = karatsubaIter.multiplyIter(vNum1, vNum2);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    myfile << "Time taken by function Karatsuba Iterative Multiply is : " << fixed
    << time_taken << setprecision(9);
    myfile << " sec" << endl;
    for (int i = 0; i < karatsubaIterOutput.size(); i++)
    {
        cout << karatsubaIterOutput[i];
    }

    myfile.close();

    return 0;
}
