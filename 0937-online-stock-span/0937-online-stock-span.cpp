class StockSpanner {
public:
    stack<pair<int, int>> s;
    StockSpanner() {   
    }
    int next(int price) {
        int counter = 1;
        while (!s.empty() && s.top().first <= price) {
            counter += s.top().second;  
            s.pop();
        }
        s.push({price, counter});
        return counter;
    }
};