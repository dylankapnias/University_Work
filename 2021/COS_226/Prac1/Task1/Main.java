public class Main {
    public static void main(String[] args){
        Counter c = new Counter();
        Thread t1 = new MyThread(c);
        Thread t2 = new MyThread(c);

        t1.start();
        t2.start();

        /*try {
            t1.join();
        } catch(InterruptedException e){}

        try {
            t2.join();
        } catch(InterruptedException e){}*/
    }
}
