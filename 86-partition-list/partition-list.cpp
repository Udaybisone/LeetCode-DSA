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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        auto i = head;
        auto j = i->next;
        while(i!=NULL){
            if(i->val < x) {
                i = i->next;
                if(i) j = i->next;
                continue;
            }
            while(j!=NULL && j->val>=x) j = j->next;
            if(j==NULL) break;
            int value = j->val;
            auto k = i;
            while(k!=j){
                int temp = k->val;
                k->val = value;
                value = temp;
                k = k->next;
            }
            k->val = value;
            i = i->next;
            j = j->next;
        }
        return head;
    }
};