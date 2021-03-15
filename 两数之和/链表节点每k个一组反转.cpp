
struct ListNode {
 	int val;
 	struct ListNode *next;
  };


class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr)
            return head;
        ListNode* K_node=head;
        ListNode* pre_head;
        bool first = true;
        ListNode* p1;
        ListNode* p2;
        ListNode* p3;
        ListNode* p4;
        int temp;
        while (1)
        {
            temp = 0;
            p1 = K_node;
            p4 = K_node;

            if (K_node == nullptr)
            {
                return head;
            }
            while (temp < k-1)
            {
                K_node = K_node->next;
                if (K_node == nullptr)
                {
                    return head;
                }
                temp++;
            }
            K_node = K_node->next;
            p2 = p1->next;
            p1->next = nullptr;
            while (p2!=K_node)
            {
                p3 = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = p3;
            }
            if (first)
            {
                head = p1;
                p4->next = K_node;
                pre_head = p4;
                first = false;
            }
            else
            {
                pre_head->next = p1;
                p4->next = K_node;
                pre_head = p4;
            }
        }
        // write code here
    }
};