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
    ListNode* removeElements(ListNode* head, int val) {
        while (head!=NULL&&head->val==val){
            delete head;
            head=head->next;
        }
        if (head==NULL)return head;
        ListNode* ret=head;
        while (head->next!=NULL){
            if (head->next->val==val){
                ListNode* del(head->next);
                head->next=del->next;
                delete del;
            }
            else head=head->next;
        }
        return ret;
    }
};