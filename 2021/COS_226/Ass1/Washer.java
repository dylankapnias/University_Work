public class Washer extends Employees
{
    public Washer(CarWash c) {
        super(c);
    }

    @Override
    public void work() {
        workAt.wash();
    }

}