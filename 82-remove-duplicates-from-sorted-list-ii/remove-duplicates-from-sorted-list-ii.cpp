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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        auto p = head;
        auto q = head->next;
        bool f = false;
        while(q!=NULL && (f or p->val==q->val)){
            if(p->val==q->val){
                f = true;
                delete(p);
                p = q;
                q = q->next;
                continue;
            }
            if(f){
                f = false;
                delete(p);
                p = q;
                q = q->next;
            }
        }
        if(q==NULL){
            if(f){
                delete(p);
                return NULL;
            }else return p;
        }else{
           head = p; 
        }

        auto r = q->next;
        f = false;
        while(r!=NULL){
            if(q->val == r->val){
                f = true;
                p ->next = r;
                delete(q);
                q = r;
                r = r->next;
                continue;
            }
            if(f){
                f = false;
                p->next = r;
                delete(q);
                q = r;
                r = r->next;
                continue;
            }
            p = q;
            q = r;
            r = r->next;
        }
        if(f){
            p->next = r;
            delete(q);
        }
        return head;
    }
};