// Dylan Kapnias (u18108467)

public class Main {
    public static void main(String[] args) {
        final int WASHER_COUNT = 2;
        final int DRIER_COUNT = 2;
        final int EMPLOYEE_COUNT = WASHER_COUNT + DRIER_COUNT;


        CarWash cw = new CarWash(WASHER_COUNT, DRIER_COUNT);
        Employees[] emp = new Employees[EMPLOYEE_COUNT];
        CASConsensus washConsensus = new CASConsensus(WASHER_COUNT);
        CASConsensus dryConsensus = new CASConsensus(DRIER_COUNT);

        for (int i = 0; i < WASHER_COUNT; i++) {
			emp[i] = new Washer(washConsensus, cw);
		}

		for (int i = WASHER_COUNT; i < EMPLOYEE_COUNT; i++) {
			emp[i] = new Drier(dryConsensus, cw);
		}

        for (Employees e : emp) {
			e.start();
        }
    }
}

