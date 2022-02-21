// Dylan Kapnias (u18108467)

public class Employees extends Thread
{
    CarWash workAt;
    Consensus<Integer> consensus;

    public Employees(Consensus<Integer> consensusObject, CarWash c) {
        consensus = consensusObject;
        workAt = c;
    }

    public void run() {
        this.work();
    }

    public void work() {
        System.out.println("Please implement in the child classes.");
    }
}