//
// Created by Saharsh Shukla on 17/10/22.
//

#ifndef DSA_ESSENTIALS_ARRAYS_H
#define DSA_ESSENTIALS_ARRAYS_H

/*
 * linear_search searches in an array linearly
 *
 * @params: const int *arr | pointer to an array
 *        :       int size | length of the array
 *        :       int key  | element that should be found
 *
 * @returns: boolean | True if found else false
 *
 * Time Space : O(n)
 */
bool linear_search(const int *arr, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return true;
        }
    }
    return false;
}

/*
 * linear_search_index searches in an array linearly and returns index of the element if found
 *
 * @params: const int *arr | pointer to an array
 *        :       int size | length of the array
 *        :       int key  | element that should be found
 *
 * @returns: int | index of the element if found, else returns -1
 *
 * Time Space : O(n)
 */
int linear_search_index(const int *arr, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

#endif //DSA_ESSENTIALS_ARRAYS_H
