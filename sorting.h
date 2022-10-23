//
// Created by Saharsh Shukla on 19/10/22.
//

#ifndef DSA_ESSENTIALS_SORTING_H
#define DSA_ESSENTIALS_SORTING_H

#include <vector>

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

#endif //DSA_ESSENTIALS_SORTING_H
