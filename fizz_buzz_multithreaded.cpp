// https://leetcode.com/problems/fizz-buzz-multithreaded/

class FizzBuzz {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int curr;
    bool ready;
public:
    FizzBuzz(int n) {
        this->n = n;
        this->curr = 1;
    }
    
    void bfRunner(function<bool(int)> check, function<void(int)> Printer) {
        while(curr <= n) {
            {
                std::unique_lock<std::mutex> lck(mtx);
                cv.wait(lck, [&]{return curr > n || check(curr);});
                if (curr > n) break;
                Printer(curr);
                curr++;
            }
            cv.notify_all();
        }
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        bfRunner([](int i) {return i % 15 != 0 && i % 3 == 0;}, 
                [&](int i){printFizz();});
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        bfRunner([](int i) {return i % 15 != 0 && i % 5 == 0;}, 
                [&](int i){printBuzz();});
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        bfRunner([](int i) {return i % 15 == 0;}, 
                [&](int i){printFizzBuzz();});
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        bfRunner([](int i) {return i % 15 != 0 && i % 5 != 0 && i % 3 != 0;}, 
                 [&](int i){printNumber(i);});
    }
};