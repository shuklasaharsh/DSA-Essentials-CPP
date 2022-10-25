//
// Created by Saharsh Shukla on 25/10/22.
//

#ifndef DSA_ESSENTIALS_LIST_H
#define DSA_ESSENTIALS_LIST_H

#include <iostream>
#include <algorithm>

const int DEFAULT_LIST_SIZE = 100;

namespace adt {
    class List {
    private:
        bool debug = false;
        int *arr;
        int size;
    public:
        friend bool reverse_cmp(int num1, int num2);

        // describes the number of elements in the list
        int length;

        int &operator[](int);

        /*
         * Creates a list of default size
         */
        List() {
            int *dynamic_array = new int(DEFAULT_LIST_SIZE);
            this->arr = dynamic_array;
            this->size = 10;
            this->length = 5;
        }

        /*
         * Creates an empty list with size as given
         */
        explicit List(int size) {
            int *dynamic_array = new int(2 * size);
            this->arr = dynamic_array;
            this->size = 2 * size;
            this->length = size;
        }

        /*
         * Initialises a list using an existing array
         */
        explicit List(const int *arr, int size) {
            int *dynamic_array = new int(2 * size);
            for (int i = 0; i < size; i++) {
                dynamic_array[i] = arr[i];
            }
            this->arr = dynamic_array;
            this->size = 2 * size;
            this->length = size;
        }

        void set_debug() {
            this->debug = true;
        }

        [[nodiscard("get debug prop")]]bool get_debug() const {
            return this->debug;
        }

        void insert(int element) {
            if (this->length + 1 >= this->size) {
                // If length after adding an element is greater than size, we need to create a new array
                int *dynamic_array = new int(2 * this->size);
                // Copy the existing array into the new one;
                for (int i = 0; i < this->length; i++) {
                    dynamic_array[i] = this->arr[i];
                }
                // And then insert it on length + 1
                dynamic_array[this->length + 1] = element;
                this->size = 2 * this->size;
                this->length += 1;
                arr = dynamic_array;
            } else {
                this->length += 1;
                arr[length] = element;
            }
        }

        void insert(int element, int position) {
            // first we check if length + 1 will be == size
            if (this->length + 1 >= this->size) {
                int *dynamic_array = new int(2 * this->size);
                // Copy the existing array into the new one;
                for (int i = 0; i < this->length; i++) {
                    dynamic_array[i] = this->arr[i];
                }
                // And then insert it on length + 1
                dynamic_array[this->length + 1] = element;
                this->length += 1;
                this->size = 2 * this->size;
                arr = dynamic_array;
            }
            // If not we carry on
            // To do this operation we shift the array by 1 pos
            for (auto i = this->length - 1; i >= position; i--) {
                arr[i + 1] = arr[i];
            }
            arr[position] = element;
            this->length++;
        }

        void print(bool debug_print = false) {
            if (debug_print) {
                for (auto i = 0; i < this->length; i++) {
                    std::cout << i << "|" << this->arr[i] << endl;
                }
                cout << endl;
            } else {
                for (auto i = 0; i < this->length; i++) {
                    std::cout << this->arr[i] << " ";
                }
                std::cout << std::endl;
            }

        }

        void resize(int new_size) {
            int *dynamic_array = new int(new_size);
            for (auto i = 0; i < this->length; i++) {
                dynamic_array[i] = this->arr[i];
            }
            this->arr = dynamic_array;
            this->size = new_size;
        }

        void sort(bool reverse = false) {
            if (reverse) {
                std::sort(arr, arr + length, std::greater<int>());
            } else {
                std::sort(arr, arr + length, std::less<int>());
            }
        }
    };

    bool reverse_cmp(int num1, int num2) {
        return num1 < num2;
    }

    int &List::operator[](int a) {
        return this->arr[a];
    }

    ostream &operator<<(ostream &o, List l) {
        if (l.get_debug()) {
            for (int i = 0; i < l.length; i++) {
                o << i << "|" << l[i] << endl;
            }
        } else {
            for (int i = 0; i < l.length; i++) {
                o << l[i] << " ";
            }
        }

        return o;
    }

}

#endif //DSA_ESSENTIALS_LIST_H
