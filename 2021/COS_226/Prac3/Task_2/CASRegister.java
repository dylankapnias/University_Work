// Dylan Kapnias (u18108467)

public class CASRegister {
    private int value;

    public CASRegister(int v){
        value = v;
    }
    public synchronized boolean compareAndSet(int e, int v) {
        if (e == this.value) {
            this.value = v;
            return true;
        } else {
            return false;
        }
    }

    public synchronized void set(int i) {
        this.value = i;
    }

    public synchronized int get() {
        return this.value;
    }
}