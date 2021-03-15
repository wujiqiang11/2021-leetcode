
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* result;
        ListNode* tail;
        bool first = true;
        int temp = 0;
        int n1 = 0;
        int n2 = 0;
        int n3 = 0;
        while (p1||p2||n3!=0)
        {
            if (p1)
            {
                n1 = p1->val;
                p1 = p1->next;
            }
            else
            {
                n1 = 0;
            }

            if (p2)
            {
                n2 = p2->val;
                p2 = p2->next;
            }
            else
            {
                n2 = 0;
            }

            temp = n1 + n2 + n3;

            n3 = temp / 10;
            temp = temp % 10;
            
            if (first)
            {
                tail = new ListNode(temp);
                result = tail;
                first = false;
            }
            else
            {
                tail->next = new ListNode(temp);
                tail = tail->next;
            }
            
        }
        return result;
    }
};