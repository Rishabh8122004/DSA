class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int key, int val) {
            this->key = key;
            this->value = val;
            this->prev = NULL;
            this->next = NULL;
        }
    };
    class DLL {
    public:
        int size;
        Node* head;
        Node* tail;
        DLL() {
            head = NULL;
            tail = NULL;
            size = 0;
        }
        void insertAtBegin(Node* temp) {
            if (head == NULL) {
                head = tail = temp;
            } else {
                head->prev = temp;
                temp->next = head;
                head = temp;
            }
            size++;
        }
        Node* removeTail() {
            if (tail == NULL)
                return NULL;
            Node* temp = tail;
            if (tail->prev) {
                tail = tail->prev;
                tail->next = NULL;
            } else {
                head = NULL;
                tail = NULL;
            }
            size--;
            return temp;
        }
        void delete_node(Node* temp) {
            if (head == tail) { // single node in the list
                head = tail = NULL;
            } else if (head == temp) { // removing if head
                head = head->next;
                head->prev = NULL;

            } else if (tail == temp) { // removing if tail
                if (tail == NULL)
                    return;
                if (tail->prev) {
                    tail = tail->prev;
                    tail->next = NULL;
                }
            } else { // any middle node
                if (temp->prev)
                    temp->prev->next = temp->next;
                if (temp->next)
                    temp->next->prev = temp->prev;
            }
            size--;
        }
        int length() { return size; }
    };
    int cap;
    unordered_map<int, Node*> mp;
    DLL a;
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node* temp = mp[key];

        a.delete_node(temp);

        a.insertAtBegin(temp);

        return temp->value;
    }

    void put(int key, int value) {

        // key already exists
        if (mp.find(key) != mp.end()) {

            Node* existing = mp[key];

            a.delete_node(existing);

            existing->value = value;

            a.insertAtBegin(existing);

            return;
        }

        // capacity full
        if (a.length() == cap) {

            Node* lru = a.removeTail();

            mp.erase(lru->key);

            delete lru;
        }

        Node* temp = new Node(key, value);

        a.insertAtBegin(temp);

        mp[key] = temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */