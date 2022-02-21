// Name: Dylan Kanpnias
// Student Number: u18108467

public class Queue extends Thread
{
	public final int PEOPLE_COUNT = 10;
	Store store;

	public Queue(Store s){
		store = s;
	}

	@Override
	public void run()
	{
		for (int i = 0; i < PEOPLE_COUNT; i++)
		{
			store.enterStore(i);
		}
	}
}
