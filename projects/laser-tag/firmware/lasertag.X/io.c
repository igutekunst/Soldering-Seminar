#include "io.h"

#include "gameSM.h"
#include "laserTagHardware.h"
#include "playerInfo.h"

unsigned short trigger_counter = 0;
extern unsigned char command;
extern unsigned char rx_counter;
extern unsigned char rx_timeout;
void sendCommand(unsigned char command,unsigned char team_id){
    while(tx_status!=IR_IDLE); //wait for ir to be ready
    
    if(command < 8){//if >7, not a valid command, so will ignore
        unsigned char packet = (my_team_id<<3) | command;
        tx_buffer = HammingTableEncode(packet);
        tx_status = 0;
    }
    
}
void sendLongCommand(unsigned char action,unsigned char player_id){
    while(tx_status!=IR_IDLE); //wait for ir to be ready

    if(action < 4){//if >7, not a valid command, so will ignore
        unsigned char packet =((player_id | action<<6)& 0xF0)>>4;
        tx_buffer = HammingTableEncode(packet);
        tx_status = 0;
    }

    while(tx_status!=IR_IDLE); //wait for ir to be ready

    if(action < 4){//if >7, not a valid command, so will ignore
        unsigned char packet = ((player_id | action<<6)) & 0xF;
        tx_buffer = HammingTableEncode(packet);
        tx_status = 0;
    }

}
void enableIO(){

    //enable timer 1 for game clock
    T1CONbits.TCS = 0; //use internal clock
   
    T1CONbits.TCKPS = 0b10 ;//prescale 1:1

    T1CONbits.TSIDL = 0; //continue in idle mode

    PR1 = 0xffff; // about 3 seconds
    IPC0bits.T1IP = 0x01;
    IEC0bits.T1IE = 1;
    T1CONbits.TON = 1;
    

    T2CONbits.TCS = 0; //use internal clock
    T2CONbits.T32 = 0;
    T2CONbits.TCKPS = 0b10 ;//prescale 1:1

    T2CONbits.TSIDL = 0; //continue in idle mode

    PR2 = 0x1fff; // about
    IPC1bits.T2IP = 0x01;
    IEC0bits.T2IE = 1;
    T2CONbits.TON = 1;
    //lols for testing

    TRIGGER_TRIS = 1;

    
    
    enableIrSerial(); //enables ir serial out on RA6

    //used for receiving IR packets
    UART1GuteInit(109);


    //lit led pins be outputs
    RED_TRIS = 0;
    GREEN_TRIS =0;
    BLUE_TRIS = 0;

    LIFE_3_TRIS = 0;
    LIFE_2_TRIS = 0;
    LIFE_1_TRIS = 0;
   


}



void updateDisplay(unsigned char lives){

    if(lives>0){
         if(my_team_id==BLUE_TEAM){
            RED_LAT = 1;
            GREEN_LAT = 1;
            BLUE_LAT = 0;
        
        }else{
            RED_LAT =1;
            GREEN_LAT = 0;
            BLUE_LAT = 1;
       }
    }else{
        RED_LAT =0;
        GREEN_LAT = 1;
        BLUE_LAT = 1;

        
    }

    if(lives==3){
        LIFE_1_LAT= 1;
        LIFE_2_LAT= 1;
        LIFE_3_LAT= 1;
       
    }else if(lives==2){
        LIFE_1_LAT= 1;
        LIFE_2_LAT= 1;
        LIFE_3_LAT= 0;
      
    }
    else if(lives==1){
        LIFE_1_LAT= 1;
        LIFE_2_LAT= 0;
        LIFE_3_LAT= 0;
       
    }
    else if(lives==0){
        LIFE_1_LAT= 0;
        LIFE_2_LAT= 0;
        LIFE_3_LAT= 0;
      
    }
}


void _ISR _T2Interrupt(void){
    if(rx_timeout > 7){
        rx_counter = 0;
    }else{
        rx_timeout++;
    }
    command = 0;
    if(TRIGGER_PORT==0){

        if(trigger_counter==0){
            //shooting time
            if(lives>0){
            sendLongCommand(1,my_player_id);
            }
            
       
        }
        else if(trigger_counter==20){
            sendLongCommand(2,my_player_id);

        }
        else{


        }
            trigger_counter++;
     }else{
        trigger_counter = 0;

     }

        IFS0bits.T2IF = 0; //ack interrupt


}