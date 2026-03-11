#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* addWord(Node* head, string word) {
    Node* newNode = new Node();
    newNode->data = word;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* undo(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    string input;
    while (true) {
        cout << "Enter word (or UNDO/EXIT): ";
        cin >> input;
        if (input == "EXIT") {
            break;
        }
        else if (input == "UNDO") {
            head = undo(head);
        }
        else {
            head = addWord(head, input);
        }

        display(head);
    }
    return 0;
}
