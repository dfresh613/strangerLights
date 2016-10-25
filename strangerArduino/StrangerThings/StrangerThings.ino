#include <FastLED.h>
#include <HashMap.h>

#define DATA_PIN 6  //this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
// The number of lettters/characters we want to store in the hashmap
const byte HASH_SIZE = 28;
HashType<char*,int> hashRawArray[HASH_SIZE]; 
//handles the storage [search,retrieve,insert]
HashMap<char*,int> charToLed = HashMap<char*,int>( hashRawArray , HASH_SIZE ); 

#define NUM_LEDS 100 //change this for the number of LEDs in the strip
#define COLOR_ORDER RGB

CRGB leds[NUM_LEDS]; 
boolean running=false;

//bxl4662's variable for LOWEREDUP and LOWEREDDOWN functions
int y = 1;

void setup(){
    FastLED.addLeds<WS2811, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS); //setting up the FastLED
    Serial.begin(9600);
    /**  
    * Array location for each letter. We can use this to dynamically create messages based on strings.
    */
    charToLed[0]('a',0);
    charToLed[1]('b',4);
    charToLed[3]('c',8);
    charToLed[4]('d',12);
    charToLed[5]('e',16);
    charToLed[6]('f',20);
    charToLed[7]('g',24);
    charToLed[8]('h',27);
    charToLed[9]('i',30);
    charToLed[10]('j',63);
    charToLed[11]('k',60);
    charToLed[12]('l',57);
    charToLed[13]('m',54);
    charToLed[14]('n',50);
    charToLed[15]('o',46);
    charToLed[16]('p',43);
    charToLed[17]('q',40);
    charToLed[18]('r',37);
    charToLed[19]('s',71);
    charToLed[20]('t',74);
    charToLed[21]('u',77);
    charToLed[22]('v',80);
    charToLed[23]('w',84);
    charToLed[24]('x',87);
    charToLed[25]('y',90);
    charToLed[26]('z',93);
    
    
    randomSeed(analogRead(0));
}

void loop(){
    if (running){
      return;
    }else{
      running=true;
    }
    
    FastLED.clear();
    FastLED.show();
    notifyPi();
    delay(1500); //delay to wait for serial response

    String msg_str = "random";
    if(Serial.available()>0){
        msg_str = Serial.readString();
        if(msg_str.equals("random")){
          doRandom();
        }else{
          displayMessage(msg_str);
          doRandom();
        }
    }else{
      doRandom();
    }

}

void notifyPi(){
  Serial.println("ready");
}
void doRandom(){
  int rNum=random(3);
  switch(rNum){
    case 0:
      LOWREDDOWN();
      break;
    case 1:
      lightRun();
      break;
    case 2:
      CHRISTMAS();
      break;
    case 3:
      displayMessage("die");
      break;
    case 4:
      displayMessage("helpme");
      break;
    case 5:
      displayMessage("itscoming");
      break;
    default:
      lightRun();
      break;
  }
  running=false;  
}

void displayMessage(String message){
  int prev_led = -1;
  int ledNum;
  char letter;
  int r;
  int g;
  int b;
  int r2;
  int g2;
  int b2;
  for(int i =0; i< message.length(); i+=1){
    FastLED.clear();
    
    if(prev_led >= 0){
      leds[prev_led] = CRGB(0,0,0);
      leds[prev_led+1] = CRGB(0,0,0);
      FastLED.show();
    }
    
    letter = message.charAt(i);
    if (isWhitespace(letter)){
        delay(2000);
        continue;
    }

    r=randomColorCode();
    g=randomColorCode();
    b=randomColorCode();
    r2=randomColorCode();
    g2=randomColorCode();
    b2=randomColorCode();
    
    ledNum = charToLed.getValueOf(letter);
    leds[ledNum] = CRGB (r,g,b);
    leds[ledNum+1] = CRGB(r2,g2,b2);
    prev_led=ledNum;
    
    FastLED.show();
    delay(2000);
    running=false;
  }
  //flash all lights in the message
  FastLED.clear();
  for(int i=0; i< message.length(); i+=1){
    r=randomColorCode();
    g=randomColorCode();
    b=randomColorCode();
    r2=randomColorCode();
    g2=randomColorCode();
    b2=randomColorCode();
    letter=message.charAt(i);
    ledNum=charToLed.getValueOf(letter);
    leds[ledNum] = CRGB(r,g,b);
    leds[ledNum+1]= CRGB(r2,g2,b2);
  }
  FastLED.show();
  delay(3000);
  
}

void lightRun() {
  int r=randomColorCode();
  int g=randomColorCode();
  int b=randomColorCode();
  for (int i =0 ;i< NUM_LEDS; i+=1){
      leds[i] = CRGB(r,g,b);
      FastLED.show();
      delay(20);
  }

  r=randomColorCode();
  g=randomColorCode();
  b=randomColorCode();
  for(int i=NUM_LEDS-1; i>=0; i-=1){
    leds[i] = CRGB(r,g,b);
    FastLED.show();
    delay(20);
  }
}

int randomColorCode(){
  int rColor = random(255);
  return rColor;
}

void allBlack(){
      int r = 13;  
      int b = 13;  
      int g = 13;   

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
          
      FastLED.show();
      delay(7000); 
      
}

//Cool functions created by bxl4662
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
      delay(7000);
     FastLED.clear(); 
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

