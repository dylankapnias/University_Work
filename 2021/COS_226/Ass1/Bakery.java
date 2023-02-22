import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

// Name: Dylan Kapnias
// Student Number: u18108467

public class Bakery implements Lock
{
	private boolean[] flag;
	private int[] label;
	private int n;
	private int startPos;

	public Bakery(int n, int s) {
		this.n = n;
		this.startPos = s;

		flag = new boolean[n];
        label = new int[n];

        for (int i = 0; i < n; i++) {
            flag[i] = false;
            label[i] = 0;
        }
	}

	public void lock() {
		int i = Integer.parseInt(Thread.currentThread().getName().split("-")[1]) - startPos;

        flag[i] = true;
        label[i] = arrMax(label) + 1;
        for (int k = 0; k < n; k++) {
            while ((k != i) && flag[k] && ((label[k] < label[i]) || ((label[k] == label[i]) && k < i))) {
                System.out.print("");
            }
        }
	}

	public void unlock() {
		flag[Integer.parseInt(Thread.currentThread().getName().split("-")[1]) - startPos] = false;
	}

	private int arrMax(int[] arr) {
        int max = -1;

        for (int a: arr) {
            if (a > max) {
                max = a;
            }
        }
        return max;
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
