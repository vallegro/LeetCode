#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };

using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int length{0};
        ListNode* cur{head};
        while(cur!=nullptr){
            length++;
            cur = cur->next;
        }

        if(length<=1)
            return head;
        int mid = length/2;
        int i{1};
        cur=head;
        while(i<mid){
            cur=cur->next;
            i++;
        }
        ListNode * l1{head},*l2{cur->next};
        cur->next = nullptr;
        l1 = sortList(l1);
        l2 = sortList(l2);
        return merge(l1,l2);
    }

    ListNode* merge(ListNode * l1,ListNode* l2){
        ListNode * cur1{l1}, *cur2{l2}, *head, *cur;
        if(cur1->val<cur2->val){
            head = cur1;
            cur1 = cur1->next;
            cur = head;
        }
        else{
            head = cur2;
            cur2 = cur2->next;
            cur = head;
        }

        while(cur1!=nullptr&&cur2!=nullptr){
            if(cur1->val<cur2->val){
                cur->next = cur1;
                cur1 = cur1->next;
                cur = cur->next;
            }
            else{
                cur->next = cur2;
                cur2 = cur2->next;
                cur = cur->next;
            }
        }

        if(cur1!=nullptr){
            cur ->next = cur1;
        }
        else{
            cur ->next = cur2;
        }

        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1), *cur = head;
    cur ->next = new ListNode(5), cur = cur->next;
    cur ->next = new ListNode(9), cur = cur->next;
    cur ->next = new ListNode(4), cur = cur->next;

    Solution s;
    head = s.sortList(head);

    cur = head;
    while(cur){
        cout<<cur->val;
        cur = cur->next;
    }
}