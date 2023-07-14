#include <iostream>
#include <vector>

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

// Abstract class for the aggregate object
class Playlist {
public:
    virtual void addSong(std::string title, std::string artist) = 0;
    virtual void removeSong(std::string title) = 0;
    virtual void createIterator() = 0;
};

// Concrete implementation of the aggregate object
class MusicPlaylist : public Playlist {
private:
    std::vector<std::string> songs;

public:
    void addSong(std::string title, std::string artist) override {
        songs.push_back(title + " by " + artist);
    }

    void removeSong(std::string title) override {
        for (auto it = songs.begin(); it != songs.end(); ++it) {
            if (*it == title) {
                songs.erase(it);
                break;
            }
        }
    }

    void createIterator() override;
};

// Song class
class Song {
public:
    std::string title;
    std::string artist;
};

// Abstract class for the iterator
class SongIterator {
public:
    virtual bool hasNext() = 0;
    virtual Song next() = 0;
};

// Concrete iterator implementation
class MusicPlaylistIterator : public SongIterator {
private:
    std::vector<Song> songs;
    int position;

public:
    MusicPlaylistIterator(std::vector<Song>& songs) {
        this->songs = songs;
        position = 0;
    }

    bool hasNext() override {
        return position < songs.size();
    }

    Song next() override {
        if (hasNext()) {
            Song song = songs[position];
            position++;
            return song;
        }
        throw std::out_of_range("No more songs in the playlist.");
    }
};

void MusicPlaylist::createIterator() {
    std::vector<Song> playlistSongs;
    for (const auto& song : songs) {
        Song playlistSong;
        playlistSong.title = song.substr(0, song.find(" by "));
        playlistSong.artist = song.substr(song.find(" by ") + 4);
        playlistSongs.push_back(playlistSong);
    }

    SongIterator* iterator = new MusicPlaylistIterator(playlistSongs);

    while (iterator->hasNext()) {
        Song song = iterator->next();
        std::cout << "Playing: " << song.title << " by " << song.artist << std::endl;
    }

    delete iterator;
}

// Usage example
int main() {
    // Create a music playlist
    Playlist* playlist = new MusicPlaylist();

    // Add songs to the playlist
    playlist->addSong("Wet Dreamz", "J. Cole");
    playlist->addSong("All in", "Nasty C");
    playlist->addSong("Blank Space", "Taylor Swift");

    // Iterate over the playlist using the iterator
    playlist->createIterator();

    delete playlist;

    return 0;
}
