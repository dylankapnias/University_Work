public class MyThread extends Thread
{
    private Counter c;

    public MyThread(Counter inC) {
        this.c = inC;
    }

	public void run() {
		for (int i = 0; i < 11; i++) {
            System.out.println(String.format("%s Counter: %d", this.getName(), this.c.inc_and_return(get_int_id())));
        }
	}

    public int get_int_id() {
        int id = 0;

        try {
            id = Integer.parseInt(this.getName().split("-")[1]);
        } catch (NumberFormatException nfe) {
            System.out.println("The input must be an integer.");
            System.exit(1);
        }
        
        return id;
    }
}