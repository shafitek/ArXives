// https://leetcode.com/problems/print-zero-even-odd/

class ZeroEvenOdd {
private:
    int n;
    int len;
    int idx;
    int num;
    mutex mtxz, mtxe, mtxo;
    condition_variable cv;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->len = 2*n;
        this->idx = 0;
        this->num = 1;
        
        // acquire these two locks now
        // leave the zero lock unacquired to avoid deadlock
        // and also because we want the thread to start with that
        mtxe.lock();
        mtxo.lock();
    }
    
    void releaseLockIfPossible() {
        idx++;
        if(idx >= len) {
            mtxz.unlock();
            mtxe.unlock();
            mtxo.unlock();
        } else if( idx % 2 == 0){
            mtxz.unlock();
        } else if(idx % 2 == 1 && num % 2 == 1) {
            mtxo.unlock();
        } else if (idx % 2 == 1 && num % 2 == 0) {
            mtxe.unlock();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(idx < len) {
            mtxz.lock();
            if (idx >= len) break;
            printNumber(0);
            cout << 0 << flush;
            releaseLockIfPossible();
        }        
    }

    void even(function<void(int)> printNumber) {
        while(idx < len) {
            mtxe.lock();
            if (idx >= len) break;
            printNumber(num);
            cout << num << flush;
            num++;            
            releaseLockIfPossible();
        }  
    }

    void odd(function<void(int)> printNumber) {
        while(idx < len) {
            mtxo.lock();
            if (idx >= len) break;
            printNumber(num);
            cout << num << flush;
            num++;            
            releaseLockIfPossible();
        }        
    }
};