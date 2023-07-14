import java.util.ArrayList;
import java.util.List;


// Author - Given Lepita
/*
 * Imagine you are developing a music player application.
 * Your application has a playlist feature that allows users to create and manage playlists.
 * Each playlist contains multiple songs.
 * To implement the playlist functionality efficiently, you decide to use the Iterator Design Pattern.
 * 
 * By using the Iterator pattern, you can iterate over the elements of a collection or data structure in a uniform way, regardless of its implementation details.
 * It promotes a separation of concerns, as the client code that uses the iterator doesn't need to know about the internal structure of the aggregate object.
 * This allows for easy swapping of different iterator implementations and enhances the flexibility and reusability of the code.
 */

// Interface for the aggregate object
interface Playlist {
    void addSong(Song song);
    void removeSong(Song song);
    SongIterator createIterator();
}

// Concrete implementation of the aggregate object
class MusicPlaylist implements Playlist {
    private List<Song> songs;

    public MusicPlaylist() {
        songs = new ArrayList<>();
    }

    @Override
    public void addSong(Song song) {
        songs.add(song);
    }

    @Override
    public void removeSong(Song song) {
        songs.remove(song);
    }

    @Override
    public SongIterator createIterator() {
        return new MusicPlaylistIterator(songs);
    }
}

// Object to be stored in the aggregate
class Song {
    private String title;
    private String artist;

    public Song(String title, String artist) {
        this.title = title;
        this.artist = artist;
    }

    public String getTitle() {
        return title;
    }

    public String getArtist() {
        return artist;
    }
}

// Interface for the iterator
interface SongIterator {
    boolean hasNext();
    Song next();
}

// Concrete iterator implementation
class MusicPlaylistIterator implements SongIterator {
    private List<Song> songs;
    private int position;

    public MusicPlaylistIterator(List<Song> songs) {
        this.songs = songs;
        position = 0;
    }

    @Override
    public boolean hasNext() {
        return position < songs.size();
    }

    @Override
    public Song next() {
        if (hasNext()) {
            Song song = songs.get(position);
            position++;
            return song;
        }
        return null;
    }
}

// Usage example
public class Main {
    public static void main(String[] args) {
        // Create a music playlist
        Playlist playlist = new MusicPlaylist();

        // Add songs to the playlist
        playlist.addSong(new Song("Wet Dreamz", "J. Cole"));
        playlist.addSong(new Song("All in", "Nasty C"));
        playlist.addSong(new Song("Taylor Swift", "Blank Space"));

        // Iterate over the playlist using the iterator
        SongIterator iterator = playlist.createIterator();
        while (iterator.hasNext()) {
            Song song = iterator.next();
            System.out.println("Playing: " + song.getTitle() + " by " + song.getArtist());
        }
    }
}
