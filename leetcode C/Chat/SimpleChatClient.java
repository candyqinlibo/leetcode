package Chat;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.PrintWriter;
import java.net.Socket;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class SimpleChatClient {
	JTextField outgoing;
	PrintWriter writer;
	Socket socket;
	
	public void go(){
		JFrame frame = new JFrame("Ludicrously Simple Chat Client");
		JPanel mainPanel = new JPanel();
		outgoing = new JTextField(20);
		JButton sendButton = new JButton("send");
		sendButton.addActionListener(new SendButtonListener());
		mainPanel.add(outgoing);
		mainPanel.add(sendButton);
		frame.getContentPane().add(BorderLayout.CENTER, mainPanel);
		setUpNetWorking();
		frame.setSize(400, 500);
		frame.setVisible(true);
	}
	
	private void setUpNetWorking(){
		try {
			socket = new Socket("127.0.0.1", 5000);
			writer = new PrintWriter(socket.getOutputStream());
			System.out.println("networking established");
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}
	}
	
	public class SendButtonListener implements ActionListener{

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			try {
				writer.println(outgoing.getText());
				writer.flush();
			} catch (Exception e2) {
				// TODO: handle exception
				e2.printStackTrace();
			}
			outgoing.setText("");
			outgoing.requestFocus();
		}
		
	}
	
	public static void main(String[] args){
		new SimpleChatClient().go();
	}
}
