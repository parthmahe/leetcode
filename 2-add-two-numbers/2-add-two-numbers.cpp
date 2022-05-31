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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res=new ListNode;
        ListNode *sum=res;
        int carry=0;
        while(l1||l2)
        {
            int val1=l1==NULL?0:l1->val;
            int val2=l2==NULL?0:l2->val;
            
            int newval=val1+val2+carry;
            if(newval>9)
            {
                res->val=newval%10;
                carry=1;
            }
            else
            {
                res->val=newval;
                carry=0;
            }
            l1= l1==NULL?NULL:l1->next;
            l2= l2==NULL?NULL:l2->next;
            
            if(carry==1)
            {
                res->next=new ListNode(1);
                res=res->next;
            }
            else if(l1 || l2)
            {
                ListNode* nextnode=new ListNode();
                res->next=nextnode;
                res=res->next;
            }
        }
        return sum;
}};