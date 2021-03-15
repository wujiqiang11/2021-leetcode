


struct ListNode {
 	int val;
 	struct ListNode *next;
};


class Solution {
public:
    /**
     *
     * @param head ListNodeÀà the head node
     * @return ListNodeÀà
     */
    ListNode* sortInList(ListNode* head) {
        if (head == nullptr||head->next==nullptr)
            return head;
        ListNode* re1;
        ListNode* re2;
        ListNode* mid = partition(head);
        ListNode* head2 = mid->next;
        mid->next = nullptr;
        re1 = sortInList(head);
        re2 = sortInList(head2);
        mid->next = re2;
        return re1;
    }
    ListNode* partition(ListNode* head)
    {
        ListNode* p1_last = head;
        if (head->next == nullptr)
            return p1_last;
        
        ListNode* p1;
        ListNode* p2;
        ListNode* pivot = head;
        int temp;
        p1 = head->next;
        p2 = head->next;
        while (p2)
        {
            if (p2->val < pivot->val)
            {
                temp = p2->val;
                p2->val = p1->val;
                p1->val = temp;
                p1 = p1->next;
                p1_last = p1_last->next;
                p2 = p2->next;
            }
            else
            {
                p2 = p2->next;
            }
        }
        temp = p1_last->val;
        p1_last->val = pivot->val;
        pivot->val = temp;
        return p1_last;
    }
};