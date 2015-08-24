#ifndef STACK_H
#define STACK_H
#include "car.h"
#include "log.h"

template <class item>
class Stack
{
public:
    Stack()
    {
        Top = NULL;
    }

    ~Stack();

    void push(item* log)
    {
        if(!Top)
        {
            Top = log;
        }else{
            item* tmp = log;
            tmp->next = Top;
            Top = tmp;
        }
    }

    item* pop()
    {
        if(!Top)
            return NULL;
        item* tmp = Top;
        Top = Top->next;
        return tmp;
    }

    item* top()
    {
        return Top;
    }

    void clear()
    {
        if(Top)
        {
            delete pop();
            clear();
        }
    }

    void clean()
    {
        if(Top)
        {
            pop();
            clean();
        }
    }

private:
    item *Top;
};

template <>
class Stack <Car*> {
public:
    Car*Top;
    WAY way;

    Stack(WAY w)
    {
        Top = NULL;
        way=w;
    }

    ~Stack(){}

    void push(Car* log)
    {
        if(!Top)
        {
            Top = log;
        }else{
            Car* tmp = log;
            tmp->next = Top;
            Top = tmp;
        }
    }

    Car* pop()
    {
        if(!Top)
            return NULL;
        Car* tmp = Top;
        Top = Top->next;
        tmp->next = NULL;
        return tmp;
    }

    Car* top()
    {
        return Top;
    }

    void clear()
    {
        if(Top)
        {
            delete pop();
            clear();
        }
    }

    void clean()
    {
        if(Top)
        {
            pop();
            clean();
        }
    }
};

template <>
class Stack <Log*> {
public:
    Log*Top;

    Stack()
    {
        Top = NULL;
    }

    ~Stack(){}

    void push(Log* log)
    {
        if(!Top)
        {
            Top = log;
        }else{
            Log* tmp = log;
            tmp->next = Top;
            Top = tmp;
        }
    }

    Log* pop()
    {
        if(!Top)
            return NULL;
        Log* tmp = Top;
        Top = Top->next;
        tmp->next = NULL;
        return tmp;
    }

    Log* top()
    {
        return Top;
    }

    void clear()
    {
        if(Top)
        {
            delete pop();
            clear();
        }
    }

    void clean()
    {
        if(Top)
        {
            pop();
            clean();
        }
    }
};

#endif // STACK_H
