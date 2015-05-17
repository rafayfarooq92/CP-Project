/*************************Allegro Main Class***********************************/
#include <allegro.h>
class stageClass{
      public:
/********************Creating Buufer for Image Processing**********************/
            BITMAP *buffer ;
	        SAMPLE *gameOver;
/********************Creating Sample for Sound Processing**********************/
            SAMPLE *winningSound;
	        SAMPLE *backGroundMusic;
	        SAMPLE *Shorter;
	        
			int scoreCounter;
	        int SecondStage(int scoreCounter);
            int ThirdStage(int scoreCounter);
            int FirstStage();
            int mainScreenFunction();
/******************Defualt Constructor****************************************/
			stageClass(){
                         buffer = create_bitmap(820, 520);
                         scoreCounter=500;
	                     gameOver=load_sample("Images/gameOver.wav");
	                     winningSound=load_sample("Images/wining.wav");
	                     backGroundMusic=load_sample("Images/beyond.wav");
	                     Shorter=load_sample("Images/looking.wav");
	        
                         }
            };
