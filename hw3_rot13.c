#include <stdio.h>
#include <string.h>

void rot13(int numlines, char * text[]){
  for(int i = 0; i < numlines; i++){
    int restriction = strlen(text[i]);

    for(int j = 0; j < restriction; j++){
      if(text[i][j] < 123 && text[i][j] > 96){
	if (text[i][j] + 13 > 122){
	  int overdraft = 13 - (122 - text[i][j]);
	  text[i][j] = 96 + overdraft;   
	} else {
	  text[i][j] = text[i][j] + 13;
	}
      } 
    }

    printf("%s ", text[i]);
  }
}

int main(int argc, char * argv[]){

  char * text[argc-1];

  for(int i = 0; i < argc - 1; i++){
    text[i] = argv[i+1];
  }

  rot13(argc-1, text);
  return 0; 
}
