#include "SortedSetIterator.h"
#include <exception>


SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
    currentNode = nullptr;
}

void SortedSetIterator::first() {
    currentNode = multime.root;
    while (currentNode && currentNode->left)
    {
        stack.push(currentNode);
        currentNode = currentNode->left;
    }
}

void SortedSetIterator::next() {
    if (currentNode == nullptr && stack.empty()) {
        throw std::exception(); // Already at the end
    }

    if (currentNode != nullptr) { // Check if currentNode is not null before accessing it
        if (currentNode->right) {
            currentNode = currentNode->right;
            while (currentNode->left) {
                stack.push(currentNode);
                currentNode = currentNode->left;
            }
        }
        else if (!stack.empty()) {
            currentNode = stack.top();
            stack.pop();
        }
        else {
            currentNode = nullptr; // Reached the end
        }
    }
}


TElem SortedSetIterator::getCurrent()
{
    if (currentNode == nullptr) {
        throw std::exception(); // Iterator not valid
    }
    return currentNode->data;
}

bool SortedSetIterator::valid() const {
    return currentNode != nullptr;
}
