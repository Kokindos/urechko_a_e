#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <queue_r.h>
#include <doctest.h>
#include <sstream>

TEST_SUITE("Priority queue QueueP testing") {
    TEST_CASE("Initialization, push, write") {
        std::ostringstream output("");
        QueueR queue;
        queue.push(2);
        output << queue;
        CHECK(output.str() == "{ 2 }\n");
        queue.push(3);
        output << queue;
        CHECK(output.str() == "{ 2 }\n{ 2 3 }\n");
        queue.push(1);
        output << queue;
        CHECK(output.str() == "{ 2 }\n{ 2 3 }\n{ 1 2 3 }\n");
    }

    TEST_CASE("Empty") {
        QueueR queue;
        CHECK(queue.empty());
        queue.push(0);
        CHECK_FALSE(queue.empty());
        queue.push(1);
        queue.pop();
        queue.pop();
        CHECK(queue.empty());
    }

    TEST_CASE("Pop") {
        QueueR queue;
        queue.push(4);
        queue.push(2);
        queue.push(5);
        queue.push(1);
        CHECK(queue.front()==1);
        queue.pop();
        CHECK(queue.front()==2);
        queue.pop();
        CHECK(queue.front()==4);
        queue.pop();
        CHECK(queue.front()==5);
        queue.pop();
        CHECK_THROWS_WITH(queue.pop(),"empty queue");
    }

    TEST_CASE("Front") {
        QueueR queue;
        queue.push(3);
        CHECK(queue.front() == 3);
        queue.push(4);
        CHECK(queue.front() == 3);
        queue.push(1);
        CHECK(queue.front() == 1);
        queue.pop();
        CHECK(queue.front() == 3);
        queue.pop();
        CHECK(queue.front() == 4);
        queue.pop();
        CHECK_THROWS_WITH(queue.front(), "empty queue");
    }

    TEST_CASE("Copying") {
        QueueR q1;
        q1.push(5);
        q1.push(3);
        q1.push(4);
        q1.push(1);
        q1.push(2);
        QueueR q2(q1);
        std::stringstream s1;
        s1<<q1;
        std::stringstream s2;
        s2<<q2;
        CHECK(s1.str()==s2.str());
        CHECK(q2.front() == 1);
        q2.pop();
        CHECK(q1.front() == 1);
        CHECK(q2.front() == 2);
        q2 = q1;
        CHECK(q2.front() == 1);
        q2.pop();
        CHECK(q1.front() == 1);
        CHECK(q2.front() == 2);
    }

}