// Dylan Kapnias (u18108467)

public class CASConsensus extends ConsensusProtocol
{
    public CASConsensus(int threadCount) {
        super(threadCount);
    }

    @Override
    public synchronized void decide(int start, CarWash cw) {
        int id = Integer.parseInt(Thread.currentThread().getName().split("-")[1]) - start;

        boolean val = reg.compareAndSet(-1, id);

        if (val == true) {
            if (start == 0) {
                cw.wash();
                this.reset();
            }
            else {
                cw.dry();
                this.reset();
            }
        } else {

        }
    }
}