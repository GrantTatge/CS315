#include "SortedLinkedListDict.hpp"
void SortedLinkedListDict::insert(int key) {
    Node* newNode = new Node(key);
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    if (key > head->data) {
        while (current->next != nullptr && key > current->next->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    else {
        newNode->next = current;
        head = newNode;
    }
}

bool SortedLinkedListDict::lookup(int key) const {
    Node* current = head;
    while (current != nullptr) {
        if ( current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void SortedLinkedListDict::remove(int key) {
    Node* current = head;
    if (current->data == key) {
        head = current->next;
        delete current;
        return;
    }
    while (current->next != nullptr && current->next->data != key) {
        current = current->next;
    }
    if (current->next != nullptr) {
        auto temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}