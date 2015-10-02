#include <cstdlib>
#include <iostream>
#include "linklist.h"

using namespace std;

MyList::MyList(){
    head = NULL;
}

MyList::~MyList(){
    NodeList *nodePtr;
    NodeList *next;
    nodePtr = head;
    while(nodePtr != NULL){
        next = nodePtr->nextNode;
        delete nodePtr;
        nodePtr = next;
    }
}

void MyList::append(int val){
    NodeList *newNode = new NodeList;
    NodeList *nodePtr;
    newNode->num = val;
    newNode->nextNode = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        nodePtr = head;
        while(nodePtr->nextNode != NULL){
            nodePtr = nodePtr->nextNode;
        }
        nodePtr->nextNode = newNode;
    }
}

void MyList::display() const{
    NodeList *nodePtr;
    nodePtr = head;
    while(nodePtr != NULL){
        cout << nodePtr->num << endl;
        nodePtr = nodePtr->nextNode;
    }
}

void MyList::insertN(int val,int pos){
    int iPos = 1;
    NodeList *newNode = new NodeList;
    NodeList *nodePtr;
    NodeList *previousNode = NULL;
    newNode->num = val;
    if(head == NULL){
        head = newNode;
        newNode->nextNode = NULL;
    }
    else{
        nodePtr = head;
        previousNode = NULL;
        while(nodePtr != NULL && iPos < pos){
            previousNode = nodePtr;
            nodePtr = nodePtr->nextNode;
            iPos++;
        }
        if(previousNode == NULL){
            head = newNode;
            newNode->nextNode = nodePtr;
        }
        else{
            previousNode->nextNode = newNode;
            newNode->nextNode = nodePtr;
        }
    }
}

void MyList::deleteN(int val){
    NodeList *nodePtr;
    NodeList *previousNode;
    if(head == NULL){
        return;
    }
    if(head->num == val){
        nodePtr = head->nextNode;
        delete head;
        head = nodePtr;
    }
    else{
        nodePtr = head;
        while(nodePtr != NULL && nodePtr->num != val){
            previousNode = nodePtr;
            nodePtr = nodePtr->nextNode;
        }
        if(nodePtr != NULL){
            previousNode->nextNode = nodePtr->nextNode;
            delete nodePtr;
        }
    }
}

void MyList::prepend(int val){
    NodeList *newNode = new NodeList;
    newNode->num = val;
    newNode->nextNode = head;
}