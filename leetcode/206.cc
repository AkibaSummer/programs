/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode* pre(NULL),*now;
        while (head->next!=NULL){
            now=head;
            head=head->next;
            now->next=pre;
            pre=now;
        }
        head->next=pre;
        return head;
    }
};