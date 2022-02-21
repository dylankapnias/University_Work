// Dylan Kapnias (u18108467)

import java.util.concurrent.atomic.AtomicInteger;

public abstract class ConsensusProtocol<T> implements Consensus<T>
{
	public volatile Object[] proposed;
	public final int v = -1;
    public AtomicInteger reg = new AtomicInteger(v);

	public ConsensusProtocol(int threadCount)	{
		proposed = new Object[threadCount];
	}

	public void propose(T value, int start) {
		int id = Integer.parseInt(Thread.currentThread().getName().split("-")[1]) - start;
		proposed[id] = value;
	}

	public void reset() {
		for (Object o : proposed)
			o = null;

		reg = new AtomicInteger(v);
	}

	abstract public void decide(int start, CarWash cw);
}