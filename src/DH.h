#ifndef DH_h
#define DH_h

#define PRIME0 	0x1B
#define PRIME1 	0x89 
#define PRIME2 	0xB7 
#define PRIME3 	0xE5 

#define PRIME4 	0xAF
#define PRIME5 	0x12 
#define PRIME6 	0xF1 
#define PRIME7 	0xEE 

#define PRIME8 	0x38
#define PRIME9 	0x89 
#define PRIME10 0x21 
#define PRIME11 0x84 

#define PRIME12 0x0A 
#define PRIME13 0xB3 
#define PRIME14 0x4F 
#define PRIME15 0x64 

#define GENERATOR0 0x02
#define GENERATOR1 0x00
#define GENERATOR2 0x00
#define GENERATOR3 0x00

#define KEY_SIZE 16
#define PRESHAREDKEY_SIZE 24
#define UNUSED_PIN 0 // For random seed

#include <Arduino.h>

#define SERIAL_DEBUG 1

class DH {
	public:
	  DH();
	  uint32_t mul_mod_p(uint32_t a, uint32_t b, uint32_t P);
	  uint32_t pow_mod_p(uint32_t a, uint32_t b, uint32_t P);
	  uint32_t pow_mod_p2(uint32_t a, uint32_t b, uint32_t P);
	  uint32_t randomInt32();
    void getSessionKey(uint8_t* neighborPublic);
	  void sendDHA(uint8_t* publicKey);
	  uint8_t session_private_key[KEY_SIZE];

    #if SERIAL_DEBUG
	    void printSessionKey();
    #endif
};

#endif