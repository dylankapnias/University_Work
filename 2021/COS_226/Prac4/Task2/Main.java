// Name: Dylan Kanpnias
// Student Number: u18108467

public class Main {
    public final static int QUEUE_SIZE = 5;

    public static void main(String[] args) {
	    Queue[] queues = new Queue[QUEUE_SIZE];
        Store store = new Store(QUEUE_SIZE);

        for(int i = 0; i < QUEUE_SIZE; i++)
            queues[i] = new Queue(store);

        for(Queue queue : queues)
            queue.start();
    }
}
