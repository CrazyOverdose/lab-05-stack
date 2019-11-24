#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T value;
    Node<T> *prev;
};

template <typename T>
class stack_for_uncopyable_types
{

private:
    Node<T>* vertex_f_u_t = nullptr;  //вершина стэка

public:
    template <typename ... Args>
    void push_emplace(Args&&... value)
    {
        auto element = new Node{{forward<Args>(value)...}, vertex_f_u_t} //позволяет выполнить идельную передачу аргументов, принимаемых в качестве rvalue-ссылок
        vertex_f_u_t = element;
    }

    void push(T&& value)
    {
        auto element = new Node{forward<T>(value), vertex_f_u_t} //позволяет выполнить идельную передачу аргументов, принимаемых в качестве rvalue-ссылок
        vertex_f_u_t = element;
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

    T pop()
    {
        if (vertex == nullptr)
        {
            Except();
        }

        else
        {   auto remote = vertex->value;
            vertex = vertex->prev;
            return remote;
        }
    }
};
