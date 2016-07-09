template <typename E>

class Node {
public:
    E element;
    Node<E> * next;
    Node(E pElement, Node<E> * pNext = NULL) {
        element = pElement;
        next = pNext;
    }
    Node(Node<E> * pNext = NULL) {
        next = pNext;
    }
};
