#include "GlobalHeader.h"

namespace krtsb {
    // Multiplies str1 and str2, and prints result.
    int* schoolMultiplication::schoolMultiply(int* num1, int* num2, int size, int* resSize)
    {
        // will keep the result number in vector
        // in reverse order
        int* result = new int[size * 2];
        for (int i = 0; i < size * 2; i++) {
            result[i] = 0;
        }

        // Below two indexes are used to find positions
        // in result.
        int i_n1 = 0;
        int i_n2 = 0;

        // Go from right to left in num1
        for (int i = size - 1; i >= 0; i--)
        {
            int carry = 0;
            int n1 = num1[i];

            // To shift position to left after every
            // multiplication of a digit in num2
            i_n2 = 0;

            // Go from right to left in num2
            for (int j = size - 1; j >= 0; j--)
            {
                // Take current digit of second number
                int n2 = num2[j];

                // Multiply with current digit of first number
                // and add result to previously stored result
                // at current position.
                int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

                // Carry for next iteration
                carry = sum / 10;

                // Store result
                result[i_n1 + i_n2] = sum % 10;

                i_n2++;
            }

            // store carry in next cell
            if (carry > 0)
                result[i_n1 + i_n2] += carry;

            // To shift position to left after every
            // multiplication of a digit in num1.
            i_n1++;
        }

        // ignore '0's from the right
        int i = (size * 2) - 1;
        while (i >= 0 && result[i] == 0)
            i--;

        // If all were '0's - means either both or
        // one of num1 or num2 were '0'
        if (i == -1)
            return 0;

        // generate the result string
        int* s = new int[i];
        int res_i = 0;
        while (i >= 0) {
            s[res_i] = result[i];
            i--;
            res_i++;
        }
        *resSize = res_i;
        return s;
    }

}