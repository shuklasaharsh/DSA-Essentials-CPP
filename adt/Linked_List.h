//
// Created by Saharsh Shukla on 25/10/22.
//

#ifndef DSA_ESSENTIALS_LINKED_LIST_H
#define DSA_ESSENTIALS_LINKED_LIST_H

#include "iostream"

namespace adt {
    class Node {
    public:
        int data;
        Node *next;

        Node() {
            this->data = 0;
            this->next = nullptr;
        }

        explicit Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    class LinkedList {
        Node *head;
    public:
        LinkedList() { head = nullptr; }

        void insert_node(int);

        void print();

        void delete_node(int);

    };

    void LinkedList::delete_node(int nodeOffset) {
        Node *temp1 = head, *temp2 = nullptr;
        int ListLen = 0;

        if (head == nullptr) {
            std::cout << "List empty." << std::endl;
            return;
        }
        while (temp1 != nullptr) {
            temp1 = temp1->next;
            ListLen++;
        }
        if (ListLen < nodeOffset) {
            std::cout << "Index out of range"
                      << std::endl;
            return;
        }

        // Declare temp1
        temp1 = head;

        // Deleting the head.
        if (nodeOffset == 1) {

            // Update head
            head = head->next;
            delete temp1;
            return;
        }

        // Traverse the list to
        // find the node to be deleted.
        while (nodeOffset-- > 1) {

            // Update temp2
            temp2 = temp1;

            // Update temp1
            temp1 = temp1->next;
        }

        // Change the next pointer
        // of the previous node.
        temp2->next = temp1->next;

        // Delete the node
        delete temp1;
    }

    void LinkedList::insert_node(int data) {
        // Create the new Node.
        Node *newNode = new Node(data);

        // Assign to head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Traverse till end of list
        Node *temp = head;
        while (temp->next != nullptr) {

            // Update temp
            temp = temp->next;
        }

        // Insert at the last.
        temp->next = newNode;
    }

// Function to print the
// nodes of the linked list.
    void LinkedList::print() {
        Node *temp = head;

        // Check for empty list.
        if (head == nullptr) {
            std::cout << "List empty" << std::endl;
            return;
        }

        // Traverse the list.
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }


}


#endif //DSA_ESSENTIALS_LINKED_LIST_H
