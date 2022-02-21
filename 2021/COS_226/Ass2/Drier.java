// Dylan Kapnias (u18108467)

public class Drier extends Employees
{
    public Drier(Consensus<Integer> consensusObject, CarWash c) {
        super(consensusObject, c);
    }

    @Override
    public void work() {
        while (!workAt.dryFin) {
            consensus.propose(Integer.parseInt(Thread.currentThread().getName().split("-")[1]) - workAt.washCount, workAt.washCount);
            try {
                Thread.sleep((int)(Math.random() * (101 - 50) + 50));
            } catch (InterruptedException e) {}

            consensus.decide(workAt.washCount, workAt);
        }
    }

}