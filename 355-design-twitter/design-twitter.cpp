// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:
//
//
//
// postTweet(userId, tweetId): Compose a new tweet.
// getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
// follow(followerId, followeeId): Follower follows a followee.
// unfollow(followerId, followeeId): Follower unfollows a followee.
//
//
//
// Example:
//
// Twitter twitter = new Twitter();
//
// // User 1 posts a new tweet (id = 5).
// twitter.postTweet(1, 5);
//
// // User 1's news feed should return a list with 1 tweet id -> [5].
// twitter.getNewsFeed(1);
//
// // User 1 follows user 2.
// twitter.follow(1, 2);
//
// // User 2 posts a new tweet (id = 6).
// twitter.postTweet(2, 6);
//
// // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
// twitter.getNewsFeed(1);
//
// // User 1 unfollows user 2.
// twitter.unfollow(1, 2);
//
// // User 1's news feed should return a list with 1 tweet id -> [5],
// // since user 1 is no longer following user 2.
// twitter.getNewsFeed(1);
//
//


typedef struct Tweet {
    int id;
    int timestamp;
    int user_id;
    
    Tweet(int index, int t, int user) : id(index), timestamp(t), user_id(user) {}
}*pTweet;

struct Comp {
    bool operator()(const Tweet &a, const Tweet &b) {
        return a.timestamp < b.timestamp;
    }
};

class Twitter {
private:
    int timestamp = 0;
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int user_id, int tweetId) {
        Tweet t(tweetId, timestamp, user_id);
        timestamp++;
        auto it = tweets.find(user_id);
        if (it == tweets.end()) {
            vector<Tweet> v = {t};
            tweets[user_id] = v;
        }
        else {
            it->second.push_back(t);
        }
        auto itf = follows.find(user_id);
        if (itf == follows.end()) {
            unordered_set<int> v;
            follows[user_id] = v;
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int user_id) {
        priority_queue<Tweet, vector<Tweet>, Comp> pq;
        vector<int> res;
        auto it = follows.find(user_id);
        if (it == follows.end()) return res;
        unordered_map<int, int> recorder;
        auto usit = it->second.begin();
        while (usit != it->second.end()) {
            int cur_user = *usit;
            if (cur_user == user_id) {usit++; continue;}
            auto itt = tweets.find(cur_user);
            if (itt != tweets.end()) {
                int len = itt->second.size();
                if (len > 0) {
                    pq.push(itt->second[len - 1]);
                    recorder[cur_user] = len - 1;
                }
            }
            usit++;
        }
        auto myself = tweets.find(user_id);
        if (myself != tweets.end()) {
            int ml = tweets[user_id].size();
            if (ml > 0) {
                pq.push(tweets[user_id][ml - 1]);
                recorder[user_id] = ml - 1;
            }
        }
        while (pq.size() != 0) {
            Tweet pt = pq.top();
            pq.pop();
            res.push_back(pt.id);
            int cur = pt.user_id;
            if (recorder[cur] > 0) {
                recorder[cur]--;
                pq.push(tweets[cur][recorder[cur]]);
            }
            if (res.size() >= 10)
                break;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int from_user_id, int to_user_id) {
        auto it = follows.find(from_user_id);
        if (it != follows.end()) {
            it->second.insert(to_user_id);
        }
        else {
            unordered_set<int> os;
            os.insert(to_user_id);
            follows[from_user_id] = os;
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int from_user_id, int to_user_id) {
        auto it = follows.find(from_user_id);
        if (it != follows.end()) {
            auto it2 = it->second.find(to_user_id);
            if (it2 != it->second.end()) {
                it->second.erase(it2);
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
