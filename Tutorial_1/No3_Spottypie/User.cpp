#include <iostream>
#include <cstring>
#include "User.h"
using namespace std;

int User :: n_user = 0;

User :: User (char* nama){
    name = new char[strlen(nama)];
    strcpy(this->name, nama);
    num_of_favourite_music = 0;
    music_list = new char*[num_of_favourite_music];
    n_user++;
}

User :: User (const User &otheruser){
    this->name = new char[strlen(otheruser.getName())];
    strcpy(this->name, otheruser.getName());
    num_of_favourite_music = otheruser.getNumOfFavouriteMusic();
    this->music_list = new char*[num_of_favourite_music];
    for(int i = 0 ; i < otheruser.getNumOfFavouriteMusic() ; i++){
        this->music_list[i] = new char[strlen(otheruser.music_list[i])];
        strcpy(this->music_list[i], otheruser.music_list[i]);
    }
    n_user++;
}

User :: ~User(){
    cout << "User " << this->name << " deleted" << endl;
    delete[] this->name;
    for(int i = 0 ; i < this->getNumOfFavouriteMusic() ; i++){
        delete[] this->music_list[i];
    }
    delete[] this->music_list;
}

void User :: addFavouriteMusic(char* music){
    char** temp = new char*[getNumOfFavouriteMusic()+1];
    int k;
    for(k ; k < num_of_favourite_music ; k++){
        temp[k] = new char[strlen(music_list[k])];
        strcpy(temp[k], music_list[k]);
        delete[] music_list[k];
    }
    temp[k] = new char[strlen(music)];
    strcpy(temp[k], music);

    delete[] music_list;

    num_of_favourite_music++;
    music_list = new char*[num_of_favourite_music];

    for(int i ; i < num_of_favourite_music ; i++){
        music_list[i] = new char[strlen(temp[i])];
        strcpy(music_list[i], temp[i]);
        delete[] temp[i];
    }

    delete[] temp;
}

void User :: deleteFavouriteMusic(char* music){
    if (num_of_favourite_music > 0){
        if (num_of_favourite_music == 1){
            if(strcmp(music_list[0],music) == 0){
                num_of_favourite_music--;
            }
        } else {
            for(int i = 0 ; i < num_of_favourite_music ; i++){
                if(strcmp(music_list[i], music) == 0){
                    num_of_favourite_music--;
                    int p = i;
                    while(p < num_of_favourite_music){
                        strcpy(music_list[p], music_list[p+1]);
                        p++;
                    }
                    break;
                }
            }
        }
    }
}

void User :: setName(char* nama){
    strcpy(this->name, nama);
}

char* User :: getName() const{
    return name;
}

int User :: getNumOfFavouriteMusic() const {
    return num_of_favourite_music;
}

void User :: viewMusicList() const {
    if (num_of_favourite_music == 0 ){
        cout << "No music in your favourite list\n";
    } else {
        for(int i = 0 ; i < num_of_favourite_music ; i++){
            cout << i+1 << ". " << music_list[i] << endl;
        }
    }
}

int User :: getNumOfUser() {
    return n_user;
}