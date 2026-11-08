#ifndef MY_UNIQUE_PTR_H
#define MY_UNIQUE_PTR_H

class my_unique_ptr {
private:
    int *m_ptr = nullptr;

public:
    my_unique_ptr(int val) {
        m_ptr = new int(val);
    }

    ~my_unique_ptr() {
        if(m_ptr != nullptr) {
            delete m_ptr;
            m_ptr = nullptr;
        }
    }

    my_unique_ptr(const my_unique_ptr&) = delete;
    my_unique_ptr& operator=(const my_unique_ptr&) = delete;

    int& operator*() {
        return *m_ptr;
    }

    int* operator->() {
        return m_ptr;
    }
    
    int* get() {
        return m_ptr;
    }
};
#endif