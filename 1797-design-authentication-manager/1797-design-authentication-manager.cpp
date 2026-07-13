class AuthenticationManager {
public:
    int TTL = 0;
    unordered_map<string, int> mpp;
    AuthenticationManager(int timeToLive) { TTL = timeToLive; }

    void generate(string tokenId, int currentTime) {
        mpp[tokenId] = currentTime;
    }

    void renew(string tokenId, int currentTime) {
        if (mpp.count(tokenId)) {
            if (mpp[tokenId] + TTL > currentTime) {
                mpp[tokenId] = currentTime;
            }
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for (auto& it : mpp) {
            if (it.second + TTL > currentTime)
                ans++;
        }
        return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */