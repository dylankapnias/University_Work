// Dylan Kapnias (u18108467)

import java.util.LinkedList;
import java.util.Queue;

public class CarWash
{
	int washCount, dryCount;
	boolean washFin, dryFin = false;

	private volatile Queue<Car> washCars = new LinkedList<>(), dryCars = new LinkedList<>();

	public CarWash(int wC, int dC){
		washCars.add(new Car('s', "Panda"));
		washCars.add(new Car('m', "Cerato"));
		washCars.add(new Car('s', "Swift"));
		washCars.add(new Car('l', "Defender"));
		washCars.add(new Car('m', "A3"));
		washCars.add(new Car('l', "Ranger"));
		washCars.add(new Car('s', "GTI"));

		washCount = wC;
		dryCount = dC;
	}

	public void wash() {
		System.out.println(String.format("%s is ready to wash a car", Thread.currentThread().getName()));

		Car c = washCars.peek();

		if (c == null) {
			washFin = true;
			return;
		}

		try {
			int wT = (int)(Math.random() * (501 - 100) + 100);
			c.washTime -= wT;
			Thread.sleep(wT);

			if (c.washTime <= 0) {
				System.out.println(String.format("%s finished washing %s.", Thread.currentThread().getName(), c.name));
				dryCars.add(washCars.remove());
			} else {
				System.out.println(String.format("%s washed %s for %dms. Time remaining: %d", Thread.currentThread().getName(), c.name, wT, c.washTime));
			}

			int bT = (int)(Math.random() * (101 - 50) + 50);
			System.out.println(String.format("%s is taking a break", Thread.currentThread().getName()));
			Thread.sleep(bT);
		} catch (InterruptedException e) {}
	}

	public void dry() {
		Car c = dryCars.peek();

		if (c == null && washCars.peek() == null) {
			dryFin = true;
			return;
		}

		if (c == null && washCars.peek() != null)
			return;

		System.out.println(String.format("%s is ready to dry a car", Thread.currentThread().getName()));

		try {
			int dT = (int)(Math.random() * (501 - 100) + 100);
			c.dryTime -= dT;
			Thread.sleep(dT);

			if (c.dryTime <= 0) {
				dryCars.remove();
				System.out.println(String.format("%s finished drying %s.", Thread.currentThread().getName(), c.name));
			} else {
				System.out.println(String.format("%s dried %s for %dms. Time remaining: %d", Thread.currentThread().getName(), c.name, dT, c.dryTime));
			}

			int bT = (int)(Math.random() * (101 - 50) + 50);
			System.out.println(String.format("%s is taking a break", Thread.currentThread().getName()));
			Thread.sleep(bT);
		} catch (InterruptedException e) {}
	}
}
