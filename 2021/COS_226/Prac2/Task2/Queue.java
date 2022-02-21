// Name: Dylan Kanpnias
// Student Number: u18108467

public class Queue extends Thread
{
	Store store;

	public Queue(Store s){
		store = s;
	}

	@Override
	public void run()
	{
		for (int i = 0; i < 5; i++)
		{
			store.enterStore(i);
		}
	}
}
