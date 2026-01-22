#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void printList(list<int> ll) {
    
        list<int>::iterator itr;    // Creating an iterator for the list

    // Printing the list using iterator 
    for(itr = ll.begin(); itr != ll.end(); itr++) {
        cout << *(itr) << " -> ";
    }
    cout << "NULL" << endl;
}

int main() {
    list<int> ll;
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.push_back(4);
    printList(ll);
    cout << "size = " << ll.size() << endl;
    
    cout << "head = " << ll.front() << endl;
    cout << "tail = " << ll.back() << endl;
    
    ll.pop_front();
    ll.pop_back();
    printList(ll);
    
    ll.insert(ll.begin(), 1, 5);            // at begining 1 time insert 5
    ll.insert(ll.end(), 1, 4);
    printList(ll);
}