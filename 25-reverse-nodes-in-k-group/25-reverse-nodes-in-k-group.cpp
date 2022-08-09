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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*tmp=head;
        for(int i=0;i<k;i++)
        {
            if(tmp==NULL) return head;
            tmp=tmp->next;
        }
        ListNode*prev=NULL;
        ListNode*nxt=NULL;
        ListNode*curr=head;
        for(int i=0;i<k;i++)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};