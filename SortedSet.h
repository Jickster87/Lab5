#pragma once

typedef int TElem;
typedef TElem TComp;
typedef bool(*Relation)(TComp, TComp);

#define NULL_TELEM -11111

class SortedSetIterator;

struct TreeNode {
    TComp data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(TComp d) : data(d), left(nullptr), right(nullptr) {}
};

class SortedSet {
    friend class SortedSetIterator;
private:
    int sizeSet;
    Relation rel;
    TreeNode* root;

public:
    // Constructor
    SortedSet(Relation r);

    // Adds an element to the sorted set
    bool add(TComp e);

    // Removes an element from the sorted set
    bool remove(TComp e);

    // Checks if an element is in the sorted set
    bool search(TElem elem) const;

    // Returns the number of elements from the sorted set
    int size() const;

    // Checks if the sorted set is empty
    bool isEmpty() const;

    // Returns an iterator for the sorted set
    SortedSetIterator iterator() const;

    // Destructor
    ~SortedSet();

private:
    // Recursive helper functions
    bool add_rec(TreeNode*& node, TComp e);
    bool remove_rec(TreeNode*& node, TComp e);
    bool search_rec(TreeNode* node, TComp e) const;
    void inorder_traversal(TreeNode* node, void(*visit)(TreeNode*));
    void destroy_tree(TreeNode* node);
};
