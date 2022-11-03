void Display_letra(int base){
  switch (base){      
      case PS2_KEY_B:
                            lcd.setCursor(15,0);
                            lcd.print("B");
                            break;
      case PS2_KEY_H:
                            lcd.setCursor(15,0);
                            lcd.print("H");                    
                            break;
      case PS2_KEY_C:
                            lcd.setCursor(15,0);
                            lcd.print("C");
                            break;
      case PS2_KEY_M:
                            lcd.setCursor(15,0);
                            lcd.print("M");
                            break;                       
      case PS2_KEY_P:        
                            lcd.setCursor(15,0);
                            lcd.print("P");
                            break;
      case PS2_KEY_D: 
                            lcd.setCursor(15,0);
                            lcd.print("D");
                            break;                                            
      } 
}


void Display_KEY(){  
  c = 0;
  base = 0;
  lcd.clear();
  while(base != PS2_KEY_ESC){
  if(c = keyboard.read()){   
  base = c & 0xFF;  
  Teclado(c, base);  
  } 
  lcd.setCursor(2,0);
  lcd.print("Seleccione motor con su letra inicial."); 
  lcd.setCursor(4,1);
  lcd.print("ESC para salir - ENT para avanzar");   
  lcd.scrollDisplayLeft(); 
  delay(150);

  if(base == PS2_KEY_ENTER){
      lcd.clear();
    Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
    control_key();
    break;
  }
  }
}

void Display_servos(String articulacion, int ANGINI1,int ANGINI2,int ANGINI3,int ANGINI4,int ANGINI5,int ANGINI6){
  
  lcd.setCursor(0,0);
  lcd.print("B:");
  lcd.print(ANGINI1);
  
  lcd.setCursor(0,1);
  lcd.print("H:");
  lcd.print(ANGINI2);

  lcd.setCursor(5,0);
  lcd.print("C:");
  lcd.print(ANGINI3);
  
  lcd.setCursor(5,1);
  lcd.print("M:");
  lcd.print(ANGINI4);

  lcd.setCursor(10,1);
  lcd.print("P:");
  lcd.print(ANGINI5);

  lcd.setCursor(10,0);
  lcd.print("D:");
  lcd.print(ANGINI6);

  //borrar el último caracter cuando baja de 100 a menos-------------------
//-----------------------------------------------------------------------
  if (ANGINI1 < 100){
  lcd.setCursor(4,0);
  lcd.print(" ");
  }
  if (ANGINI1 < 10){
  lcd.setCursor(3,0);
  lcd.print(" ");
  }
  if (ANGINI2 < 100){
  lcd.setCursor(4,1);
  lcd.print(" ");
  }
  if (ANGINI2 < 10){
  lcd.setCursor(3,1);
  lcd.print(" ");
  }  
  if (ANGINI3 < 100){
  lcd.setCursor(9,0);
  lcd.print(" ");
  }
  if (ANGINI3 < 10){
  lcd.setCursor(8,0);
  lcd.print(" ");
  }  
  if (ANGINI4 < 100){
  lcd.setCursor(9,1);
  lcd.print(" ");
  }
  if (ANGINI4 < 10){
  lcd.setCursor(8,1);
  lcd.print(" ");
  }  
  if (ANGINI5 < 100){
  lcd.setCursor(14,1);
  lcd.print(" ");
  }
  if (ANGINI5 < 10){
  lcd.setCursor(13,1);
  lcd.print(" ");
  }  
  if (ANGINI6 < 100){
  lcd.setCursor(14,0);
  lcd.print(" ");
  }
  if (ANGINI6 < 10){
  lcd.setCursor(13,0);
  lcd.print(" ");
  }  
}
