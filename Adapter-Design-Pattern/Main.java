// Author - Given Lepita

/*
 * Imagine you are developing a music player application that can play various types of media files, such as MP3, WAV, and OGG.
 * Each media type has its own implementation for playing the file.
 * However, you want to add a new feature that allows the music player to play online radio streams as well.
 * Since online radio streams have a different interface compared to media files, you decide to use the -
 * Adapter Design Pattern to seamlessly integrate the new functionality into the existing music player.
*/

// Interface for media players
interface MediaPlayer {
    void play(String fileName);
}

// MP3 player implementation
class Mp3Player implements MediaPlayer {
    @Override
    public void play(String fileName) {
        System.out.println("Playing MP3 file: " + fileName);
    }
}

// WAV player implementation
class WavPlayer implements MediaPlayer {
    @Override
    public void play(String fileName) {
        System.out.println("Playing WAV file: " + fileName);
    }
}

// OGG player implementation
class OggPlayer implements MediaPlayer {
    @Override
    public void play(String fileName) {
        System.out.println("Playing OGG file: " + fileName);
    }
}

// Interface for online radio streams
interface OnlineRadio {
    void playRadio(String radioStation);
}

// Online radio stream implementation
class OnlineRadioStream implements OnlineRadio {
    @Override
    public void playRadio(String radioStation) {
        System.out.println("Playing online radio stream: " + radioStation);
    }
}

// Adapter to convert OnlineRadio to MediaPlayer
class OnlineRadioAdapter implements MediaPlayer {
    private final OnlineRadio onlineRadio;

    public OnlineRadioAdapter(OnlineRadio onlineRadio) {
        this.onlineRadio = onlineRadio;
    }

    @Override
    public void play(String radioStation) {
        onlineRadio.playRadio(radioStation);
    }
}

public class Main {
    public static void main(String[] args) {
        MediaPlayer mp3Player = new Mp3Player();
        MediaPlayer wavPlayer = new WavPlayer();
        MediaPlayer oggPlayer = new OggPlayer();

        mp3Player.play("song.mp3");
        wavPlayer.play("sound.wav");
        oggPlayer.play("music.ogg");

        // Adding support for online radio stream using the adapter
        OnlineRadio onlineRadio = new OnlineRadioStream();
        MediaPlayer radioAdapter = new OnlineRadioAdapter(onlineRadio);

        radioAdapter.play("www.givenlepita.com");
    }
}
