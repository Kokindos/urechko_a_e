//
// Created by admin on 28.09.2022.
//

#include "queue_r.h"
#include <iostream>
QueueR::QueueR(const QueueR &copy) {
    head = new Node(copy.head->value);
    Node *currentCopy = copy.head->next;
    Node *current = head;
    while (currentCopy != nullptr) {
        current->next = new Node(currentCopy->value);
        currentCopy = currentCopy->next;
    }
}

QueueR &QueueR::operator=(const QueueR &rhs) {
    QueueR copy(rhs);
    head = copy.head;
    return *this;
}

QueueR::~QueueR() {

} //деструктор указателя уничтожает сам указатель, а объект на которым ссылается указатель не уничтожается
void QueueR::push(int value) {
    if (head == nullptr) {
        head = new Node(value);
    } else if (value < head->value) {
        // если value < head
        Node *inserted = new Node(value);
        inserted->next = head;
        head = inserted;
    } else {
        Node *current = head;
        while (current->next != nullptr && current->next->value <= value) {
            current = current->next;
        } // двигаем current в цикле, а присваивание после цикла
        Node *inserted = new Node(value);
        inserted->next = current->next;
        current->next = inserted;
        //-> одновременно разыменовывает и достает значение
    }
}

void QueueR::pop() {
    head = head->next;
}

bool QueueR::empty() const {
    return head == nullptr;
}
std::ostream &QueueR::writeTo(std::ostream &ostrm) const {
    ostrm << left_bracket_ << " ";
    Node* current = head;
    while (current != nullptr) {
        ostrm << current->value << " ";
        current=current->next;
    }
    ostrm << right_bracket_ << std::endl;
    return ostrm;
}
int QueueR::front() const {
    return head->value;
}
std::ostream& operator<<(std::ostream &ostrm, const QueueR &data){
    return data.writeTo(ostrm);
}