#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int stringPrinter(int inputEnd){
  int width = floor(log10(abs(inputEnd))) + 1;
  int convertLength = 0;
  int tmpNumber = inputEnd;
  do{
    tmpNumber /= 2;
    convertLength++; 
  } while (tmpNumber > 0);


  char binaryOut[convertLength];
  for(int i = 0; i < convertLength; i++){
    binaryOut[i] = '0';
  }

  for(int i = 0; i < inputEnd; i++){

    int j = 0;
    int tmpNumber = i; 
    do{
      binaryOut[j] = (tmpNumber % 2) + '0'; 
      tmpNumber /= 2;
      j++;
      
    } while(tmpNumber > 0);

    printf("%*d: ",width,i);
    for(j=convertLength - 1; j >= 0; j--){
      printf("%c", binaryOut[j]);
    }
    printf("\n");
  }
}

int main(int argc, char * argv[]){
  int inputEnd = strtol(argv[1], NULL, 10);  
  
  stringPrinter(inputEnd);
  return 0; 
}
