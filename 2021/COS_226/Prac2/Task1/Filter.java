import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

// Name: Dylan Kanpnias
// Student Number: u18108467

public class Filter implements Lock
{
	private int[] level;
	private int[] victim;
	private int n;

	public Filter(int n) {
		this.n = n;
		level = new int[n];
		victim = new int[n];

		for (int i = 0; i < n; i++) {
			level[i] = 0;
		}
	}	

	public void lock() {
		int myId = Integer.parseInt(Thread.currentThread().getName().split("-")[1]);

		for (int i = 1; i < n; i++) {
            level[myId] = i;
            victim[i] = myId;

            for (int k = 0; k < n; k++) {
                while ((k != myId) && (level[k] >= i && victim[i] == myId)) {
					//System.out.println(String.format("I am spinning with i -> %d, :: k -> %d, :: level[k] -> %d, :: victim[i] -> %d", i, k, level[k], victim[i]));
					System.out.print(""); // Ask about not working
				}
            }
        }
	}

	public void unlock() {
		int myId = Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
		level[myId] = 0;
	}

	public void lockInterruptibly() throws InterruptedException
	{
		throw new UnsupportedOperationException();
	}

	public boolean tryLock()
	{
		throw new UnsupportedOperationException();
	}

	public boolean tryLock(long time, TimeUnit unit) throws InterruptedException
	{
		throw new UnsupportedOperationException();
	}

	public Condition newCondition()
	{
		throw new UnsupportedOperationException();
	}
}
