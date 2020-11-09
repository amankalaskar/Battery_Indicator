#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <Windows.h>
#include <Winbase.h>
SYSTEM_POWER_STATUS status;
FILE * fp;
char per;
unsigned char charging;
unsigned char battery;

int refreshRate(int rate){
    Sleep(rate*1000);
    return 0;
}

int batteryPercent(){
    if(GetSystemPowerStatus(&status)){
            battery = status.BatteryLifePercent;
            /* battery := 0..100 or 255 if unknown */
            if(battery == 255){
                printf("Battery level unknown !");
            }
            else{
                printf("Battery level : %u%%.", battery);
                per = battery;
            }

            if(battery>=70 || battery <=30){
               MessageBeep(MB_ICONINFORMATION); //alert
            }
        } 
        else {
            printf("Cannot get the power status, error %lu", GetLastError()); 
        }
    return 0;
}

int batteryCharging(){
    charging = status.BatteryFlag;
    printf("\nBattery Flag = %u\n",charging);
    return 0;
}

int main() {

    while(1){
        batteryPercent();   //get battery percentage x%.

        batteryCharging();  //get battery charging status.
      
        /* open the file for writing*/
        fp = fopen("battery_status.txt","w");
        fprintf(fp,"%u%% ",per);
        if(charging == 8){
            fprintf(fp,"Plugged_in");
        }
        else{
            fprintf(fp,"Not_plugged_in");
        }
        /* close the file*/
        fclose(fp);

        refreshRate(5); //set refresh rate here.
        system("cls");
    }
    return 0;
}