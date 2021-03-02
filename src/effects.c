#include"effects.h"

void ding()
{
	set_tone(2, 0xF8);
	enable_channel(2, 1, 0);
	set_volume(2, 0x10);
	set_envelope(0x00, 0x38);
}

void play_nextLevel()
{
	set_noise(0xAA);
	enable_channel(2, 0, 1);
	set_volume(0, 0x10);
	set_volume(1, 0x10);
	set_volume(2, 0x10);
	set_envelope(0x00, 0x42);
}

void play_gunshot()
{
	set_noise(0x0F);
	enable_channel(2, 0, 1);
	set_volume(0, 0x10);
	set_volume(1, 0x10);
	set_volume(2, 0x10);
	set_envelope(0x00, 0x10);
}


