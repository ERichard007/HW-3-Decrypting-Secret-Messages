// Programmer: Evan Richard
// Date: 2/22/2024
// File: HW#3.cpp
// Assignment: HW#3
// Purpose: Decipher my Ceasar Cipher letter from the Oscar Academy of Magic. 


#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*CONSTANTS*/
const string LETTER = "Eqpitcvwncvkqpu! Vjg Quect Cecfgoa qh Ocike ku vjtknngf vq kphqto aqw vjcv aqw jcxg dggp cfokvvgf vq qwt rtguvkikqwu kpuvkvwvkqp. Aqwt jctf yqtm, vcngpv, cpf rcuukqp hqt ocike jcxg gctpgf aqw c rnceg coqpi vjg pgzv igpgtcvkqp qh vjg yqtnf'u itgcvguv ykbctfu. Kp cffkvkqp vq vjg 8 ycpfu tgswktgf hqt vjg qrgpkpi yggm, yg yqwnf nkmg vq tgokpf aqw vq cnuq dtkpi c ecogn ykvj aqw cu c ocikecn etgcvwtg rgv. Vjku ku c pgy tgswktgogpv hqt cnn uvwfgpvu, cu ecognu ctg mpqyp hqt vjgkt cdknkva vq vtcxgtug gxgp vjg jctujguv qh vgttckpu, ocmkpi vjgo rgthgev eqorcpkqpu hqt cpa aqwpi ykbctf qp vjg iq. Rngcug pqvg vjcv vjg vwkvkqp hgg ku pqy hkzgf cv $50,000 rgt ugoguvgt hqt cnn uvwfgpvu fwg vq kphncvkqp. Vjku kpxguvogpv kp aqwt gfwecvkqp cpf vtckpkpi yknn ugv aqw wr hqt c nkhgvkog qh ocikecn uweeguu. Yg nqqm hqtyctf vq ygneqokpi aqw vq vjg cecfgoa cpf jgnrkpi aqw wpnqem aqwt hwnn rqvgpvkcn. Ygnn fqpg!";
const int LETTER_SHIFT = 2;


int main() {
    /*VARIABLES*/
    string decodedLetter; 
    string playerMessage;
    int encodeOrDecrypt;
    int playerShift;
    char playAgain = 'y';
    bool isVowel = false;

    /*MAGIC LETTER DECRYPTION*/
    cout << "Welcome to the Oscar Academy of Magic Caesar Cipher Program!" << endl;
    cout << "\nUnraveling the secret acceptance decision letter from the Oscar Academy of Magic… " << endl;
    cout << "\nUsing a shift value of 2..." << endl;
    cout << "\n..." << endl;
    cout << "\nDrumroll please..." << endl;
    cout << "\n(Writing my own C++ program to figure it out!)" << endl;
    cout << "\nThe acceptance letter says:\n" << endl;

    for (int i = 0;i < LETTER.length();i++) { 
        char oldChar = LETTER[i];  
        char x = oldChar; 


        if (oldChar >= 97 && oldChar <= 122) {
            for (int j = 0;j < LETTER_SHIFT;j++) { 
                x -= 1;
                if (x < 97) {
                    x = 122;
                }
            }
            decodedLetter += x;
        }


        else if (oldChar >= 65 && oldChar <= 90) {
            for (int j = 0;j < LETTER_SHIFT;j++) { 
                x -= 1;
                if (x < 65) {
                    x = 90;
                }
            }
            decodedLetter += x;
        }


        else {
            decodedLetter += x;
        }


    }
    cout << decodedLetter << endl; 

    cout << "\n YAY, now lets start the game!\n" << endl;

    /*GAME BEGINS*/
    while (playAgain == 'y') {

        /*SETUP FOR ENCRYPTION/DECRYPTION*/
        string newMessage = "";

        
        cout << "\nEnter a message to be decoded or encrypted: ";
        getline(cin, playerMessage); 


        cout << "Would you like to encrypt or decrypt this message? (1 - Encrypt / 2 - Decrypt): ";
        cin >> encodeOrDecrypt; 


        while (encodeOrDecrypt < 1 || encodeOrDecrypt > 2) {
            cout << encodeOrDecrypt << " IS NOT VALID, TRY AGAIN (1 - Encrypt / 2 - Decrypt): ";
            cin >> encodeOrDecrypt;
        }


        cout << "What is the shift value for your message? (enter a number between 1 and 40, can be negative): ";
        cin >> playerShift;


        while (playerShift < -40 || playerShift > 40 || playerShift == 0) {
            cout << playerShift << " IS NOT A VALID SHIFT VALUE, TRY AGAIN (Must be a number between 1 and 40, can be negative): ";
            cin >> playerShift;
        }

        /*ENCRYPTION CODE*/
        if (encodeOrDecrypt == 1) {
            
            //iterates through players message
            for (int i = 0;i < playerMessage.length();i++) { 

                
                char oldChar = playerMessage[i];
                char x = oldChar;

                //if character is between e/n and E/N exclusive
                if ((oldChar > 101 && oldChar < 110) || (oldChar > 69 && oldChar < 78)) {

                    //if its even
                    if (oldChar % 2 == 0) {

                        if (playerShift > 0) {
                            if (oldChar >= 97 && oldChar <= 122) {
                                for (int j = 0;j < playerShift;j++) {
                                    x += 1;
                                    if (x > 122) {
                                        x = 97;
                                    }
                                }
                                newMessage += x; 
                            }


                            else if (oldChar >= 65 && oldChar <= 90) {
                                for (int j = 0;j < playerShift;j++) {
                                    x += 1;
                                    if (x > 90) {
                                        x = 65;
                                    }
                                }
                                newMessage += x;
                            }
                        }

                        else {
                            if (oldChar >= 97 && oldChar <= 122) {
                                for (int j = 0;j < abs(playerShift);j++) { 
                                    x -= 1;
                                    if (x < 97) {
                                        x = 122;
                                    }
                                }
                                newMessage += x; 
                            }


                            else if (oldChar >= 65 && oldChar <= 90) { 
                                for (int j = 0;j < abs(playerShift);j++) {
                                    x -= 1;
                                    if (x < 65) {
                                        x = 90;
                                    }
                                }
                                newMessage += x;
                            }
                        }

                        
                    }
                    
                    // if its odd
                    else {
                        newMessage += x; 
                    }
                }
                
                //test if character is a Vowel
                else if (tolower(oldChar) == 'a' || tolower(oldChar) == 'e' || tolower(oldChar) == 'i' || tolower(oldChar) == 'o' || tolower(oldChar) == 'u'){
                    if (playerShift > 0) {
                        if (oldChar >= 97 && oldChar <= 122) {
                            for (int j = 0;j < playerShift+27;j++) {
                                x += 1;
                                if (x > 122) {
                                    x = 97;
                                }
                            }
                            newMessage += x;
                        }


                        else if (oldChar >= 65 && oldChar <= 90) {
                            for (int j = 0;j < playerShift+27;j++) {
                                x += 1;
                                if (x > 90) {
                                    x = 65;
                                }
                            }
                            newMessage += x;
                        }
                    }

                    else {
                        if (oldChar >= 97 && oldChar <= 122) {
                            for (int j = 0;j < abs(playerShift)+27;j++) {
                                x -= 1;
                                if (x < 97) {
                                    x = 122;
                                }
                            }
                            newMessage += x;
                        }


                        else if (oldChar >= 65 && oldChar <= 90) {
                            for (int j = 0;j < abs(playerShift)+27;j++) {
                                x -= 1;
                                if (x < 65) {
                                    x = 90;
                                }
                            }
                            newMessage += x;
                        }
                    }
                }

                //If characters is not between above nor a variable
                else {
                    if (playerShift > 0) {
                        if (oldChar >= 97 && oldChar <= 122) {
                            for (int j = 0;j < playerShift;j++) {
                                x += 1;
                                if (x > 122) {
                                    x = 97;
                                }
                            }
                            newMessage += x;
                        }


                        else if (oldChar >= 65 && oldChar <= 90) {
                            for (int j = 0;j < playerShift;j++) {
                                x += 1;
                                if (x > 90) {
                                    x = 65;
                                }
                            }
                            newMessage += x;
                        }

                        else {
                            newMessage += x; 
                        }
                    }

                    else {
                        if (oldChar >= 97 && oldChar <= 122) {
                            for (int j = 0;j < abs(playerShift);j++) {
                                x -= 1;
                                if (x < 97) {
                                    x = 122;
                                }
                            }
                            newMessage += x;
                        }


                        else if (oldChar >= 65 && oldChar <= 90) {
                            for (int j = 0;j < abs(playerShift);j++) {
                                x -= 1;
                                if (x < 65) {
                                    x = 90;
                                }
                            }
                            newMessage += x;
                        }

                        else {
                            newMessage += x; 
                        }
                    }
                }
            }
        }
        
        /*DECRYPTION CODE*/
        else { 

            //Iterates through message
            for (int i = 0;i < playerMessage.length();i++) { 
                char oldChar = playerMessage[i];
                char x = oldChar; 


                if (playerShift > 0) {
                    if (oldChar >= 97 && oldChar <= 122) {
                        for (int j = 0;j < playerShift;j++) {
                            x -= 1;
                            if (x < 97) {
                                x = 122;
                            }
                        }
                        newMessage += x;
                    }


                    else if (oldChar >= 65 && oldChar <= 90) {
                        for (int j = 0;j < playerShift;j++) {
                            x -= 1;
                            if (x < 65) {
                                x = 90;
                            }
                        }
                        newMessage += x;
                    }

                    else {
                        newMessage += x;
                    }
                }

                else {
                    if (oldChar >= 97 && oldChar <= 122) {
                        for (int j = 0;j < abs(playerShift);j++) {
                            x += 1;
                            if (x > 122) {
                                x = 97;
                            }
                        }
                        newMessage += x;
                    }


                    else if (oldChar >= 65 && oldChar <= 90) {
                        for (int j = 0;j < abs(playerShift);j++) {
                            x += 1;
                            if (x > 90) {
                                x = 65;
                            }
                        }
                        newMessage += x;
                    }

                    else {
                        newMessage += x;
                    }
                }


            }
        }

        /*OUTPUT & PLAY AGAIN*/
        if (encodeOrDecrypt == 1) {
            cout << "Encrypted Message: " << newMessage << endl;
        }
        else {
            cout << "Decrypted Message: " << newMessage << endl; 
        }
       
        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
        cin.ignore();
    }

    /*ENDING OUTPUT*/
    cout << "\nThanks for testing my game! Have a good day!";
    return 0;
}
