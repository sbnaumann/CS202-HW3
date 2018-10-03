/*
Assignment: 3
<binary>

Name: Sam Naumann
Email: sbnaumann@middlebury.edu
Date: 9/3/2018
Collaborators: None

To compile: gcc ~/CS202/HW3/hw3_binary.c -lm -o ~/CS202/HW3/hw3_binary
To run: ./CS202/HW3/hw3_binary
     This function takes one positive integer greater than zero and sets 
     that as the end value. It then counts from 0 up to but not including that 
     number. It converts every number in that series into binary
*/ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Converts to binary and prints out that value
int stringPrinter(int inputEnd){
  int width = floor(log10(abs(inputEnd))) + 1;
  int convertLength = 0;
  int tmpNumber = inputEnd;

  //get length for string 
  do{
    tmpNumber /= 2;
    convertLength++; 
  } while (tmpNumber > 0);

  //set the String initially all to zeros 
  char binaryOut[convertLength];
  for(int i = 0; i < convertLength; i++){
    binaryOut[i] = '0';
  }

  //convert to binary
  for(int i = 0; i < inputEnd; i++){

    int j = 0;
    int tmpNumber = i; 
    do{
      binaryOut[j] = (tmpNumber % 2) + '0'; 
      tmpNumber /= 2;
      j++;
      
    } while(tmpNumber > 0);

    //print the string in reverse 
    printf("%*d: ",width,i);
    for(j=convertLength - 1; j >= 0; j--){
      printf("%c", binaryOut[j]);
    }
    printf("\n");
  }
}

int main(int argc, char * argv[]){
  int inputEnd = strtol(argv[1], NULL, 10);  
  if(inputEnd <= 0){
    printf("Please enter something that is not a number and greater than 0\n"); 
  }
  stringPrinter(inputEnd);
  return 0; 
}
