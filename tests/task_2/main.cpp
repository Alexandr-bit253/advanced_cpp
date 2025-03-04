#include <iostream>
#include <catch2/catch_test_macros.hpp>


struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};


TEST_CASE("PopBack and PopFront throw on empty list", "[List]") {
    List list;
    REQUIRE_THROWS(list.PopBack());
    REQUIRE_THROWS(list.PopFront());
}


TEST_CASE("Function `PushBack` works correctly", "[List]") {
    List list;
    list.PushBack(10);
    REQUIRE(list.Size() == 1);

    list.PushBack(20);
    REQUIRE(list.Size() == 2);

    REQUIRE(list.PopFront() == 10);
    REQUIRE(list.PopFront() == 20);
}


TEST_CASE("Function `PushFront` works correctly", "[List]") {
    List list;
    list.PushFront(30);
    REQUIRE(list.Size() == 1);

    list.PushFront(40);
    REQUIRE(list.Size() == 2);

    REQUIRE(list.PopBack() == 30);
    REQUIRE(list.PopBack() == 40);
}


TEST_CASE("Function `PopBack` works correctly", "[List]") {
    List list;
    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);

    list.PushBack(50);
    list.PushBack(60);
    REQUIRE(list.PopBack() == 60);
    REQUIRE(list.PopBack() == 50);
    REQUIRE(list.Empty());
}


TEST_CASE("Function `PopFront` works correctly", "[List]") {
    List list;
    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);

    list.PushFront(70);
    list.PushFront(80);
    REQUIRE(list.PopFront() == 80);
    REQUIRE(list.PopFront() == 70);
    REQUIRE(list.Empty());
}


TEST_CASE("Complex usage", "[List]") {
    List list;

    list.PushFront(10);
    list.PushBack(20);
    list.PushFront(5);
    list.PushBack(25);

    REQUIRE(list.Size() == 4);

    REQUIRE(list.PopFront() == 5);
    REQUIRE(list.PopBack() == 25);
    REQUIRE(list.PopFront() == 10);
    REQUIRE(list.PopBack() == 20);

    REQUIRE(list.Empty());
}