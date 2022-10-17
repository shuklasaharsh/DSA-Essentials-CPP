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

/*
 * binary_search searches in an array in a binary fashion and returns index if found
 *
 * @params: const int *arr | pointer to an array
 *        :      int start | start of lookup
 *        :      int end   | end of lookup
 *        :       int key  | element that should be found
 *
 * @returns: int | index of the element if found, else returns -1
 *
 * Time Space : O(LOG(n))

 */
int binary_search(const int *arr, int start, int end, int key) {
    int middle_index = (start + end)/2;

    if (arr[middle_index] == key) {
        return middle_index;
    } else if (arr[middle_index] > key) {
        return binary_search(arr, start, middle_index - 1, key);
    } else {
        return binary_search(arr, middle_index + 1, end, key);
    }
}

#endif //DSA_ESSENTIALS_ARRAYS_H
