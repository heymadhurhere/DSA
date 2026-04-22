class Twitter {
    unordered_map<int, unordered_set<int>> mpp2;
    // user -> influencer1, influencer2.... etc;
    unordered_map<int, vector<pair<int, int>>> tweets;
    // {userId, tweetId, time}
    int tweet_no = 0;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweet_no, tweetId});
        tweet_no++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;

        unordered_set<int> allowed = mpp2[userId];
        allowed.insert(userId);

        for (int uid : allowed) {
            int n = tweets[uid].size();

            for (int i = max(0, n - 10); i < n; i++) {
                pq.push(tweets[uid][i]);
            }
        }

        while (!pq.empty()and res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            mpp2[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        mpp2[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */