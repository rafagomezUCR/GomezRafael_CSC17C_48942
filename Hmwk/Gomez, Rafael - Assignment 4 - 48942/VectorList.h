/* 
 * File:   VectorList.h
 * Author: User
 *
 * Created on September 27, 2015, 12:48 PM
 */

#ifndef VECTORLIST_H
#define	VECTORLIST_H

#include <iostream>
using namespace std;

template <class T>
class SimpleList{
    private:
        struct Node{
            T data;
            Node *next;
        };
        Node *head;
        int listSize;
        void memError();
        void subError();
    public:
        SimpleList();
        SimpleList(int);
        SimpleList(const SimpleList &);
        ~SimpleList();
        int size() const
        { return listSize; }
        T getElement(int);
        T &operator[](const int &);
        void push(T);
        void pull();
};

template <class T>
SimpleList<T>::SimpleList(){
    head = NULL;
    listSize = 0;
}

template <class T>
SimpleList<T>::SimpleList(int size){
    listSize = size;
    Node *nodePtr;
    Node *firstNode = new Node;
    head = firstNode;
    head->data = 0;
    nodePtr = head;
    for(int i = 1; i < listSize; i++){
        Node *newNode = new Node;
        newNode->data = 0;
        nodePtr->next = newNode;
        newNode->next = NULL;
        nodePtr = newNode;
    }
}

template <class T>
T &SimpleList<T>::operator [](const int &sub){
    if(sub < 0 || sub > listSize)subError();
    Node *nodePtr;
    nodePtr = head;
    if(sub == 0){
        return nodePtr->data;
    }
    for(int i = 0; i < sub; i++){
        nodePtr = nodePtr->next;
    }
    return nodePtr->data;
}

template <class T>
T SimpleList<T>::getElement(int value){
    if(value < 0 || value > listSize)subError();
    if(value == 1){
        return head->data;
    }
    else{
        Node *nodePtr;
        nodePtr = head;
        for(int i = 1; i < value; i++){
            nodePtr = nodePtr->next;
        }
        return nodePtr->data;
    }
}

template <class T>
SimpleList<T>::~SimpleList(){
    Node *nodePtr;
    Node *pNode;
    nodePtr = head;
    pNode = NULL;
    while(nodePtr != NULL){
        pNode = nodePtr->next;
        delete nodePtr;
        nodePtr = pNode;
    }
}

template <class T>
void SimpleList<T>::push(T value){
    Node *newNode = new Node;
    Node *nodePtr;
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        nodePtr = head;
        while(nodePtr->next != NULL){
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
    listSize++;
}

template <class T>
void SimpleList<T>::subError(){
    cout << "Subscript error";
    exit(EXIT_FAILURE);
}

template <class T>
void SimpleList<T>::memError(){
    cout << "can't allocate memory";
    exit(EXIT_FAILURE);
}

#endif	/* VECTORLIST_H */

