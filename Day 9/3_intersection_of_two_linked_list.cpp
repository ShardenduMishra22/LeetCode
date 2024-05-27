#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode* > stt;
        ListNode *curr=headA;
        while(curr!=NULL){
            stt.insert(curr);
            curr=curr->next;
        }
        ListNode *temp=headB;
        while(temp!=NULL){
            if(stt.find(temp)!=stt.end()){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }
};

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_map<ListNode*,bool> stt;
//         ListNode *curr=headA;
//         while(curr!=NULL){
//             stt[curr]=true;
//             curr=curr->next;
//         }
//         ListNode *temp=headB;
//         while(temp!=NULL){
//             if(stt[temp]){
//                 return temp;
//             }
//             temp=temp->next;
//         }
//         return NULL;
//     }
// };

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int length1=0;
//         ListNode*tempA=headA;
//         while(tempA!=NULL){
//             tempA=tempA->next;
//             length1++;
//         }
//         int length2=0;
//         ListNode*tempB=headB;
//         while(tempB!=NULL){
//             tempB=tempB->next;
//             length2++;
//         }
//         ListNode*temp1=headA;
//         ListNode*temp2=headB;
//         if(length1<length2) {
//             int move=(length2-length1);
//             for(int i=1;i<=move;i++){
//                 temp2=temp2->next;
//             }
//         }
//         if(length2<length1) {
//             int move=(length1-length2);
//             for(int i=1;i<=move;i++){
//                 temp1=temp1->next;
//             }
//         }
//         while(temp1!=temp2){
//             temp1=temp1->next;
//             temp2=temp2->next;
//         }
//         return temp1;
//     }
// };