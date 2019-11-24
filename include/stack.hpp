#include <iostream>
#include "exceptions.hpp"

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
        else  // новый элемент  = вершина
        {
            Node<T> *elem = new Node<T>;

            elem->value = vertex->value;   // элемент получает значения "старой" вершины
            elem->prev = vertex->prev;

            vertex->value = value;        // "новая" вершина
            vertex->prev = elem;
        }
    }

    const T& head() const
    {
        return vertex->value;
    }
    void pop()
    {
        if (vertex == nullptr)
           throw Exceptions();
        else if (vertex != nullptr)
        vertex = vertex->prev;
    }
};
