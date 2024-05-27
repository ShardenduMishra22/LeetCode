// 1.) MERGE  2 SORTED LINKED LSIT 
// Problem number 21



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                if(head == nullptr){
                    head = tail = list1;
                    list1 = list1->next;
                }else{
                    tail->next = list1;
                    tail = list1;
                    list1 = list1->next;
                }
            }else{
                if(head == nullptr){
                    head = tail = list2;
                    list2 = list2->next;
                }else{
                    tail->next = list2;
                    tail = list2;
                    list2 = list2->next;
                }
            }
        }
        while (list1 != nullptr) {
            if (tail != nullptr) {
                tail->next = list1;
            } else {
                head = list1;
            }
            tail = list1;
            list1 = list1->next;
        }

        while (list2 != nullptr) {
            if (tail != nullptr) {
                tail->next = list2;
            } else {
                head = list2;
            }
            tail = list2;
            list2 = list2->next;
        }
        
        return head;
    }
};