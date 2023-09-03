#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ResldNode {
    long resls;
    int KeyA;
    int KeyB;
};

typedef struct ResldNode ResldNode;

typedef struct {
    ResldNode *nodes;
    int capacity;
    int size;
} ResourceManager;

ResourceManager *createResourceManager(int capacity) {
    ResourceManager *manager = (ResourceManager *)malloc(sizeof(ResourceManager));
    manager->nodes = (ResldNode *)malloc(sizeof(ResldNode) * capacity);
    manager->capacity = capacity;
    manager->size = 0;
    return manager;
}

long allocResld(ResourceManager *manager, int userls, int keyA, int keyB) {
    for (int i = 0; i < manager->size; i++) {
        if (manager->nodes[i].KeyA == keyA && manager->nodes[i].KeyB == keyB) {
            return manager->nodes[i].resls;
        }
    }

    if (manager->size >= manager->capacity) {
        return -1; // Resource ID allocation failed
    }

    manager->nodes[manager->size].resls = manager->size + 1;
    manager->nodes[manager->size].KeyA = keyA;
    manager->nodes[manager->size].KeyB = keyB;
    manager->size++;

    return manager->nodes[manager->size - 1].resls;
}

int freeResla(ResourceManager *manager, int userls, int keyA, int keyB) {
    for (int i = 0; i < manager->size; i++) {
        if (manager->nodes[i].KeyA == keyA && manager->nodes[i].KeyB == keyB) {
            if (i == 0) {
                if (manager->size == 1) {
                    manager->size--;
                    return 0;
                }
                return 0;
            } else {
                manager->nodes[i] = manager->nodes[manager->size - 1];
                manager->size--;
                return 0;
            }
        }
    }

    return -1;
}

int main() {
    ResourceManager *manager = createResourceManager(100);

    long id1 = allocResld(manager, 1, 10, 20);
    long id2 = allocResld(manager, 2, 10, 20);
    long id3 = allocResld(manager, 3, 30, 40);

    printf("ID1: %ld\n", id1);
    printf("ID2: %ld\n", id2);
    printf("ID3: %ld\n", id3);

    int result = freeResla(manager, 1, 10, 20);
    if (result == 0) {
        printf("Resource freed successfully.\n");
    } else {
        printf("Failed to free resource.\n");
    }

    free(manager->nodes);
    free(manager);

    return 0;
}
