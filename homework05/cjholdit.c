#include <stdio.h>
#include <string.h>
#include <time.h>

  int main(){
    char ch;
    time_t firsttime;
    time_t secondtime;

    printf("This program will time how long you can hold your breath.\n");
    printf("Take a deep breath, then press the 'Enter' key. \n");
    printf("When you absolutely have to exhale, press the enter key again.\n");
    printf("The duration will be displayed in minutes and seconds.\n");


    ch= fgetc(stdin);
      if(ch==0x0A)
      {
        printf("%s", time(&firsttime));
        printf("Timer has started!!!");
        printf("TIMER: %ld", firsttime);
      }
      ch= fgetc(stdin);
        if(ch==0x0A)
        {
          time(&secondtime);
          printf("T = %d .%d", difftime(secondtime, firsttime), (secondtime-firsttime) % 1000);
          printf(" seconds.miliseconds (good job but you can do better) \n   ");
          //ftimer would start here
        }
        //printf("%ld",secondtime-firsttime);

    }