class Solution
{
public:
    ListNode *solve(ListNode *LL1, ListNode *LL2)
    {

        if (LL1->next == NULL)
        {
            LL1->next = LL2;
            return LL1;
        }
        ListNode *curr1 = LL1;
        ListNode *next1 = curr1->next;
        ListNode *curr2 = LL2;
        ListNode *next2 = curr2->next;
        while (next1 != NULL && curr2 != NULL)
        {
            if ((curr2->val >= curr1->val) && (curr2->val <= next1->val))
            {
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;
                curr1 = curr2;
                curr2 = next2;
            }
            else
            {
                curr1 = next1;
                next1 = next1->next;
                if (next1 == NULL)
                {
                    curr1->next = curr2;
                    return LL1;
                }
            }
        }
        return LL1;
    }

public:
    ListNode *mergeTwoLists(ListNode *first, ListNode *second)
    {
        if (first == NULL)
        {
            return second;
        }
        if (second == NULL)
        {
            return first;
        }
        if (first->val <= second->val)
        {
            return solve(first, second);
        }
        else
        {
            return solve(second, first);
        }
    }
};