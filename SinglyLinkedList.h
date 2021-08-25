#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#define NULL 0

template<class T>
struct Node {

    T val_;
    Node * next_;

    explicit Node(T val) {
        val_ = val;
        next_ = nullptr;
    }

    Node(T val, Node * next) {
        val_ = val;
        next_ = next;
    }
};

template <class T>
class SinglyLinkedList {

    Node<T> * head_;
    Node<T> * tail_;
    int size_;

    void DeleteRecursively(Node<T> * head) {
        if (head == nullptr)
        {
            return;
        }

        DeleteRecursively(head->next_);

        delete head;
    }

public:

    SinglyLinkedList() {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }

    ~SinglyLinkedList() {
        Clear();
    }

    Node<T> * InsertFront(T val) {
        if (Empty())
        {
            head_ = new Node<T>(val);
            tail_ = head_;
        }
        else
        {
            Node<T> * new_head = new Node<T>(val, head_);
            head_ = new_head;
        }
        size_++;
        return head_;
    }

    Node<T> * InsertBack(T val) {
        if (Empty())
        {
            tail_ = new Node<T>(val);
            head_ = tail_;
        }
        else
        {
            tail_->next_ = new Node<T>(val);
            tail_ = tail_->next_;
        }
        size_++;
        return tail_;
    }

    T RemoveFront() {
        if (Empty())
        {
            return NULL;
        }

        if (size_ == 1)
        {
            tail_ = nullptr;
        }

        Node<T> * to_remove = head_;
        T val = head_->val_;

        head_ = head_->next_;
        size_--;

        delete to_remove;
        return val;
    }

    T RemoveBack() {
        if (Empty())
        {
            return NULL;
        }

        Node<T> * to_remove = tail_;
        T val = tail_->val_;

        Node<T> * itr = head_;
        while (itr->next_ != nullptr && itr->next_ != tail_)
        {
            itr = itr->next_;
        }
        itr->next_ = nullptr;
        tail_ = itr;
        size_--;

        if (Empty())
        {
            head_ = nullptr;
            tail_ = nullptr;
        }

        delete to_remove;
        return val;
    }

    T Remove(T val) {
        if (Empty() || !Find(val))
        {
            return NULL;
        }

        if (val == head_->val_)
        {
            return RemoveFront();
        }
        else if (val == tail_->val_)
        {
            return RemoveBack();
        }
        else
        {
            Node<T> * itr = head_;
            while (itr->next_ != nullptr && itr->next_->val_ != val)
            {
                itr = itr->next_;
            }

            Node<T> * to_remove = itr->next_;
            itr->next_ = itr->next_->next_;
            size_--;

            delete to_remove;
            return val;
        }
    }

    Node<T> * Find(T val) {
        Node<T> * itr = head_;
        while (itr != nullptr && itr->val_ != val)
        {
            itr = itr->next_;
        }
        return itr;
    }

    Node<T> * Head() {
        return head_;
    }

    Node<T> * Tail() {
        return tail_;
    }

    int Size() {
        return size_;
    }

    bool Empty() {
        return size_ == 0;
    }

    void Clear() {
        DeleteRecursively(head_);
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }

};

#endif
