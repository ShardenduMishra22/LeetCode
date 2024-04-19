#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> s;
        int j = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i == n - 1 || nums[i] + 1 != nums[i + 1]) {
                if (j == i) {
                    s.push_back(to_string(nums[j]));
                } else {
                    s.push_back(to_string(nums[j]) + "->" + to_string(nums[i]));
                }
                j = i + 1;
            }
        }
        return s;
    }
};