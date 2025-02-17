
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "node.h"
#include "./include/doctest.h"

TEST_CASE("Building a linked list") {
    std::vector<int> values = {1, 2, 3, 4, 5};
    Node* root = build_linked_list(values);

    // Test accessing data by index
    CHECK(get_linked_list_data_item_value(root, 0) == 1);
    CHECK(get_linked_list_data_item_value(root, 2) == 3);
    CHECK(get_linked_list_data_item_value(root, 4) == 5);
    
    // Test out of bounds access
    CHECK_THROWS_AS(get_linked_list_data_item_value(root, 5), std::out_of_range);
    CHECK_THROWS_AS(get_linked_list_data_item_value(root, -1), std::out_of_range);
    
    delete_entire_linked_list(root);
}

TEST_CASE("Deleting a node in the linked list") {
    std::vector<int> values = {1, 2, 3, 4, 5};
    Node* root = build_linked_list(values);

    // Test deletion of a node at index 4 (last element)
    delete_list_element(root, 4);
    CHECK(print_linked_list(root) == "1 -> 2 -> 3 -> 4");

    // Test deletion of node at index 0 (first element)
    delete_list_element(root, 0);
    CHECK(print_linked_list(root) == "2 -> 3 -> 4");

    // Test deletion of node at index 1 (middle element)
    delete_list_element(root, 1);
    CHECK(print_linked_list(root) == "2 -> 4");
    
    delete_entire_linked_list(root);
}

TEST_CASE("Edge cases with empty list") {
    Node* root = nullptr;
    CHECK_THROWS_AS(print_linked_list(root), std::out_of_range);
    CHECK_THROWS_AS(delete_list_element(root, 0), std::out_of_range);
    CHECK_THROWS_AS(get_linked_list_data_item_value(root, -5), std::out_of_range);

}
TEST_CASE("Edge case with a single element") {
    std::vector<int> values = {10};
    Node* root = build_linked_list(values);

    // Test accessing the single element
    CHECK(get_linked_list_data_item_value(root, 0) == 10);

    // Test deleting the single element
    delete_list_element(root, 0);
    CHECK(root == nullptr);

    CHECK_THROWS_AS(delete_list_element(root, 0), std::out_of_range);
}
