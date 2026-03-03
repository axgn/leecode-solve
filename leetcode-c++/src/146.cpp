#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
// 这里有两种写法，一种是在满的时候删除，然后重新添加，另一种是直接修改尾部节点。
class LRUCache1 {
  struct Node {
    int key, value;
    Node *next;
    Node *prev;
    Node(int key = 0, int value = 0, Node *next = nullptr, Node *prev = nullptr)
        : key(key), value(value), next(next), prev(prev) {}
  };
  Node *tail;
  Node *head;

  unordered_map<int, Node *> map;
  int capacity;
  int cur_cap;

public:
  LRUCache1(int capacity) {
    this->capacity = capacity, this->cur_cap = 0;
    this->head = new Node(), this->tail = new Node();
    head->next = tail, tail->prev = head;
  }

  void addToHead(Node *node) {
    Node *next = head->next;
    head->next = node;
    node->prev = head;
    node->next = next;
    next->prev = node;
  }
  void deleteNode(Node *node) {
    Node *prev = node->prev;
    Node *next = node->next;
    prev->next = next;
    next->prev = prev;
  }
  void moveToHead(Node *node) {
    deleteNode(node);
    addToHead(node);
  }
  // Node *deleteTail() {
  //   Node *temp = tail->prev;
  //   deleteNode(temp);
  //   return temp;
  // }

  int get(int key) {
    if (!map.contains(key)) {
      return -1;
    }
    moveToHead(map[key]);
    return map[key]->value;
  }

  void put(int key, int value) {
    if (map.contains(key)) {
      map[key]->value = value;
      moveToHead(map[key]);
      return;
    }
    if (cur_cap == capacity) {
      map.erase(tail->prev->key);
      tail->prev->key = key;
      tail->prev->value = value;
      map[key] = tail->prev;
      moveToHead(tail->prev);
      return;
    }
    Node *temp = new Node(key, value);
    map[key] = temp;
    addToHead(temp);
    cur_cap++;
  }
};

class LRUCache {
  list<pair<int, int>> lst;
  unordered_map<int, list<pair<int, int>>::iterator> map;
  int capacity;

public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (!map.contains(key)) {
      return -1;
    }
    lst.splice(lst.begin(), lst, map[key]);
    return map[key]->second;
  }

  void put(int key, int value) {
    if (map.contains(key)) {
      map[key]->second = value;
      lst.splice(lst.begin(), lst, map[key]);
      return;
    }
    if (lst.size() == capacity) {
      map.erase(lst.back().first);
      lst.pop_back();
    }
    lst.emplace_front(key, value);
    map[key] = lst.begin();
  }
};

int main() {
  LRUCache lRUCache = LRUCache(2);
  lRUCache.put(1, 1);              // 缓存是 {1=1}
  lRUCache.put(2, 2);              // 缓存是 {1=1, 2=2}
  cout << lRUCache.get(1) << endl; // 返回 1
  lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
  cout << lRUCache.get(2) << endl; // 返回 -1 (未找到)
  lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
  cout << lRUCache.get(1) << endl; // 返回 -1 (未找到)
  cout << lRUCache.get(3) << endl; // 返回 3
  cout << lRUCache.get(4) << endl; // 返回 4
  return 0;
}
