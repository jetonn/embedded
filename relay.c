#include <stdio.h>
#include <wiringPi.h>


#define GPIO 5

int main (void)
{
  printf ("Raspberry Pi - Solid State Relay\n");

  wiringPiSetup ();

  pinMode (GPIO, OUTPUT);

  char state;

  for (;;)
  {

    printf("Would you like to turn the light on? (press y for YES, n for NO, or q to QUIT): ");
    scanf("%state", &state);
    switch (state) {
    case 'y':
	digitalWrite(GPIO, 0);
	break;
    case 'n':
	digitalWrite(GPIO, 1);
	break;
    default:
	break;
    }

   if (state != 'y' && state != 'n'){
	break;
    }
  }

  return 0;
}
