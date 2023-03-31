//
// Created by Sergiu Neag on 5/2/2022.
//

#ifndef PROIECTSDA_NODE_H
#define PROIECTSDA_NODE_H
template <class T> class List;
template <class T>
class Node {
private:
    T info;
    Node<T> *next;
public:
    // construcorul cu parametrii
    Node(T info) {
        this->next = nullptr;
        this->info = info;
    }

    // returneaza informatia unui nod
    T& getInfo(){
        return this->info;
    }

    // returneaza un pointer catre nodul urmator
    Node<T> * getNext(){
        return next;
    }

//    bool operator == (Node<T> * node){
//        return () ;
//    }

    friend class List<T>;
};
#endif //PROIECTSDA_NODE_H
