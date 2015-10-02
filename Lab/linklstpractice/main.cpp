/* 
 * File:   main.cpp
 * Author: User
 *
 * Created on September 23, 2015, 2:49 PM
 */

#include <cstdlib>
#include "linklist.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    MyList myList;
    myList.append(2);
    myList.insertN(1,2);
    myList.insertN(3,3);
    myList.prepend(0);
    myList.display();
    return 0;
}
