#include "SortedSet.h"
#include "SortedSetIterator.h"

// Constructor
SortedSet::SortedSet(Relation r) : rel(r), sizeSet(0), root(nullptr) {}

// Recursive function to add an element
bool SortedSet::add_rec(TreeNode*& node, TComp e) {
    if (node == nullptr) {
        node = new TreeNode(e);
        return true;
    }
    if (rel(e, node->data)) {
        if (node->data == e) return false;
        return add_rec(node->left, e);
    }
    else {
        return add_rec(node->right, e);
    }
}

// Adds an element to the sorted set
bool SortedSet::add(TComp e) {
    if (add_rec(root, e)) {
        sizeSet++;
        return true;
    }
    return false;
}

// Recursive function to search for an element
bool SortedSet::search_rec(TreeNode* node, TComp e) const {
    if (node == nullptr) return false;
    if (node->data == e) return true;
    if (rel(e, node->data)) return search_rec(node->left, e);
    return search_rec(node->right, e);
}

// Checks if an element is in the sorted set
bool SortedSet::search(TElem elem) const {
    return search_rec(root, elem);
}

// Returns the number of elements from the sorted set
int SortedSet::size() const {
    return sizeSet;
}

// Checks if the sorted set is empty
bool SortedSet::isEmpty() const {
    return sizeSet == 0;
}

// Recursive function to remove an element
bool SortedSet::remove_rec(TreeNode*& node, TComp e) {
    if (node == nullptr) return false;
    if (node->data == e) {
        TreeNode* temp = nullptr;
        if (node->left == nullptr) {
            temp = node->right;
            delete node;
            node = temp;
        }
        else if (node->right == nullptr) {
            temp = node->left;
            delete node;
            node = temp;
        }
        else {
            TreeNode* successorParent = node;
            TreeNode* successor = node->right;
            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }
            if (successorParent != node) {
                successorParent->left = successor->right;
                successor->right = node->right;
            }
            successor->left = node->left;
            delete node;
            node = successor;
        }
        return true;
    }
    else if (rel(e, node->data)) {
        return remove_rec(node->left, e);
    }
    else {
        return remove_rec(node->right, e);
    }
}

// Removes an element from the sorted set
bool SortedSet::remove(TComp e) {
    if (remove_rec(root, e)) {
        sizeSet--;
        return true;
    }
    return false;
}

// Inorder traversal to visit each node
void SortedSet::inorder_traversal(TreeNode* node, void(*visit)(TreeNode*)) {
    if (node == nullptr) return;
    inorder_traversal(node->left, visit);
    visit(node);
    inorder_traversal(node->right, visit);
}

// Destructor helper to destroy the tree
void SortedSet::destroy_tree(TreeNode* node) {
    if (node == nullptr) return;
    destroy_tree(node->left);
    destroy_tree(node->right);
    delete node;
}

// Destructor
SortedSet::~SortedSet() {
    destroy_tree(root);
}


SortedSetIterator SortedSet::iterator() const {
    return SortedSetIterator(*this);
}

