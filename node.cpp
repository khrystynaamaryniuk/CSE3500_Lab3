#include "node.h"
#include <iostream>
#include <string>


Node* build_linked_list(const std::vector<int>& values) {
    if (values.empty()) return nullptr;

    Node* root = new Node(values[0]);
    Node* current = root;
    for (auto i = 1; i < values.size(); i++) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return root;
}

std::string print_linked_list(Node* root) {
    
    if(!root){
        throw std::out_of_range("No root");
     
    }
    
    std::string output;
    while (root) {
        output+=std::to_string(root->data);
        if (root->next != nullptr) {
            output += " -> ";
        }
        root = root->next;
    }
    std::cout << output << std::endl;
    return output;
    
}
void delete_entire_linked_list(Node* root) {
    if(!root){
        throw std::out_of_range("No root");
        
    }
    while (root) {
        Node* temp = root;
        root = root->next;
        delete temp;
    }


}

int get_linked_list_data_item_value(Node* root, int node_number) {
    if(!root){
        throw std::out_of_range("No root");
    }
    if (node_number<0){
        throw std::out_of_range("Index out of range");
    }
    int i=0;
    while(root){
        if(i==node_number){
            return root->data;
        }
        root=root->next;
        i++;
    }
    throw std::out_of_range("Index out of range");
    
}
void delete_list_element(Node*& root, int node_number) {
    if (node_number<0){
        throw std::out_of_range("Index out of range");
        return;
    }
    if (!root){
        throw std::out_of_range("No root present");
        return;
    }

    if (node_number == 0) {
        Node* temp = root;
        root = root->next;
        delete temp;
        return;
    }

    Node* prev = root;
    for (int i=1; i<node_number && prev; i++){
        prev=prev->next;

    }
    if (!prev || !prev->next) throw std::out_of_range("Index out of range");

    Node* temp = prev->next;
    prev->next = prev->next->next;
    delete temp;
}

