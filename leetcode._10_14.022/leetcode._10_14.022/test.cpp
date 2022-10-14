struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)//相遇
        {
            struct ListNode* meet = fast;
            slow = head;
            while (slow != meet)//看板书链表带环
            {
                slow = slow->next;
                meet = meet->next;
            }
            return meet;
        }
    }
    return NULL;
}