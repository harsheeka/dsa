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
        ListNode *a= l1,*b=l2,*head= new ListNode(0),*curr=head;
        int carry=0;
        while(a || b|| carry!=0){
            int sum=carry;
            if(a!=nullptr){
                sum+=a->val;
                a=a->next;
            }
            if(b!=nullptr){
                sum+=b->val;
                b=b->next;
            }
            curr->next= new ListNode(sum%10);
            curr=curr->next;
            carry=sum/10;
        }
        return head->next;
        
    }
};