// Dylan Kapnias (u18108467)

public class ConsensusThread extends Thread
{
	private Consensus<Integer> consensus;

	ConsensusThread(Consensus<Integer> consensusObject)
	{
		consensus = consensusObject;
	}

	public void run()
	{
		for (int i = 0; i < 5; i++) {
			consensus.propose((int)(Math.random() * (201 - 100) + 100));

			try {
				Thread.sleep((int)(Math.random() * (101 - 50) + 50));
			} catch (InterruptedException e) {}

			consensus.decide();
		}
	}
}