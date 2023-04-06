#pragma once

template <typename Type>
class Stack
{
    enum
    {
        SIZE = 10
    };
    int stack_size;
    Type *items;
    int top;

public:
    explicit Stack(int ss = SIZE);
    Stack(const Stack &st);
    ~Stack() { delete[] items; }

    bool is_empty();
    bool is_full();

    bool push(Type &item);
    bool pop(Type &item);
    Stack &operator=(const Stack &st);
};

template <typename Type>
Stack<Type>::Stack(int ss) : stack_size(ss), top(0)
{
    items = new Type[stack_size];
}

template <typename Type>
Stack<Type>::Stack(const Stack &st)
{
    stack_size = st.stack_size;
    top = st.top;
    for (int i(0); i < top; i++)
        items[i] = *(st.items + i);
}

template <typename Type>
bool Stack<Type>::is_empty() { return top == 0; }

template <typename Type>
bool Stack<Type>::is_full() { return top == Size; }

template <typename Type>
bool Stack<Type>::push(Type &item)
{
    if (top < Size)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template <typename Type>
bool Stack<Type>::pop(Type &item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    return false;
}

template <typename Type>
Stack<Type> &Stack<Type>::operator=(const Stack &st)
{
    if (this == &st)
        return *this;
    delete[] items;
    stack_size = st.stack_size;
    top = st.top;
    items = new Type[stack_size];
    for (int i(0); i < top; i++)
        items[i] = *(st.items + i);
    return *this;
}
