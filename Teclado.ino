int Teclado(int c, int base){                                          
      switch (base){      
      case PS2_KEY_DN_ARROW:
                            Serial.println("ABAJO");
                            break;
      case PS2_KEY_UP_ARROW:
                            Serial.println("ARRIBA");                     
                            break;
      case PS2_KEY_R_ARROW:
                            Serial.println("DERECHA");
                            break;
      case PS2_KEY_L_ARROW:
                            Serial.println("IZQUIERDA");
                            break;                       
      case PS2_KEY_ENTER:        
      case PS2_KEY_KP_ENTER:
                            Serial.println("ENTER");
                            break;
      case PS2_KEY_ESC: 
                            Serial.println("ESC");
                            break;                                            
      }   
      return(base);
}
