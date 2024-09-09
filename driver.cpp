// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "playlist.h"


int main(int argc, char *argv[]){

//variables used to call a member function
bool program_run = true;

std::string command = " ";
unsigned int size_input = 0;

std::string total_input = " ";
std::string music = " ";
std::string artist = " ";

unsigned int play_input = 0;

unsigned int erase_input = 0;

//creating object
playlist playobject;


while (program_run ==true) {
    std::cin >> command;
    if (command == "m"){
        std::cin >> size_input;
        playobject.m (size_input);  // calling function m
    }else if (command == "i"){
        std::getline(std::cin >> std::ws, total_input);     // commanding to ignore the blank space in the input. 
        size_t loc = total_input. find(";");    // setting up location on a position of ";".
        music = total_input. substr(0, loc);    // setting music to first part before ";".
        artist = total_input. substr(loc+1);    // setting artist to second part after ";".
        playobject.i (music, artist);   // calling function i
    }else if (command == "p"){
        std::cin >> play_input;
        playobject.p(play_input);   // calling function p
    }else if (command == "e"){
        std::cin >> erase_input;
        playobject.e(erase_input);  // calling function e
    }else if (command == "done"){
        std::cout << "done" << std::endl;   // returning done
        program_run = false;
    };
};



};