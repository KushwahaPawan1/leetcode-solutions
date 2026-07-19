class MyCircularQueue {
public:
    int f; // Front index (Queue ka first element)
    int b; // Back index (Next insertion position)
    int s; // Current size of queue
    int c; // Maximum capacity
    vector<int> arr;

    // Constructor
    MyCircularQueue(int k) {
        f = 0;
        b = 0;
        s = 0;
        c = k;

        // Capacity size ka vector banao
        vector<int> v(k);
        arr = v;
    }

    // =================== ENQUEUE ===================
    // Queue ke back me element insert karega
    bool enQueue(int k) {

        // Agar queue full hai to insertion possible nahi
        if(s == c)
            return false;

        // Current back position par value insert karo
        arr[b] = k;

        // Back ko next position par le jao
        b++;

        // Agar array ke end tak pahunch gaye
        // to circular queue me dobara 0 index par aa jao
        if(b == c)
            b = 0;

        // Size increase karo
        s++;

        return true;
    }

    // =================== DEQUEUE ===================
    // Front se element remove karega
    bool deQueue() {

        // Queue empty hai
        if(s == 0)
            return false;

        // Front ko next position par le jao
        f++;

        // Agar end par pahunch gaye
        // to dobara starting par aa jao
        if(f == c)
            f = 0;

        // Size decrease
        s--;

        return true;
    }

    // =================== FRONT ===================
    // Front element return karega
    int Front() {

        if(s == 0)
            return -1;

        return arr[f];
    }

    // =================== REAR ===================
    // Last inserted element return karega
    int Rear() {

        if(s == 0)
            return -1;

        // Agar b == 0 hai to iska matlab
        // last inserted element last index par hai
        if(b == 0)
            return arr[c - 1];

        // Normal case
        // b hamesha next empty position ko point karta hai
        // Isliye rear = b-1
        return arr[b - 1];
    }

    // =================== ISEMPTY ===================
    bool isEmpty() {

        if(s == 0)
            return true;
        else
            return false;
    }

    // =================== ISFULL ===================
    bool isFull() {

        if(s == c)
            return true;
        else
            return false;
    }
};

