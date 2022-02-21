// Dylan Kapnias (u18108467)

public class Washer extends Employees
{
    public Washer(Consensus<Integer> consensusObject, CarWash c) {
        super(consensusObject, c);
    }

    @Override
    public void work() {
        while (!workAt.washFin) {
            consensus.propose(Integer.parseInt(Thread.currentThread().getName().split("-")[1]), 0);
            try {
                Thread.sleep((int)(Math.random() * (101 - 50) + 50));
            } catch (InterruptedException e) {}

            consensus.decide(0, workAt);
        }
    }

}