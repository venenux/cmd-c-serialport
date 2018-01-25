
#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"


// uso es "dual_tr 2 1 025F03"
// The device name      Ex: 0=ttyS0 for com1, 1=ttyS1 for com2, 16=ttyUSB0 for USB1 \r\n";
// Format of data received:  1=hex, 2=dec, 3=hex/asc, 4=dec/asc, 5=asc\r\n";
// Data to send         ex:  025f03 aqui debes enviar ejemplo 02[xx]000103[cheksum] 
// NOTES: lo que esta en [] no se si deba incluirse el cheksum no logro saber que es.. no se que lei alli en introduccion de bajo nivel

int main(int Parm_Count, char *Parms[])
{
  int i, n, j,
      cport_nr=0,        /* /dev/ttyS0 (COM1 on windows) /dev/ttyUSB0 are 16 */
      bdrate=9600,       /* 9600 baud */
      Format=1;

   if (Parm_Count==2)  //if there are the right number of parameters on the command line
   {
      for (j=1; j<Parm_Count; j++)  // for all wild search parameters
      {
         strcpy(Param_strings[j-1],Parms[j]);	// on each loop scan the current param
      }
      j=sscanf(Param_strings[0],"%i",&cport_nr); // search if the current param are valid
      if (j != 1) error=1;
      j=sscanf(Param_strings[1],"%i",&Format); // search if the current param are valid
      if (j != 1) error=1;
      sprintf(message,"Devicecode=%s, Message=Baud=%li\r\n",devicename, bdrate); //output the received setup parameters
      fputs(message,output);
   }  //end of if param_count==3

  unsigned char buf[2048];	// maximo lenght es 2 k en la docu lo dice

  char mode[]={'8','N','1',0}; // databit 8, bit de paridad no, stopbit 1


  if(RS232_OpenComport(cport_nr, bdrate, mode))
  {
    printf("Can not open comport\n");

    return(0);
  }


// esta parte es la que recibe, aun no la implemento.. debe alternarse por algun semaforo
  while(1)
  {
    n = RS232_PollComport(cport_nr, buf, 4095);

    if(n > 0)
    {
      buf[n] = 0;   /* always put a "null" at the end of a string! */

      for(i=0; i < n; i++)
      {
        if(buf[i] < 32)  /* replace unreadable control-codes by dots */
        {
          buf[i] = '.';
        }
      }

      printf("received %i bytes: %s\n", n, (char *)buf);
    }
    // pauses the program for a while amonth data received
#ifdef _WIN32
    Sleep(100);
#else
    usleep(100000);  /* sleep for 100 milliSeconds */
#endif
  }

  return(0);
}

