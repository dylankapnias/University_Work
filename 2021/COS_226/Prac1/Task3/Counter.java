public class Counter {
    int iCount = 0;
    PetersonLock pLock = new PetersonLock();

    public int inc_and_return(int id) {
        pLock.lock(id);

        try {
            int temp = iCount;
            iCount = temp + 1;
        } finally {
            pLock.unlock(id);
        }

        return iCount;
    }
}