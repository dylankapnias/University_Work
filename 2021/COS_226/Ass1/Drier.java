public class Drier extends Employees
{
    public Drier(CarWash c) {
        super(c);
    }

    @Override
    public void work() {
        workAt.dry();
    }

}