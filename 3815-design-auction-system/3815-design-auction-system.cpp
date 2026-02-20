// all this for ordered_set use to avoid the header file missing error
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <unordered_map>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class AuctionSystem {
public:
    unordered_map<int, unordered_map<int, int>> mpp;
    unordered_map<int, unordered_map<int, int>> mpp2;
    unordered_map<int, ordered_set<pair<int, int>>> mpp3;

    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        mpp[userId][itemId] = bidAmount;
        bool flag = false;

        if (mpp2[itemId].find(userId) != mpp2[itemId].end())
            flag = true;

        int amt = mpp2[itemId][userId];
        mpp2[itemId][userId] = bidAmount;

        if (flag) {
            mpp3[itemId].erase({amt, userId});
        }
        mpp3[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        mpp[userId][itemId] = newAmount;
        bool flag = false;

        if (mpp2[itemId].find(userId) != mpp2[itemId].end())
            flag = true;

        int amt = mpp2[itemId][userId];
        mpp2[itemId][userId] = newAmount;

        if (flag) {
            mpp3[itemId].erase({amt, userId});
        }
        mpp3[itemId].insert({newAmount, userId});
    }

    void removeBid(int userId, int itemId) {
        mpp.erase(userId);

        int amt = mpp2[itemId][userId];
        mpp2[itemId].erase(userId);

        if (mpp2[itemId].empty())
            mpp2.erase(itemId);

        mpp3[itemId].erase({amt, userId});

        if (mpp3[itemId].empty()) {
            mpp3.erase(itemId);
        }
    }

    int getHighestBidder(int itemId) {
        if (mpp3.find(itemId) == mpp3.end())
            return -1;
        int ans = mpp3[itemId].rbegin()->second;
        return ans;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */