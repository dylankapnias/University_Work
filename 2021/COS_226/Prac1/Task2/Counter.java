import java.util.concurrent.locks.ReentrantLock;

public class Counter {
    int iCount = 0;
    ReentrantLock reLock = new ReentrantLock();

    public int inc_and_return() {
        reLock.lock();

        try {
            iCount++;
        } finally {
            reLock.unlock();
        }

        return iCount;
    }
}