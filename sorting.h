//
// Created by Saharsh Shukla on 19/10/22.
//

#ifndef DSA_ESSENTIALS_SORTING_H
#define DSA_ESSENTIALS_SORTING_H

#include <vector>
#include <algorithm>

using namespace std;

/*
 * bubble_sort sorts an array in O(n^3) time
 */
void bubble_sort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            for (int k = 0; k < arr.size(); k++) {
                if (arr[j] < arr[k]) {
//                    cout << "swapping" << arr[j] << " " << arr[k] << endl;
                    swap(arr[j], arr[k]);
                }
            }
        }
    }
}

/*
 * bubble_sort_opt sorts the array in O(n^2) time
 *
 * 1 -> n times
 * We compare i = 0 to n
 */
void bubble_sort_opt(vector<int> &arr) {
    // We take the second element and if it less than the first element we shift all the elements by 1
    // we add the card to position 0 (1)

    // [0, 22, -1, 3, 5]
    // [i   j          ] = is larger than 0 (no action)
    // [        j      ] = is less than 0
    // [-1, 0, 22, 3, 5]
    // [    i  j       ] = is larger than 0
    // [    i      j   ] = is larger than 0
    // [    i         j] = is larger than 0
    // [-1, 0, 22, 3, 5]
    // [       i   j   ] = is less than 22
    // [-1, 0, 3, 22, 5]
    // [           i  j] = is less than 22
    // [-1, 0, 3, 5, 22]
    // Sorted

    // By the above algorithm explanation we see that we have 2 vars i and j
    for (int times = 1; times <= arr.size() - 1; times++) {
        for (int i = 0; i <= arr.size() - times - 1; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
    }
}

void insertion_sort(vector<int> &arr) {



}


#endif //DSA_ESSENTIALS_SORTING_H
