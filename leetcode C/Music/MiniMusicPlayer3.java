package Music;

import javax.sound.midi.MidiEvent;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.Sequence;
import javax.sound.midi.Sequencer;
import javax.sound.midi.ShortMessage;
import javax.sound.midi.Track;
import javax.swing.JFrame;

import GUI.MyDrawPanel;

public class MiniMusicPlayer3 {

	static JFrame frame = new JFrame("My first music video");
	static MyDrawPanel mlDrawPanel;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MiniMusicPlayer3 miniMusicPlayer3 = new MiniMusicPlayer3();
		miniMusicPlayer3.go();
	}

	public void setUpGui(){
		mlDrawPanel = new MyDrawPanel();
		frame.setContentPane(mlDrawPanel);
		frame.setBounds(30, 30, 300, 300);
		frame.setVisible(true);
	}
	
	public void go(){
		setUpGui();
		
		try {
			Sequencer sequencer = MidiSystem.getSequencer();
			sequencer.open();
			sequencer.addControllerEventListener(mlDrawPanel, new int[] {127});
			Sequence sequence = new Sequence(Sequence.PPQ, 4);
			Track track = sequence.createTrack();
			
			int r = 0;
			for (int i = 5; i < 120; i+=4) {
				r = (int)((Math.random() * 50) + 1);
				track.add(makeEvent(144, 1, i, 100, i));
				track.add(makeEvent(176, 1, 127, 0, i));
				track.add(makeEvent(128, 1, r, 100, i+2));
			}
			
			sequencer.setSequence(sequence);
			sequencer.setTempoInBPM(120);
			sequencer.start();
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}
	}
	
	public MidiEvent makeEvent(int comd,int chan,int one,int two,int tick){
		MidiEvent event = null;
		try {
			ShortMessage a = new ShortMessage();
			a.setMessage(comd, chan, one, two);
			event = new MidiEvent(a, tick);
		} catch (Exception e) {
			// TODO: handle exception
		}
		return event;
	}

}
