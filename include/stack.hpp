#include <iostream>
#include <except.hpp>

template <typename T>
struct Node
{
    T value;
    Node<T> *prev;
};

template <typename T>
class stack
{
private:
    Node<T>* vertex = nullptr;  //вершина стэка

public:
    void push(T&& value)
    {
        if (vertex == nullptr)
        {
            vertex = new Node<T>;
            vertex->value = value;
            vertex->prev = nullptr;
        }
        if (vertex != nullptr)   // новый элемент  = вершина
        {
            Node<T> *elem = new Node<T>;

            elem->value = vertex->value;   // элемент получает значения "старой" вершины
            elem->prev = vertex->prev;

            vertex->value = value;        // "новая" вершина
            vertex->prev = elem;
        }
    }

    void push(const T& value)
    {
        if (vertex == nullptr)
        {
            vertex = new Node<T>;
            vertex->value = value;
            vertex->prev = nullptr;
        }
        if (vertex != nullptr)   // новый элемент  = вершина
        {
            Node<T> *elem = new Node<T>;

            elem->value = vertex->value;   // элемент получает значения "старой" вершины
            elem->prev = vertex->prev;

            vertex->value = value;        // "новая" вершина
            vertex->prev = elem;
        }
    }

    void pop()
    {

        if (vertex == nullptr)
        {
            Except();
        }
        else {
            vertex = vertex->prev;}
    }

    const T& head() const
    {
        if (vertex == nullptr)
        {
            Except();
        }
        else {
        return vertex->value;}
    }
};