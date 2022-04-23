// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Vignere Cipher.cpp
// Program Description: encrypt and decrypt vignere cipher
// Last Modification Date: 23/3/2022
// Author 1 and ID and Group: 2021 0273
// Teaching Assistant:
// section S7, S8
// Purpose: encrypt and decrypt
#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;

// defining a void function named encryption
void encryption(int choice)
{
      //Declaring two string of type char.
      char original_message[81];
      char key[9];

      //print a Message to user to enter the message
      cout << "Please Enter Your Message: \n";

      cin.getline(original_message, 81, '\n'); //getting input

      //print a Message to user to enter the key
      cout << "Please Enter Your Key: \n";

      cin.getline(key, 9, '\n'); //getting input

      //declare empty variable to store the repeated key
      char repeated_key[81] = "";

      //for loop to create repeated key
      for (int i = 0; i <= round((strlen(original_message)/strlen(key)));i++)
      {
        //using strcat to store in it the repeated key
        strcat(repeated_key, key);
      }

      //printing the encryption message.
      cout << "The Encryption Is: ";

      //for loop to check each letter of the original message
      for (int i = 0; i < strlen(original_message); i++)
      {
        //check if any letter is space so we can pass it
        if (!(original_message[i] == (char)32))
        {
            //convert each letter of original message and key to upper case.
            repeated_key[i] = toupper(repeated_key[i]);
            original_message[i] = toupper(original_message[i]);
            //encrypt each letter to its corresponding letter.
            if ((int)original_message[i] >= 65 && (int)original_message[i] <= 90)
            {
                int mod = ((int)original_message[i] + (int)repeated_key[i])% 26;
                char letter = 'A' + mod;
                cout << letter;
            }
            else
                cout << original_message[i];
        }
        else
          cout << original_message[i];
      }
      cout << endl;
      //printing the original message in upper case.
      cout << "The Original Message in Upper Case is: " << original_message;
}

//defining a function to decrypt the encrypted message.
void decryption(int choice)
{
      //Declaring two string of type char.
      char encrypted_message[81];
      char key[9];

      //print the decrypted message to user to enter the message
      cout << "Please Enter Your Encrypted Message: \n";
      cin.getline(encrypted_message, 81, '\n'); //getting input

      //print a message to user to enter the key
      cout << "Please Enter Your Key: \n";
      cin.getline(key, 81, '\n'); //getting input
      // declare empty variable to store the repeated key
      char repeated_key[81] = "";

      //for loop to create repeated key
      for (int i = 0; i <= round((strlen(encrypted_message)/strlen(key)));i++)
      {
        //using strcat to store in it the repeated key
        strcat(repeated_key, key);
      }
      //print the decrypted message
      cout << "The Decryption of The Message in Upper Case: ";

      //for loop to check each letter of the encrypted message
      for (int i = 0; i < strlen(encrypted_message); i++)
      {
        //check if any letter is space so we can pass it
        if (!(encrypted_message[i] == (char)32))
        {
            //convert each letter of encrypted message and key to upper case.
            repeated_key[i] = toupper(repeated_key[i]);
            encrypted_message[i] = toupper(encrypted_message[i]);
            if ((int)encrypted_message[i] >= 65 && (int)encrypted_message[i] <= 90)
            {
              //decrypt each letter to its corresponding letter.
              int mod = abs(((int)encrypted_message[i] - (int)repeated_key[i])+26) % 26;
              char letter = mod + 65;
              cout << letter;
            }
            else
                cout << encrypted_message[i];
        }
        else
          cout << encrypted_message[i];

      }
      cout << endl;
      //printing the encrypted message in upper case.
      cout << "The Encryption in Upper Case is: " << encrypted_message;
}

int main()
{
    char choice[101]; //declaring choice
    cout << "Ahlan ya user ya habibi.\nWhat do you like to do today?\n1- Cipher a message\n2- Decipher a message\n3- End\n" << endl;
    cin.getline(choice, 100, '\n'); //getting input

    //check if length of the input is bigger than one or not
    while(strlen(choice) > 1){
        cout << "invalid input \n";
        cout << "1- Cipher a message\n2- Decipher a message\n3- End\n";
        cin.getline(choice, 100, '\n');}

    //check if the input is bigger than one and smaller than four
    while ((int)choice[0] > 51 || (int)choice[0] < 49)
      {cout << "enter a choice from these:\n1- Cipher a message\n2- Decipher a message\n3- End\n";
      cin.getline(choice, 100, '\n');}

    //converting string into integer using (atoi)
    int final_choice = atoi(choice);
    if (final_choice == 1)
        encryption(1); //calling the function by value

    else if (final_choice == 2)
        decryption(2); //calling the function by value

return 0;
}


