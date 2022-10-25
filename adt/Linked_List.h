//
// Created by Saharsh Shukla on 25/10/22.
//

#ifndef DSA_ESSENTIALS_LINKED_LIST_H
#define DSA_ESSENTIALS_LINKED_LIST_H

#include "iostream"

namespace adt {
    class Linked_List {
    private:
        int length = 0;
        struct Node {
            int data;
            Node *next;
        };
        Node *head{};
    public:
        friend std::ostream &operator<<(std::ostream &o, Linked_List l);

        Linked_List() {
            auto d = new Node();
            d->data = 0;
            head = d;
        }

        auto get_head() const {return head;}

        void insert(int data) {
            auto d = new Node();
            d->data = data;
            head->next = d;
        }
    };

    std::ostream &operator<<(std::ostream &o, Linked_List l) {
        auto i = l.get_head();
        while (i != nullptr) {
            o << i->data << " ";
            i = i->next;
        }
        o << std::endl;
        return o;
    }


}


#endif //DSA_ESSENTIALS_LINKED_LIST_H
