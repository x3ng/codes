class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode* prev;
        ListNode* next;

        ListNode() : val(0), prev(nullptr), next(nullptr) {}
        ListNode(int v) : val(v), prev(nullptr), next(nullptr) {}
        ListNode(int v, ListNode* p, ListNode* n) : val(v), prev(p), next(n) {}
    };

    ListNode* head;
    ListNode* tail;
    int listsize;

    ListNode* getNode(int index) {
        if (index>listsize || index<0) {
            return nullptr;
        }
        int m = listsize / 2;
        ListNode* tmp;
        if (index > m) {
            tmp = tail;
            int ci = listsize;
            while (ci > index) {
                tmp =  tmp->prev;
                --ci;
            }
        } else {
            tmp = head->next;
            int ci = 0;
            while (ci < index) {
                tmp = tmp->next;
                ++ci;
            }
        }
        return tmp;
    }

public:
    MyLinkedList() {
        listsize = 0;
        head = new ListNode(0);
        tail = new ListNode(0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        ListNode* tn = getNode(index);
        return tn ? tn==tail ? -1 : tn->val : -1;
    }
    
    void addAtHead(int val) {
        ListNode* nn = new ListNode(val, head, head->next);
        head->next = nn;
        nn->next->prev = nn;
        ++listsize;
    }
    
    void addAtTail(int val) {
        ListNode* nn = new ListNode(val, tail->prev, tail);
        tail->prev = nn;
        nn->prev->next = nn;
        ++listsize;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* tmp = getNode(index);
        if (tmp) {
            ListNode* nn = new ListNode(val, tmp->prev, tmp);
            tmp->prev = nn;
            nn->prev->next = nn;
            ++listsize;
        }
    }
    
    void deleteAtIndex(int index) {
        ListNode* tmp = getNode(index);
        if (tmp && tmp!=tail) {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            --listsize;
            delete tmp;
        }
    }
};
