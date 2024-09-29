#include<bits/stdc++.h>
using namespace std;

class MyCalendar {
private:
    vector<pair<int, int>> calendar;

public:
    bool book(int start, int end) {
        for (const auto& interval : calendar) {
            int s = interval.first;
            int e = interval.second;
            if (start < e && s < end) {
                return false;
            }
        }
        calendar.emplace_back(start, end);
        return true;
    }
};