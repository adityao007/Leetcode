class MyCircularQueue {
private:
    int* arr;
    int k;
    int currSize;
    int f;
    int r;

public:
    MyCircularQueue(int k) {
        this->k = k;
        arr = new int[k];
        currSize = 0;
        f = 0;
        r = -1;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        r = (r + 1) % k;
        arr[r] = value;
        currSize++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        f = (f + 1) % k;
        currSize--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return arr[f];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[r];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == k;
    }
};
