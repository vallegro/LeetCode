#include <iostream>

using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr||headB==nullptr) return nullptr;

        ListNode * cur{headA};
        int lengthA{0},lengthB{0}, lengthBi{0};

        while(cur->next){
            cur=cur->next;
            lengthA++;
        }
        ListNode * tailA = cur;
        lengthA ++;

        tailA->next = headA;
        cur = headB;
        bool tail_met{false};
        while(cur!=nullptr){
            if(cur ==tailA){
                tail_met=true;
            }
            if(cur == headA){
                if(tail_met) {
                    tailA->next = nullptr;
                    break;
                }
                else{
                    tailA->next = nullptr;
                    break;
                }
            }
            lengthB++;
            cur=cur->next;
        }

        if(cur== nullptr){
            tailA->next =nullptr;
            return nullptr;
        }

        if(!tail_met)
            return headA;

        inverseList(headA);

        tail_met= false;
        headA ->next = tailA;
        cur = headB;
        while(cur!=nullptr){
            if(cur == headA)
                tail_met = true;
            if(cur == tailA&&tail_met){
                headA->next = nullptr;
                break;
            }
            lengthBi++;
            cur=cur->next;
        }
        headA ->next =nullptr;

        inverseList(tailA);
        cout<<lengthB<<" "<<lengthBi<<" "<<lengthA<<endl;
        int lengthBind = (lengthB+lengthBi-lengthA+1)/2;
        cur = headB;
        for(int i{0};i<lengthBind-1;i++){
            cur=cur->next;
        }

        return cur;
    }

    ListNode* inverseList(ListNode *head){
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode *hhead = new ListNode(-1);
        hhead->next =head;
        ListNode * cur1{hhead}, *cur2{cur1->next}, *cur3{cur2->next};
        while(cur3!=nullptr){
            cur2 ->next = cur1;
            cur1 = cur2;
            cur2 = cur3;
            cur3 = cur3->next;
        }
        cur2->next = cur1;
        head->next =nullptr;
        return cur1;
    }
};


int main() {
    ListNode * heada = new ListNode(1);
    ListNode * cur = heada;
    for(int i{2};i<=12;i++) {
        cur->next = new ListNode(i);
        cur=cur->next;
    }
    ListNode* headb = heada->next;
    Solution s;
    ListNode* ans = s.getIntersectionNode(heada,headb);
    cout<<ans->val;
}