// https://leetcode.com/problems/linked-list-cycle/
// O(N^2) solution. The idea: use two pointers. The goal is to detect a cycle
// by 'removing' each edge, while keeping track of the removed edge. The 
// intuition here is that if an edge is removed, the connected node to the
// removed edge can still be reached if there is a cycle.

// O(N) solution can be attained using the simple Floyd's Tortoise and Hare
// algorithm.

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
    bool hasCycle(ListNode *head) {
        ListNode* tmp = head;
        ListNode* curr_node = head;
        
        if (curr_node == NULL) return false;
        
        ListNode * target_node = head->next;
        
        if (target_node == NULL) return false;
        
        while(target_node != NULL) {
            tmp = head;
            while(tmp != NULL) {
                if (tmp == target_node) return true;
                if (tmp == curr_node) {
                    tmp = NULL;
                } else {
                    tmp = tmp->next;
                }
            }
            curr_node = target_node;
            target_node = target_node->next;
        }
        
        return false;
    }
};