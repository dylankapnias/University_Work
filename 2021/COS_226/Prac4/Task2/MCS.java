// Name: Dylan Kanpnias
// Student Number: u18108467

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicReference;
import java.lang.ThreadLocal;

public class MCS implements Lock
{
    private AtomicReference<QNode> tail;
    private ThreadLocal<QNode> qnode;

    public MCS() {
        tail = new AtomicReference<QNode>(null);
        qnode = new ThreadLocal<QNode>() {
            protected QNode initialValue() {
                return new QNode();
            }
        };  
    }

    public void lock() {
        QNode node = qnode.get();
        QNode pred = tail.getAndSet(node);

        if (pred != null) {
            node.locked = true;
            pred.next = node;

            while (node.locked) {
                Thread.yield();
            }
        }
    }

    public void unlock() {
        QNode node = qnode.get();
        if (node.next == null){
            if (tail.compareAndSet(node, null))
                return;
            
            while (node.next == null) {
                Thread.yield();
            }
        }

        node.next.locked = false;
    }

    public Condition newCondition() {
        return null;
    }

    public boolean tryLock(long lUnit, TimeUnit tUnit) {
        return false;
    }

    public boolean tryLock() {
        return false;
    }

    public void lockInterruptibly() {}
}