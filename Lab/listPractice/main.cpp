/* 
 * File:   main.cpp
 * Author: User
 *
 * Created on September 24, 2015, 5:12 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
};

int main(int argc, char** argv) {
    Node *head, *nodePtr;
    int size = 5;
    Node *firstNode = new Node;
    head = firstNode;
    head->value = 0;
    nodePtr = head;
    for(int i = 0; i < size; i++){
        Node *newNode = new Node;
        newNode->value = i+1;
        nodePtr->next = newNode;
        newNode->next = NULL;
        nodePtr = newNode;
    }
    nodePtr = head;
    cout << "first node is: " << nodePtr->value << endl;
    nodePtr = nodePtr->next;
    cout << "Second node is: " << nodePtr->value << endl;
    nodePtr = nodePtr->next;
    cout << "Third node is: " << nodePtr->value << endl;
    nodePtr = nodePtr->next;
    cout << "fourth node is: " << nodePtr->value << endl;
    nodePtr = nodePtr->next;
    cout << "fifth node is: " << nodePtr->value << endl;
    nodePtr = head;
    nodePtr = nodePtr->next;
    delete head;
    head = nodePtr;
    nodePtr = nodePtr->next;
    delete head;
    head = nodePtr;
    nodePtr = nodePtr->next;
    delete head;
    head = nodePtr;
    nodePtr = nodePtr->next;
    delete head;
    head = nodePtr;
    nodePtr = nodePtr->next;
    delete head;
    return 0;
}