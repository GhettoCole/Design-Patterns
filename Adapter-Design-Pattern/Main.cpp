#include <iostream>
#include <string>

// Author - Given Lepita

/*
 * Imagine you are developing a music player application that can play various types of media files, such as MP3, WAV, and OGG.
 * Each media type has its own implementation for playing the file.
 * However, you want to add a new feature that allows the music player to play online radio streams as well.
 * Since online radio streams have a different interface compared to media files, you decide to use the -
 * Adapter Design Pattern to seamlessly integrate the new functionality into the existing music player.
*/

// Interface for media players
class MediaPlayer {
public:
    virtual void play(const std::string& fileName) = 0;
};

// MP3 player implementation
class Mp3Player : public MediaPlayer {
public:
    void play(const std::string& fileName) override {
        std::cout << "Playing MP3 file: " << fileName << std::endl;
    }
};

// WAV player implementation
class WavPlayer : public MediaPlayer {
public:
    void play(const std::string& fileName) override {
        std::cout << "Playing WAV file: " << fileName << std::endl;
    }
};

// OGG player implementation
class OggPlayer : public MediaPlayer {
public:
    void play(const std::string& fileName) override {
        std::cout << "Playing OGG file: " << fileName << std::endl;
    }
};

// Interface for online radio streams
class OnlineRadio {
public:
    virtual void playRadio(const std::string& radioStation) = 0;
};

// Online radio stream implementation
class OnlineRadioStream : public OnlineRadio {
public:
    void playRadio(const std::string& radioStation) override {
        std::cout << "Playing online radio stream: " << radioStation << std::endl;
    }
};

// Adapter to convert OnlineRadio to MediaPlayer
class OnlineRadioAdapter : public MediaPlayer {
private:
    OnlineRadio* onlineRadio;

public:
    OnlineRadioAdapter(OnlineRadio* radio) : onlineRadio(radio) {}

    void play(const std::string& radioStation) override {
        onlineRadio->playRadio(radioStation);
    }
};

int main() {
    MediaPlayer* mp3Player = new Mp3Player();
    MediaPlayer* wavPlayer = new WavPlayer();
    MediaPlayer* oggPlayer = new OggPlayer();

    mp3Player->play("song.mp3");
    wavPlayer->play("sound.wav");
    oggPlayer->play("music.ogg");

    // Adding support for online radio stream using the adapter
    OnlineRadio* onlineRadio = new OnlineRadioStream();
    MediaPlayer* radioAdapter = new OnlineRadioAdapter(onlineRadio);

    radioAdapter->play("www.givenlepita.com");

    delete mp3Player;
    delete wavPlayer;
    delete oggPlayer;
    delete onlineRadio;
    delete radioAdapter;

    return 0;
}
