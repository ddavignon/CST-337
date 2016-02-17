/**
* Dustin D'Avignon
* CST 337 Lab 01 SP16
* This program uses the void function to convert the RGB value to greyscale.
* The main function is for testing the function 
**/

#include <stdio.h>

void grey_scale(unsigned int pixels[], unsigned int size){
	
	unsigned int RGB[3], R, G, B; //array to hold RGB values	
	for(int i = 0; i < size; i++){ //iterate through hex values
	
		for(int j = 0; j < (sizeof(RGB)/sizeof(unsigned int)); j++){ //iterate through RGB values
			RGB[j] = (pixels[i] & 0x000000FF); //finds end values from B->G->R
			pixels[i] = pixels[i] >> 8; //pushes values until alpha is at far right
		}
		
		//average pixel set to B then pushed to each color value 
		B = (RGB[0]+RGB[1]+RGB[2])/3 ;
		G = (B << 8);
		R = (G << 8);		
		
		//push alpha values back into position, then put new R,G,B values back in
		pixels[i] =  (pixels[i] << 24); 
		pixels[i] = ((pixels[i] ^ R) ^ (pixels[i] ^ G) ^ (pixels[i] ^ B));	
		
	}
}

int main(int argc, char *argv[]) {
	
	unsigned int pixels[]= {0xAA112233, 0xBB334455};
	grey_scale(pixels, sizeof(pixels)/sizeof(unsigned int));
	for(int i = 0; i < sizeof(pixels)/sizeof(unsigned int); i++){
			printf("%x \n", pixels[i]);	
	}
		
}
