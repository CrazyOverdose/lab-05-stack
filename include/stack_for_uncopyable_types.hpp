#include <iostream>
#include <exception>

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

    stack_for_uncopyable_types () = default;
    stack_for_uncopyable_types(const stack_for_uncopyable_types &stack)= delete; //конструктор копирования

    stack_for_uncopyable_types (stack_for_uncopyable_types&& te) = default;      // конструктор перемещения (constructible)
   auto operator=(stack_for_uncopyable_types&& te) noexcept -> stack_for_uncopyable_types& = default; // (assignable)

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
            throw logic_error("The stack is empty");
        else
        return vertex_f_u_t->value;
    }

    T pop()
    {
        if (vertex_f_u_t == nullptr)
            throw logic_error("The stack is empty");
        else {
       auto remote = vertex_f_u_t->value;
            vertex_f_u_t = vertex_f_u_t->prev;
            return remote;}
    }};
