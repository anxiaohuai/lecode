struct DLinkedNode {
    int m_key;
    int m_value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode(): m_key(0), m_value(0), prev(nullptr), next(nullptr) {

    }
    DLinkedNode(int key, int value): m_key(key), m_value(value), prev(nullptr), next(nullptr) {

    }
};

class LRUCache {
private:
unordered_map<int, DLinkedNode *> m_key2Node;
int m_capacity;
DLinkedNode *head;
DLinkedNode *tail;

public:
    LRUCache(int capacity) {
        // 初始化的时候, 让系统分配头尾两个节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
        // 控制缓存的容量
        m_capacity = capacity;
    }
    
    int get(int key) {
        // 如果容器里有这个key，就直接返回，并把这个移动到链表的头部
        if (m_key2Node.find(key) != m_key2Node.end()) {
            removeNode(m_key2Node[key]);
            addNode2Head(m_key2Node[key]);
            return m_key2Node[key]->m_value;
        } else { // 如果没有这个节点，就返回-1
            return -1;
        }
    }
    
    void put(int key, int value) {
        // 如果有这个节点，就覆盖这个key对应的值，并把这个节点放在链表的头部
        if (m_key2Node.find(key) != m_key2Node.end()) {
            m_key2Node[key]->m_value = value;
            removeNode(m_key2Node[key]);
            addNode2Head(m_key2Node[key]);
        } else { // 如果没有这个节点，就添加这个节点，并把这个节点放在链表头部，如果节点数量超过容器大小，就删除尾部节点的元素
            DLinkedNode *node = new DLinkedNode(key, value);
            m_key2Node[key] = node;
            addNode2Head(node);
            while (m_key2Node.size() > m_capacity) {
                removeTail();
            }
        }
    }

    // 移动一个节点到链表的头部，是要先删除节点，再在链表的头部添加这个节点
    // 删除一个节点的函数
    void removeNode(DLinkedNode *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    // 添加一个节点到链表的头部的函数
    void addNode2Head(DLinkedNode *node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    // 从尾部移除一个节点的函数
    void removeTail() {
        m_key2Node.erase(tail->prev->m_key);
        DLinkedNode *node = tail->prev;
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
        // 防止内存泄漏
        delete node;
    }
};
