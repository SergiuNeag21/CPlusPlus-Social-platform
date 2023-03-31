//
// Created by Sergiu Neag on 5/2/2022.
//

#ifndef PROIECTSDA_LIST_H
#define PROIECTSDA_LIST_H

#include "Node.h"
#include "Domain/User.h"

template <class T>
class List {
private:
    Node<T> *first;
public:
    // default constructor
    List() {
        first = nullptr;
    }

    // vetifica daca lista este goala
    bool isEmpty() {
        return (this->first == nullptr);
    }

    // adauga un nod in lista cu informatia primita ca parametru
    void add(T elem) {
        Node<T> *node = new Node<T>(elem);
        if (isEmpty())
            first = node;
        else {
            Node<T> *last = first;
            while (last->next != nullptr)
                last = last->next;
            last->next = node;
        }
    }

    // modifica un elemnt din lista
    void update(T uV, T uN) {
        Node<T> *nodeV = new Node<T>(uV);
        Node<T> *nodeN = new Node<T>(uN);
        Node<T> *last = first;
        while (last != nullptr) {
            if (last->info == nodeV->info)
                last->info = nodeN->info;
            last = last->next;
        }
    }

    // sterge un element din lista
    void remove(T& e) {
        Node<T> *nodeToDelete = nullptr;
        T infoToReturn;

        if (first != nullptr) { // if the list is not empty
            if (first->info == e) {
                nodeToDelete = first;
                first = first->next; //first points to the next node
            } else {
                Node<T> *p = first->next;
                Node<T> *q = first;
                while (p != nullptr)
                    if (p->info == e) {
                        nodeToDelete = p;
                        p = nullptr;
                    } else {
                        p = p->next;
                        q = q->next;
                    }
                if (nodeToDelete != nullptr)
                    q->next = nodeToDelete->next;
            }
        }
        if (nodeToDelete != nullptr) { // if the elem e was found
            infoToReturn = nodeToDelete->info;
            delete nodeToDelete;
            return;
        }
        return; // e does not exist in the list or the list is empty
    }

    // cauta un element din lista
    bool search(T elem){
        Node<T> * node = new Node<T>(elem);
        Node<T> *last = first;
        while (last != nullptr){
            if (last->info == node->info)
                return true;
            last = last->next;
        }
        return false;
    }

    // returneaza primul nod al listei
    Node<T>* getFirst(){
        return first;
    };

    // destructorul
    ~List(){
        first = nullptr;
    }
};

#endif //PROIECTSDA_LIST_H
