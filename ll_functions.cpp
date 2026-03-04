// file: ll_functions.cpp
// had to delete #include "ll_headers.h" it would not compile
#include <string>
#include<iostream> //getting errors without
using namespace std; //getting errors without
// Used in the function createLL()
// This function is started for you correctly - you have to complete it.
//   Use the comments to help you figure out what to do.
void h_insert(LinkNodePtr& head, string nom, int num) {
    LinkNodePtr tmp_ptr;
    tmp_ptr = new LinkNode;

    tmp_ptr->name = nom;
    tmp_ptr->number = num;
    tmp_ptr->link = nullptr; 

// If the list is empty, the new node becomes the head
    if (head == nullptr) {
            head = tmp_ptr;
            return;
        }


// If the list is not empty, traverse to the last node
    LinkNodePtr current = head;

    while (current->link != nullptr) {
        current = current->link;
    }
    

// Change the pointer of the last node to the new node

    current->link = tmp_ptr;

}

void createLL(LinkNodePtr& h) {
    // Incomplete function - student must complete
    string nom = "";
    int num;  
    while(true) // THIS IS A STUB
    {
        cout << "Enter name, then a number. To quit, enter 0 for the name AND 0 for the number:\n";
        cin >> nom >> num;
        // Incomplete code here...
        // At some point, you call:    h_insert(h, nom, num);
        if (nom == "0" && num == 0) {
            break;
        }

        h_insert(h, nom, num);
    }
}

void printLL(LinkNodePtr h) {
    // Incomplete function - student must complete
    if (h == nullptr) {
        cout << "This list is empty." << endl;
        return;
    }
    LinkNodePtr current = h;
    while (current != nullptr) {
        cout << current->name << ", " << current->number << endl;
        current = current->link;
    }

}

void insertNodeAfter(LinkNodePtr& h) { //added & since it didnt align
    // Incomplete function - student must complete
    int pos;
    cout << "Enter node position to insert after (negative number to exit): ";
    cin >> pos;

    if (pos < 0)
        return;

    LinkNodePtr current = h;
    int index = 0;

    while (current != nullptr && index < pos) {
        current = current->link;
        index++;
    }

    if (current == nullptr) {
        cout << "Position entered is illegal. Nothing inserted." << endl;
        return;
    }

    string nom;
    int num;

    cout << "Enter data (name then number): ";
    cin >> nom >> num;

    LinkNodePtr newNode = new LinkNode;

    newNode->name = nom;
    newNode->number = num;

    newNode->link = current->link;
    current->link = newNode;

}




void findMax(LinkNodePtr h) {
    // Incomplete function - student must complete
    int max = h->number;

    while (h != nullptr) {

        if (h->number > max) {
            max = h->number;
        }

        h = h->link;
    }

    cout << "Largest number in the list is: " << max << endl;

}

void findMin(LinkNodePtr h) {
    // Incomplete function - student must complete
    int min = h->number;

    while (h != nullptr) {
        if (h->number < min)
            min = h->number;

        h = h->link;
    }

    cout << "Smallest number in the list is: " << min << endl;
}


