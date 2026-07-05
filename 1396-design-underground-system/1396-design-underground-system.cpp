struct hash_pair {
    size_t operator()(const pair<string, string>& p) const {
        return hash<string>()(p.first) ^ (hash<string>()(p.second) << 1);
    }
};
class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>>
        enter; // id -> {startStation, startTime}
    unordered_map<pair<string, string>, pair<int, int>, hash_pair>
        out; // {startStation, startTime} -> {time,
             // timesTravelled_between_these_two}
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        if (enter.find(id) ==
            enter.end()) { // person can only checkIn at one place
            enter[id] = {stationName, t};
        }
    }

    void checkOut(int id, string stationName, int t) {
        string startStation = enter[id].first;
        int startTime = enter[id].second;
        enter.erase(id);
        int diff = t - startTime;

        if (out.find({startStation, stationName}) == out.end()) {
            out[{startStation, stationName}] = {diff, 1};
        } else {
            int time = out[{startStation, stationName}].first;
            int cnt = out[{startStation, stationName}].second;
            time += diff;
            cnt += 1;
            out[{startStation, stationName}] = {
                time, cnt}; // {total_time_taken_till_now,
                            // total_stations_travelled_till_now}
        }
    }

    double getAverageTime(string startStation, string endStation) {
        int time = out[{startStation, endStation}].first;
        int cnt = out[{startStation, endStation}].second;
        double ans = (double)time / (double)cnt;
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */