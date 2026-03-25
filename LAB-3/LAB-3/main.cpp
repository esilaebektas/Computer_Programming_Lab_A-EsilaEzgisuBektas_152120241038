#include <iostream>
#include <string>

using namespace std;

struct Song {
    string title;
    string artist;
    int ratings[3];
    Song* next;
    Song* prev;
};

Song* head = NULL;
Song* tail = NULL;
Song* current = NULL;

void addSong(string title, string artist, int r1, int r2, int r3) {
    Song* newSong = new Song;

    newSong->title = title;
    newSong->artist = artist;
    newSong->ratings[0] = r1;
    newSong->ratings[1] = r2;
    newSong->ratings[2] = r3;

    newSong->next = NULL;
    newSong->prev = NULL;

    if (head == NULL) {
        head = tail = current = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
}

void nextSong() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
    } else {
        cout << "there's no next song." << endl;
    }
}

void prevSong() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
    } else {
        cout << "there's no previous song." << endl;
    }
}

void removeCurrent(){
    if(current == NULL){
        return;
    }

    Song* temp = current;

    if(head == tail){
        head = tail = current = NULL;
    }
    else if(current == head){
        head = head->next;
        head->prev = NULL;
        current = head;
    }
    else if(current == tail){
        tail = tail->prev;
        tail->prev = NULL;
        current = tail;
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        current=current->next;
    }

    delete temp;
}

void display(){
    Song* temp = head;

    while (temp != NULL){
        if (temp == current){
            cout << "> ";
        }
        cout << temp->title << " | " << temp->artist << " | ratings: ";

        for(int i=0;i<3;i++){
            cout << temp->ratings[i] << " ";
        }

        cout << endl;

        temp = temp->next;
    }
}

int main(){
    addSong("song1", "artist1", 5, 7, 3);
    addSong("song2", "artist2", 9, 9, 9);

    display();

    cout << "\nNext:" << endl;
    nextSong();
    display();

    cout << "\nPrevious:" << endl;
    prevSong();
    display();

    cout << "\nRemove current:" << endl;
    removeCurrent();
    display();

    return 0;
}
