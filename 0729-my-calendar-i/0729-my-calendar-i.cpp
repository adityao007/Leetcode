#include <vector>
#include <iostream>
using namespace std;

class MyCalendar {
private:
    vector<pair<int, int>> bookings;

public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        // Check for overlap with existing bookings using a simple loop
        for (int i = 0; i < bookings.size(); i++) {
            int s = bookings[i].first;
            int e = bookings[i].second;
            if (start < e && end > s) {  // Overlap condition
                return false;
            }
        }
        // If no overlap, add the new booking
        bookings.push_back({start, end});
        return true;
    }
};

