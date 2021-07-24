/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                break;
            }
        }
        if(fast == NULL || fast->next == NULL)
        {
            return NULL;
        }
        else
        {
            ListNode* temp = head;
            while(temp != fast)
            {
                temp = temp->next;
                fast = fast->next;
            }
            return temp;
        }
    }
};