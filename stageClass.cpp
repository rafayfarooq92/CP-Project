#include<allegro.h>
#include "stageClass.h"
using namespace std;
/****************************Third Stage Function*****************************/
int stageClass::ThirdStage(int scoreCounter){
    int counterForBox=0;
	int stage3=3;
	
	FONT *digital=load_font("digital.pcx",NULL,NULL);
	
	BITMAP *stage1=load_bitmap("Images/one.bmp",NULL);
	BITMAP *tile=load_bitmap("Images/black.bmp",NULL);
	BITMAP *box=load_bitmap("Images/box.bmp",NULL);
	BITMAP *boxw=load_bitmap("Images/box2.bmp",NULL);
	
	FONT *installedFont=load_font("myFont.pcx",NULL,NULL);
	
	float array[29][2]={(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0)};
	
	blit(stage1,buffer,0,0,0,0,820,520);
    blit(box,buffer,0,0,313,311,44,48);
    
    masked_blit(tile,stage1,0,0,313,311+24+4,44,24);
    masked_blit(buffer,screen,0,0,0,0,820,520);
   	int i=0,j=0;
   	int counterForBlock=0;
   	int counterForSpecialTile=0,positionX=200;
   	
   	float boxX=313,boxY=311;
   	
   	bool boolOper=false;
   	float animationX=0, animationY=0;
   	
	array[0][0]=313, array[0][1]=311;
	while(!key[KEY_E]){
                         //End of Function without Winnning
                         if(boxX==435 && boxY==281 &&counterForBox==26){
                         rest(500);
                         return 1;
                         }
                         //End of Function Successfully
                         
                         if(boxX==435 && boxY==281 && counterForBox==28)
						 {
                                      play_sample(winningSound, 511, 128, 1000, false);
                              
                                      textout_ex(screen,digital," Congrates You Won.",270,200,makecol(255,0,128),-1);
                                      textout_ex(screen,installedFont," Your High Score.",140,225,makecol(255,0,128),-1);
                                      textprintf_ex(screen, installedFont, 380, 270, makecol(250,220,210),-1,"%d", scoreCounter);
                                      
                                      textout_ex(screen,digital," Press any key (except E) and then Arrow key to move Back.",100,325,makecol(255,0,128),-1);
                                      readkey();
                                      stop_sample(backGroundMusic);  
                                      return mainScreenFunction();
                        }
                         //Condition For Loosing Game
                         if(boxX>=280 && boxX<=285 && boxY >=315 && boxY<=321 || boxX>=280+13.2 && boxX<=285+13.2 && boxY >=315+16.2 && boxY<=321+16.2||boxX>=337 && boxX<=343 && boxY >=340 && boxY<=345|| boxX>=337+30.5 && boxX<=343+30.5 && boxY >=340-7.5 && boxY<=345-7.5 ||boxX>=337+61 && boxX<=343+61 && boxY >=340-15 && boxY<=345-15||boxX>=337+92 && boxX<=343+92 && boxY >=340-23 && boxY<=345-23||boxX>=337+122 && boxX<=343+122 && boxY >=340-30 && boxY<=345-30||boxX>=337+152.5 && boxX<=343+152.5 && boxY >=340-37.5 && boxY<=345-37.5||boxX>=337+183 && boxX<=343+183 && boxY >=340-45 && boxY<=345-45||boxX>=337+213.5 && boxX<=343+213.5 && boxY >=340-52.5 && boxY<=345-52.5||boxX>=337+230.8 && boxX<=343+230.8 && boxY >=340-76.2 && boxY<=345-76.2||boxX>=337+217.6 && boxX<=343+217.6 && boxY >=340-92.4 && boxY<=345-92.4||boxX>=337+174 && boxX<=343+174 && boxY >=340-101 && boxY<=345-101||boxX>=337+160.8 && boxX<=343+160.8 && boxY >=340-117 && boxY<=345-117||boxX>=337+147.6 && boxX<=343+147.6 && boxY >=340-133.2 && boxY<=345-133.2||boxX>=337+104 && boxX<=343+104 && boxY >=340-141.9 && boxY<=345-141.9 ||boxX>=337+73.5 && boxX<=343+73.5 && boxY >=340-134.4 && boxY<=345-134.4 ||boxX>=337+43 && boxX<=343+43 && boxY >=340-126.9 && boxY<=345 -126.9||boxX>=337+25.7 && boxX<=343+25.7 && boxY >=340-103.2 && boxY<=345-103.2||boxX>=337-4.8 && boxX<=343-4.8 && boxY >=340-95.7 && boxY<=345-95.7||boxX>=337-22.1 && boxX<=343-22.1 && boxY >=340-72 && boxY<=345-72||boxX>=337-8.9 && boxX<=343-8.9 && boxY >=340-55.8 && boxY<=345-55.8 ||boxX>=337-39.4 && boxX<=343-39.4 && boxY >=340-48.3 && boxY<=345-48.3 ||boxX>=337+82.7 && boxX<=343+82.7 && boxY >=340-78.3 && boxY<=345-78.3)
						 {
                              masked_blit(boxw,buffer,0,0,boxX,boxY,44,48);
                              masked_blit(buffer,screen,0,0,0,0,820,520);
   	                          
						      play_sample(gameOver, 511, 128, 2000, false);
                              scoreCounter=scoreCounter-20;
                              
							  textout_ex(screen,digital,"GAME OVER..!",350,175,makecol(255,0,128),-1);
                              textout_ex(screen,digital,"Press 'S' To Start Again. ",300,200,makecol(255,0,128),-1);
                              textout_ex(screen,digital,"Or AnyOther Key To Exit.",300,225,makecol(255,0,128),-1);
                              
                              readkey();
                              
							  if(key[KEY_S])
			  				            //Returning to Mian Funciton
							            {
                                        return ThirdStage(scoreCounter);
                                        }
                                        else
										{
                                        return 0;
                                        }
	                      }
                         
                         
                         if(boxX>420 && boxX<425 && boxY>260 && boxY<267)
						 {
                                           rest(1000);      
                                           return 1;
                         } 
                         
                         readkey();
                         
                         play_sample(Shorter, 400, 128, 1000, false);
                         
                         if(key[KEY_UP]){
                                         boxX=boxX-13.2;
                                         boxY=boxY-16.2;
                                         }
                         if(key[KEY_DOWN]){
                                         boxX=boxX+13.2;
                                         boxY=boxY+16.2;
                                           
                                         }
                         if(key[KEY_RIGHT]){
                                         boxX=boxX+30.5;
                                         boxY=boxY-7.5;
                                         
                                         }
                         if(key[KEY_LEFT]){
                                         boxX=boxX-30.5;
                                         boxY=boxY+7.5;
                                         }
                         if(key[KEY_UP]|| key[KEY_DOWN]||key[KEY_RIGHT] || key[KEY_LEFT]){
                                          counterForBox++;
                                          }
                         for(int k=0;k<i;k++)
                         {       
                                 if(array[k][0]==boxX && array[k][1]==boxY )
								 {
                                 play_sample(gameOver, 511, 128, 1000, false);
                                 scoreCounter=scoreCounter-20;
                                 textout_ex(screen,digital,"GAME OVER..!",350,175,makecol(255,0,128),-1);
                                 textout_ex(screen,digital,"Press 'S' To Start Again.",300,200,makecol(255,0,128),-1);
                                 textout_ex(screen,digital,"Or AnyOther Key To Exit.",300,225,makecol(255,0,128),-1);
                                 readkey();
                                 if(key[KEY_S]){
                                        return ThirdStage(scoreCounter);
                                               }
                                        else{
                                        stop_sample(backGroundMusic);     
                                        return 0;
                                            }
                                 }
                         }
                         if(!(boxX>=467 && boxX<=471 && boxY>=228 && boxY<=235))
						 {
                         i++;
                         array[i][j]=boxX;                
                         j++;
                         array[i][j]=boxY;                
                         j=0;
                         }
                         
						 masked_blit(stage1,buffer,0,0,0,0,820,640);
                         
						 if(boxX>=467 && boxX<=471 && boxY>=228 && boxY<=235)
						 			  	 		   	  			{
                                                                counterForSpecialTile++;
                                                                }
                         if((boxX!=435 && boxY!=281)&&(!( boxX>=467 && boxX<=471 && boxY>=228 && boxY<=235 && counterForSpecialTile!=2)))
						 {
                         masked_blit(tile,stage1,0,0,boxX,boxY+24+4,44,24);
                         }
                         textout_ex(buffer,digital,"Stage 3/3",10,10,makecol(50,220,210),-1);
                         textprintf_ex(buffer, digital, 150, 10, makecol(50,220,210),-1,"Score:%d", scoreCounter);
                         textout_ex(buffer,digital,"Press E and Then Arrow key to Exit",400,10,makecol(150,220,210),-1);
                         textprintf_ex(buffer, digital, 300, 10, makecol(50,220,210),-1,"Moves:%d", counterForBox);
    
                         masked_blit(box,buffer,0,0,boxX,boxY,44,48);
                         if(boxX==435 && boxY==281 && (counterForBox<28 ||counterForBox>28)  ){
                                      textout_ex(buffer,digital,"You Need to move",350,175,makecol(255,0,128),-1);
                                      textout_ex(buffer,digital," Acoss All Boxes.",350,200,makecol(255,0,128),-1);
                                      }
                         
                         blit(buffer,screen,0,0,0,0,820,640);
	                     rest(10);                     
                         }//End of While
	
	
    readkey();
	
	destroy_bitmap(buffer);
	
	return 0;
    
    
    
    }


/*************************************Secon Stage Function********************/
int stageClass::SecondStage(int scoreCounter)
{
	int counterForBox=0;
	int stage3=3;
	
	FONT *digital=load_font("digital.pcx",NULL,NULL);
	
	BITMAP *stage1=load_bitmap("Images/FirstStage.bmp",NULL);
	BITMAP *tile=load_bitmap("Images/black.bmp",NULL);
	BITMAP *box=load_bitmap("Images/NewBox.bmp",NULL);
	BITMAP *boxw=load_bitmap("Images/NewBox2.bmp",NULL);
	
	FONT *installedFont=load_font("myFont.pcx",NULL,NULL);
	
	float array[17][2]={(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0)};
	
	blit(stage1,buffer,0,0,0,0,820,520);
    blit(box,buffer,0,0,302,218,46,62);
    masked_blit(tile,stage1,0,0,302,218+24+4,44,24);
    masked_blit(buffer,screen,0,0,0,0,820,520);
    
   	float boxX=302,boxY=218;
   	int i=0,j=0;
   	
   	array[0][0]=302, array[0][1]=218;
	while(!key[KEY_E])
	{
                         
                         if(boxX>=371 && boxX<=381 &&counterForBox==16&& boxY>=251 && boxY<=261)
						 {
                         play_sample(winningSound, 255, 128, 1000, false);
                         textout_ex(screen,digital,"You WON..!",350,125,makecol(255,0,128),-1);
                         textout_ex(screen,digital,"Taking To Next Level",300,150,makecol(255,0,128),-1);
                         rest(1000);
                         //Calling for Third Stage
                         return ThirdStage(scoreCounter);
                         }
                         if(boxX>=302-14.7-4 && boxX<=302-14.7+4 && boxY>=218-15.2-4 &&boxY<=218-15.2+4||boxX>=302-14.7-4+30.75 && boxX<=302-14.7+4+30.75 && boxY>=218-15.2-4-7.25 &&boxY<=218-15.2+4-7.25||boxX>=302-14.7-4+61.5 && boxX<=302-14.7+4+61.5 && boxY>=218-15.2-4-14.5 &&boxY<=218-15.2+4-14.5||boxX>=302-14.7-4+30.75+61.5 && boxX<=302-14.7+4+30.75+61.5 && boxY>=218-15.2-4-7.25-14.5 &&boxY<=218-15.2+4-7.25-14.5||boxX>=302-4+123 && boxX<=302+4+123 && boxY>=218-4-29 &&boxY<=218+4-29||boxX>=302-4+123+14.7 && boxX<=302+4+123+14.7 && boxY>=218-4-29+15.2 &&boxY<=218+4-29+15.2||boxX>=302-4+123+29.4 && boxX<=302+4+123+29.4 && boxY>=218-4-29+30.4 &&boxY<=218+4-29+30.4||boxX>=302-4+123+29.4+14.7 && boxX<=302+4+123+29.4+14.7 && boxY>=218-4-29+30.4+15.2 &&boxY<=218+4-29+30.4+15.2||boxX>=302-4+123+59 && boxX<=302+4+123+59 && boxY>=218-4-29+60.8 &&boxY<=218+4-29+60.8||boxX>=302-4+123+59+14.7-30.75 && boxX<=302+4+123+59+14.7-30.75 && boxY>=218-4-29+60.8+15.2+7.25 &&boxY<=218+4-29+60.8+15.2+7.25||boxX>=302-4+123+59+14.7-61.5 && boxX<=302+4+123+59+14.7-61 && boxY>=218-4-29+60.8+15.2+14.5 &&boxY<=218+4-29+60.8+15.2+14.5||boxX>=302-4+123+59+14.7-92 && boxX<=302+4+123+59+14.7-92 && boxY>=218-4-29+60.8+15.2+21.75 &&boxY<=218+4-29+60.8+15.2+21.75||boxX>=302-4+123+59+14.7-123 && boxX<=302+4+123+59+14.7-123 && boxY>=218-4-29+60.8+15.2+29 &&boxY<=218+4-29+60.8+15.2+29||boxX>=302-4+123+59-153.2 && boxX<=302+4+123+59-153.25 && boxY>=218-4-29+60.8+36.25 &&boxY<=218+4-29+60.8+36.25||boxX>=302-4+123+45-153.2 && boxX<=302+4+123+45-153.25 && boxY>=218-4-29+45.8+36.25 &&boxY<=218+4-29+45.8+36.25||boxX>=302-4+123+29.5-153.2 && boxX<=302+4+123+29.5-153.25 && boxY>=218-4-29+30.4+36.25 &&boxY<=218+4-29+30.4+36.25||boxX>=302-4+123+14.7-153.2 && boxX<=302+4+123+14.7-153.25 && boxY>=218-4-29+15.2+36.25 &&boxY<=218+4-29+15.2+36.25||boxX>=302-4+123-153.2 && boxX<=302+4+123-153.25 && boxY>=218-4-29+36.25 &&boxY<=218+4-29+36.25||boxX>=302-4+14.7 && boxX<=302+14.7+4 && boxY>=218+15.2-4 &&boxY<=218+15.2+4||boxX>=302-4+14.7+30.75 && boxX<=302+14.7+4+30.75 && boxY>=218+7.2-4 &&boxY<=218+7.2+4||boxX>=302-4+14.7+61 && boxX<=302+14.7+4+61 && boxY>=218-4 &&boxY<=218+4)
						 {
                         masked_blit(boxw,buffer,0,0,boxX,boxY,44,48);
                         masked_blit(buffer,screen,0,0,0,0,820,520);
   	                     play_sample(gameOver, 511, 128, 1000, false);
                         //Decrementing Score
						 scoreCounter=scoreCounter-20;
						 
                         textout_ex(screen,digital,"GAME OVER..!",350,175,makecol(255,0,128),-1);
                         textout_ex(screen,digital,"Press 'S' To Start Again.",300,200,makecol(255,0,128),-1);
                         textout_ex(screen,digital,"Or AnyOther Key To Exit.",300,225,makecol(255,0,128),-1);
                         readkey();
                         
						 if(key[KEY_S]){
						 				//Second Stage Calling
                                        return SecondStage(scoreCounter);
                                        }
                         else	{
                         return 0;
                         		}
                         }	
                  
                         readkey();
                         
                         play_sample(Shorter, 400, 128, 1000, false);
                         
						 if(key[KEY_UP]){
                                         boxX=boxX-14.7;
                                         boxY=boxY-15.2;
                                         }
                         if(key[KEY_DOWN]){
                                         boxX=boxX+14.7;
                                         boxY=boxY+15.2;
                                           
                                         }
                         if(key[KEY_RIGHT]){
                                         boxX=boxX+30.75;
                                         boxY=boxY-7.25;
                                         
                                         }
                         if(key[KEY_LEFT]){
                                         boxX=boxX-30.75;
                                         boxY=boxY+7.25;
                                         }
                         if(key[KEY_UP]|| key[KEY_DOWN]||key[KEY_RIGHT] || key[KEY_LEFT]){
                                          counterForBox++;
                                          }
                         for(int k=0;k<i;k++)
                         {       
                                 if(array[k][0]==boxX && array[k][1]==boxY)
								 {
                                 play_sample(gameOver, 511, 128, 1000, false);
                                 scoreCounter=scoreCounter-20;
                                 textout_ex(screen,digital,"GAME OVER..!",350,175,makecol(255,0,128),-1);
                                 textout_ex(screen,digital,"Press 'S' To Start Again.",300,200,makecol(255,0,128),-1);
                                 textout_ex(screen,digital,"Or AnyOther Key To Exit.",300,225,makecol(255,0,128),-1);
                                 readkey();
                                 if(key[KEY_S]){
                                        return SecondStage(scoreCounter);
                                               }
                                        else	{
                                        return 0;
                                        	    }
						       }
                         }              
                         i++;
                         array[i][0]=boxX;                
			             array[i][1]=boxY;                

                                         
                         masked_blit(stage1,buffer,0,0,0,0,820,640);
                         if(!(boxX>=373 && boxX<=379 && boxY>=253 && boxY<=259))
						 {
                         masked_blit(tile,stage1,0,0,boxX,boxY+24+4,44,24);
    		             }
						/*Formatted text output, using a printf() style format string. 
						Due to an internal limitation,this function can't be used for extremely long texts. */														  
                         textout_ex(buffer,digital,"Stage 2/3",10,10,makecol(50,220,210),-1);
                         textprintf_ex(buffer, digital, 150, 10, makecol(50,220,210),-1,"Score:%d", scoreCounter);
                         textout_ex(buffer,digital,"Press E and Then Arrow key to Exit",400,10,makecol(150,220,210),-1);
                         textprintf_ex(buffer, digital, 300, 10, makecol(50,220,210),-1,"Moves:%d", counterForBox);
    
                         masked_blit(box,buffer,0,0,boxX,boxY,46,62);
                         if(boxX>=373 &&boxX<=379&& boxY>=253&& boxY<=259 && counterForBox<16)
						 {
                                      textout_ex(buffer,digital,"You Need to move",350,175,makecol(255,0,128),-1);
                                      textout_ex(buffer,digital," Acoss All Boxes.",350,200,makecol(255,0,128),-1);
 				         }
                         
                         blit(buffer,screen,0,0,0,0,820,640);
	                     rest(10);                     
	                                          
    }//End of While Loop
	
	
    readkey();
	
	destroy_bitmap(buffer);
	
	return 0;
}
/******************************First Stage Function Calling**********************/
int stageClass::FirstStage(){
    
    FONT *digital=load_font("digital.pcx",NULL,NULL);
	BITMAP *stage1=load_bitmap("Images/St1.bmp",NULL);
	BITMAP *tile=load_bitmap("Images/black.bmp",NULL);
	BITMAP *box=load_bitmap("Images/box.bmp",NULL);
	BITMAP *boxw=load_bitmap("Images/box2.bmp",NULL);
	
	FONT *installedFont=load_font("myFont.pcx",NULL,NULL);
	
	static int scoreCounter=500;
    int counterForBox=0;
    
    float array[12][2]={(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0)};
	
	blit(stage1,buffer,0,0,0,0,820,520);
    blit(box,buffer,0,0,116,304,44,48);
    masked_blit(tile,stage1,0,0,116,304+24+4,44,24);
    masked_blit(buffer,screen,0,0,0,0,820,520);
   	
 	float boxX=116,boxY=304;
   	int i=0,j=0;
   	
  	array[0][0]=116;array[0][1]=304;
   	                
	while(!key[KEY_E]){
                         //Conditions for Game Over
                         if(boxX>=385 && boxX<=395 &&counterForBox==11 && boxY>=228 && boxY<=243){
                         play_sample(winningSound, 255, 128, 1000, false);
                         //Writes the string `s' onto the bitmap at position x, y, using the specified font, 
						 //foreground color and background color.
 						 //If the background color is -1, then the text is written transparently     
                         textout_ex(screen,digital,"You WON..!",350,125,makecol(255,0,128),-1);
                         textout_ex(screen,digital,"Taking To Next Level",300,150,makecol(255,0,128),-1);
                         rest(1000);
                         //Calling for Second Stage
						 return SecondStage(scoreCounter);
                         }
                         if(boxX>=80 && boxX<=90 && boxY>=306 && boxY<=316||boxX>=97 && boxX<=107 && boxY>=282 && boxY<=292||boxX>=125 && boxX<=135 && boxY>=315 && boxY<=325||boxX>=128 && boxX<=138 && boxY>=275 && boxY<=285||boxX>=155 && boxX<=165 && boxY>=308 && boxY<=315||boxX>=158 && boxX<=168 && boxY>=268 && boxY<=275||boxX>=185 && boxX<=195 && boxY>=300 && boxY<=310||boxX>=190 && boxX<=200 && boxY>=260 && boxY<=270||boxX>=235 && boxX<=242 && boxY>=270 && boxY<=280||boxX>=230 && boxX<=235 && boxY>=310 && boxY<=315||boxX>=265 && boxX<=271 && boxY>=262 && boxY<=270||boxX>=290 && boxX<=300 && boxY>=295 && boxY<=302||boxX>=321 && boxX<=329 && boxY>=285 && boxY<=295||boxX>=280 && boxX<=290 && boxY>=238 && boxY<=245||boxX>=280+30.5 && boxX<=290+30.5 && boxY>=238-7.5 && boxY<=245-7.5||boxX>=280+61 && boxX<=290+61 && boxY>=238-15 && boxY<=245-15||boxX>=337&& boxX<=347&&boxX>=262 && boxY<=272||boxX>=337+30.5&& boxX<=347+30.5&&boxX>=262-7.5 && boxY<=272-7.5||boxX>=337+30.5&& boxX<=347+30.5&&boxX>=262-7.5 && boxY<=272-7.5)
						 {
                         masked_blit(boxw,buffer,0,0,boxX,boxY,44,48);
                         masked_blit(buffer,screen,0,0,0,0,820,520);
   	                     play_sample(gameOver, 511, 128, 1000, false);
                         //-20 detect from Score for one Miss
						 scoreCounter=scoreCounter-20;
                         
						 textout_ex(screen,digital,"GAME OVER..!",350,175,makecol(255,0,128),-1);
                         textout_ex(screen,digital,"Press 'S' To Start Again.",300,200,makecol(255,0,128),-1);
                         textout_ex(screen,digital,"Or AnyOther Key To Exit.",300,225,makecol(255,0,128),-1);
                         readkey();
                         if(key[KEY_S]){
                                        return FirstStage();
                                        }
                         else	{
                         return 0;
                         		}
                         }
                         readkey();
                         
                         play_sample(Shorter, 400, 128, 1000, false);
                    
                         if(key[KEY_UP]){
                                         boxX=boxX-13.2;
                                         boxY=boxY-16.2;
                                         }
                         if(key[KEY_DOWN]){
                                         boxX=boxX+13.2;
                                         boxY=boxY+16.2;
                                           
                                         }
                         if(key[KEY_RIGHT]){
                                         boxX=boxX+30.5;
                                         boxY=boxY-7.5;
                                         
                                         }
                         if(key[KEY_LEFT]){
                                         boxX=boxX-30.5;
                                         boxY=boxY+7.5;
                                         }
                         if(key[KEY_UP]|| key[KEY_DOWN]||key[KEY_RIGHT] || key[KEY_LEFT]){
                                          counterForBox++;
                                          }
                                 for(int k=0;k<i;k++)
                                 {       
                                 if(array[k][0]==boxX && array[k][1]==boxY){
                                 play_sample(gameOver, 511, 128, 1000, false);
                                 scoreCounter=scoreCounter-20;
                                 textout_ex(screen,digital,"GAME OVER..!",350,175,makecol(255,0,128),-1);
                                 textout_ex(screen,digital,"Press 'S' To Start Again.",300,200,makecol(255,0,128),-1);
                                 textout_ex(screen,digital,"Or AnyOther Key To Exit.",300,225,makecol(255,0,128),-1);
                                 readkey();
                                 
                                 if(key[KEY_S])
								 			   {
                                        return FirstStage();
                                        	   }
                                        else	{
                                        return 0;
                                        	   }
                                        	   	 			   				}
							     }              
                         i++;
                         array[i][j]=boxX;                
                         j++;
                         array[i][j]=boxY;                
                         j=0;
                         
                         
                         masked_blit(stage1,buffer,0,0,0,0,820,640);
                         if(boxX!=435 && boxY!=281){
                         masked_blit(tile,stage1,0,0,boxX,boxY+24+4,44,24);
                                                                           }
                         textout_ex(buffer,digital,"Stage 1/3",10,10,makecol(50,220,210),-1);
                         textprintf_ex(buffer, digital, 150, 10, makecol(50,220,210),-1,"Score:%d", scoreCounter);
                         textout_ex(buffer,digital,"Press E and Then Arrow key to Exit",400,10,makecol(150,220,210),-1);
                         textprintf_ex(buffer, digital, 300, 10, makecol(50,220,210),-1,"Moves:%d", counterForBox);
    
                         masked_blit(box,buffer,0,0,boxX,boxY,44,48);
                         if(boxX>=385 && boxX<=395 &&(counterForBox<11||counterForBox>11) && boxY>=231 && boxY<=241){
                                      textout_ex(buffer,digital,"You Need to move",350,175,makecol(255,0,128),-1);
                                      textout_ex(buffer,digital," Acoss All Boxes.",350,200,makecol(255,0,128),-1);
                                      }
                         
                         blit(buffer,screen,0,0,0,0,820,640);
	                     rest(10);                     
	                                          
                         }
	
	
    readkey();
	
	destroy_bitmap(buffer);
	
	return 0;
    }
/*********************************Main Screen Function*******************/
int stageClass::mainScreenFunction(){

/************************Loading images**************************************/
	BITMAP *tutorial=load_bitmap("Images/Tutorials.bmp",NULL);
	BITMAP *startGame=load_bitmap("Images/StartGame.bmp",NULL);
	BITMAP *highScore=load_bitmap("Images/HighScore.bmp",NULL);
	BITMAP *credits=load_bitmap("Images/Credits.bmp",NULL);
	BITMAP *tutImage1=load_bitmap("Images/Tut1.bmp",NULL);
	BITMAP *tutImage2=load_bitmap("Images/tut2.bmp",NULL);
	BITMAP *tutImage3=load_bitmap("Images/tut3.bmp",NULL);
	BITMAP *tutImage4=load_bitmap("Images/tut4.bmp",NULL);
	BITMAP *tutImage5=load_bitmap("Images/tut5.bmp",NULL);
	BITMAP *creditsImage=load_bitmap("Images/gow.bmp",NULL);
	BITMAP *finally=load_bitmap("Images/sc.bmp",NULL);
	
	bool tutorialChecker=false,mainChecker=false;
	int slideCounter=0,tutorialCounter=0;
	/*Triggers a sample at the specified volume, pan position, and frequency. 
	First Parameter:Sound Pointer
	Second and Third Parameter:`vol' and `pan' range from 0 (min/left) to 255 (max/right). 
	Fourth:Frequency= 1000 represents the frequency that the sample was recorded.
	Fifth Parameter:Loop= If `loop' is not zero, the sample will repeat until you call 
	stop_sample(), and can be manipulated while it is playing by calling adjust_sample().*/
	play_sample(backGroundMusic, 200, 128, 1000, true);
    
	  while(mainChecker==false)
    {
                        readkey();
                        if(key[KEY_LEFT])
						{
                                          if(slideCounter!=2)
                                          slideCounter++; 
                                          else if(slideCounter==2)
                                          slideCounter=0; 
                                          if(slideCounter==2) 
                                          {
                                          draw_sprite(buffer,startGame,0, 0);
                                          blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                          readkey();
                                          if(key[KEY_ENTER]){
										  					 //First Stage Calling from where all the
										  					 //rest stage functions will be called
                                                             FirstStage();
                                                             //function to Current Sound
	                                                         stop_sample(backGroundMusic);
	                                                         //main function calling again
                                                             mainScreenFunction();
                                                                                              
                                                             }
                                          }
                                          if(slideCounter==0) 
                                          {
                                          draw_sprite(buffer,credits,0, 0);
                                          blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                          readkey();
                                          if(key[KEY_ENTER]){
                                               while(tutorialChecker==false){
                                                                             draw_sprite(buffer,creditsImage,0, 0);
                                                                             blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                             if(key[KEY_ESC]){
                                                                                              tutorialChecker=true;
                                                                                              clear_bitmap(buffer);
                                                                                              stop_sample(backGroundMusic);
                                                                                              //main function calling again
                                                                                              mainScreenFunction();
                                                                                              }
                                                                             }
                                               
                                               }
                                          }
                                          if(slideCounter==1) 
                                          {
                                          draw_sprite(buffer,tutorial,0, 0);
                                          blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                          readkey();
                                          if(key[KEY_ENTER])
                                          {
                                                            while(tutorialChecker==false)
                                                            {
                                                                              readkey();
                                                                              if(key[KEY_LEFT])
                                                                              {
                                                                                               if(tutorialCounter!=4)
                                                                                               tutorialCounter++; 
                                                                                               else if(tutorialCounter==4)
                                                                                               tutorialCounter=0; 
                                                                                               if(tutorialCounter==2) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage2,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==3) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage3,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==0) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage5,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==1) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage1,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==4)
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage4,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               }
                                                                                if(key[KEY_RIGHT])
                                                                                {
                                                                                               if(tutorialCounter!=4)
                                                                                               tutorialCounter++; 
                                                                                               else if(tutorialCounter==4)
                                                                                               tutorialCounter=0; 
                                                                                               if(tutorialCounter==2) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage2,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==3) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage3,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==0) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage5,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==1) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage1,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==4)
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage4,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                                }                 
                                                                                               if(key[KEY_ESC])
                                                                                               {
                                                                                               tutorialChecker=true;
                                                                                               //stop the current music
                                                                                               stop_sample(backGroundMusic);
                                                                                               clear_bitmap(buffer);
                                                                                               //main function calling again
                                                                                               mainScreenFunction();
                                                                                               
                                                                                               }
                                                                                               }
                                                            
                                                           }
                                          
                                          
                                          
                                          }
                                          
                        }
                        if(key[KEY_RIGHT])
						{
                                          if(slideCounter!=2)
                                          slideCounter++; 
                                          else if(slideCounter==2)
                                          slideCounter=0; 
                                          if(slideCounter==2) 
                                          {
                                          draw_sprite(buffer,startGame,0, 0);
                                          blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                          readkey();
                                          if(key[KEY_ENTER]){
										  					  //First Stage Calling from where all the
										  					 //rest stage functions will be called
                                                             FirstStage();
	                                                         stop_sample(backGroundMusic);
                                                             mainScreenFunction();
                                                             }
                                          }
                                          if(slideCounter==0) 
                                          {
                                          draw_sprite(buffer,credits,0, 0);
                                          blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                        readkey();
                                          if(key[KEY_ENTER]){
                                               while(tutorialChecker==false){
                                                                             draw_sprite(buffer,creditsImage,0, 0);
                                                                             blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                             if(key[KEY_ESC]){
                                                                                              
                                                                                              tutorialChecker=true;
                                                                                              clear_bitmap(buffer);
                                                                                              stop_sample(backGroundMusic);
                                                                                              mainScreenFunction();
                                                                                              }
                                                                             }
                                               
                                               }
                                               }
                                          if(slideCounter==1) 
                                          {
                                          draw_sprite(buffer,tutorial,0, 0);
                                          blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                          readkey();
                                          if(key[KEY_ENTER])
                                          {
                                                            while(tutorialChecker==false)
                                                            {
                                                                              readkey();
                                                                              if(key[KEY_LEFT])
                                                                              {
                                                                                               if(tutorialCounter!=4)
                                                                                               tutorialCounter++; 
                                                                                               else if(tutorialCounter==4)
                                                                                               tutorialCounter=0; 
                                                                                               if(tutorialCounter==2) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage2,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==3) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage3,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==0) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage5,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==1) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage1,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==4)
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage4,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                              }
                                                                                if(key[KEY_RIGHT])
                                                                                {
                                                                                               if(tutorialCounter!=4)
                                                                                               tutorialCounter++; 
                                                                                               else if(tutorialCounter==4)
                                                                                               tutorialCounter=0; 
                                                                                               if(tutorialCounter==2) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage2,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==3) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage3, 175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==0) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage5,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==1) 
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage1,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                               if(tutorialCounter==4)
                                                                                               {
                                                                                               draw_sprite(buffer,tutImage4,175, 150);
                                                                                               blit(buffer, screen, 0, 0, 0, 0, 820, 520);
                                                                                               }
                                                                                                }                 
                                                                                               if(key[KEY_ESC])
                                                                                               {
                                                                                               tutorialChecker=true;
                                                                                               clear_bitmap(buffer);
                                                                                               stop_sample(backGroundMusic);
                                                                                               mainScreenFunction();
                                                                                               }
                                                                                }
                                                            
                                                           }
                                          
                                          
                                          
                                          }
				        }
                                          if(key[KEY_E])
                                          mainChecker=true;//condition for breaking the loop
      }//closing of While Loop
  

     }//closing of Main
