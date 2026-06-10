// Time Complexity: O(1)
//
// The get operation takes O(1) average time because unordered_map gives direct access to the key,
// and list erase and push_front operations take O(1).
// The put operation also takes O(1) average time because insertion, deletion,
// updating the map, and moving nodes in the list are all O(1).
//
// Space Complexity: O(capacity)
//
// The list stores at most capacity key-value pairs.
// The unordered_map also stores at most capacity keys.
// Therefore, the overall space complexity is O(capacity).

class LRUCache {
public:
    int cap;
    list<pair<int,int>>l;
    unordered_map<int,list<pair<int,int>>::iterator>mp;

    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())  return -1;

        auto it=mp[key];
        int value=it->second;

        l.erase(it);
        l.push_front({key,value});
        mp[key]=l.begin();

        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            auto it=mp[key];

            l.erase(it);
            l.push_front({key,value});

            mp[key]=l.begin();
        }
        else{
            if(cap==l.size()){
                int lastkey=l.back().first;

                l.pop_back();
                mp.erase(lastkey);
            }
            l.push_front({key,value});
            mp[key]=l.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


//approach - 2
//without using stl
// Time Complexity: O(1)
//
// The get operation takes O(1) average time because unordered_map gives direct access to the node,
// and deleting/inserting a node in the doubly linked list takes O(1).
// The put operation also takes O(1) average time because map lookup, insertion,
// deletion of least recently used node, and moving nodes are all O(1).
//
// Space Complexity: O(capacity)
//
// The unordered_map stores at most capacity keys.
// The doubly linked list also stores at most capacity nodes.
// Therefore, the overall space complexity is O(capacity).
class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        Node* before = node->prev;
        Node* after = node->next;

        before->next = after;
        after->prev = before;
    }

    void insertAfterHead(Node* node) {
        Node* after = head->next;

        head->next = node;
        node->prev = head;

        node->next = after;
        after->prev = node;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];
        int ans = node->value;

        deleteNode(node);
        insertAfterHead(node);

        return ans;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            deleteNode(node);
            insertAfterHead(node);
        }
        else {
            if(mp.size() == cap) {
                Node* lru = tail->prev;

                mp.erase(lru->key);
                deleteNode(lru);
                delete lru;
            }

            Node* newNode = new Node(key, value);

            insertAfterHead(newNode);
            mp[key] = newNode;
        }
    }
};
