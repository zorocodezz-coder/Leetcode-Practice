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
        int n = fun(head);
        int half_time= n/2;

        ListNode* temp=head;
        while(half_time--){
            temp=temp->next;
        }

        ListNode* curr= temp;
        ListNode* prev = nullptr;
        ListNode* fut = temp;
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