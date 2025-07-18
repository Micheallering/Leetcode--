
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA==NULL ||headB==NULL)
        return NULL;

    struct ListNode* listA=headA;
    struct ListNode* listB=headB;
    int distA=0;  //用于记录链表A的长度
    int distB=0;  //用于记录链表B的长度
    
    for(;listA->next!=NULL;listA=listA->next)     //循环计算出长度
        distA++;
        
    for(;listA->next!=NULL;listA=listA->next)
        distB++;

    //尾指针都不在一起，一定没有交叉点！
    if(listA!=listB)
        return NULL;
    
    //让更长的那一个链表，先多走多出来的部分
    if(distA > distB){                      
        for(int i=1 ; i <= distA-distB ; i++)
            headA = headA->next;
    }
    else{
        for(int i=1 ; i <= distB-distA ; i++)
            headB = headB->next;
    }

    //两个链表剩余量一样了，开始一起走，并逐个比对值是否相等
    while(headA != headB){       //判断是否为交点，必须判断节点地址是否相等（即指针相等 headA == headB），不能只比较值！因为“相交”指的是 两个链表共享节点对象本身（即地址相同），并不是值相同。
        headA = headA->next;
        headB = headB->next;
    }
    return headA;

}
