/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL)
        return NULL;

    struct ListNode* pre=NULL;
    struct ListNode* cur=head;
    struct ListNode* back=head->next;

    while(cur->next!=NULL){
        
        cur->next=pre;
        pre=cur;
        cur=back;
        back=back->next;
    }

    head=cur;
    return head;
}