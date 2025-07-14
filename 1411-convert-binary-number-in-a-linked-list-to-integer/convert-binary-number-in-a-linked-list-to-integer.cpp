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
    int getDecimalValue(ListNode* head) {
        auto p = head;
        int n = 0;

        while(p){
            n++;
            p = p->next;
        }

        p = head;
        int num = 0;
        while(p){
            n--;
            if(p->val == 1) num += (1<<n);
            p = p->next;
        }
        return num;
    }
};