//
// Created by Saharsh Shukla on 17/10/22.
//

#ifndef DSA_ESSENTIALS_ARRAYS_H
#define DSA_ESSENTIALS_ARRAYS_H

#include <iostream>
#include <utility>

using namespace std;

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
    int middle_index = (start + end) / 2;
    // If not found
    if (start == end) {
        return -1;
    }
    // If found
    if (arr[middle_index] == key) {
        return middle_index;
        // If the number is greater than key
    } else if (arr[middle_index] > key) {
        return binary_search(arr, start, middle_index - 1, key);
        // If the number is less than key
    } else if (arr[middle_index] < key) {
        return binary_search(arr, middle_index + 1, end, key);
    }
    // Default case
    return -1;
}

/*
 * reverse_array goes from start and the end and swaps the elements until it reaches the middle
 */
void reverse_array(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

/*
 * print_array linearly goes over each and every element of the array and prints it
 */
void print_array(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
 * print_pairs goes over each individual element and all the others with it to print out pairs
 *
 * Time Space: n!
 */
void print_pairs(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            cout << arr[i] << " " << arr[j] << endl;
        }
    }
}

#endif //DSA_ESSENTIALS_ARRAYS_H
