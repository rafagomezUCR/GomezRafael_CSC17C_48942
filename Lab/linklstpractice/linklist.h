/* 
 * File:   linklist.h
 * Author: User
 *
 * Created on September 23, 2015, 3:01 PM
 */

#ifndef LINKLIST_H
#define	LINKLIST_H

class MyList{
    private:
        struct NodeList{
            int num;
            NodeList *nextNode;
        };
        NodeList *head;
    public:
        MyList();
        ~MyList();
        void append(int);
        void insertN(int, int);
        void deleteN(int);
        void display() const;
        void prepend(int);
};

#endif	/* LINKLIST_H */

