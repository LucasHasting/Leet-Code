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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* to_remove = head;
        ListNode* to_connect = head;
        ListNode* temp = head;
        short count = 0;

        if(n == 1){
            while(temp != nullptr){
                if(count > 1){
                    to_remove = to_remove->next;
                }
                temp = temp->next;
                ++count;
            }
            if(count == 1){
                return nullptr;
            }
            to_remove->next = nullptr;
            return head;
        }

        while(temp != nullptr){
            if(count > n-1){
                to_remove = to_remove->next;
            }

            if(count > n){
                to_connect = to_connect->next;
            }

            temp = temp->next;
            ++count;
        }

        if(count == n){
            head = head->next;
            return head;
        }

        to_connect->next = to_remove->next;
        return head;
    }
};
