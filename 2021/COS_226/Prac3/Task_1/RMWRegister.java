// Dylan Kapnias (u18108467)

public class RMWRegister {
    private int value;

    public RMWRegister(int v){
        value = v;
    }
    public synchronized int getAndIncrement() {
        int prior = this.value;
        this.value++;
        return prior;
    }

    public synchronized void set(int i) {
        this.value = i;
    }
}