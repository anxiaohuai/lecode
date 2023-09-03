typedef struct {
    int key;
    int value;
} ITEM_S;

typedef struct {
    int capacity;
    ITEM_S *pstItem;
} Solution;

Solution* SolutionCreate(int capacity) {
    Solution* obj = malloc(sizeof(Solution));
    obj->capacity = capacity;
    obj->pstItem = malloc(sizeof(ITEM_S) * capacity);
    memset(obj->pstItem, 0, sizeof(ITEM_S) * capacity);
    return obj;
}

int SolutionGet(Solution* obj, int key) {
    ITEM_S *pstItem = obj->pstItem;
    
    for(int i = 0; i < obj->capacity; i++) {
        if (key == pstItem[i].key) {
            int value = pstItem[i].value;

            for(int j = i - 1; j >= 0; j--) {
                ITEM_S tmp = pstItem[i];
                pstItem[i] = pstItem[j];
                pstItem[j] = tmp;
            }
            return value;
        }
    }

    return -1;
}

void SolutionSet(Solution* obj, int key, int value) {
    ITEM_S *pstItem = obj->pstItem;

    for(int j = obj->capacity - 1; j > 0; j--) {
        pstItem[j] = pstItem[j - 1];
    }
    pstItem[0].key = key;
    pstItem[0].value = value;
}

void SolutionFree(Solution* obj) {
    if (obj != NULL) {
        free(obj->pstItem);
        free(obj);
    }
}
