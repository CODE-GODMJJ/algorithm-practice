struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    struct ListNode* currentA = headA;
    struct ListNode* currentB = headB;

    while (currentA != currentB)
    {
        currentA = currentA == NULL ? headB : currentA->next;
        currentB = currentB == NULL ? headA : currentB->next;
    }

    return currentA;
}
