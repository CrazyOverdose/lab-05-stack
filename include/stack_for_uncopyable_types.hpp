#include <iostream>
#include "exceptions.hpp"

using namespace std;

template <typename T>
struct Node_f_u_t
{
    T value;
    Node_f_u_t<T> *prev;
};

template <typename T>
class stack_for_uncopyable_types
{

private:
    Node_f_u_t<T>* vertex_f_u_t = nullptr;  //вершина стэка

public:
    template <typename ... Args>
    void push_emplace(Args&&... value)
    {
        auto element = vertex_f_u_t;
        vertex_f_u_t = new Node_f_u_t<T>{{forward<Args>(value)...}, element}; //позволяет выполнить идельную передачу аргументов, принимаемых в качестве rvalue-ссылок
    }

    void push(T&& value)
    {
        auto element = vertex_f_u_t;
        vertex_f_u_t = new Node_f_u_t<T>{forward<T>(value), element};
    }

    const T& head() const
    {
        if (vertex_f_u_t == nullptr)
            throw Exceptions();
        else
        return vertex_f_u_t->value;
    }

    T pop()
    {
        if (vertex_f_u_t == nullptr)
            throw Exceptions();
        else {
       auto remote = vertex_f_u_t->value;
            vertex_f_u_t = vertex_f_u_t->prev;
            return remote;}
    }
};
