class CustomStack {
public:
    vector<int> st;
    int count;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        this->count = 0;
        this->st.reserve(maxSize);
    }

    void push(int x) {
        if (count < maxSize) {
            st[count] = x;
            count++;
        }
        //cout << "push " << count << " " << st[count - 1] << " " << x << endl;
    }

    int pop() {
        if (count > 0) {
            int temp = st[count - 1];
            st.erase(st.begin() + count);
            count--;
            return temp;
        } else {
            return -1;
        }
    }

    void increment(int k, int val) {
        int len = (count > k ? k : count);
        for (int i = 0; i < len; i++) {
            this->st[i] = this->st[i] + val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */