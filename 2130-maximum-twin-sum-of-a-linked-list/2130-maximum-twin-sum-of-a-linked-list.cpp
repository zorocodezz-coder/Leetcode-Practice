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
    int fun(ListNode* head){
        int count=0;
        while(head!=nullptr){
            count++;
            head=head->next;
        }
        return count;
    }
    int pairSum(ListNode* head) {
        // int n = fun(head);
        // int half_time= n/2;

        ListNode* slow=head;
        ListNode* fast = head;
        // while(half_time--){
        //     temp=temp->next;
        // }
        while(fast!=nullptr){
            slow = slow->next;
            fast=fast->next;
            if(fast!=nullptr){
                fast = fast->next;
            }
        }

        ListNode* curr= slow;
        ListNode* prev = nullptr;
        ListNode* fut = slow;
        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }

        int maxi_sum=0;
        while(prev!=nullptr){
            maxi_sum=max(maxi_sum,head->val+prev->val);
            head=head->next;
            prev=prev->next;
        }
        return maxi_sum;
    }
};