#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
    Node(const Node& other): data(other.data), next(nullptr){
        if (other.next){
            next = new Node(*other.next);
        }
    };
    ~Node(){};
};
Node* build_linked_list(const std::vector<int>& values);
std::string print_linked_list(Node* root);
void delete_entire_linked_list(Node* root);
int get_linked_list_data_item_value(Node* root, int node_number);
void delete_list_element(Node*& root,int node_number);

#endif