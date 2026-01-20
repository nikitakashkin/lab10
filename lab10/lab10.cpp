#include <iostream>
#include <stdio.h>
using namespace std;

void insertNode(int key, string data);
void displayList();
void menu();
void usunElement();

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
    int num = 1;
    Node* temp = head;
    while (temp != nullptr) {
        cout << "<" << num << ">" << " Key: " << temp->key << ", Data: " << temp->data << endl;
        temp = temp->next;
        num++;
    }
}

int main() {
    int n, key;
    string data;
    //cout << "Enter the number of nodes: ";
    //cin >> n;

    while(true){
        menu();
		cin >> n;
        switch (n) {
        case 1://stworz lub dodaj element do tabeli
            cout << "Podaj klucz: ";
            cin >> key;
            cout << "Podaj date: ";
            cin >> data;
            insertNode(key, data);
			break;
        case 2://usun element
			displayList();
        }
        

    }

    /*
    for (int i = 0; i < n; i++) {
        cout << "Enter key and data for node " << i + 1 << ": " << endl;
        cout << "Please write integer number: ";
        cin >> key;
        cout << "Please write any string: ";
        cin >> data;
        insertNode(key, data);
    }
    */

    cout << "The entire list:" << endl;
    displayList();
}

void deleteElement(Node* elementToRemov) {
    int index;
	elementToRemov = head;

	cout << "Podaj numer elementu do usuniecia: ";
    cin >> index;

    for (int i = 0; i < index; i++) {
        if (elementToRemov->next != nullptr) {
            elementToRemov = elementToRemov->next;
        }
	}

    if (elementToRemov == head || elementToRemov -> next == nullptr) {
        head = nullptr;
        lastAdded = nullptr;
		delete elementToRemov;
    }
    else if (elementToRemov == head || elementToRemov -> next != nullptr) {
        head = elementToRemov -> next;
		delete elementToRemov;
    }
    else if (elementToRemov != head || elementToRemov->next == nullptr) {
		Node* temp = head;
        while (temp->next != elementToRemov) {
            temp = temp->next;
        }
		temp->next = nullptr;
        lastAdded = temp;
        delete elementToRemov;
    }
    else if (head != elementToRemov || elementToRemov->next != nullptr) {
        Node* temp = head;
        while (temp->next != elementToRemov) {
            temp = temp->next;
        }
        temp->next = elementToRemov->next;
		delete elementToRemov;
    }
}

void menu(){
    cout << "1. Dodaj nowy element" << endl;
    cout << "2. ususn element" << endl;
    cout << "3. pokaz liste" << endl;
    cout << "9. wyjdz z programu ";
}