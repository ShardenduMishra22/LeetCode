// class Solution {
// public:
//     int sizell(ListNode* head){
//         int cnt = 0;
//         while(head){
//             cnt++;
//             head = head->next;
//         }
//         return cnt;
//     }

//     vector<ListNode*> splitListToParts(ListNode* head, int k) {
//         int size = sizell(head);
//         vector<ListNode*> ans(k, nullptr);
//         int n1 = size / k;
//         int n2 = size % k;
//         ListNode* temp = head;

//         for(int i = 0; i < k && temp; i++) {
//             ans[i] = temp;
//             int partSize = n1 + (n2-- > 0 ? 1 : 0);
//             for(int j = 1; j < partSize; j++) {
//                 temp = temp->next;
//             }
//             ListNode* nextPart = temp->next;
//             temp->next = nullptr;
//             temp = nextPart;
//         }

//         return ans;
//     }
// };