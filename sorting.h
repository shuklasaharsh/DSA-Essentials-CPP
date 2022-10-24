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
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

/*
 * insertion_sort sorts an algorithm
 */
template <typename t>
void insertion_sort(vector<t> &arr, bool comp(t num1, t num2, bool dec)) {
    // For insertion sort we have the left side of the array always sorted
    // [0, 22, -1, 3, 5]
    // We select an element on the right side
    // Select 22 in case 1 and check with

    auto n = arr.size();
    for (int current_card = 0; current_card < n; current_card++) {
        // We have array after the first element
        // [22, -1, 3, 5]
        // We select the first element
        // 22 should come after 0
        // [0, 22, -1, 3, 5]
        // -1 should come before 0
        // [-1 0 22 3 5]

        t key = arr[current_card];
        auto hand = current_card - 1;
        while (hand >= 0 && comp(arr[hand], key, false)) {
            arr[hand + 1] = arr[hand];
            hand--;
        }
        arr[hand + 1] = key;
    }
}

template <typename t>
ostream &operator<<(ostream &o,vector<t> &v) {
    for (auto i: v) {
        o << i << " ";
    }
    o << endl;
    return o;
}

namespace SORTING {

}



#endif //DSA_ESSENTIALS_SORTING_H
