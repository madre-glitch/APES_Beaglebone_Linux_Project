/*
* FileName        :    led.c
* Description     :    This file contains concurrent function implementation for toggling the USR led
*					   of Beagle Bone Green
*                        
* File Author Name:    Bhallaji Venkatesan, Divya Sampath Kumar
* Tools used      :    gcc, gedit, Sublime Text
* References      :    
*
*
*/
#include <decision_led.h>

uint8_t dec_led_toggle()
{
	FILE *LED = NULL;
	char *LED_PATH = "/sys/class/leds/beaglebone:green:usr0/brightness";
    for(int i=0;i<3;i++)
    {
	    if((LED = fopen(LED_PATH,"r+"))!=NULL)
	    {
	    	fwrite("1",sizeof(char),1, LED);
	    	fclose(LED);
	    }
	    usleep(100);
	    //Toggling the LED
	    if((LED = fopen(LED_PATH,"r+"))!=NULL)
	    {
	    	fwrite("0",sizeof(char),1, LED);
	    	fclose(LED);
	    }
	}	

    return 0;
}
