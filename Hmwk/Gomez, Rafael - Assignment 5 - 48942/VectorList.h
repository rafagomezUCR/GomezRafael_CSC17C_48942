/* 
 * File:   VectorList.h
 * Author: Rafael Gomez
 *
 * Created on October 8, 2015, 5:30 PM
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
        T &operator=(const SimpleList &);
        void append(T);
        void prepend(T);
        void pull();
        T first();
        T last();
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
void SimpleList<T>::append(T value){
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
void SimpleList<T>::prepend(T value){
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    listSize++;
}

template <class T>
void SimpleList<T>::pull(){
    Node *prev;
    Node *nodePtr;
    if(head == NULL){
        cout << "List is empty" << endl;
    }
    else{
        nodePtr = head;
        while(nodePtr->next != NULL){
            prev = nodePtr;
            nodePtr = nodePtr->next;
        }
        prev->next = NULL;
        delete nodePtr;
    }
    listSize--;
}

template <class T>
T SimpleList<T>::first(){
    if(head == NULL){
        cout << "List is empty" << endl;
    }
    else{
        return head->data;
    }
}

template <class T>
T SimpleList<T>::last(){
    Node *nodePtr;
    if(head == NULL){
        cout << "The list is empty " << endl;
    }
    else{
        nodePtr = head;
        while(nodePtr->next != NULL){
            nodePtr = nodePtr->next;
        }
        return nodePtr->data;
    }
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


