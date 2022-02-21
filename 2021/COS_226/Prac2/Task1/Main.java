// Name: Dylan Kanpnias
// Student Number: u18108467

public class Main {

    public static void main(String[] args) {
	    Queue[] queues = new Queue[4];
        Store store = new Store(4);

        for(int i = 0; i < 4; i++)
            queues[i] = new Queue(store);

        for(Queue queue : queues)
            queue.start();
    }
}
