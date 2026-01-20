#include <iostream>
#include <stdio.h>
using namespace std;

void insertNode(int key, string data);
void displayList();

struct Node { //kod 10_01
    int key = -1;
    string data = "";
    Node* next = nullptr;
};

Node* head = nullptr; //globalny wskaznik zawsze pokazujacy pierszy wezel
Node* lastAdded = nullptr;//wskaznik na ostatnio dodany wezel   

void insertNode(int key, string data) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode; //jak nic nie ma, stworzy pierszy wezel
    }
    else {
		lastAdded->next = newNode; //ustawiamy wskaznik next ostatnio dodanego wezla na nowy wezelz
        lastAdded = newNode; //w koncu jestesmy na koncu, wiec wstawiamy nowe element
    }
}

void displayList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Key: " << temp->key << ", Data: " << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    int n, key;
    string data;
    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter key and data for node " << i + 1 << ": " << endl;
        cout << "Please write integer number: ";
        cin >> key;
        cout << "Please write any string: ";
        cin >> data;
        insertNode(key, data);
    }

    cout << "The entire list:" << endl;
    displayList();
}
