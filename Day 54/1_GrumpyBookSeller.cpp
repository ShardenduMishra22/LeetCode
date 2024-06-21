//sliding window approach
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int n = customers.size();
        int CstmrNotGrmpy = 0;
        for(int i=0;i<n;i++){
            CstmrNotGrmpy += (1-grumpy[i])*(customers[i]);
        }

        int CstmrGrmpy = 0;
        for(int i=0;i<k;i++){
            CstmrGrmpy += grumpy[i]*customers[i];
        }
        int mx = CstmrGrmpy;

        for(int i=k;i<n;i++){
            CstmrGrmpy += customers[i]*grumpy[i];
            CstmrGrmpy -= customers[i-k]*grumpy[i-k];

            mx = max(mx,CstmrGrmpy);
        }

        return CstmrNotGrmpy + mx;
    }        
};

// brute force
// class Solution {
// public:
//     int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
//         int sum = 0;
//         for(int i=0;i<grumpy.size();i++){
//             sum += customers[i]*(1-grumpy[i]);
//         }
//         int mx = 0;
//         for(int i=0;i<=grumpy.size()-k;i++){
//             int cr = 0;
//             for(int j=i;j<i+k;j++){
//                 cr += grumpy[j]*customers[j];
//             }
//             mx = max(mx,cr);
//         }

//         return sum + mx;
//     }        
// };