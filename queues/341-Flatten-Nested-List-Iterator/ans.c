// https://leetcode.com/problems/flatten-nested-list-iterator/description/

/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */

 #define LIST_LENGTH 100000

struct NestedIterator {
    int flattenList[LIST_LENGTH];
    int size;
    int currentIndex;
};

void flatten(struct NestedIterator *iter, struct NestedInteger *nestedInt) {
    if (NestedIntegerIsInteger(nestedInt)) {
        iter->flattenList[iter->size++] = NestedIntegerGetInteger(nestedInt);
    } else {
        struct NestedInteger **nestedList = NestedIntegerGetList(nestedInt);
        int nestedListSize = NestedIntegerGetListSize(nestedInt);
        for (int index = 0; index < nestedListSize; index++) {
            flatten(iter, nestedList[index]);
        }
    }
    return;
}

struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize) {
    struct NestedIterator *iter = calloc(1, sizeof(struct NestedIterator));
    for (int index = 0; index < nestedListSize; index++) {
        flatten(iter, nestedList[index]);
    }
    return iter;
}

bool nestedIterHasNext(struct NestedIterator *iter) {
    return iter->currentIndex < iter->size;
}

int nestedIterNext(struct NestedIterator *iter) {
    return iter->flattenList[iter->currentIndex++];
}

/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter) {
    free(iter);
    return;
}

/**
 * Your NestedIterator will be called like this:
 * struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize);
 * while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i));
 * nestedIterFree(i);
 */