#include <iostream>
#include <queue>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        q.push_back(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        deque<int> temp;
        while(q.size()!=1){
            temp.push_back(q.back());
            q.pop_back();
        }
        q.pop_back();
        while(temp.size()!=0){
            q.push_back(temp.back());
            temp.pop_back();
        }
    }

    // Get the front element.
    int peek(void) {
        deque<int> temp;
        int rt_val;
        while(q.size()!=1){
            temp.push_back(q.back());
            q.pop_back();
        }
        rt_val=q.back();
        while(temp.size()!=0){
            q.push_back(temp.back());
            temp.pop_back();
        }
        return rt_val;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return q.size()==0;
    }

    deque<int> q;
};


int main() {
    Queue q;
    cout<<q.empty();
    q.push(1);
    q.push(2);
    q.peek();
    return 0;
}