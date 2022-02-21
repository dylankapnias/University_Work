// Dylan Kapnias (u18108467)

public interface Consensus<T>
{
	void decide(int start, CarWash cw);
	void propose(T value, int start);
}