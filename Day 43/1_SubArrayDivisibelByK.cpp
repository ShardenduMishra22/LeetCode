#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<int, int> countMap;
        countMap[0] = 1;
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            int mod = (sum % k + k) % k;

            if (countMap.find(mod) != countMap.end()) {
                count += countMap[mod];
            }

            countMap[mod]++;
        }

        return count;
    }
};