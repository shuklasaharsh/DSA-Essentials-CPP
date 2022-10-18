//
// Created by Saharsh Shukla on 17/10/22.
//

#ifndef DSA_ESSENTIALS_ARRAYS_H
#define DSA_ESSENTIALS_ARRAYS_H

#include <iostream>
#include <utility>
#include <vector>
#include <limits>

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

/*
 * print_sub_arrays_brute_force prints all the sub arrays of a given array
 *
 * Example: 1, 2, 3, 4 will have
 * 1, 2, 3, 4
 * 1, 2, 3
 * 1, 2
 * 1
 *
 * 2, 3, 4
 * 3, 4
 * 4
 *
 * 3, 4
 * 4
 *
 * as its NC2 sub arrays
 *
 * Time Space: O(n^3)
 */
template<typename t>
void print_sub_arrays_brute_force(const t *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = i; k <= j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

/*
 * largest_sum_in_sub_arrays sums all the sub arrays of a given array
 * [BRUTE FORCE]
 *
 * Example: 1, 2, 3, 4 will have
 * 1, 2, 3, 4 = 10
 * 1, 2, 3 = 6
 * 1, 2 = 3
 * 1 = 1
 *
 * 2, 3, 4 = 9
 * 3, 4 = 7
 * 4 = 4
 *
 * 3, 4 = 7
 * 4 = 4
 *
 * as its sub array sums
 *
 * Time Space: O(n^3)
 */
template<typename t>
int largest_sum_in_sub_arrays(const t *arr, int size) {
    int largest_sum = 0;
    pair<int, int> indices = {0, 0};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if (sum > largest_sum) {
                largest_sum = sum;
                indices.first = i;
                indices.second = j;
            }
        }
    }
    for (int i = indices.first; i <= indices.second; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return largest_sum;
}


/*
 * largest_sum_sub_arrays_opt sums all the sub arrays of a given array
 * using a prefix sum array
 *
 * Example: 1, 2, 3, 4 will have
 * 1, 2, 3, 4 = 10
 * 1, 2, 3 = 6
 * 1, 2 = 3
 * 1 = 1
 *
 * 2, 3, 4 = 9
 * 3, 4 = 7
 * 4 = 4
 *
 * 3, 4 = 7
 * 4 = 4
 *
 * We use a prefix sum approach which computes a prefix array
 * The sum for a subarray becomes = prefix[i] = prefix[i-1] + arr[i]
 *
 * as its sub array sums
 *
 * Time Space: O(n^2)
 */
template<typename t>
int largest_sum_sub_arrays_opt(const t *arr, int size) {
    int *pfx_arr = new int(size);
    pfx_arr[0] = arr[0];
    // Build prefix sum array
    for (int i = 1; i < size; i++) {
        pfx_arr[i] = (arr[i] + pfx_arr[i - 1]);
    }
    // Get all sums
    int largest_sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int current_sum = 0;
            if (i == 0) {
                current_sum = pfx_arr[j];
            } else {
                current_sum = pfx_arr[j] - pfx_arr[i - 1];
            }
            largest_sum = max(largest_sum, current_sum);
        }
    }
    return largest_sum;
}

/*
 * largest_sum_sub_array_running_sum sums all the sub arrays of a given array
 * using a running sum [Kadane's Algorithm]
 *
 * Example: 1, 2, 3, 4 will have
 * 1, 2, 3, 4 = 10
 * 1, 2, 3 = 6
 * 1, 2 = 3
 * 1 = 1
 *
 * 2, 3, 4 = 9
 * 3, 4 = 7
 * 4 = 4
 *
 * 3, 4 = 7
 * 4 = 4
 *
 *
 * as its sub array sums
 *
 * To do this we maintain a current sum variable where if we have a sum less than 0, we discard it and start again
 * Time Space: O(n)
 */
template <typename t>
int largest_sum_sub_array_running_sum(const t *arr, int size) {
    int max_sum = 0;
    int current_sum = 0;
    for (int i = 0; i < size; i++) {
        current_sum += arr[i];
        if (current_sum < 0) {
            current_sum = 0;
        }
        max_sum = max(current_sum, max_sum);
    }
    return current_sum;
}

#endif //DSA_ESSENTIALS_ARRAYS_H
