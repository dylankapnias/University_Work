// Dylan Kapnias (u18108467)

public class RMWConsensus extends ConsensusProtocol
{
    public RMWConsensus(int threadCount) {
        super(threadCount);
    }

    @Override
    public synchronized void decide() {
        int id = Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
        int otherID = 1 - id;
        int val = reg.getAndIncrement();

        System.out.println(String.format("The register value is %d.", val));

        if (val == v) {
            System.out.println(String.format("%s has decided to spend it's own proposed amount of R%d.", Thread.currentThread().getName(), proposed[id]));
        } else {
            System.out.println(String.format("%s has decided to spend the other proposed amount of R%d.", Thread.currentThread().getName(), proposed[otherID]));
            this.reset();
        }
    }
}