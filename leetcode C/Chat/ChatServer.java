package Chat;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class ChatServer {
	ArrayList clientOutputStreams;
	
	public class ClientHandler implements Runnable{

		BufferedReader reader;
		Socket sock;
		
		public ClientHandler(Socket clientSocket) {
			// TODO Auto-generated constructor stub
			try {
				sock = clientSocket;
				InputStreamReader inputStreamReader = new InputStreamReader(sock.getInputStream());
				reader = new BufferedReader(inputStreamReader);
			} catch (Exception e) {
				// TODO: handle exception
				e.printStackTrace();
			}
		}
		
		@Override
		public void run() {
			// TODO Auto-generated method stub
			String message;
			try {
				while ((message = reader.readLine()) != null) {
					System.out.println("read " + message);
					tellEveryone(message);
				}
			} catch (Exception e) {
				// TODO: handle exception
				e.printStackTrace();
			}
		}
	}
	
	public static void main(String[] args){
		new ChatServer().go();
	}
	
	public void go(){
		clientOutputStreams = new ArrayList();
		try {
			ServerSocket serverSocket = new ServerSocket(5000);
		} catch (Exception e) {
			// TODO: handle exception
		}
	}
	public void tellEveryone(String message){
		
	}
}
