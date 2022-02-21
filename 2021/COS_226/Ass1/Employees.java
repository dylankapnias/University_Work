public class Employees extends Thread
{
    CarWash workAt;

    public Employees(CarWash c) {
        workAt = c;
    }

    @Override
    public void run() {
        this.work();
    }

    public void work() {
        System.out.println("Please implement in the child classes.");
    }
}