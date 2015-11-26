package Music;

import javax.sound.midi.MidiEvent;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.Sequence;
import javax.sound.midi.Sequencer;
import javax.sound.midi.ShortMessage;
import javax.sound.midi.Track;

public class MiniMusicPlayer1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MiniMusicPlayer1 miniMusicPlayer1 = new MiniMusicPlayer1();
		try {
			Sequencer sequencer = MidiSystem.getSequencer();
			sequencer.open();
			
			Sequence sequence = new Sequence(Sequence.PPQ, 4);
			Track track = sequence.createTrack();
			
			for (int i = 1; i < 101; i+=4) {
				track.add(miniMusicPlayer1.makeEvent(144, 1, i, 100, i));
				track.add(miniMusicPlayer1.makeEvent(128, 1, i, 100, i+2));
			}
			
			sequencer.setSequence(sequence);
			sequencer.setTempoInBPM(220);
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
