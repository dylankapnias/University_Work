public class PetersonLock {
    private boolean[] flag = new boolean[2];
    int victim = 0;

    public void lock(int id) {
        int i = id;
        int j = 1 - id;
        this.flag[i] = true;
        this.victim = i;
        while (this.flag[j] && this.victim == i) {};
    }

    public void unlock(int id) {
        this.flag[id] = false;
    }
}

/*public Condition newCondition() {

    }

    public boolean tryLock(long lUnit, TimeUnit tUnit) {

    }

    public boolean tryLock() {
        
    }*/