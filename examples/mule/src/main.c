#include <tice.h>
#include <stdlib.h>
#include <graphx.h>
#include <keypadc.h>

#include "gfx/gfx.h"

// game vars
int level = 0; // 0 = beginner 1 = tournament
int planeteers = 0; // 0 = 1 (only one for now)


void drawMule(gfx_sprite_t *sprite, int x, int y) {
	gfx_GetSprite(mule_behind, x, y);
	gfx_TransparentSprite(sprite, x, y);
}

/* Main function, called first */
int main(void)
{	
	int x = -100;
	int y = 100;
	bool moving = true;
	bool flip = true;
	bool sprite2 = false;
	
	os_ClrHome();
	
	// background
	gfx_Begin();
	gfx_SetPalette(global_palette, sizeof_global_palette, 0);
	
	/* EA LOGO */
	gfx_FillScreen(1); // fill with grey
	gfx_Sprite(ea_logo, 50, 65);
	delay(2000);

	/* MULE SCREEN */
	gfx_FillScreen(230); // fill with yellow
	gfx_SetTextFGColor(2);
	gfx_SetTextScale(4, 4);
	gfx_PrintStringXY("M.U.L.E.", 75, 40);
	gfx_SetTextScale(1, 1);
	gfx_PrintStringXY("TI84+CE EDITION", 95, 72);
	gfx_PrintStringXY("COPYRIGHT (C) 2021 - CEMETECH.NET", 40, 200);
	gfx_PrintStringXY("REMAKE BY KNIGHTSWHOSAYNI", 60, 220);

	/* MULE ANIMATION */
	drawMule(mule, x, y);

    while (!os_GetCSC()) {
		if (x == 312) {
			moving = false;
			continue;
		}
		
		gfx_Sprite(mule_behind, x, y);

		if (flip) {
			x = x + 5;
			sprite2 = !sprite2;
		}
		flip = !flip;

		if (!sprite2) {
			drawMule(mule, x, y);
		} else {
			drawMule(mule2, x, y);
		}
		
		if (kb_On) { // e stop
			gfx_End();
			return 0;
		}

		delay(100);
	}

	gfx_FillScreen(230); // fill with yellow
	gfx_SetTextFGColor(2);
	gfx_SetTextScale(4, 4);
	gfx_PrintStringXY("M.U.L.E.", 75, 40);
	gfx_SetTextScale(1, 1);
	gfx_PrintStringXY("PRESS 2ND TO CHANGE LEVEL OF PLAY", 40, 140);
	gfx_PrintStringXY("PRESS ALPHA TO CHANGE NUMBER OF PLAYERS", 20, 180);
	gfx_PrintStringXY("PRESS ENTER TO CONTINUE", 70, 220);
	gfx_SetTextFGColor(3);

	while (true) {
		switch (level) {
			case 0:
				gfx_PrintStringXY("BEGINNER", 130, 160);
				break;
			
			case 1:
				gfx_PrintStringXY("TOURNAMENT", 125, 160);
				break;
		}

		switch (planeteers) {
			case 0:
				gfx_PrintStringXY("1 PLANETEER", 120, 200);
				break;
			case 1:
				gfx_PrintStringXY("2 PLANETEERS", 118, 200);
				break;
		}

		if (kb_Data[1] & kb_2nd) {
			if (level != 1) {
				level++;
			} else {
				level = 0;
			}
		}

		if (kb_Data[2] & kb_Alpha) {
			if (planeteers != 1) {
				planeteers++;
			} else {
				planeteers = 0;
			}
		}

		if (kb_Data[6] & kb_Enter) {
			continue;
		}

		if (kb_On) { // e stop
			gfx_End();
			return 0;
		}
	}

	delay(1000);

	gfx_End();
    return 0;
}