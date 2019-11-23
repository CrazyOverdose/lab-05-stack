
template <typename T>
class stack_for_uncopyable_types
{
public:
    template <typename ... Args>
    void push_emplace(Args&&... value);
    void push(T&& value);
    const T& head() const;
    T pop();
};
