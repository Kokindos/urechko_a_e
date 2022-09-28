//
// Created by admin on 28.09.2022.
//

#include "queue_r.h"

QueueR(const QueueR &copy){
    Node* current=copy.head;

};

QueueR &operator=(const QueueR &rhs){

};

~QueueR(); //деструктор указателя уничтожает сам указатель, а объект на которым ссылается указатель не уничтожается
void QueueR::push(int value) {
    if (head == nullptr) {
        head = &Node(value);
    } else if (head->next == nullptr) { // если value < head
        Node inserted = Node(value);
        if (value < head->value) {
            head = &inserted;
            head->next = current;
        }
    } else {
        Node *current = head;
        while (current->next != nullptr && current->next->value <= value) {
            current = current->next;
        } // двигаем current в цикле а присваивание после цикла
        Node inserted = Node(value);
        inserted.next = current->next;
        current->next = &inserted;
        //-> одновременно разыменовывает и достает значение
    }
}

void QueueR::pop() {
    head = head.next;
}

bool QueueR::empty() const {
    return head == nullptr;
};

int QueueR::front() const {
    return head->value;
};