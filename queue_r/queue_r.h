//
// Created by admin on 28.09.2022.
//

#ifndef URECHKO_A_E_QUEUE_R_H
#define URECHKO_A_E_QUEUE_R_H


class QueueR {
public:
    QueueR() = default;

    QueueR(const QueueR &copy);

    QueueR &operator=(const QueueR &rhs);

    ~QueueR(); //деструктор указателя уничтожает сам указатель, а объект на которым ссылается указатель не уничтожается
    void push(int value);

    void pop();

    bool empty() const;

    int front() const;

private:
    struct Node {
        explicit Node(int value) : value(value); //

        Node *next = nullptr;
        int value = 0;
    };

    Node *head = nullptr;
};


#endif //URECHKO_A_E_QUEUE_R_H
