/* current cursor position */
signed char cols = 0;
signed char rows = 0;

/* Key codes and strings for keys producing a string */
/* three arrays in same order ( keycode, string to display, length of string ) */
uint8_t codes[] = { PS2_KEY_SPACE, PS2_KEY_TAB, PS2_KEY_ESC,
                          PS2_KEY_DELETE, PS2_KEY_F1, PS2_KEY_F2, PS2_KEY_F3,
                          PS2_KEY_F4, PS2_KEY_F5, PS2_KEY_F6, PS2_KEY_F7,
                          PS2_KEY_F8, PS2_KEY_F9, PS2_KEY_F10, PS2_KEY_F11,
                          PS2_KEY_F12 };
const char *const keys[]  =  { " ", "[Tab]", "[ESC]", "[Del]", "[F1]", "[F2]", "[F3]",
                               "[F4]", "[F5]", "[F6]", "[F7]", "[F8]",
                               "[F9]", "[F10]", "[F11]", "[F12]" };
int8_t sizes[]  = { 1, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5 };

  byte mode;
  byte idx;

void check_cursor(){
  
if( cols >= MAX_COL ){
  cols = MAX_COL-1;
  //rows++;
 // if( rows >= MAX_ROW )
  //  rows = 0;
  lcd.setCursor( cols, rows );
  }
}

void libre_teclado(){
lcd.cursor();                     // Enable Cursor
lcd.blink();                      // Blinking cursor

lcd.setCursor(2,1);
cols = 2;                        // update cursor position
rows = 1;
  
  while(base != PS2_KEY_ESC){

     if(c = keyboard.read()){
      mode = 2;   
      base = c & 0xFF;
      switch( base ){                     /* Cursor movements */
      
     /* case PS2_KEY_ENTER:           // Cursor to beginning of next line or start
      case PS2_KEY_KP_ENTER:*/
                /*cols = 0;
                rows++;
                if( rows >= MAX_ROW )
                   rows = 0;
                break;*/

      case PS2_KEY_L_ARROW:         /* Cursor left or end of previous line */
                cols--;
                if( cols < 2 ){
                  cols = 2;
                  }
                break;
      case PS2_KEY_R_ARROW:         /* Cursor right or start of next line */
                cols++;
                if( cols >= MAX_COL-1 ){
                  cols = MAX_COL-1;
                  }
                break;
      case PS2_KEY_BS:      // Move cursor back write space move cursor back
                  if(cols == MAX_COL-1){
                      lcd.write( ' ' );
                  }                
                cols--;
                if( cols < 2 )
                  {
                  cols = 2;}
                 // rows--;
                  if(cols == MAX_COL){
                      lcd.write( ' ' );
                  }
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
      default:  /* Not cursor movement */
                mode = 0;
      }
      /* if was cursor movement do last movement */
      if( mode == 2 )
        lcd.setCursor( cols, rows );
//-----------------------------------------------------------------------------------------------------------------------------
else
        {
        /* Check for strings or single character to display */
        if( base != PS2_KEY_EUROPE2 && ( base < PS2_KEY_KP0 || base >= PS2_KEY_F1 ) )
          {  // Non printable sort which ones we can print
          for( idx = 3; idx < sizeof( codes ); idx++ )
            if( base == codes[ idx ] )
              {
              /* String outputs */
              mode = 1;
              c = sizes[ idx ];
              cols += c - 1;
              check_cursor( );
              /* when cursor reset keep track */
              if( cols == 0 )
                cols = c;
              lcd.print( keys[ idx ] );
              cols++;
              check_cursor( );
              break;
              }
          /* if not found a string ignore key cant do anything */
          }

  //funcion para escribir caracteres sin borrado
        else
          {  /* Supported key */
          if( ( base = keymap.remapKey( c ) ) > 0 )
            {
            check_cursor( );
            cols++;
            lcd.write( base );
            check_cursor( );
            }
          }
        }       
//-----------------------------------------------------------------------------------------------------------------------------      
      }
      delay(100);
     } 
     lcd.noCursor();
     lcd.noBlink();   
  }
