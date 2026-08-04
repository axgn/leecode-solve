#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Tweet {
public:
  int id;
  int time;
  Tweet *next;

public:
  Tweet(int id, int time, Tweet *next = nullptr)
      : id(id), time(time), next(next) {}
};

class User {
public:
  int id;
  Tweet *tweet;
  unordered_set<int> follows;

public:
  User(int id, Tweet *tweet = nullptr,
       unordered_set<int> follows = unordered_set<int>())
      : id(id), tweet(tweet), follows(std::move(follows)) {}

  void follow(int followeeId) {
    if (followeeId != id) {
      follows.insert(followeeId);
    }
  }

  void unfollow(int followeeId) {
    if (follows.contains(followeeId)) {
      follows.erase(followeeId);
    }
  }

  void postTweet(int tweetId, int time) {
    tweet = new Tweet(tweetId, time, tweet);
  }
};

class Twitter {

  int global_Time;
  unordered_map<int, User *> user_map;

public:
  Twitter() : global_Time(0) { user_map.clear(); }

  void postTweet(int userId, int tweetId) {
    if (!user_map.contains(userId)) {
      User *user = new User(userId);
      user_map[userId] = user;
    }

    user_map[userId]->postTweet(tweetId, global_Time++);
  }

  vector<int> getNewsFeed(int userId) {
    if (!user_map.contains(userId)) {
      return {};
    }
    struct cmp {
      bool operator()(const Tweet *a, const Tweet *b) {
        return a->time < b->time;
      }
    };
    priority_queue<Tweet *, vector<Tweet *>, cmp> q;
    if (user_map[userId]->tweet) {
      q.push(user_map[userId]->tweet);
    }
    for (int followeeId : user_map[userId]->follows) {
      Tweet *head = user_map[followeeId]->tweet;
      if (head) {
        q.push(head);
      }
    }
    vector<int> rs;
    while (!q.empty()) {
      Tweet *t = q.top();
      q.pop();
      rs.push_back(t->id);
      if (rs.size() == 10) {
        return rs;
      }
      if (t->next) {
        q.push(t->next);
      }
    }
    return rs;
  }

  void follow(int followerId, int followeeId) {
    if (!user_map.contains(followerId)) {
      User *user = new User(followerId);
      user_map[followerId] = user;
    }
    if (!user_map.contains(followeeId)) {
      User *user = new User(followeeId);
      user_map[followeeId] = user;
    }
    user_map[followerId]->follow(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (!user_map.contains(followerId)) {
      return;
    }
    if (!user_map.contains(followeeId)) {
      return;
    }
    user_map[followerId]->unfollow(followeeId);
  }
};
int main() {
  Twitter *obj = new Twitter();
  obj->postTweet(1, 5);
  vector<int> param_2 = obj->getNewsFeed(1);
  obj->follow(1, 2);
  obj->postTweet(2, 6);
  obj->getNewsFeed(1);
  obj->unfollow(1, 2);
  obj->getNewsFeed(1);


  /**
   * Your Twitter object will be instantiated and called as such:
   * Twitter* obj = new Twitter();
   * obj->postTweet(userId,tweetId);
   * vector<int> param_2 = obj->getNewsFeed(userId);
   * obj->follow(followerId,followeeId);
   * obj->unfollow(followerId,followeeId);
   */
  cout << "" << "\n";
  return 0;
}
