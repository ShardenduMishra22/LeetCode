#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        string largestNum;
        for (int num : nums) {
            largestNum += to_string(num);
        }
        return largestNum[0] == '0' ? "0" : largestNum;
    }

private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int pivotIndex = partition(nums, left, right);
        quickSort(nums, left, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int lowIndex = left;
        for (int i = left; i < right; ++i) {
            if (compare(nums[i], pivot)) {
                swap(nums[i], nums[lowIndex]);
                ++lowIndex;
            }
        }
        swap(nums[lowIndex], nums[right]);
        return lowIndex;
    }

    bool compare(int firstNum, int secondNum) {
        return to_string(firstNum) + to_string(secondNum) >
               to_string(secondNum) + to_string(firstNum);
    }
};

// class Solution {
// public:
//     string largestNumber(vector<int> &nums) {
//         vector<string> numStrings;
//         for (int num : nums) {
//             numStrings.push_back(to_string(num));
//         }

//         sort(numStrings.begin(), numStrings.end(),
//              [](string &a, string &b) { return a + b > b + a; });

//         if (numStrings[0] == "0") 
//             return "0";
        
//         string largestNum;
//         for (string &numStr : numStrings) {
//             largestNum += numStr;
//         }

//         return largestNum;
//     }
// };