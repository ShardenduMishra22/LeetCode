#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode*curr = head;
        ListNode*frwd = head->next;
        while(frwd != NULL){
            if(frwd->val == curr->val){;
                curr->next = frwd->next;
                delete frwd;
                frwd = curr->next;
            }else{
                curr = frwd;
                frwd = frwd->next;
            }
        }
        return head;
    }
};