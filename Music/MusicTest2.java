package Music;

import javax.sound.midi.MidiEvent;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.Sequence;
import javax.sound.midi.Sequencer;
import javax.sound.midi.ShortMessage;
import javax.sound.midi.Track;

public class MusicTest2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MusicTest2 musicTest2 = new MusicTest2();
//		if (args.length < 2) {
//			System.out.println("Do not forget the instrument and note args");
//		}else{
			int instrument = 40;
			int note  = 70;
			musicTest2.play(instrument, note);
//		}
	}

	public void play(int instrument,int note){
		try {
			Sequencer player = MidiSystem.getSequencer();
			player.open();
			Sequence sequence = new Sequence(Sequence.PPQ, 4);
			Track track = sequence.createTrack();
			
//			MidiEvent event = null;
			
			ShortMessage first = new ShortMessage();
			first.setMessage(192,1,instrument,0);
			MidiEvent changeInstrument = new MidiEvent(first, 1);
			track.add(changeInstrument);
			
			ShortMessage a = new ShortMessage();
			a.setMessage(144,1,note,100);
			MidiEvent noteOn = new MidiEvent(a, 1);
			track.add(noteOn);
			
			ShortMessage b = new ShortMessage();
			b.setMessage(128,1,note,0);
			MidiEvent noteOff = new MidiEvent(b, 16);
			track.add(noteOff);
			
			player.setSequence(sequence);
			player.start();
		} catch (Exception e) {
			// TODO: handle exception
		}
	}
}
