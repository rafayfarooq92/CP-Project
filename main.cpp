#include <allegro.h>
#include "stageClass.h"

int main() 
{	
	allegro_init();
	install_keyboard();
	install_timer();
	set_color_depth(32);
	/*Initializing the sound module.*/
	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
	int score=500;
	int minusScore=-1;
	BITMAP *buffer = create_bitmap(820, 520);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 820, 520, 0, 0);
    BITMAP *poster=load_bitmap("Images/Poster2.bmp",NULL);
	FONT *installedFont=load_font("notComplete.pcx",NULL,NULL); 
    FONT *installedFont2=load_font("myFont.pcx",NULL,NULL);           
	blit(poster,buffer,0,0,0,0,820,640);
	blit(buffer, screen, 0, 0, 0, 0, 820, 640);
    rest(1000);
    textout_ex(screen,installedFont2,"*-Basic Guide.",125,350,makecol(255,0,0),-1);
    textout_ex(screen,installedFont,"*-Press Arrow Key To Move Main Menu",125,400,makecol(255,0,0),-1);
    textout_ex(screen,installedFont,"*-You Will Press",125,425,makecol(255,0,0),-1);
    textout_ex(screen,installedFont," E Multiple TIMES ",288,425,makecol(0,0,255),-1);
    textout_ex(screen,installedFont," any time to EXIT.",490,425,makecol(255,0,0),-1);
    textout_ex(screen,installedFont,"*-You Will Press ENTER to select Menu Items.",125,450,makecol(255,0,0),-1);
    textout_ex(screen,installedFont,"*-To Go To Main Menu Press Any Arrow Key.",125,475,makecol(255,0,0),-1);
    
	stageClass obj;//obejct delcaration
    obj.mainScreenFunction(); //calling main Function from where all the rest will call

    readkey();
	
	destroy_bitmap(buffer); //destroying Dynamic memory allocation
	
	return 0;
}
END_OF_MAIN();
