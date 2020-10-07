// https://leetcode.com/problems/print-foobar-alternately/

class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int cnt;
public:
    FooBar(int n) {
        this->n = n;
        this->cnt = 0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this](){return cnt==0;});
            cnt = 1;
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            
            mtx.unlock();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this](){return cnt==1;});
            cnt = 0;

            // printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            
            mtx.unlock();
            cv.notify_one();
        }
    }
};