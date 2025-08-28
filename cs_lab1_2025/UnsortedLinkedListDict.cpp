#include "UnsortedLinkedListDict.hpp"

#include "Dictionary.hpp"

void UnsortedLinkedListDict::insert(int key) {
    Node* newNode = new Node(key);
    newNode->next = head;
    head = newNode;
}

bool UnsortedLinkedListDict::lookup(int key) const {
    Node* current = head;
    while (current != nullptr) {
        if ( current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void UnsortedLinkedListDict::remove(int key) {
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