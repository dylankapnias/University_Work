// Dylan Kapnias (u18108467)

public class CASConsensus extends ConsensusProtocol
{
    public CASConsensus(int threadCount) {
        super(threadCount);
    }

    @Override
    public synchronized void decide() {
        int id = Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
        boolean val = reg.compareAndSet(-1, id);

        System.out.println(String.format("The register value is %d.", reg.get()));

        if (val == true) {
            System.out.println(String.format("%s has decided to spend it's own proposed amount of R%d.", Thread.currentThread().getName(), proposed[id]));
        } else {
            System.out.println(String.format("%s has decided to spend Thread-%d's proposed amount of R%d.", Thread.currentThread().getName(), reg.get(), proposed[reg.get()]));
        }
    }
}