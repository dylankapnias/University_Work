// Name: Dylan Kanpnias
// Student Number: u18108467

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.Condition;

public class Semaphore {
    private Lock lock = new ReentrantLock();
    private Condition condition = lock.newCondition();
    public int capacity = 0;
    public volatile int state = 0;

    public Semaphore(int n) {
        capacity = n;
    }

    public void lock() {
        lock.lock();
        try {
            while (state == capacity) {
                condition.await();
            }
            state++;
        } catch (InterruptedException e) {} 
        finally {
            lock.unlock();
        }
    }

    public void unlock() {
        lock.lock();
        try {
            state--;
            condition.signalAll();
        } finally {
            lock.unlock();
        }
    }
}