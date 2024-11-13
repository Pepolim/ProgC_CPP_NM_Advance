class List {
private:
    int m_count;
    int* m_items;

public:
    List(): m_count(0) {
        m_items = new int[100]; // Initial capacity
    }

    ~List() {
        delete[] m_items;
        m_items = nullptr;
    }

    void Insert(int index, int value) {
        if (index >= 0 && index <= m_count) {
            for (int i = m_count; i > index; i--) {
                m_items[i] = m_items[i-1];
            }
            m_items[index] = value;
            m_count++;
        }
    }

    int Get(int index) {
        if (index >= 0 && index < m_count)
            return m_items[index];
        return -1;
    }

    void Remove(int index) {
        if (index >= 0 && index < m_count) {
            for (int i = index; i < m_count-1; i++) {
                m_items[i] = m_items[i+1];
            }
            m_count--;
        }
    }

    int Count() {
        return m_count;
    }
};