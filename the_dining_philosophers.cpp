// https://leetcode.com/problems/the-dining-philosophers/

class DiningPhilosophers {
private:
    const int N = 5;
    mutex fork[5];
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        // This avoids the deadlock cycle if we look at the resource 
        // allocation graph
        mutex &first_fork = fork[min(philosopher, (philosopher + 1) % N)];
        mutex &second_fork = fork[max(philosopher, (philosopher + 1) % N)];
        
        first_fork.lock();
        pickRightFork();
        second_fork.lock();
        pickLeftFork();
        eat();
        putLeftFork();
        second_fork.unlock();
        putRightFork();
        first_fork.unlock();
    }
};