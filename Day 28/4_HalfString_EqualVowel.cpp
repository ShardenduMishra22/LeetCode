#include <string>
using namespace std;

class Solution {
public:
    bool isVowel(char x) {
        return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
                x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U');
    }

    bool halvesAreAlike(string s) {
        int n = s.size();
        int mid = n / 2;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < mid; i++) {
            if (isVowel(s[i])) {
                cnt1++;
            }
        }
        for (int j = mid; j < n; j++) {
            if (isVowel(s[j])) {
                cnt2++;
            }
        }
        return cnt1 == cnt2;
    }
};