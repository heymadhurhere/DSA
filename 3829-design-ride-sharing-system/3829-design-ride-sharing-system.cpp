class RideSharingSystem {
public:
    vector<pair<int, bool>> driver, rider;
    int idxR = 0;
    int idxD = 0;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push_back({riderId, false});
    }
    
    void addDriver(int driverId) {
        driver.push_back({driverId, false});
    }
    
    vector<int> matchDriverWithRider() {
        while (idxD < driver.size() && driver[idxD].second == true) idxD++;
        while (idxR < rider.size() && rider[idxR].second == true) idxR++;
        if (idxD < driver.size() && idxR < rider.size()) {
            driver[idxD].second = true;
            rider[idxR].second = true;
            return {driver[idxD++].first, rider[idxR++].first};
        }
        return {-1, -1};
    }
    
    void cancelRider(int riderId) {
        for (int i = 0; i < rider.size(); i++) {
            if (rider[i].first == riderId) {
                rider[i].second = true;
                return;
            }
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */