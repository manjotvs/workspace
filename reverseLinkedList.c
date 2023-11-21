struct ListNode* reverseList(struct ListNode* head)
{
    if((head== NULL) || (head->next == NULL ))
        return head;
    
    struct ListNode* itr = reverseList(head->next);
    head->next= NULL;
    struct ListNode* itr1 = itr;
    while(itr->next!= NULL)
        itr = itr->next;
    itr->next = head;
    return(itr1);
}
