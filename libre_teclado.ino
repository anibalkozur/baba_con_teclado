/* current cursor position */
signed char cols = 0;
signed char rows = 0;

/* Códigos de tecla y cadenas para teclas que producen una cadena */
/* tres matrices en el mismo orden (código clave, cadena para mostrar, longitud de la cadena ) */
/*uint8_t codes[] = { PS2_KEY_SPACE, PS2_KEY_TAB, PS2_KEY_ESC,
                          PS2_KEY_DELETE, PS2_KEY_F1, PS2_KEY_F2, PS2_KEY_F3,
                          PS2_KEY_F4, PS2_KEY_F5, PS2_KEY_F6, PS2_KEY_F7,
                          PS2_KEY_F8, PS2_KEY_F9, PS2_KEY_F10, PS2_KEY_F11,
                          PS2_KEY_F12 };
const char *const keys[]  =  { " ", "[Tab]", "[ESC]", "[Del]", "[F1]", "[F2]", "[F3]",
                               "[F4]", "[F5]", "[F6]", "[F7]", "[F8]",
                               "[F9]", "[F10]", "[F11]", "[F12]" };
int8_t sizes[]  = { 1, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5 };*/

  byte mode;
  byte idx;

void check_cursor(){
  
if( cols >= MAX_COL ){
  cols = MAX_COL-1;
  lcd.setCursor( cols, rows );
  }
}

void libre_teclado(){
String cadena_archivo; 
char caracter_archivo;
lcd.cursor();                     // Enable Cursor
lcd.blink();                      // Blinking cursor

lcd.setCursor(2,1);
cols = 2;                        // update cursor position
rows = 1;
 
while(base != PS2_KEY_ESC){
  
   if(c = keyboard.read()){ 

      base = c & 0xFF;

      switch( base ){                     /* Cursor movements */
      
      case PS2_KEY_ENTER:          
      case PS2_KEY_KP_ENTER:
                if(cols >= 7 and rows == 1){
                archivo_nuevo(cadena_archivo);
                }
                break;
                

      case PS2_KEY_L_ARROW:         /* Cursor left or end of previous line */
                cols--;
                if( cols < 2 ){
                  cols = 2;
                  }
                break;
      case PS2_KEY_R_ARROW:       
                cols++;
                if( cols >= MAX_COL-1 ){
                  cols = MAX_COL-1;
                  }
                break;
      case PS2_KEY_BS:
      case PS2_KEY_DELETE:
                if(cols == MAX_COL-1){
                  lcd.write( ' ' );
                  }                
                cols--;
                if( cols < 2 )
                  {
                  cols = 2;}

                lcd.setCursor( cols, rows );
                lcd.write( ' ' );
                break;
      case PS2_KEY_HOME:        // Cursor to top left
                cols = 2;
                rows = 1;
                break;
      case PS2_KEY_END:         // Cursor to max position
                cols = MAX_COL - 2;
                rows = MAX_ROW - 1;
                break;
      }


        lcd.setCursor( cols, rows );
//-----------------------------------------------------------------------------------------------------------------------------
       if(base != PS2_KEY_DELETE and base != PS2_KEY_BS and base != PS2_KEY_KP_ENTER and base != PS2_KEY_ENTER){
          if( ( base = keymap.remapKey( c ) ) > 0 )
            {
            check_cursor( );
            cols++;
            lcd.write( base );
            caracter_archivo =  base;
            cadena_archivo = cadena_archivo + caracter_archivo;            
            Serial.println(cadena_archivo);
            check_cursor( );
            }
          }
   }    
//-----------------------------------------------------------------------------------------------------------------------------      
      
      delay(100);
     } 
     lcd.noCursor();
     lcd.noBlink();   
  }
