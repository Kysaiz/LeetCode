/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    unsigned short d = 0;

    struct ListNode *h = NULL;
    struct ListNode *h1 = l1;
    struct ListNode *h2 = l2;
    h = malloc(sizeof(struct ListNode));
    h->next = NULL;
    struct ListNode *head = h;

    while(1)
    {
        d = d + h1->val + h2->val;
        h->val = d%10;
        d = d/10;
        
        if (h1->next != NULL || h2->next != NULL)
        {
            h->next = malloc(sizeof(struct ListNode));
            h->next->next = NULL;
            h = h->next;
        }
        else if (d == 0)
        {
            break;
        }
        else
        {
            h->next = malloc(sizeof(struct ListNode));
            h->next->next = NULL;
            h->next->val = d;
            break;
        }

        if (h1->next != NULL)
        {
            h1 = h1->next;
        }
        else 
        {
            h1->val = 0;
        }

        if (h2->next != NULL)
        {
            h2 = h2->next;
        }
        else 
        {
            h2->val = 0;
        }
    }

    return head;
}