struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode *t = NULL, *p = head, *q = head->next;
    head->next = NULL;
    while (q != NULL)
    {
        t = q;
        q = q->next;
        t->next = p;
        p = t;
    }
    head = p;
    return head;
}