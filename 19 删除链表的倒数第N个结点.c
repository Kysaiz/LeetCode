/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *p = head;
    struct ListNode *q = head;
    for(; p->next != NULL; p = p->next)
    {
        if (n == 0)
        {
            q = q->next;
        }
        else
        {
            n--;
        }
    }
    
    struct ListNode *temp;
    if (n > 0)
    {
        return head->next;
    }
    else if (q->next == NULL)
    {
        return NULL;
    }
    else if (q->next->next != NULL)
    {  
        temp = q->next->next;
    }
    else
    {
        temp = NULL;
    }
    q->next = temp;
    
    return head;
}