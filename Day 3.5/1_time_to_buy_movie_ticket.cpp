#include<bits/stdc++.h>
using namespace std;

#include <vector>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total = 0;
        while (true) {
            for (int i = 0; i < tickets.size(); i++) {
                if (tickets[i] > 0) {
                    tickets[i]--;
                    total++;
                }
                if (tickets[k] == 0) {
                    return total;
                }
            }
        }
        return -1; 
    }
};
