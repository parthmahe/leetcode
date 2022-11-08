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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head)
            return head;
        
        ListNode* p=head;
        
        int count=1;
        
        while(p->next!=NULL)
        {
            count++;
            p=p->next;
        }
        
        if(!(k%count))
            return head;
        
        
        
        ListNode* pre=NULL;
        ListNode* nxt=head;
        
        k=k%count;
        
        for(int x=1;x<=count-k;x++)
        {
            pre=nxt;
            nxt=nxt->next;
            
        }
         pre->next=NULL;
         p->next=head;
         head=nxt;
        return head;
        
    }
};