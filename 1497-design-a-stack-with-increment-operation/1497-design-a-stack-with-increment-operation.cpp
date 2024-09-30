class CustomStack {
public:
    vector<int> stack;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }

    int pop() {
        if (stack.empty()) {
            return -1;
        } else {
            int topElement = stack.back();
            stack.pop_back();
            return topElement;
        }
    }

    void increment(int k, int val) {
        int limit = min(k, (int)stack.size());
        for (int i = 0; i < limit; ++i) {
            stack[i] += val;
        }
    }
};