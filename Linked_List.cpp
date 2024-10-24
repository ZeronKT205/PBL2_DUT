#pragma once
#include <iostream>
using namespace std;

template<class T>
class Node {
private:
    T data;
    Node<T>* next;
    template<class U>
    friend class LinkedList;

public:
    Node() : next(nullptr) {}  // Khởi tạo con trỏ next là nullptr

    Node(T data) : data(data), next(nullptr) {}  // Constructor khởi tạo giá trị
};

template<class T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() {
        this->head = nullptr;
    }

    ~LinkedList() {
        // Xóa toàn bộ danh sách khi đối tượng bị hủy để tránh rò rỉ bộ nhớ
        while (head != nullptr) {
            removeFirst();
        }
    }
    Node<T>* getHead() const {
        return head;
    }   

    void addLast(T item) {
        Node<T>* node = new Node<T>(item);  // Sử dụng new Node<T> thay vì new Node<T>[1]
        if (head == nullptr) {
            head = node;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
    }

    void addFirst(T item) {
        Node<T>* node = new Node<T>(item);  // Sử dụng new Node<T> thay vì new Node<T>[1]
        if (head == nullptr) {
            head = node;
            return;
        }
        node->next = head;
        head = node;
    }

    void addAtIndex(int index, T item) {
        if (index > length() || index < 0) {
            return;
        }
        Node<T>* node = new Node<T>(item);
        if (index == 0) {
            addFirst(item);
            return;
        }
        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr && count < index - 1) {
            temp = temp->next;
            count++;
        }
        node->next = temp->next;
        temp->next = node;
    }

    int length() const {
        int len = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void remove() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;  // Giải phóng bộ nhớ của Node cuối cùng
        temp->next = nullptr;
    }

    void removeAtIndex(int index) {
        if (index >= length() || index < 0 || head == nullptr) {
            return;
        }

        if (index == 0) {
            removeFirst();
            return;
        }

        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (count == index - 1) {
                Node<T>* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;  // Giải phóng bộ nhớ
                break;
            }
            count++;
            temp = temp->next;
        }
    }

    void removeFirst() {
        if (head == nullptr) {
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;  // Giải phóng bộ nhớ của Node đầu tiên
    }

 /*   T get(int index) const {
        if (head == nullptr) {
            throw std::out_of_range("Empty list!");
        }
        else if (index >= length() || index < 0) {
            throw std::out_of_range("Index out of bound!");
        }

        Node<T>* temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (count == index) {
                return temp->data;
            }
            count++;
            temp = temp->next;
        }

        throw std::out_of_range("Index out of bound!");
    }*/

    bool empty() const {
        return head == nullptr;
    }
    T& get(int index) const {
        if (head == nullptr) {
            throw std::out_of_range("Empty list!");  // Danh sách trống
        }
        else if (index >= length() || index < 0) {
            throw std::out_of_range("Index out of bound!");  // Index không hợp lệ
        }

        Node<T>* temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (count == index) {
                return temp->data;  // Trả về tham chiếu tới dữ liệu trong node
            }
            count++;
            temp = temp->next;
        }

        throw std::out_of_range("Index out of bound!");  // Phòng trường hợp không tìm thấy index
    }

};
