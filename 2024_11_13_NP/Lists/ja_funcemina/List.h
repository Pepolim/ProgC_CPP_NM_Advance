#include <iostream>

class List
{
private:
    int m_count;
    int *m_items;

public:
    List(): m_count(0) {
         m_items = new int[100]; // Initial capacity
    }

    ~List()
    {
        delete[] m_items;
        m_items = NULL;
    }

    int Get(int index)
    {
        // Check if the index is out of bound
        if (index < 0 || index > m_count)
            return -1;
        return m_items[index];
    }

    void Insert(int index, int val)
    {
        // Check if the index is out of bound
        if (index < 0 || index > m_count)
            return;
        // Copy the current array
        int *oldArray = m_items;
        // Increase the array length
        m_count++;
        // Initialize a new array
        m_items = new int[m_count];
        // Fill the new array with inserted data
        for (int i = 0, j = 0; i < m_count; ++i)
        {

            if (index == i)
            {
                m_items[i] = val;
            }
            else
            {
                m_items[i] = oldArray[j];
                ++j;
            }
        }
        // Remove copied array
        delete[] oldArray;
    }

    int Search(int val)
    {
        // Looping through the array elements
        // return the array index if value is found
        for (int i = 0; i < m_count; ++i)
        {
            if (m_items[i] == val)
            {
                return i;
            }
        }
        return -1;
    }

    void Remove(int index)
    {
        // Check if the index is out of bound
        if (index < 0 || index > m_count)
            return;
        // Copy the current array
        int *oldArray = m_items;
        // Decrease the array length
        m_count--;
        // Initialize a new array
        m_items = new int[m_count];
        // Fill the new array
        // and remove the selected index
        for (int i = 0, j = 0; i < m_count; ++i, ++j)
        {
            if (index == j)
            {
                ++j;
            }
            m_items[i] = oldArray[j];
        }
        // Remove copied array
        delete[] oldArray;
    }

    int Count()
    {
        return m_count;
    }
};

