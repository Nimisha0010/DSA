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
        ListNode *left = head;
        ListNode *right = head;
        while(right && right->next){
            left = left->next;
            right = right->next->next;
            if(left == right){
                left = head;
                while(left != right){
                    left = left->next;
                    right = right->next;
                }
                return left ;
            }
        }
        return nullptr;
    }
};