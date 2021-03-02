#include <osbind.h>
#include"types.h"
#include<stdlib.h>
#include"PSG.H"

volatile char * const PSG_reg_select = 0xFF8800;
volatile char * const PSG_reg_write = 0xFF8802;

void write_psg(int reg, UINT8 val)
{
	/* CHECK VALUES*/
	long old_ssp;
	old_ssp = Super(0);
	
	*PSG_reg_select= reg;
	*PSG_reg_write = val;
	
	Super(old_ssp);
}

UINT8 read_psg(int reg)
{
	UINT8 returnVal;
	long old_ssp;
	old_ssp = Super(0);
	*PSG_reg_select = reg;
	returnVal = *PSG_reg_select;
	Super(old_ssp);
	return returnVal;
}
void set_tone(int channel, int tuning)
{
	UINT8 rough = (tuning & 0xF00) >> 8;
	UINT8 fine = tuning & 0x0FF;
	
	if(channel == 0) /* a channel */
	{
		/* 0 1  need first 8 bits of tuning for reg 0, need last 8 bits for reg 1*/
		write_psg(0, fine);
		write_psg(1, rough);
	}
	else if(channel == 1) /* b channel */
	{
		/* 2 3 */
		write_psg(2, fine);
		write_psg(3, rough);
	}
	else
	{
		/* 4 5 */
		write_psg(4, fine);
		write_psg(5, rough);
	}
}
void set_volume(int channel, int volume)
{
	/* CHECK VALUES*/
	if(channel == 0)
	{
		write_psg(8, volume);
	}
	else if(channel == 1)
	{
		write_psg(9, volume);
	}
	else
	{
		write_psg(10, volume);
	}
}
void enable_channel(int channel, int tone_on, int noise_on)
{
	int reg = 7;
	/* CHECK VALUES*/
	if(tone_on == 1 && noise_on == 0)
	{
		write_psg(reg, 0xFF);
	}
	
	if(channel == 0) /* a channel */
	{
		if(tone_on == 1 && noise_on == 1)
		{
			write_psg(reg, 0x36);
		}
		else if(tone_on == 1)
		{
			write_psg(reg, 0x3E);
		}
		else
		{
			write_psg(reg, 0x27);
		}
	}
	else if(channel == 1)
	{
		if(tone_on == 1 && noise_on == 1)
		{
			write_psg(reg, 0x2D);
		}
		else if(tone_on == 1)
		{
			write_psg(reg, 0x3D);
		}
		else
		{
			write_psg(reg, 0x2F);
		}
	}
	else
	{
		if(tone_on == 1 && noise_on == 1)
		{
			write_psg(reg, 0x1B);
		}
		else if(tone_on == 1)
		{
			write_psg(reg, 0x3B);
		}
		else
		{
			write_psg(reg, 0x17);
		}
	}
}
void stop_sound()
{
	write_psg(8, 0);
	write_psg(9, 0);
	write_psg(10, 0);
}
void set_noise(int tuning)
{
	write_psg(6, tuning);
} 
void set_envelope(int shape, unsigned int sustain)
{
	UINT8 roughSustain = sustain & 0x00FF;
	UINT8 fineSustain = (sustain & 0xFF00) >> 8;
	
	write_psg(11, fineSustain);
	write_psg(12, roughSustain);
	write_psg(13, shape);
}
