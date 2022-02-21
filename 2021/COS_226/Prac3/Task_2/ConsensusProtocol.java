// Dylan Kapnias (u18108467)

public abstract class ConsensusProtocol<T> implements Consensus<T>
{
	public volatile Object[] proposed;
	public final int v = -1;
    public CASRegister reg = new CASRegister(v);

	public ConsensusProtocol(int threadCount)	{
		proposed = new Object[threadCount];
	}

	public void propose(T value) {
		//while (proposed[Integer.parseInt(Thread.currentThread().getName().split("-")[1])] != null) {}

		System.out.println(String.format("%s proposes to spend R%d.", Thread.currentThread().getName(), value));
		int id = Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
		proposed[id] = value;
	}

	public void reset() {
		for (int i = 0; i < proposed.length; i++) {
			proposed[i] = null;
		}
		reg.set(v);
		System.out.println("Resetting!\n");
	}

	abstract public void decide();
}