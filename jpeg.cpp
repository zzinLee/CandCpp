#include <stdio.h>

int main(int argc, char *argv[]){
  //Ensure user ran program with 2 words at prompt
  if(argc!=2)
    return 1;
  
  //Open file
  FILE *file = fopen(argv[1],"r");
  if(file == NULL)
    return 1;

  //Read 3 bytes (24bits) from file
  unsigned char bytes[3];
  fread(bytes, 3, 1, file);
  //fread(배열, 읽을 바이트 수, 읽을 횟수, 읽을 파일)

  //check if bytes are 0xff, 0xd8, 0xff
  if(bytes[0]==0xff && bytes[1]==0xd8 && bytes[2]==0xff)
  {
    printf("Maybe");
  }
  else{
    printf("No");
  }

  return 0; 
}