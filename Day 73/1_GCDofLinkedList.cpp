// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     // How to find gcd // ill use built in method
//     // int gcd(int a, int b) {
//     //     while (b != 0) {
//     //         int t = b;
//     //         b = a % b;
//     //         a = t;
//     //     }
//     //     return a;
//     // }

//     ListNode* insertGreatestCommonDivisors(ListNode* head) {
//         ListNode* prev = head;
//         ListNode* frwd = head->next;
//         while(frwd){
//             int num = __gcd(prev->val,frwd->val);
//             ListNode* curr = new ListNode(num);
//             curr->next = frwd;
//             prev->next = curr;

//             prev = frwd;
//             frwd = frwd->next;
//         }

//         return head;
//     }
// };