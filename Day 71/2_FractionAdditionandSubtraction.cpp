#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionAddition(string expr) {
        int i = 0;
        int n = expr.size();

        int numi = 0;
        int dnom = 1;

        while (i < n) {
            int CurrNum = 0;
            int CurrDen = 0;
            bool IsNeg = expr[i] == '-';
            if (expr[i] == '+' || expr[i] == '-') {
                i += 1;
            }

            while (i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                CurrNum = (CurrNum * 10) + val;
                i += 1;
            }

            i += 1;

            if (IsNeg) {
                CurrNum = -CurrNum;
            }

            while (i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                CurrDen = (CurrDen * 10) + val;
                i += 1;
            }

            numi = numi * CurrDen + CurrNum * dnom;
            dnom = dnom * CurrDen;

            int GCD = abs(__gcd(numi, dnom));
            numi /= GCD;
            dnom /= GCD;
        }

        return to_string(numi) + "/" + to_string(dnom);
    }
};