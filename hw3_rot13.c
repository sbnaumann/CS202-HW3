/*
Assignment: 3

Name: Sam Naumann
Email: sbnaumann@middlebury.edu
Date: 10/3/2018
Collaborators: None

To compile: gcc ~/filepath/hw3_rot13.c -o ~/filepath/hw3_rot13
To run: ./filepath/hw3_rot13 argx argx+1 arg...
     This program takes any number of arguments that can really be any keyboard characters that are not console 
     commands. If they are console commands then the terminal will give you an error. Otherwise this program
     will encrypt all uppercase and lowercase latin letters. It will leave all numbers and symbols alone. The
     encryption consists of moving up 13 ascii places, if the args are 'encrypted' twice they will be returned
     to their initial form.
*/ 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//encrypting and printing funtion for the args 
void rot13(int numlines, char * text[]){

  //Test to see if it is an uppercase or lowercase latin letter, if it is then change it 
  for(int i = 0; i < numlines; i++){
    int restriction = strlen(text[i]);

    for(int j = 0; j < restriction; j++){

      //lowecase letters 
      if(text[i][j] < 123 && text[i][j] > 96){

	if (text[i][j] + 13 > 122){
	  int overdraft = 13 - (122 - text[i][j]);
	  text[i][j] = 96 + overdraft;   

	} else {
	  text[i][j] = text[i][j] + 13;
	}
      //uppercase letters 
      } else if(text[i][j] < 91 && text[i][j] > 64){
	if (text[i][j] + 13 > 90){
	  int overdraft = 13 - (90 - text[i][j]);
	  text[i][j] = 64 + overdraft;   

	} else {
	  text[i][j] = text[i][j] + 13;
	}

      } 
    }

    printf("%s ", text[i]);
  }
  printf("\n");
}

//receive the input and put it in an array 
int main(int argc, char * argv[]){

  char * text[argc-1];

  for(int i = 0; i < argc - 1; i++){
    text[i] = argv[i+1];
  }

  rot13(argc-1, text);
  return 0; 
}
