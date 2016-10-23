#include <FastLED.h>
#include <HashMap.h>

#define DATA_PIN 6  //this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
/**  
 *   Array location for each letter. We can use this to dynamically create messages based on strings.
 */
const byte HASH_SIZE = 28;
HashType<char*,int> hashRawArray[HASH_SIZE]; 
//handles the storage [search,retrieve,insert]
HashMap<char*,int> hashMap = HashMap<char*,int>( hashRawArray , HASH_SIZE ); 

#define NUM_LEDS 100 //change this for the number of LEDs in the strip
#define COLOR_ORDER RGB

CRGB leds[NUM_LEDS]; 
//I have a few additional integers in here from different tests. 
int y = 1;
int z = 0;
int w = 5;
int i = 20;
int a = 0;
int t = 0;

void setup(){
    FastLED.addLeds<WS2811, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS); //setting up the FastLED
    // Add Led values for each letter into hashmap
    hashMap[0]('a',0);
    
    randomSeed(analogRead(0)); //seeding my random numbers to make it more random.  If you just use the random function it will repeat the same pattern every time it is loaded.
    }

void loop(){

  //The switch case loop let me use a random number generator to switch between subroutines.  The default case is run if the condition isn't met in any other case.  Since I wanted the standard christmas lights more often
  //than everything else, I have 3 conditions that will give me the christmas lights (z=6, z=7, z=8) while there is only one condition for all other subroutines.
/*
switch(z){
 case 0:
  IMHERE();
  break;
 case 1:
  RUN();
  break;
 case 2:
  HELP();
  break;
 case 3:
 //I broke case 3 and case 5 into two routines, one to go up and one to go down.  When I had it as a for loop that went up and down the program got stuck in a never ending loop and didn't leave the subroutine
  LOWREDUP();
  LOWREDDOWN();
  LOWREDUP();
  LOWREDDOWN();
  break;
 case 4:
  BLACKOUT();
  break;
  case 5:
  glowup();
  glowdown();
  glowup();
  glowdown();
  break;
 default:
  CHRISTMAS();
  break;
}*/
//z = random (0, 9); //random includes the first number and maxes out at one less than the second number
  
  while (true){
    char message[ ] = "aaaaa";
    displayMessage(message);
    //lightRun();
  }
}

void displayMessage(char message[]){
  int prev_led = -1;
  for(int i =0; i< sizeof(message); i+=1){
    FastLED.clear();
    
    if(prev_led >= 0){
      leds[prev_led] = CRGB(0,0,0);
      leds[prev_led+1] = CRGB(0,0,0);
      FastLED.show();
      delay(3000);
    }
  
    
    char letter = message[i];
    int ledNum = hashMap.getValueOf(letter);
    leds[ledNum] = CRGB (0,255,0);
    leds[ledNum+1] = CRGB(0,255,0);
    prev_led=ledNum;
    
    FastLED.show();
    delay(5000);
  }
  
}
 //All of my subroutines are below.  I've been told that this is very poor coding, but I'm new to all of this.  Feel free to replace my subroutines with ones of your own.  Many people have suggested using strings instead of 
 //hard writing each of the LED conditions like I have below.
void CHRISTMAS() {
  FastLED.clear();
    leds[0] = CRGB (0,255,255); //aqua
      leds[10] = CRGB (0,255,255); //aqua
        leds[20] = CRGB (0,255,255); //aqua
          leds[30] = CRGB (0,255,255); //aqua
            leds[40] = CRGB (0,255,255); //aqua
              leds[50] = CRGB (0,255,255); //aqua
                leds[60] = CRGB (0,255,255); //aqua
                  leds[70] = CRGB (0,255,255); //aqua
                    leds[80] = CRGB (0,255,255); //aqua
                      leds[90] = CRGB (0,255,255); //aqua
    leds[1] = CRGB (153, 50, 204); //dark orchid
      leds[11] = CRGB (153, 50, 204); //dark orchid
        leds[21] = CRGB (153, 50, 204); //dark orchid
          leds[31] = CRGB (153, 50, 204); //dark orchid
            leds[41] = CRGB (153, 50, 204); //dark orchid
              leds[51] = CRGB (153, 50, 204); //dark orchid
                leds[61] = CRGB (153, 50, 204); //dark orchid
                  leds[71] = CRGB (153, 50, 204); //dark orchid
                    leds[81] = CRGB (153, 50, 204); //dark orchid
                      leds[91] = CRGB (153, 50, 204); //dark orchid
    leds[2] = CRGB (255,255,0); //yellow
      leds[12] = CRGB (255,255,0); //yellow
        leds[22] = CRGB (255,255,0); //yellow
          leds[32] = CRGB (255,255,0); //yellow
            leds[42] = CRGB (255,255,0); //yellow
              leds[52] = CRGB (255,255,0); //yellow
                leds[62] = CRGB (255,255,0); //yellow
                  leds[72] = CRGB (255,255,0); //yellow
                    leds[82] = CRGB (255,255,0); //yellow
                      leds[92] = CRGB (255,255,0); //yellow
                                        
    leds[3] = CRGB (0,255,127); //spring green
      leds[13] = CRGB (0,255,127); //spring green
        leds[23] = CRGB (0,255,127); //spring green
          leds[33] = CRGB (0,255,127); //spring green
            leds[43] = CRGB (0,255,127); //spring green
              leds[53] = CRGB (0,255,127); //spring green
                leds[63] = CRGB (0,255,127); //spring green
                  leds[73] = CRGB (0,255,127); //spring green
                    leds[83] = CRGB (0,255,127); //spring green
                      leds[93] = CRGB (0,255,127); //spring green
    leds[4] = CRGB (255,165,0); //orange 
      leds[14] = CRGB (255,165,0); //orange 
        leds[24] = CRGB (255,165,0); //orange 
          leds[34] = CRGB (255,165,0); //orange 
            leds[44] = CRGB (255,165,0); //orange 
              leds[54] = CRGB (255,165,0); //orange 
                leds[64] = CRGB (255,165,0); //orange 
                  leds[74] = CRGB (255,165,0); //orange 
                    leds[84] = CRGB (255,165,0); //orange 
                      leds[94] = CRGB (255,165,0); //orange 
    leds[5] = CRGB (65,105,255); //royal blue
      leds[15] = CRGB (65,105,255); //royal blue
        leds[25] = CRGB (65,105,255); //royal blue
          leds[35] = CRGB (65,105,255); //royal blue
            leds[45] = CRGB (65,105,255); //royal blue
              leds[55] = CRGB (65,105,255); //royal blue
                leds[65] = CRGB (65,105,255); //royal blue
                  leds[75] = CRGB (65,105,255); //royal blue
                    leds[85] = CRGB (65,105,255); //royal blue
                      leds[95] = CRGB (65,105,255); //royal blue
    leds[6] = CRGB (76, 0, 153); //dark purple
      leds[16] = CRGB (76, 0, 153); //dark purple
        leds[26] = CRGB (76, 0, 153); //dark purple
          leds[36] = CRGB (76, 0, 153); //dark purple
            leds[46] = CRGB (76, 0, 153); //dark purple
              leds[56] = CRGB (76, 0, 153); //dark purple
                leds[66] = CRGB (76, 0, 153); //dark purple
                  leds[76] = CRGB (76, 0, 153); //dark purple
                    leds[86] = CRGB (76, 0, 153); //dark purple
                      leds[96] = CRGB (76, 0, 153); //dark purple
    leds[7] = CRGB (255,105,180); //hot pink
      leds[17] = CRGB (255,105,180); //hot pink
        leds[27] = CRGB (255,105,180); //hot pink
          leds[37] = CRGB (255,105,180); //hot pink
            leds[47] = CRGB (255,105,180); //hot pink
              leds[57] = CRGB (255,105,180); //hot pink
                leds[67] = CRGB (255,105,180); //hot pink
                  leds[77] = CRGB (255,105,180); //hot pink
                    leds[87] = CRGB (255,105,180); //hot pink
                      leds[97] = CRGB (255,105,180); //hot pink
    leds[8] = CRGB (0,128,0); //dark green 
      leds[18] = CRGB (0,128,0); //dark green 
        leds[28] = CRGB (0,128,0); //dark green 
          leds[38] = CRGB (0,128,0); //dark green 
            leds[48] = CRGB (0,128,0); //dark green 
              leds[58] = CRGB (0,128,0); //dark green 
                leds[68] = CRGB (0,128,0); //dark green 
                  leds[78] = CRGB (0,128,0); //dark green 
                    leds[88] = CRGB (0,128,0); //dark green 
                      leds[98] = CRGB (0,128,0); //dark green 
    leds[9] = CRGB (255,0,0); //red
      leds[19] = CRGB (255,0,0); //red
        leds[29] = CRGB (255,0,0); //red
          leds[39] = CRGB (255,0,0); //red
            leds[49] = CRGB (255,0,0); //red
              leds[59] = CRGB (255,0,0); //red
                leds[69] = CRGB (255,0,0); //red
                  leds[79] = CRGB (255,0,0); //red
                    leds[89] = CRGB (255,0,0); //red
                      leds[99] = CRGB (255,0,0); //red
        FastLED.show();
        t = random(20, 30) * 1000;
      delay(t);
     FastLED.clear(); 
}
  

void glowup() {
  FastLED.clear();
  //Setting i determines your lowest power value. the second condition determines the max value and the y determines your step
  for( int i = 60; i < 255; i = i + y ) {

      int r = i;  
      int b = 0;  
      int g = 0;   

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
          
      FastLED.show();
      delay(50); 
    }
 
}

void lightRun() {
  for (int i =0 ;i< NUM_LEDS; i+=1){
      leds[i] = CRGB(153,51,255);
      FastLED.show();
      delay(20);
  }

  for(int i=NUM_LEDS-1; i>=0; i-=1){
    leds[i] = CRGB(0,255,0);
    FastLED.show();
    delay(20);
  }
}

void glowdown() {
  //Same thing as glowup, except in reverse
  for (int i = 255; i > 60; i = i - y){

      int r = i;  
      int b = 0;  
      int g = 0;   

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
          
      FastLED.show();
      delay(50); 
    }      
}

void IMHERE() {
  //These are all where strings would have been better.  I'm going to work on a rev2 so we'll see what happens.  Suggestions are appreciated
      FastLED.clear();
  leds[84] = CRGB (255,255,255);
  leds[85] = CRGB (255,255,255);
  leds[86] = CRGB (255,255,255);
        FastLED.show();
      delay(2000); 
  leds[84] = CRGB (0,0,0);
  leds[85] = CRGB (0,0,0);
  leds[86] = CRGB (0,0,0);
        FastLED.show();
      delay(500);
  leds[95] = CRGB (255,255,255);
  leds[96] = CRGB (255,255,255);
        FastLED.show();
      delay(2000); 
  leds[95] = CRGB (0,0,0);
  leds[96] = CRGB (0,0,0);
        FastLED.show();
      delay(500); 
  leds[82] = CRGB (255,255,255);
  leds[83] = CRGB (255,255,255);
        FastLED.show();
      delay(2000); 
  leds[82] = CRGB (0,0,0);
  leds[83] = CRGB (0,0,0);
        FastLED.show();
      delay(500); 
  leds[73] = CRGB (255,255,255);
  leds[74] = CRGB (255,255,255);
  leds[75] = CRGB (255,255,255);
        FastLED.show();
      delay(2000); 
  leds[73] = CRGB (0,0,0);
  leds[74] = CRGB (0,0,0);
  leds[75] = CRGB (0,0,0);
        FastLED.show();
      delay(500); 
  leds[33] = CRGB (255,255,255);
  leds[34] = CRGB (255,255,255);
        FastLED.show();
      delay(2000); 
  leds[33] = CRGB (0,0,0);
  leds[34] = CRGB (0,0,0);
        FastLED.show();
      delay(500); 
  leds[73] = CRGB (255,255,255);
  leds[74] = CRGB (255,255,255);
  leds[75] = CRGB (255,255,255);
        FastLED.show();
      delay(2000); 
  leds[73] = CRGB (0,0,0);
  leds[74] = CRGB (0,0,0);
  leds[75] = CRGB (0,0,0);
        FastLED.show();
      delay(500); 
  leds[84] = CRGB (255,255,255);
  leds[85] = CRGB (255,255,255);
  leds[86] = CRGB (255,255,255);
  leds[95] = CRGB (255,255,255);
  leds[96] = CRGB (255,255,255);
  leds[82] = CRGB (255,255,255);
  leds[83] = CRGB (255,255,255);
  leds[73] = CRGB (255,255,255);
  leds[74] = CRGB (255,255,255);  
  leds[75] = CRGB (255,255,255);
  leds[33] = CRGB (255,255,255);
  leds[34] = CRGB (255,255,255);
        FastLED.show();
        delay(500);
  FastLED.clear();
        delay(500);
  leds[84] = CRGB (255,255,255);
  leds[85] = CRGB (255,255,255);
  leds[86] = CRGB (255,255,255);
  leds[95] = CRGB (255,255,255);
  leds[96] = CRGB (255,255,255);
  leds[82] = CRGB (255,255,255);
  leds[83] = CRGB (255,255,255);
  leds[73] = CRGB (255,255,255);
  leds[74] = CRGB (255,255,255);  
  leds[75] = CRGB (255,255,255);
  leds[33] = CRGB (255,255,255);
  leds[34] = CRGB (255,255,255);
        FastLED.show();
        delay(200);
FastLED.clear();
        delay(300);
  leds[84] = CRGB (255,255,255);
  leds[85] = CRGB (255,255,255);
  leds[86] = CRGB (255,255,255);
  leds[95] = CRGB (255,255,255);
  leds[96] = CRGB (255,255,255);
  leds[82] = CRGB (255,255,255);
  leds[83] = CRGB (255,255,255);
  leds[73] = CRGB (255,255,255);
  leds[74] = CRGB (255,255,255);  
  leds[75] = CRGB (255,255,255);
  leds[33] = CRGB (255,255,255);
  leds[34] = CRGB (255,255,255);
        FastLED.show();        
  delay(10000); 
    FastLED.clear();  
}

void RUN() {
      FastLED.clear();
  leds[33] = CRGB (255,255,255);
  leds[34] = CRGB (255,255,255);
        FastLED.show();
      delay(500); 
  leds[33] = CRGB (0,0,0);
  leds[34] = CRGB (0,0,0);
        FastLED.show();
      delay(500); 
  leds[33] = CRGB (255,255,255);
  leds[34] = CRGB (255,255,255);
        FastLED.show();
      delay(300); 
  leds[33] = CRGB (0,0,0);
  leds[34] = CRGB (0,0,0);
        FastLED.show();
      delay(600); 
  leds[33] = CRGB (255,255,255);
  leds[34] = CRGB (255,255,255);
        FastLED.show();
      delay(400); 
  leds[33] = CRGB (0,0,0);
  leds[34] = CRGB (0,0,0);
        FastLED.show();
      delay(500); 
  leds[33] = CRGB (255,255,255);
  leds[34] = CRGB (255,255,255);
        FastLED.show();
      delay(2000); 
  leds[23] = CRGB (255,255,255);
  leds[24] = CRGB (255,255,255);
        FastLED.show();
      delay(2000); 
  leds[45] = CRGB (255,255,255);
  leds[46] = CRGB (255,255,255);
        FastLED.show();
      delay(10000); 
leds[34] = CRGB (0,0,0);
 FastLED.show();
      delay(300); 
leds[45] = CRGB (0,0,0);
FastLED.show();
     delay(500); 
leds[23] = CRGB (0,0,0);
FastLED.show();
     delay(1000); 
leds[46] = CRGB (0,0,0);
FastLED.show();
     delay(2000); 
leds[33] = CRGB (0,0,0);
FastLED.show();
     delay(300); 
leds[24] = CRGB (0,0,0);
FastLED.show();
     delay(5000); 
    FastLED.clear();  
}

void HELP() {
      FastLED.clear();
  leds[82] = CRGB (255,255,255);
  leds[83] = CRGB (255,255,255);
        FastLED.show();
      delay(500); 
  leds[82] = CRGB (0,0,0);
  leds[83] = CRGB (0,0,0);
        FastLED.show();
      delay(700); 
  leds[82] = CRGB (255,255,255);
  leds[83] = CRGB (255,255,255);
        FastLED.show();
      delay(400); 
  leds[82] = CRGB (0,0,0);
  leds[83] = CRGB (0,0,0);
        FastLED.show();
      delay(400); 
  leds[82] = CRGB (255,255,255);
  leds[83] = CRGB (255,255,255);
        FastLED.show();
      delay(250); 
  leds[82] = CRGB (0,0,0);
  leds[83] = CRGB (0,0,0);
        FastLED.show();
      delay(250); 
  leds[82] = CRGB (255,255,255);
  leds[83] = CRGB (255,255,255);
        FastLED.show();
      delay(2000); 
  leds[73] = CRGB (255,255,255);
  leds[74] = CRGB (255,255,255);
  leds[75] = CRGB (255,255,255);
        FastLED.show();
      delay(2000); 
  leds[93] = CRGB (255,255,255);
        FastLED.show();
      delay(2000); 
  leds[38] = CRGB (255,255,255);
  leds[39] = CRGB (255,255,255);
        FastLED.show();
      delay(2000); 
  leds[38] = CRGB (0, 0, 0);
  leds[39] = CRGB (0, 0, 0);
        FastLED.show();
      delay(1000); 
  leds[38] = CRGB (255,255,255);
  leds[39] = CRGB (255,255,255);
        FastLED.show();
      delay(500); 
  leds[38] = CRGB (0, 0, 0);
  leds[39] = CRGB (0, 0, 0);
        FastLED.show();
      delay(200); 
  leds[38] = CRGB (255,255,255);
  leds[39] = CRGB (255,255,255);
        FastLED.show();
      delay(200); 
  leds[38] = CRGB (0, 0, 0);
  leds[39] = CRGB (0, 0, 0);
        FastLED.show();
      delay(200); 
  leds[38] = CRGB (255,255,255);
  leds[39] = CRGB (255,255,255);
        FastLED.show();
      delay(10000); 
    FastLED.clear();  
    delay(5000); 
}

void LOWREDUP(){
     for( int i = 20; i < 150; i = i + y ) {

      int r = i;  
      int b = 0;  
      int g = 0;   

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
          
      FastLED.show();
      delay(100); 
    } 
}
void LOWREDDOWN(){
     for(int i = 150; i > 20; i = i - y) {

      int r = i;  
      int b = 0;  
      int g = 0;   

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
          
      FastLED.show();
      delay(100); 
    } 
}

void BLACKOUT(){
      int r = 0;  
      int b = 0;  
      int g = 0;   

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
          
      FastLED.show();
      delay(30000); 
      
}
