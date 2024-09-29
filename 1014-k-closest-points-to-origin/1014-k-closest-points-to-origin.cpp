class Car {
public:
    int idx;
    int distSq;

    Car(int idx, int distSq) {
        this->idx = idx;
        this->distSq = distSq;
    }

    bool operator<(const Car& obj) const {
        return this->distSq > obj.distSq;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<Car> cars;

        for (int i = 0; i < points.size(); i++) {
            int distSq = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            cars.push_back(Car(i, distSq));
        }

        priority_queue<Car> pq(cars.begin(), cars.end());

        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            int idx = pq.top().idx;
            result.push_back(points[idx]);
            pq.pop();
        }

        return result;
    }
};