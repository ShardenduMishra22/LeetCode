#include <bits/stdc++.h>
using namespace std;

#pragma GCC target   ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("Ofast")

static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define fr(i, len) for(int i=0; i < len; i++)

#define YES cout<<"Yes \n";
#define NOO cout<<"No  \n";
#define nl cout<<"\n";

#define MAX_SIZE 10000
#define nptr nullptr

typedef stringstream sstr;
typedef long long int ll;
typedef const int c_int;
typedef unsigned unsg;
typedef double dbl;

typedef vector<vector<string>> vvstr;
typedef vector<vector<bool>> vvbl;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvll;

typedef vector<string> vstr;
typedef vector<int> vint;
typedef vector<bool> vbl;
typedef vector<ll> vll;

typedef stack<string> sstr;
typedef stack<bool> sbl;
typedef stack<int> sint;
typedef stack<ll> sll;

typedef queue<string> qstr;
typedef queue<bool> qbl;
typedef queue<int> qint;
typedef queue<ll> qll;

int size_stack=0;
int InvrsnCnt=0;
int size_arr=0;
int size_ll=0;
int top=-1;
c_int MOD=1e9+7;
c_int Mx_row=100;
c_int Mx_col=100;

// class Solution {
// public:
//     int maximumGain(string s, int x, int y) {
//         if (x < y) {
//             int temp = x;
//             x = y;
//             y = temp;
//             reverse(s.begin(), s.end());
//         }

//         int aCount = 0, bCount = 0, totalPoints = 0;

//         for (int i = 0; i < s.size(); ++i) {
//             char currentChar = s[i];

//             if (currentChar == 'a') {
//                 ++aCount;
//             } else if (currentChar == 'b') {
//                 if (aCount > 0) {
//                     --aCount;
//                     totalPoints += x;
//                 } else {
//                     ++bCount;
//                 }
//             } else {
//                 totalPoints += min(bCount, aCount) * y;
//                 aCount = bCount = 0;
//             }
//         }
//         totalPoints += min(bCount, aCount) * y;

//         return totalPoints;
//     }
// };

// class Solution {
// public:
//     int maximumGain(string s, int x, int y) {
//         int totalPoints = 0;

//         if (x > y) {
//             totalPoints += removeSubstring(s, "ab", x);
//             totalPoints += removeSubstring(s, "ba", y);
//         } else {
//             totalPoints += removeSubstring(s, "ba", y);
//             totalPoints += removeSubstring(s, "ab", x);
//         }

//         return totalPoints;
//     }

//     int removeSubstring(string& inputString, string targetSubstring,int pointsPerRemoval) {
//         int totalPoints = 0;
//         int writeIndex = 0;

//         for (int readIndex = 0; readIndex < inputString.size(); readIndex++) {
//             inputString[writeIndex++] = inputString[readIndex];

//             if (writeIndex > 1 &&
//                 inputString[writeIndex - 2] == targetSubstring[0] &&
//                 inputString[writeIndex - 1] == targetSubstring[1]) {
//                 writeIndex -= 2;  
//                 totalPoints += pointsPerRemoval;
//             }
//         }

//         inputString.erase(inputString.begin() + writeIndex, inputString.end());

//         return totalPoints;
//     }
// };

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        string highPriorityPair = x > y ? "ab" : "ba";
        string lowPriorityPair = highPriorityPair == "ab" ? "ba" : "ab";

        string stringAfterFirstPass = removeSubstring(s, highPriorityPair);
        int removedPairsCount =(s.length() - stringAfterFirstPass.length()) / 2;

        totalScore += removedPairsCount * max(x, y);

        string stringAfterSecondPass =removeSubstring(stringAfterFirstPass, lowPriorityPair);
        removedPairsCount =(stringAfterFirstPass.length() - stringAfterSecondPass.length())/2;

        totalScore += removedPairsCount * min(x, y);

        return totalScore;
    }

private:
    string removeSubstring(const string& input, const string& targetPair) {
        stack<char> charStack;

        for (char currentChar : input) {
            if (currentChar == targetPair[1] && !charStack.empty() &&
                charStack.top() == targetPair[0]) {
                charStack.pop(); 
            } else {
                charStack.push(currentChar);
            }
        }

        string remainingChars;
        while (!charStack.empty()) {
            remainingChars += charStack.top();
            charStack.pop();
        }
        reverse(remainingChars.begin(), remainingChars.end());
        return remainingChars;
    }
};