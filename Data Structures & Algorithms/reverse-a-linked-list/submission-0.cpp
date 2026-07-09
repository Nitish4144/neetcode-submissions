/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* f(ListNode* prev, ListNode* curr){
        ListNode* t = curr->next;
        curr->next = prev;
        if(t == nullptr ) return curr;
        else{
            return f(curr,t);
        }

    }
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* temp = head->next;
        head->next = nullptr;
        return f(head,temp);
    }
};
