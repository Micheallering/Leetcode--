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
    struct ListNode* back;      //不能让back直接=head->next。因为在 head != NULL 但 head->next == NULL 时，这句会运行，之后访问 back->next 时，就是访问空指针就会崩溃。

    while(cur->next!=NULL){
        back=cur->next;
        cur->next=pre;
        pre=cur;
        cur=back;
        // 所以不能back=back->next这么写
    }

    
    return pre;  //pre是新头节点