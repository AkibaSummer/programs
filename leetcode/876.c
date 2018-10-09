/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getAns(struct ListNode* head,int now,int *deep){
    if (head==NULL)return 0;
    *deep=now;
    struct ListNode* ret=getAns(head->next,now+1,deep);
    if (now==(*deep+2)/2)return head;
    else return ret;
}
struct ListNode* middleNode(struct ListNode* head) {
    int length=0;
    return getAns(head,1,&length);
}