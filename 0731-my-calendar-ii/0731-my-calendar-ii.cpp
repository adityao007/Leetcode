class MyCalendarTwo {
public:
    vector<pair<int, int>> bookings; 
    vector<pair<int, int>> overlaps;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (int i = 0; i < overlaps.size(); i++) {
            int s = overlaps[i].first;
            int e = overlaps[i].second;
            if (start < e && end > s) {  // Overlap condition with double bookings
                return false;
            }
        }
        for (int i = 0; i < bookings.size(); i++) {
            int s = bookings[i].first;
            int e = bookings[i].second;
            if (start < e && end > s) {  // Overlap condition with single bookings
                overlaps.push_back({max(start, s), min(end, e)});
            }
        }
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */