class MyCircularDeque
{
    deque<int> q;
    int size;
    int limitSize;

public:
    MyCircularDeque(int k)
    {
        size = 0;
        limitSize = k;
    }

    bool insertFront(int value)
    {
        if (size == limitSize)
        {
            return false;
        }
        q.push_front(value);
        size++;
        return true;
    }

    bool insertLast(int value)
    {
        if (size == limitSize)
        {
            return false;
        }
        q.push_back(value);
        size++;
        return true;
    }

    bool deleteFront()
    {
        if (!size)
        {
            return false;
        }
        q.pop_front();
        size--;
        return true;
    }

    bool deleteLast()
    {
        if (!size)
        {
            return false;
        }
        q.pop_back();
        size--;
        return true;
    }

    int getFront()
    {
        if (size == 0)
        {
            return -1;
        }
        return q.front();
    }

    int getRear()
    {
        if (size == 0)
        {
            return -1;
        }
        return q.back();
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == limitSize;
    }
};

/**
 * 
 *
 *
*MyCircularDeque *obj = new MyCircularDeque(k);
*bool param_1 = obj->insertFront(value);
*bool param_2 = obj->insertLast(value);
*bool param_3 = obj->deleteFront();
*bool param_4 = obj->deleteLast();
*int param_5 = obj->getFront();
*int param_6 = obj->getRear();
*bool param_7 = obj->isEmpty();
*bool param_8 = obj->isFull();
* /