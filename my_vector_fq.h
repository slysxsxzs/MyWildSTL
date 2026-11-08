#ifndef MY_VECTOR_H
#define MY_VECTOR_H

class my_vector
{
private:
    int *m_data = nullptr; 
    int m_size = 0;
    int m_capacity = 0;

public:
    void init(int a, int b) {
        if(a > m_capacity)
        {
            if(m_data != nullptr)
            {
                delete[] m_data;
            }
            m_data = new int[a];
            m_capacity = a;
        }
        m_size = a;

        for(int os = 0; os < m_size; os++)
        {
            m_data[os] = b;
        }
    }

    void new_cap() {
        if(m_size == m_capacity)
        {   
            int new_capacity = (m_capacity == 0) ? 4 : m_capacity * 2;
            int *new_data = new int[new_capacity]; 
            
            for(int os = 0; os < m_size; os++)
            {
                new_data[os] = m_data[os];
            }

            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        } else {
            return;
        }
    }

    void insert(int index, int value) {
        if(index < 0 || index > m_size)
        {
            return;
        }
        if(m_size == m_capacity)
        {
            new_cap();
        }

        for(int os = m_size; os > index; os--)
        {
            m_data[os] = m_data[os - 1];
        }
        m_data[index] = value;
        m_size++;
    }

    int* get_data() { return m_data; }
    int get_size() { return m_size; }

    void push_back(int val) {
        if(m_size == m_capacity)
        {
            new_cap();
        }
        m_data[m_size] = val;
        m_size++;
    }

    void clear() {
        if(m_data != nullptr)
        {
            delete[] m_data;
            m_data = nullptr;
            m_size = 0;
            m_capacity = 0;
        }
    }

    ~my_vector() {
        clear();
    }
};
#endif