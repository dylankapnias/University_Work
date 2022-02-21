import java.util.Random;
import java.util.concurrent.locks.Lock;
import java.lang.Math;

// Name: Dylan Kanpnias
// Student Number: u18108467

public class Store
{
	volatile Semaphore l;

	public Store(int n) {
		l = new Semaphore(3);
	}

	public void enterStore(int j){
		System.out.println(String.format("%s Person %d is trying to get inside.", Thread.currentThread().getName(), j));
		l.lock();

		try {
			System.out.println(String.format("%s Person %d has entered the store. Spaces remaining: %d", Thread.currentThread().getName(), j, l.capacity - l.state));
			Thread.sleep((int)(Math.random() * (1001 - 200) + 200));
		} catch (InterruptedException e) {} finally {		
			System.out.println(String.format("%s Person %d has left the store.", Thread.currentThread().getName(), j));	
			l.unlock();
		}
	}
}
