#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};

class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
    
        vector<int>numbers;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) numbers.push_back(i);
        }
        for(int i=0;i<numbers.size();i++){
            nums[i]=nums[numbers[i]];
        }
        
        for(int i=numbers.size();i<nums.size();i++){
            nums[i]=0;
        }
    }
};

class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        int end = nums.size();
        int j = 0;
        for (int i = 0; i < end && j<end; i++,j++) {
            while (j< end && nums[j] == 0) {
                j++;
            }
            if(j!=end){
                swap(nums[i],nums[j]);
            }
        }
    }
};

class Solution3 {
    public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) return;
        
        int i = 0, j = 0;
        while (i < len && j < len) {
            while (i < len && nums[i] != 0) {
                i++;
            }
            j = max(j, i); 
            while (j < len && nums[j] == 0) {
                j++;
            }
            if (i < len && j < len) {
                swap(nums[i], nums[j]);
                i++; 
            }
        }   
    }
};
