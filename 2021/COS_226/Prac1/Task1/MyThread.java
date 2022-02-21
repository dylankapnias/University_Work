public class MyThread extends Thread
{
    private Counter c;

    public MyThread(Counter inC) {
        this.c = inC;
    }

	public void run() {
		for (int i = 0; i < 5; i++) {
            System.out.println(String.format("%s Counter: %d", this.getName(), this.c.inc_and_return()));
        }
	}
}