//
// Created by admin on 28.09.2022.
//

#ifndef URECHKO_A_E_QUEUE_R_H
#define URECHKO_A_E_QUEUE_R_H

#include <iosfwd>

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

    std::ostream &writeTo(std::ostream &ostrm) const;

private:
    struct Node {
        explicit Node(int value) : value(value) {};
        Node *next = nullptr;
        int value = 0;
    };

    Node *head = nullptr;
    static const char left_bracket_ = '{', right_bracket_ = '}';
};
std::ostream& operator<<(std::ostream &ostrm, const QueueR &data);

#endif //URECHKO_A_E_QUEUE_R_H
