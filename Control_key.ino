
void control_key(){
   int letra_anterior;
  while(base != PS2_KEY_ESC){
    
    if(c = keyboard.read()){   
     base = c & 0xFF; 
     letra_anterior = base;
     Display_letra(base);
     Serial.println(base);
     }

//mover base-------------------------------------------------
    while(letra_anterior == PS2_KEY_B){
      base = 0;
      if(c = keyboard.read()){   
        base = c & 0xFF; 
        }
      if(base == PS2_KEY_KP_MINUS){
        ANGINI1 = ANGINI1 - 5;
      if (ANGINI1 < 1){
        ANGINI1 = 0;
        } 
        ciclo1 = map(ANGINI1,0,180,ciclomin1,ciclomax1);
        servosx1.setPWM(1,0,ciclo1);
        Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
        base = 0;
      }
      if(base == PS2_KEY_KP_PLUS){
        ANGINI1 = ANGINI1 + 5;
      if (ANGINI1 > 179){
        ANGINI1 = 180;
        }
        ciclo1 = map(ANGINI1,0,180,ciclomin1,ciclomax1);
        servosx1.setPWM(1,0,ciclo1);
        Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
        base = 0;
      }
      if(base == PS2_KEY_H or base ==PS2_KEY_C or base ==PS2_KEY_M or base ==PS2_KEY_P or base ==PS2_KEY_D){
        Display_letra(base);
        letra_anterior = base;
      }
      if(base == PS2_KEY_ESC){
        return(base);
      }
    }
    
//mover hombro-------------------------------------------------
    while(letra_anterior == PS2_KEY_H){
      base = 0;
      if(c = keyboard.read()){   
        base = c & 0xFF; 
        }
      if(base == PS2_KEY_KP_MINUS){
        ANGINI2 = ANGINI2 - 5;
      if (ANGINI2 < 1){
        ANGINI2 = 0;
        }
        ciclo2 = map(ANGINI2,0,180,ciclomin2,ciclomax2);
        servosx1.setPWM(2,0,ciclo2);
        Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
        base = 0;
      }
      if(base == PS2_KEY_KP_PLUS){
        ANGINI2 = ANGINI2 + 5;
      if (ANGINI2 > 179){
        ANGINI2 = 180;
        }
        ciclo2 = map(ANGINI2,0,180,ciclomin2,ciclomax2);
        servosx1.setPWM(2,0,ciclo2);
        Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
        base = 0;
      }
      if(base == PS2_KEY_B or base ==PS2_KEY_C or base ==PS2_KEY_M or base ==PS2_KEY_P or base ==PS2_KEY_D){
        Display_letra(base);
        letra_anterior = base;
      }
      if(base == PS2_KEY_ESC){
        return(base);
      }
    }    

//mover codo---------------------------------------------------
    while(letra_anterior == PS2_KEY_C){
      base = 0;
      if(c = keyboard.read()){   
        base = c & 0xFF; 
        }
      if(base == PS2_KEY_KP_MINUS){
        ANGINI3 = ANGINI3 - 5;
      if (ANGINI3 < 1){
        ANGINI3 = 0;
        }         
        ciclo3 = map(ANGINI3,0,180,ciclomin3,ciclomax3);
        servosx1.setPWM(3,0,ciclo3);
        Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
        base = 0;
      }
      if(base == PS2_KEY_KP_PLUS){
        ANGINI3 = ANGINI3 + 5;
      if (ANGINI3 > 179){
        ANGINI3 = 180;
        }
        ciclo3 = map(ANGINI3,0,180,ciclomin3,ciclomax3);
        servosx1.setPWM(3,0,ciclo3);
        Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
        base = 0;
      }
      if(base == PS2_KEY_B or base ==PS2_KEY_H or base ==PS2_KEY_M or base ==PS2_KEY_P or base ==PS2_KEY_D){
        Display_letra(base);
        letra_anterior = base;
      }
      if(base == PS2_KEY_ESC){
        return(base);
      }
    } 

//mover muñeca---------------------------------------------------
    while(letra_anterior == PS2_KEY_M){
      base = 0;
      if(c = keyboard.read()){   
        base = c & 0xFF; 
        }
      if(base == PS2_KEY_KP_MINUS){
        ANGINI4 = ANGINI4 - 5;
      if (ANGINI4 < 1){
        ANGINI4 = 0;
        }
        ciclo4 = map(ANGINI4,0,180,ciclomin4,ciclomax4);
        servosx1.setPWM(4,0,ciclo4);
        Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
        base = 0;
      }
      if(base == PS2_KEY_KP_PLUS){
        ANGINI4 = ANGINI4 + 5;
      if (ANGINI4 > 179){
        ANGINI4 = 180;
        }
        ciclo4 = map(ANGINI4,0,180,ciclomin4,ciclomax4);
        servosx1.setPWM(4,0,ciclo4);
        Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
        base = 0;
      }
      if(base == PS2_KEY_B or base ==PS2_KEY_H or base ==PS2_KEY_C or base ==PS2_KEY_P or base ==PS2_KEY_D){
        Display_letra(base);
        letra_anterior = base;
      }
      if(base == PS2_KEY_ESC){
        return(base);
      }
    } 

//mover palma---------------------------------------------------
    while(letra_anterior == PS2_KEY_P){
      base = 0;
      if(c = keyboard.read()){   
        base = c & 0xFF; 
        }
      if(base == PS2_KEY_KP_MINUS){
        ANGINI5 = ANGINI5 - 5;
      if (ANGINI5 < 1){
        ANGINI5 = 0;
        }
        ciclo5 = map(ANGINI5,0,180,ciclomin5,ciclomax5);
        servosx1.setPWM(5,0,ciclo5);
        Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
        base = 0;
      }
      if(base == PS2_KEY_KP_PLUS){
        ANGINI5 = ANGINI5 + 5;
      if (ANGINI5 > 179){
        ANGINI5 = 180;
        }
        ciclo5 = map(ANGINI5,0,180,ciclomin5,ciclomax5);
        servosx1.setPWM(5,0,ciclo5);
        Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
        base = 0;
      }
      if(base == PS2_KEY_B or base ==PS2_KEY_H or base ==PS2_KEY_C or base ==PS2_KEY_M or base ==PS2_KEY_D){
        Display_letra(base);
        letra_anterior = base;
      }
      if(base == PS2_KEY_ESC){
        return(base);
      }
    } 

//mover dedo---------------------------------------------------
    while(letra_anterior == PS2_KEY_D){
      base = 0;
      if(c = keyboard.read()){   
        base = c & 0xFF; 
        }
      if(base == PS2_KEY_KP_MINUS){
        ANGINI6 = ANGINI6 - 5;
      if (ANGINI6 < 1){
        ANGINI6 = 0;
        }
        ciclo6 = map(ANGINI6,0,180,ciclomin6,ciclomax6);
        servosx1.setPWM(6,0,ciclo6);
        Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
        base = 0;
      }
      if(base == PS2_KEY_KP_PLUS){
        ANGINI6 = ANGINI6 + 5;
      if (ANGINI6 > 179){
        ANGINI6 = 180;
        }
        ciclo6 = map(ANGINI6,0,180,ciclomin6,ciclomax6);
        servosx1.setPWM(6,0,ciclo6);
        Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
        base = 0;
      }
      if(base == PS2_KEY_B or base ==PS2_KEY_H or base ==PS2_KEY_C or base ==PS2_KEY_M or base ==PS2_KEY_P){
        Display_letra(base);
        letra_anterior = base;
      }
      if(base == PS2_KEY_ESC){
        return(base);
      }
    } 
  } 
}
