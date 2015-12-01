package Music;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import GUI.TwoButtons;

public class Jukebox {
	ArrayList<Song> songList = new ArrayList<Song>();
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Jukebox().go();
	}

	class ArtistCompare implements Comparator<Song>{
		@Override
		public int compare(Song o1, Song o2) {
			// TODO Auto-generated method stub
			return o1.getArtist().compareTo(o2.getArtist());
		}
		
	}
	
	void go(){
		ArtistCompare artistCompare = new ArtistCompare();
		getSongs();
		System.out.println(songList.toString());
		Collections.sort(songList,artistCompare);
		System.out.println(songList.toString());
	}
	
	void getSongs(){
		try {
			File file = new File("SongList.txt");
			BufferedReader reader = new BufferedReader(new FileReader(file));
			String line = null;
			while ((line = reader.readLine()) != null) {
				addSong(line);
			}
			reader.close();
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}
	}
	
	void addSong(String name){
		String[] tokens = name.split("/");
		Song nextSong = new Song(tokens[0],tokens[1],tokens[2],tokens[3]);
		songList.add(nextSong);
	}
}
