class MyCircularDeque {
public:
    deque<int> q;
    int limit=0;
    MyCircularDeque(int k) {
        limit=k;
    }
    
    bool insertFront(int value) {
        if(q.size()<limit){
            q.push_front(value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(q.size()<limit){
            q.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(q.size()>=1){
            q.pop_front();
            return true;
        }
        else return false;
    }
    
    bool deleteLast() {
        if(q.size()>=1){
            q.pop_back();
            return true;
        }
        else return false;
    }
    
    int getFront() {

        if(q.size()==0)return -1;
        return q.front();
    }
    
    int getRear() {
        if(q.size()==0)return -1;
        return q.back();
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        return q.size()==limit?true:false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */