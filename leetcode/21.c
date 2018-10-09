/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void getAns(struct ListNode* l1,struct ListNode* l2,struct ListNode* now){
    if(l1==0){
        now->next=l2;
        return;
    }
    else if(l2==0){
        now->next=l1;
        return;
    }
    else {
        if (l1->val>l2->val){
            now->next=l2;
            getAns(l1,l2->next,l2);
            return;
        }
        else {
            now->next=l1;
            getAns(l1->next,l2,l1);
            return;
        }
    }
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* root=(struct ListNode *)malloc(sizeof(struct ListNode));
    root->next=NULL;
    getAns(l1,l2,root);
    return root->next;
}