// Name: Dylan Kanpnias
// Student Number: u18108467

import java.util.concurrent.atomic.AtomicBoolean;

public class TTAS
{
    private AtomicBoolean state = new AtomicBoolean(false);

    public void lock() {
        while (true) {
            while (state.get()) {}

            if (!state.getAndSet(true))
                return;
        }
    }

    public void unlock() {
        state.set(false);;
    }
}