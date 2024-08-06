// class Solution {
// public:
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         ListNode* prev = head;
//         head = head->next;
//         int i = 1, MnDst = INT_MAX, prev_i = INT_MIN, first_i = -1;

//         while (head->next != nullptr) {
//             if((prev->val < head->val && head->val > head->next->val) ||
//             (prev->val > head->val && head->val < head->next->val)) {
//                 if (prev_i != INT_MIN) {
//                     MnDst = min(MnDst, i - prev_i);
//                 }
//                 if (first_i == -1) {
//                     first_i = i;
//                 }
//                 prev_i = i;
//             }
//             prev = head;
//             head = head->next;
//             i++;
//         }

//         if (MnDst == INT_MAX) {
//             return {-1, -1};
//         }

//         return {MnDst, prev_i - first_i};
//     }
// };