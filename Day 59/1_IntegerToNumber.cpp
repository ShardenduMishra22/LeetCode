#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const vector<string> bl_10 = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    const vector<string> bl_100 = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    const vector<string> bl_20 = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

    string solve(int num) {
        if(num < 10) {
            return bl_10[num];
        }
        if(num < 20) {
            return bl_20[num - 10];
        }
        if(num < 100) {
            return bl_100[num / 10] + (num % 10 ? " " + solve(num % 10) : "");
        }
        if(num < 1000) {
            return solve(num / 100) + " Hundred" + (num % 100 ? " " + solve(num % 100) : "");
        }
        if(num < 1000000) {
            return solve(num / 1000) + " Thousand" + (num % 1000 ? " " + solve(num % 1000) : "");
        }
        if(num < 1000000000) {
            return solve(num / 1000000) + " Million" + (num % 1000000 ? " " + solve(num % 1000000) : "");
        }
        return solve(num / 1000000000) + " Billion" + (num % 1000000000 ? " " + solve(num % 1000000000) : "");
    }

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        return solve(num);
    }
};