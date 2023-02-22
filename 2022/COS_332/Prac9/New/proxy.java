/* D.S Kapnias u18108467 */
/* L.M Burgess u18015001 */

import java.io.*;
import java.net.*;
import java.nio.charset.StandardCharsets;

public class proxy {
    public static void main(String[] args){
        try{
            ServerSocket socket = new ServerSocket(5000);
            print("Socket build");
            print("Open for connections");
            while (true) {
                Socket connect = socket.accept();
                new client_connection(connect).start();
            }

        } catch(Exception e) {
            System.out.print(e);
        }
    }

    private static void print(String line) {
        System.out.println(line);
    }

    static class client_connection extends Thread {
        public String telnetServerIP = "10.0.2.15";
        private Socket socket;
        BufferedReader input;
        PrintStream output;
        static int num=0;
        PrintStream telnetOut;
        BufferedReader telnetIn;
        DataInputStream din;
        DataOutputStream dout;

        client_connection(Socket socket) {
            this.socket = socket;
        }

        public void run() {
            try {

                input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                output = new PrintStream(socket.getOutputStream());

                output.print(">Connected to server\r\n");
                output.print(">Connection number "+(num++)+"\r\n");

                output.print("Port No:");
                int port = Integer.valueOf(input.readLine());
                print(Integer.toString(port));
                output.print("Connecting to server...");

                try {
                    Socket telnetServer = new Socket("localhost", port);
                    telnetOut = new PrintStream(telnetServer.getOutputStream(), true);
                    telnetIn = new BufferedReader(new InputStreamReader(telnetServer.getInputStream()));
                    din=new DataInputStream(telnetServer.getInputStream());
                    dout=new DataOutputStream(telnetServer.getOutputStream());
                } catch(Error e) {
                    e.printStackTrace();
                    output.print("Server unreachable");
                    System.out.print("Closing");
                    input.close();
                    output.close();
                    socket.close();
                    return;
                }

                output.print("Server found\r\n");
                print("Here 1");
                dout.writeUTF("onyx");
                print("Here 2");
                System.out.println(din.readUTF());
                print("Here 3");
                telnetOut.println("test");
                System.out.println(telnetIn.readLine());

               /* String received = "";
                String user = "Client "+num + ">";
                while((received = input.readLine())!= null && !received.equals(":quit")) {
                    output.print(user+received);
                }*/
                System.out.print("Closing");
                input.close();
                output.close();
                socket.close();

            } catch (IOException e) {
                e.printStackTrace();
            } finally {
            }
        }
    }
}
