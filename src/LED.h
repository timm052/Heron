// USEFUL LED FUNCTIONS
void momentaryLED(int address, int time,  int hue){
    leds[address].setHue(hue);
    delay(time)
    leds[address] = CRGB::Black;
    return;
}

// TODO: Cursor fuctionality needs basic step sequencer first
//void Cursor(int play, int range_start, int bpm, int colour, CRGB ledbuffer){
//    while(play);
//    {
//        for (size_t i = 0; i < 16; i++)
//        {
//            ledbuffer[i].setRGB(255, 255, 255);
//            delay(bpm); //delay for one note of whatever zoom level device is at
//            ledbuffer[i].setRGB(0, 0, 0);
//        }  
//    return;
//}

void toggleLED(int address, bool state, int hue){
    if (state == true)
    {
        leds[address].setHue(hue);
    }
    else
    {
        leds[address] = CRGB::Black;
    }
    
    return;
}

void knobLED(int range_stat, int range_stop, int value, int colour){
    return;
}

int colouraddition (int colour1, int colour2){
    return;
}

void dumbmodes (){
    return;
}

void palettechange (string palette){
    myPal = palette;
    return;
}

void brightness (){
    return;    
}


//store all gradients here only used gradients will be included in mem