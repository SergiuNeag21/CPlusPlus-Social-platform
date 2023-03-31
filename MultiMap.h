//
// Created by Sergiu Neag on 5/16/2022.
//

#ifndef PROIECTSDA_MULTIMAP_H
#define PROIECTSDA_MULTIMAP_H

#include "List.h"
#include <iostream>
#include <vector>

using namespace std;

template <class Key, class Value>
class Multimap {
private:
    template <class K, class V>
    class MapNode {
    public:
        K key;
        V value;
        MapNode<K,V>* next;
        MapNode(K key, V value) : key(key), value(value){ this->next= nullptr;}
    };

    template<class V>
    class ListNode {
    public:
        V info;
        ListNode<V> *next;
        ListNode(V info, ListNode<V> *next) : info(info), next(next) {}
        ListNode(V info) : info(info) { next = nullptr; }
    };
    int size;
    MapNode<Key,ListNode<Value>*>* first;

    MapNode<Key, ListNode<Value>*>* searchAdress(Key k){
        if(this->size == 0) return nullptr;
        MapNode<Key, ListNode<Value>*>* p = first;
        while(p->next != nullptr){
            if(p->key == k) return p;
            p = p->next;
        }
        return p;
    }


public:
    // constructorul default
    Multimap(){
        this->first = nullptr;
        this->size = 0;
    }

    // adauga o cheie si valoare
    void put(Key key, Value value){
        MapNode<Key, ListNode<Value>*>* poz = searchAdress(key);

        if(poz == nullptr){
            this->first = new MapNode<Key, ListNode<Value>*>(key, new ListNode<Value>(value));
            this->size++;
        }else{
            if(poz->key == key){  //cazul:exista in dictionar o pereche cu cheia egala cu key
                ListNode<Value>* node = new ListNode<Value>(value, poz->value);
                poz->value = node;
            }else{
                poz->next = new MapNode<Key, ListNode<Value>*>(key, new ListNode<Value>(value));
                this->size++;
            }
        }
    }

    int get_size(){
        return this->size;
    }


    // sterge o cheie si valoare specificata
    void remove(Key key, Value value) {
        MapNode<Key, ListNode<Value>*>* poz = searchAdress(key);

        if (poz != nullptr && poz->key == key) {
            ListNode<Value> *p = poz->value;
            if (p->info == value) {
                poz->value = p->next;
                delete p;
                this->size--;
            }
            else {
                while (p->next != nullptr && !(p->next->info == value)) p = p->next;
                if (p->next != nullptr && p->next->info == value) {
                    ListNode<Value> *q = p->next;
                    p->next = q->next;
                    delete q;
                    this->size--;
                }
            }
        }
    }

    // returneaza o lista cu elementele multimapului
    List<Value> get_all(){
        List<Value> result;
        MapNode<Key, ListNode<Value> *> *p = first;
        while (p != nullptr) {
            ListNode<Value> *q = p->value;
            p = p->next;
            result.add(q->info);
        }
        return result;
    }

    // destructorul
    ~Multimap() {
        MapNode<Key, ListNode<Value> *> *p = first;
        while (p != nullptr) {
            MapNode<Key, ListNode<Value> *> *q = p;
            p = p->next;
            delete q;
        }
    }
};

//
//#include <vector>
//
//template<class T, class U>
//class Multimap {
//private:
//    struct ListNode {
//        U value;
//        ListNode* next;
//    };
//
//    struct DictNode {
//        T key;
//        ListNode* value;
//        DictNode* next;
//    };
//
//    DictNode* searchAddress(T key);
//public:
//    Multimap();
//    ~Multimap();
//
//    void put(T key, U value);
//    std::vector<U> remove(T key);
//    void remove(T key, U value);
//    std::vector<U> get(T key);
//    bool contains(T key);
//    bool contains(T key, U value);
//
//    std::vector<std::vector<U>> get_all();
//    int get_size();
//
//private:
//    DictNode* head;
//};
//
//template<class T, class U>
//inline typename Multimap<T, U>::DictNode* Multimap<T, U>::searchAddress(T key) {
//    DictNode* current = head;
//    while (current != nullptr) {
//        if (current->key == key) {
//            return current;
//        }
//        current = current->next;
//    }
//    return nullptr;
//}
//
//template<class T, class U>
//inline Multimap<T, U>::Multimap()
//        : head(nullptr)
//{}
//
//template<class T, class U>
//inline Multimap<T, U>::~Multimap()
//{
//    DictNode* curr = head;
//    while (curr != nullptr) {
//        DictNode* next = curr->next;
//        delete curr->value;
//        delete curr;
//        curr = next;
//    }
//}
//
//template<class T, class U>
//inline void Multimap<T, U>::put(T key, U value) {
//    DictNode* current = searchAddress(key);
//    if (current == nullptr) {
//        DictNode* newNode = new DictNode;
//        newNode->key = key;
//        newNode->value = new ListNode;
//        newNode->value->value = value;
//        newNode->value->next = nullptr;
//        newNode->next = head;
//        head = newNode;
//    }
//    else {
//        ListNode* newNode = new ListNode;
//        newNode->value = value;
//        newNode->next = current->value;
//        current->value = newNode;
//    }
//}
//
//template<class T, class U>
//inline std::vector<U> Multimap<T, U>::remove(T key) {
//    std::vector<U> values;
//    DictNode* current = searchAddress(key);
//    if (current == nullptr) {
//        return values;
//    }
//    else {
//        ListNode* prev = nullptr;
//        ListNode* curr = current->value;
//        while (curr != nullptr) {
//            values.push_back(curr->value);
//            prev = curr;
//            curr = curr->next;
//            delete prev;
//        }
//    }
//
//    if (current->next == nullptr) {
//        delete current;
//        head = nullptr;
//    }
//
//    return values;
//}
//
//template<class T, class U>
//inline void Multimap<T, U>::remove(T key, U value) {
//    DictNode* current = searchAddress(key);
//    if (current == nullptr) {
//        return;
//    }
//    else {
//        ListNode* curr = current->value;
//        ListNode* prev = nullptr;
//        while (curr != nullptr) {
//            if (curr->value == value) {
//                if (prev == nullptr) {
//                    current->value = curr->next;
//                }
//                else {
//                    prev->next = curr->next;
//                }
//                delete curr;
//                return;
//            }
//            prev = curr;
//            curr = curr->next;
//        }
//    }
//}
//
//template<class T, class U>
//inline std::vector<U> Multimap<T, U>::get(T key) {
//    DictNode* current = searchAddress(key);
//    if (current == nullptr) {
//        return std::vector<U>();
//    }
//    else {
//        ListNode* curr = current->value;
//        std::vector<U> result;
//        while (curr != nullptr) {
//            result.push_back(curr->value);
//            curr = curr->next;
//        }
//
//        return result;
//    }
//}
//
//template<class T, class U>
//inline bool Multimap<T, U>::contains(T key) {
//    return searchAddress(key) != nullptr;
//}
//
//template<class T, class U>
//inline bool Multimap<T, U>::contains(T key, U value) {
//    DictNode* current = searchAddress(key);
//    if (current == nullptr) {
//        return false;
//    }
//    else {
//        ListNode* curr = current->value;
//        while (curr != nullptr) {
//            if (curr->value == value) {
//                return true;
//            }
//            curr = curr->next;
//        }
//        return false;
//    }
//}
//
//template<class T, class U>
//inline std::vector<std::vector<U>> Multimap<T, U>::get_all() {
//    std::vector<std::vector<U>> result;
//    DictNode* current = head;
//    while (current != nullptr) {
//        result.push_back(get(current->key));
//        current = current->next;
//    }
//
//    return result;
//}
//
//template<class T, class U>
//int Multimap<T,U>::get_size(){
//    int nr = 0;
//    for(auto& t: get_all())
//        for(auto& elem: t)
//            nr++;
//    return nr;
//}

#endif //PROIECTSDA_MULTIMAP_H
