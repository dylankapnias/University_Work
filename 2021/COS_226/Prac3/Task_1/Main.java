// Dylan Kapnias (u18108467)

public class Main
{
    public static void main(String[] args) {
        int threadAmount = 2;
        ConsensusThread[] threads = new ConsensusThread[threadAmount];
        RMWConsensus consensus = new RMWConsensus(threadAmount);

        for (int i = 0; i < threadAmount; i++) {
            threads[i] = new ConsensusThread(consensus);
        }

        for (int i = 0; i < threadAmount; i++) {
            threads[i].start();
        }
    }
}