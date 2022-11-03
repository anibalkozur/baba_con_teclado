
unsigned long previoMillis = 0;
unsigned long valorMillis;
unsigned long unavezMillis = 0;

//Ancho de cuclo de trabajo de pulso a 50 hz de cada servo--------------unsigned int
#define ciclomin1 140 //ancho de pulso para 50 hz en 0°
#define ciclomax1 480 //ancho de pulso para 50hz en 180°
#define ciclomin2 160 //ancho de pulso para 50 hz en 0°
#define ciclomax2 460 //ancho de pulso para 50hz en 180°
#define ciclomin3 160 //ancho de pulso para 50 hz en 0°
#define ciclomax3 490 //ancho de pulso para 50hz en 180°
#define ciclomin4 120 //ancho de pulso para 50 hz en 0°
#define ciclomax4 550 //ancho de pulso para 50hz en 180°
#define ciclomin5 120 //ancho de pulso para 50 hz en 0°
#define ciclomax5 550 //ancho de pulso para 50hz en 180°
#define ciclomin6 120 //ancho de pulso para 50 hz en 0°
#define ciclomax6 550 //ancho de pulso para 50hz en 180°

int VALORPOTJOY1;
int VALORPOTJOY2;
int VALORPOTJOY3;
int VALORPOTJOY4;
int VALORPOTJOY5;
int VALORPOTJOY6;
int POTJOY1 = 8;
int POTJOY2 = 9;
int POTJOY3 = 10;
int POTJOY4 = 11;
int POTJOY5 = 12;
int POTJOY6 = 13;
int mimap1;
int mimap2;
int mimap3;
int mimap4;
int mimap5;
int mimap6;
int ciclo1;
int ciclo2;
int ciclo3;
int ciclo4;
int ciclo5;
int ciclo6;

void Control_Joy(int c,int base, int ANGINI1,int ANGINI2,int ANGINI3,int ANGINI4,int ANGINI5,int ANGINI6){
   
  while(base != PS2_KEY_ESC){
  if(c = keyboard.read()){   
  base = c & 0xFF;  
 // Teclado(c, base);
  }

  VALORPOTJOY1 = analogRead(POTJOY1);          //lee el valor de pote 1 - entrada analogica 0
  VALORPOTJOY2 = analogRead(POTJOY2);          //lee el valor del pote 2 - entrada analogica 1
  VALORPOTJOY3 = analogRead(POTJOY3);          //lee el valor de pote 3 - entrada analogica 2
  VALORPOTJOY4 = analogRead(POTJOY4);          //lee el valor del pote 4 - entrada analogica 3
  VALORPOTJOY5 = analogRead(POTJOY5);          //lee el valor del pote 5 - entrada analogica 6
  VALORPOTJOY6 = analogRead(POTJOY6);          //lee el valor del pote 6 - entrada analogica 7

//ahora iniciamos los movimientos de los servos---------------------
//------------------------------------------------------------------
//base--------------------------------------------------------------
  if (VALORPOTJOY1 < 480){    
   if (valorMillis - previoMillis >= VALORPOTJOY1){
   previoMillis = valorMillis;   
    int MAPANGINI1 = map(VALORPOTJOY1, 480, 0, 1, 5);   
    ANGINI1 = ANGINI1 - MAPANGINI1;
    if (ANGINI1 < 1){
      ANGINI1 = 0;
      } 
    ciclo1 = map(ANGINI1,0,180,ciclomin1,ciclomax1);
    servosx1.setPWM(1,0,ciclo1);
   
   }
    Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
  }
  
  if (VALORPOTJOY1 > 630){
    mimap1 = map(VALORPOTJOY1, 630, 1023, 630, 0);    
    if (valorMillis - previoMillis >= mimap1){
    previoMillis = valorMillis;

    int MAPANGINI1 = map(VALORPOTJOY1, 630, 1023, 1, 5);
    ANGINI1 = ANGINI1 + MAPANGINI1 ;
    if (ANGINI1 > 179){
      ANGINI1 = 180;
      }

    ciclo1 = map(ANGINI1,0,180,ciclomin1,ciclomax1);
    servosx1.setPWM(1,0,ciclo1);
   
  }
  Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
  }
//hombro--------------------------------------------------------------
   if (VALORPOTJOY2 < 480){    
    if (valorMillis - previoMillis >= VALORPOTJOY2){
    previoMillis = valorMillis;
    int MAPANGINI2 = map(VALORPOTJOY2, 480, 0, 1, 5);
    ANGINI2 = ANGINI2 - MAPANGINI2;
    if (ANGINI2 < 1){
      ANGINI2 = 0;
      }
    ciclo2 = map(ANGINI2,0,180,ciclomin2,ciclomax2);
    servosx1.setPWM(2,0,ciclo2);
    }
  Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
  }

  if (VALORPOTJOY2 > 610){
    mimap2 = map(VALORPOTJOY2, 610, 1023, 580, 0);    
    if (valorMillis - previoMillis >= mimap2){
    previoMillis = valorMillis;
    int MAPANGINI2 = map(VALORPOTJOY2, 610, 1023, 1, 5);
    ANGINI2 = ANGINI2 + MAPANGINI2;
    if (ANGINI2 > 179){
      ANGINI2 = 180;
      }
    ciclo2 = map(ANGINI2,0,180,ciclomin2,ciclomax2);
    servosx1.setPWM(2,0,ciclo2);  
    }
  Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
  }
//Codo--------------------------------------------------------------
if (VALORPOTJOY3 < 480){    
    if (valorMillis - previoMillis >= VALORPOTJOY3){
    previoMillis = valorMillis;
    int MAPANGINI3 = map(VALORPOTJOY3, 480, 0, 1, 4);
    ANGINI3 = ANGINI3 - MAPANGINI3;
    if (ANGINI3 < 1){
      ANGINI3 = 0;
      }
    ciclo3 = map(ANGINI3,0,180,ciclomin3,ciclomax3);
    servosx1.setPWM(3,0,ciclo3);
    }
  Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
  }

  if (VALORPOTJOY3 > 610){
    mimap3 = map(VALORPOTJOY3, 610, 1023, 580, 0);    
    if (valorMillis - previoMillis >= mimap3){
    previoMillis = valorMillis;

    int MAPANGINI3 = map(VALORPOTJOY3, 610, 1023, 1, 4);
    ANGINI3 = ANGINI3 + MAPANGINI3;
    if (ANGINI3 > 179){
      ANGINI3 = 180;
      }
    ciclo3 = map(ANGINI3,0,180,ciclomin3,ciclomax3);
    servosx1.setPWM(3,0,ciclo3);     
    }
  Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
  }
//muñeca--------------------------------------------------------------
if (VALORPOTJOY4 < 480){    
    if (valorMillis - previoMillis >= VALORPOTJOY4){
    previoMillis = valorMillis;   
    int MAPANGINI4 = map(VALORPOTJOY4, 480, 0, 1, 4);
    ANGINI4 = ANGINI4 - MAPANGINI4;
    if (ANGINI4 < 1){
      ANGINI4 = 0;
      }
    ciclo4 = map(ANGINI4,0,180,ciclomin4,ciclomax4);
    servosx1.setPWM(4,0,ciclo4);
    }
  Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
  }

  if (VALORPOTJOY4 > 630){
    mimap4 = map(VALORPOTJOY4, 630, 1023, 580, 0);     
    if (valorMillis - previoMillis >= mimap4){
    previoMillis = valorMillis;
    
    int MAPANGINI4 = map(VALORPOTJOY4, 630, 1023, 1, 4);
    ANGINI4 = ANGINI4 + MAPANGINI4;
    if (ANGINI4 > 179){
      ANGINI4 = 180;
      }
    ciclo4 = map(ANGINI4,0,180,ciclomin4,ciclomax4);
    servosx1.setPWM(4,0,ciclo4);        
    }
  Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
  }
//Palma------------------------------------------------------------
if (VALORPOTJOY5 < 450){    
    if (valorMillis - previoMillis >= VALORPOTJOY5){
    previoMillis = valorMillis;
    int MAPANGINI5 = map(VALORPOTJOY5, 450, 0, 1, 4);
    ANGINI5 = ANGINI5 - MAPANGINI5;
    if (ANGINI5 < 1){
      ANGINI5 = 0;
      }
    ciclo5 = map(ANGINI5,0,180,ciclomin5,ciclomax5);
    Serial.println(ciclo5);
    servosx1.setPWM(5,0,ciclo5);
    }
  Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
  }
  
  if (VALORPOTJOY5 > 680){  
    mimap5 = map(VALORPOTJOY5, 680, 1023, 680, 0);    
    if (valorMillis - previoMillis >= mimap5){
    previoMillis = valorMillis;

    int MAPANGINI5 = map(VALORPOTJOY5, 680, 1023, 1, 4);
    ANGINI5 = ANGINI5 + MAPANGINI5;
    if (ANGINI5 > 179){
      ANGINI5 = 180;
      }
    ciclo5 = map(ANGINI5,0,180,ciclomin5,ciclomax5);
    Serial.println(ciclo5);
    servosx1.setPWM(5,0,ciclo5);  
       
    }
  Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
  }
//Dedo--------------------------------------------------------
if (VALORPOTJOY6 < 450){    
    if (valorMillis - previoMillis >= VALORPOTJOY6){
    previoMillis = valorMillis;    
    int MAPANGINI6 = map(VALORPOTJOY6, 450, 0, 1, 4);
    ANGINI6 = ANGINI6 - MAPANGINI6;
    if (ANGINI6 < 1){
      ANGINI6 = 0;
      }  
    ciclo6 = map(ANGINI6,0,180,ciclomin6,ciclomax6);
    servosx1.setPWM(6,0,ciclo6);
    }
  Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
  }

  if (VALORPOTJOY6 > 630){
    mimap6 = map(VALORPOTJOY6, 630, 1023, 630, 0);    
    if (valorMillis - previoMillis >= mimap6){
    previoMillis = valorMillis;  
    int MAPANGINI6 = map(VALORPOTJOY6, 630, 1023, 1, 4);
    ANGINI6 = ANGINI6 + MAPANGINI6;
    if (ANGINI6 > 179){
      ANGINI6 = 180;
      } 
    ciclo6 = map(ANGINI6,0,180,ciclomin6,ciclomax6);
    servosx1.setPWM(6,0,ciclo6);  
      
  }
  Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
  }  
  }
}
