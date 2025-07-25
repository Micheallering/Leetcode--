/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1==NULL&&list2==NULL)
        return NULL;
    if(list1==NULL && list2!=NULL)
        return list2;
    else if(list1!=NULL && list2==NULL)
        return list1;
    
    if(list1!=NULL && list2!=NULL){
        //建一个新链表
        struct ListNode* head=NULL;     //新链表头节点
        struct ListNode* cur=NULL;     //指向新链表当前位置
        
        //当两个链表中的一个结束时，循环停止
        while(list1 !=NULL && list2 !=NULL){
            //先确定头节点head指向list1 or list2
            if(list1->val > list2->val){
                head = list2;
                cur=head;
                list2=list2->next;
            }
            else{
                head = list1;
                cur=head;
                list1=list1->next;
            }

            if(list1->val <= list2->val){
                cur->next = list1;
                list1 = list1->next;
            }
            else{
                cur->next = list2;
                list2 = list2->next;
            }
        }

        //把剩下的接上
        if(list1!=NULL)
                cur->next=list1;
        else if(list2!=NULL)
                cur->next=list2;

        return head;
    }
}