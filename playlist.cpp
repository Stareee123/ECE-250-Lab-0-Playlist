#include "playlist.h"
#include <iostream>
#include <string>

// Constructer of a class
playlist::playlist(){
    size = 0;
    num_of_song = 0; 
    /*arr = new std::string[size] {" "};*/

};

// Destructor of a class
playlist::~playlist(){
    delete[] arr;
};


void playlist::m (unsigned int n){
    size = n;
    arr = new std::string[size] {" "};  //creating dynamically allocated array with 'size' entries.
    std::cout << "success"<< std::endl;
    for (unsigned int i = 0; i < size; ++i){  // filling up every entries with blank string value. 
        arr[i] = " ";
    }
    
}

void playlist::i (std::string t, std::string a){
    unsigned int i = 0;

    unsigned int full = 0;
    full = (size - 1);

    // chekcing rather the very last entry is already filled. 
    if(arr[full] != " "){
        std::string total = t + ";" + a;
        std::cout << "can not insert " << total<< std::endl;
        return;
    };
    
    while (i < size){
        if (t == "My Heart Will Go On"){  // check rather the inputted song name is "My Heart Will Go On"
            std::string total = t + ";" + a;
            std::cout << "can not insert " << total<< std::endl;
            break;
        };
        
        // combine input t and a for easier comparision
        std::string total_2 =  t + ";" + a;

        if (total_2 == "Baby;Justin Bieber"){   // check rather Baby by Justin Bieber is being inserted. 
            std::cout << "can not insert " << total_2<< std::endl;
            break;
        };
        if(total_2 == arr[i]){  // check rather there is same song;artist already inserted
            std::cout << "can not insert " << total_2<< std::endl;
            
        };
        if(arr[i] == " "){  // add song;artist to ith entry
            arr[i] = total_2;
            std::cout << "success"<< std::endl;
            break;
        };
        ++i;
    }
    
};

void playlist::p (unsigned int n){
    
    if (n > size){  // check rather the user input is greater than the size of the playlist. 
        std::cout << "can not play " << n << std::endl;
        return;
    };

    if (arr[n-1] == " "){   // check rather the entry user is trying to play is empty or not
        std::cout << "can not play " << n << std::endl;
    }else{
        std::string song_to_play = arr[n-1];
        std::cout << "played " << n << " " << arr[n-1] << std::endl;
    }
    
};

void playlist::e (unsigned int n){
    
    if (n > size){  // check rather the user input is greater than the size of the playlist.
        std::cout << "can not erase" << n << std::endl;
        return;
    };

    if (arr[n-1] == " "){  // check rather the entry user is trying to erase is empty or not.
        std::cout << "can not erase " << n << std::endl;

    }else{  // erasing entries.
        for (unsigned int e = (n - 1); e < size; ++e){
            if (e == size - 1){
                arr[e] = " ";
            }else{
                arr[e] = arr[e+1];
            };
        };
        std::cout << "success" << std::endl;

    };
    
};