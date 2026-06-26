class MyCircularQueue {
public:
    vector<int>arr;
    int f = 0;
    int r = 0;
    int size = 0;
    int capacity;

    MyCircularQueue(int k) {
        capacity = k;
        arr.reserve(k);
    }
    
    bool enQueue(int value) {
        if(size==capacity) return false;

        arr[r] = value;
        r++;
        r = r%capacity;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size==0) return false;

        f++;
        f = f%capacity;
        size--;
        return true;        
    }
    
    int Front() {
        if(size==0) return -1;
        return arr[f];
    }
    
    int Rear() {
        if(size==0) return -1;
        if(r==0) return arr[capacity-1];
        return arr[r-1];
    }
    
    bool isEmpty() {
        return (size==0);
    }
    
    bool isFull() {
        return (size==capacity);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */