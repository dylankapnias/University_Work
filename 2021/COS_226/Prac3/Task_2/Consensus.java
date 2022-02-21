// Dylan Kapnias (u18108467)

public interface Consensus<T>
{
	void decide();
	void propose(T value);
}