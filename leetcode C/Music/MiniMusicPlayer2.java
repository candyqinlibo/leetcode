package Music;

import javax.sound.midi.ControllerEventListener;
import javax.sound.midi.MidiEvent;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.Sequence;
import javax.sound.midi.Sequencer;
import javax.sound.midi.ShortMessage;
import javax.sound.midi.Track;

public class MiniMusicPlayer2 implements ControllerEventListener{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MiniMusicPlayer2 miniMusicPlayer2 = new MiniMusicPlayer2();
		miniMusicPlayer2.go();
	}

	public void go(){
		try {
			Sequencer sequencer = MidiSystem.getSequencer();
			sequencer.open();
			
			int[] events = {127};
			sequencer.addControllerEventListener(this, events);
			
			Sequence sequence = new Sequence(Sequence.PPQ, 4);
			Track track = sequence.createTrack();
			
			for (int i = 5; i < 60; i+=4) {
				track.add(makeEvent(144, 1, i, 100, i));
				track.add(makeEvent(176, 1, i, 0, i));
				track.add(makeEvent(128, 1, i, 100, i+2));
			}
			
			sequencer.setSequence(sequence);
			sequencer.setTempoInBPM(220);
			sequencer.start();
			
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}
	}
	
	@Override
	public void controlChange(ShortMessage event) {
		// TODO Auto-generated method stub
		System.out.println("la");
	}
	
	public static MidiEvent makeEvent(int comd,int chan,int one,int two,int tick){
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
