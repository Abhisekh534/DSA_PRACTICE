class MyCircularDeque {
public:
    vector<int>arr;
    int f = 0;
    int r = 0;
    int size = 0;
    int capacity;

    MyCircularDeque(int k) {
        capacity = k;
        arr.resize(k);
    }
    
    bool insertFront(int value) {
        if(size==capacity) return false;

        f--;
        f = (f+capacity)%capacity;

        arr[f] = value;

        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size==capacity) return false;

        arr[r] = value;
        r++;
        r = r%capacity;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size==0) return false;

        f++;
        f = f%capacity;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size==0) return false;

        r--;
        r = (r+capacity)%capacity;
        size--;
        return true;
    }
    
    int getFront() {
        if(size==0) return -1;
        return arr[f];
    }
    
    int getRear() {
        if(size==0) return -1;
        return arr[(r-1+capacity)%capacity];
    }
    
    bool isEmpty() {
        return (size==0);
    }
    
    bool isFull() {
        return (size==capacity);
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