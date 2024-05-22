#include "L298n.h"

L298n::L298n (
	uint8_t pwma, uint8_t fora, uint8_t reva, 
	uint8_t pwmb, uint8_t forb, uint8_t revb
) {
	this->pwma = pwma;
	this->fora = fora;
	this->reva = reva;
	this->pwmb = pwmb;
	this->forb = forb;
	this->revb = revb;

	pinMode(pwma, OUTPUT);
	pinMode(fora, OUTPUT);
	pinMode(reva, OUTPUT);
	pinMode(pwmb, OUTPUT);
	pinMode(forb, OUTPUT);
	pinMode(revb, OUTPUT);

	analogWriteFrequency(pwma, 800);
	analogWriteFrequency(pwmb, 800);
}

void L298n::set(int16_t dutya, int16_t dutyb) {
	if (dutya >= 0) {
		digitalWrite(this->fora, HIGH);
		digitalWrite(this->reva, LOW);
		analogWrite(this->pwma, dutya);
	} else {
		digitalWrite(this->fora, LOW);
		digitalWrite(this->reva, HIGH);
		analogWrite(this->pwma, -dutya);
	}

	if (dutyb >= 0) {
		digitalWrite(this->forb, HIGH);
		digitalWrite(this->revb, LOW);
		analogWrite(this->pwmb, dutyb);
	} else {
		digitalWrite(this->forb, LOW);
		digitalWrite(this->revb, HIGH);
		analogWrite(this->pwmb, -dutyb);
	}
}

void L298n::set_freq(int freq) {
	analogWriteFrequency(pwma, freq);
	analogWriteFrequency(pwmb, freq);
}