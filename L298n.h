#include <Arduino.h>
extern "C" {
	#include <inttypes.h>
}

class L298n 
{
	public:
		uint8_t pwma, fora, reva;
		uint8_t pwmb, forb, revb;
		L298n(
			uint8_t pwma, uint8_t fora, uint8_t reva, 
			uint8_t pwmb, uint8_t forb, uint8_t revb
		);
		void set(int16_t dutya, int16_t dutyb);
		void set_freq(int freq);
};