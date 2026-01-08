typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} LRUNode;

typedef struct {
    int cap;
    LRUNode* lrun;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*) malloc(sizeof(LRUCache));
    obj->cap = capacity;
    obj->lrun = NULL;
    return obj;        
}

int lRUCacheGet(LRUCache* obj, int key) {
    LRUNode* curn = NULL;
    HASH_FIND_INT(obj->lrun, &key, curn);
    if (curn != NULL) {
        HASH_DEL(obj->lrun, curn);
        HASH_ADD_INT(obj->lrun, key, curn);
        return curn->value;
    }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    LRUNode* curn = NULL;
    LRUNode* nexn = NULL;
    HASH_FIND_INT(obj->lrun, &key, curn);
    if (curn != NULL) {
        HASH_DEL(obj->lrun, curn);
        curn->value = value;
        HASH_ADD_INT(obj->lrun, key, curn);
    } else {
        int cnt = HASH_COUNT(obj->lrun);
        if (cnt == obj->cap) {
            HASH_ITER(hh, obj->lrun, curn, nexn) {
                HASH_DEL(obj->lrun, curn);
                free(curn);
                break;
            }
        }
        LRUNode* newn = (LRUNode*) malloc(sizeof(LRUNode));
        newn->key = key;
        newn->value = value;
        HASH_ADD_INT(obj->lrun, key, newn);
    }
    return;
}

void lRUCacheFree(LRUCache* obj) {
    LRUNode* curn = NULL;
    LRUNode* nexn = NULL;
    HASH_ITER(hh, obj->lrun, curn, nexn) {
        HASH_DEL(obj->lrun, curn);
        free(curn);
    }
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
