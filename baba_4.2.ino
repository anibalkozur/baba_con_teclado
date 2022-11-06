//tarjeta de memoria SD------------------------------------------------
#include <SPI.h>
#include <SD.h>
#define SSpin 53
File archivo;

// comunicacion I2C----------------------------------------------------
//#include <Wire.h> //comunicacion por i2c

//Comunicacion IC2 placa servos----------------------------------------

#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver servosx1 = Adafruit_PWMServoDriver(0x40);

#include <LiquidCrystal_I2C.h>
#include <LiquidMenu.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <PS2KeyAdvanced.h>
#include <PS2KeyMap.h>
// Class initialisation/instantiation
// keyboard library 
PS2KeyAdvanced keyboard;
// Initialise the keyboard remapping to UTF-8
PS2KeyMap keymap;


//lineas pantalla 0
LiquidLine linea1_pant0(1, 0, "Crear autom");
LiquidLine linea2_pant0(1, 1, "Activar autom");
LiquidLine linea3_pant0(1, 0, "Mover libremente");
LiquidLine linea4_pant0(1, 1, "Ayuda");

//lineas pantalla 1
LiquidLine linea1_pant1(1, 0, "Crear archivo");
LiquidLine linea2_pant1(1, 1, "Borrar archivo");
LiquidLine linea5_pant1(1, 0, "< atras");

//lineas pantalla 2
LiquidLine linea1_pant2(1, 1, "select archivo");
LiquidLine linea2_pant2(1, 0, "Set velocidad");
LiquidLine linea5_pant2(1, 1, "< atras");

//lineas pantalla 3
LiquidLine linea1_pant3(1, 0, "Control Joy");
LiquidLine linea2_pant3(1, 1, "Control Key");
//LiquidLine linea3_pant3(1, 0, "Pant3 lin3");
//LiquidLine linea4_pant3(1, 1, "Pant3 lin4");
LiquidLine linea5_pant3(1, 0, "< atras");

//lineas pantalla 4
LiquidLine linea1_pant4(1, 0, "Nombre archivo:");
//LiquidLine linea2_pant4(1, 1, "Pant4 lin2");
//LiquidLine linea3_pant4(1, 0, "Pant4 lin3");
//LiquidLine linea4_pant4(1, 1, "Pant4 lin4");
LiquidLine linea5_pant4(1, 1, "[             ]");

//lineas pantalla 5
LiquidLine linea1_pant5(1, 0, "Pant5 lin1");
LiquidLine linea2_pant5(1, 1, "Pant5 lin2");
LiquidLine linea3_pant5(1, 0, "Pant5 lin3");
LiquidLine linea4_pant5(1, 1, "Pant5 lin4");
LiquidLine linea5_pant5(1, 0, "< atras");


//declaracion de pantallas
LiquidScreen pantalla0;
LiquidScreen pantalla1;
LiquidScreen pantalla2;
LiquidScreen pantalla3;
LiquidScreen pantalla4;
LiquidScreen pantalla5;

LiquidMenu menu(lcd);
int ANGINI1 = 90;
int ANGINI2 = 90;
int ANGINI3 = 90;
int ANGINI4 = 90;
int ANGINI5 = 90;
int ANGINI6 = 90;

#define DATAPIN 2
#define IRQPIN  3  

/* LCD Constants to match your display  16 x 2 */
/* Columns in display */
#define MAX_COL 15
/* Rows in display */
#define MAX_ROW  1


uint16_t c;
byte base;
String articulacion = " ";

void setup() {

  servosx1.begin();
  servosx1.setOscillatorFrequency(27000000);
  servosx1.setPWMFreq(50);
  delay(30);
  servosx1.setPWM(1,0,310);
  servosx1.setPWM(2,0,310);
  servosx1.setPWM(3,0,325);
  servosx1.setPWM(4,0,335);
  servosx1.setPWM(5,0,335);
  servosx1.setPWM(6,0,335);
  delay(50);
  
  Serial.begin(9600);
  lcd.init();
  lcd.begin(16,2);
  lcd.backlight();


  keyboard.begin( DATAPIN, IRQPIN );// Setup keyboard pins
  keyboard.setNoBreak( 1 );         // No break codes for keys (when key released)
  keyboard.setNoRepeat( 1 );        // Don't repeat shift ctrl etc
  keymap.selectMap( (char *)"ES" );

//añadir lineas a pantalla 0
  pantalla0.add_line(linea1_pant0);
  pantalla0.add_line(linea2_pant0);
  pantalla0.add_line(linea3_pant0);
  pantalla0.add_line(linea4_pant0);

//añadir lineas a pantalla 1
  pantalla1.add_line(linea1_pant1);
  pantalla1.add_line(linea2_pant1);
  pantalla1.add_line(linea5_pant1);

//añadir lineas a pantalla 2
  pantalla2.add_line(linea1_pant2);
  pantalla2.add_line(linea2_pant2);
  //pantalla2.add_line(linea3_pant2);
 //pantalla2.add_line(linea4_pant2);
  pantalla2.add_line(linea5_pant2);

//añadir lineas a pantalla 3
  pantalla3.add_line(linea1_pant3);
  pantalla3.add_line(linea2_pant3);
 // pantalla3.add_line(linea3_pant3);
 // pantalla3.add_line(linea4_pant3);
  pantalla3.add_line(linea5_pant3);

//añadir lineas a pantalla 4
  pantalla4.add_line(linea1_pant4);
 // pantalla4.add_line(linea2_pant4);
 // pantalla4.add_line(linea3_pant4);
 // pantalla4.add_line(linea4_pant4);
  pantalla4.add_line(linea5_pant4);  

//añadir lineas a pantalla 5
  pantalla5.add_line(linea1_pant5);
  pantalla5.add_line(linea2_pant5);
  pantalla5.add_line(linea3_pant5);
  pantalla5.add_line(linea4_pant5);
  pantalla5.add_line(linea5_pant5);

  
  //definir posicion del selector lineas de patalla 0
  linea1_pant0.set_focusPosition(Position::LEFT); 
  linea2_pant0.set_focusPosition(Position::LEFT); 
  linea3_pant0.set_focusPosition(Position::LEFT); 
  linea4_pant0.set_focusPosition(Position::LEFT); 

  //definir posicion del selector lineas de patalla 1
  linea1_pant1.set_focusPosition(Position::LEFT); 
  linea2_pant1.set_focusPosition(Position::LEFT); 
 // linea3_pant1.set_focusPosition(Position::LEFT); 
  //linea4_pant1.set_focusPosition(Position::LEFT); 
  linea5_pant1.set_focusPosition(Position::LEFT); 

  //definir posicion del selector lineas de patalla 2
  linea1_pant2.set_focusPosition(Position::LEFT); 
  linea2_pant2.set_focusPosition(Position::LEFT); 
 // linea3_pant2.set_focusPosition(Position::LEFT); 
  //linea4_pant2.set_focusPosition(Position::LEFT); 
  linea5_pant2.set_focusPosition(Position::LEFT); 

  //definir posicion del selector lineas de patalla 3
  linea1_pant3.set_focusPosition(Position::LEFT); 
  linea2_pant3.set_focusPosition(Position::LEFT); 
  //linea3_pant3.set_focusPosition(Position::LEFT); 
  //linea4_pant3.set_focusPosition(Position::LEFT); 
  linea5_pant3.set_focusPosition(Position::LEFT);

  //definir posicion del selector lineas de patalla 4
  linea1_pant4.set_focusPosition(Position::LEFT); 
 // linea2_pant4.set_focusPosition(Position::LEFT); 
 // linea3_pant4.set_focusPosition(Position::LEFT); 
 // linea4_pant4.set_focusPosition(Position::LEFT); 
  linea5_pant4.set_focusPosition(Position::LEFT);

  //definir posicion del selector lineas de patalla 5
  linea1_pant5.set_focusPosition(Position::LEFT); 
  linea2_pant5.set_focusPosition(Position::LEFT); 
  linea3_pant5.set_focusPosition(Position::LEFT); 
  linea4_pant5.set_focusPosition(Position::LEFT); 
  linea5_pant5.set_focusPosition(Position::LEFT);  

  linea1_pant0.attach_function(1, fn_ir_a_pantalla1); 
  linea2_pant0.attach_function(1, fn_ir_a_pantalla2); 
  linea3_pant0.attach_function(1, fn_ir_a_pantalla3); 
  linea4_pant0.attach_function(1, fn_ir_a_pantalla4); 

  linea1_pant1.attach_function(1, nombre_archivo); 
  linea2_pant1.attach_function(1, fn_vacio); 
  linea5_pant1.attach_function(1, fn_atras);

  linea1_pant2.attach_function(1, fn_vacio); 
  linea2_pant2.attach_function(1, fn_vacio);  
  linea5_pant2.attach_function(1, fn_atras);

  linea1_pant3.attach_function(1, pantalla_joy); 
  linea2_pant3.attach_function(1, pantalla_key); 
  //linea3_pant3.attach_function(1, fn_vacio); 
  //linea4_pant3.attach_function(1, fn_vacio); 
  linea5_pant3.attach_function(1, fn_ir_a_pantalla0);
//pantalla escritura archivo----------------------------------------- 
  linea1_pant4.attach_function(1, fn_vacio); 
  //linea2_pant4.attach_function(1, fn_vacio); 
  //linea3_pant4.attach_function(1, fn_vacio); 
 // linea4_pant4.attach_function(1, fn_vacio); 
  linea5_pant4.attach_function(1, fn_escritura);

  linea1_pant5.attach_function(1, fn_vacio); 
  linea2_pant5.attach_function(1, fn_vacio); 
  linea3_pant5.attach_function(1, fn_vacio); 
  linea4_pant5.attach_function(1, fn_vacio); 
  linea5_pant5.attach_function(1, fn_atras);


  menu.add_screen(pantalla0);
  menu.add_screen(pantalla1);
  menu.add_screen(pantalla2);
  menu.add_screen(pantalla3);
  menu.add_screen(pantalla4);
  menu.add_screen(pantalla5);
  
  pantalla0.set_displayLineCount(2);
  pantalla1.set_displayLineCount(2);
  pantalla2.set_displayLineCount(2);
  pantalla3.set_displayLineCount(2);
  pantalla4.set_displayLineCount(2);
  pantalla5.set_displayLineCount(2);
  
  menu.init();
  menu.set_focusedLine(0);
  menu.update();
}

void loop() {
  
  keyboard.available();
  if(c = keyboard.read()){   
    base = c & 0xFF;  
    Teclado(c, base);
    Serial.println(base);
    }

    if(base == PS2_KEY_DN_ARROW){
      menu.switch_focus(true);
      base = 0;
      }                     
    if(base == PS2_KEY_UP_ARROW){
      menu.switch_focus(false);
      base = 0;
      }                    
    if(base == PS2_KEY_R_ARROW){
      menu.next_screen();
      base = 0;
      }  
    if(base == PS2_KEY_L_ARROW){
      menu.previous_screen();
      base = 0;
      }  
    if(base == PS2_KEY_ENTER or base == PS2_KEY_KP_ENTER){
      menu.call_function(1);
      base = 0;
      } 
    if(base == PS2_KEY_ESC){
      menu.change_screen(1);
      menu.set_focusedLine(0);
      menu.update();
      base = 0;
      } 
}

void fn_ir_a_pantalla0(){
  menu.change_screen(1);
  menu.set_focusedLine(0);  
}

void fn_ir_a_pantalla1(){
    
  menu.change_screen(2);
  menu.set_focusedLine(0);
}

void fn_ir_a_pantalla2(){
   
  menu.change_screen(3);
   menu.set_focusedLine(0);
}

void fn_ir_a_pantalla3(){
   
  menu.change_screen(4);
   menu.set_focusedLine(0);
}

void fn_ir_a_pantalla4(){
   
  menu.change_screen(5);
   menu.set_focusedLine(0);
}

void fn_ir_a_pantalla5(){
   
  menu.change_screen(6);
   menu.set_focusedLine(0);
}

void nombre_archivo(){
  menu.change_screen(5);
   menu.set_focusedLine(0);
}

void fn_escritura(){
  libre_teclado(); 
}

void pantalla_joy(){
  
  Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
  Control_Joy(c,base,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6); 
}

void pantalla_key(){
  Display_KEY();
  
  if(base == PS2_KEY_ENTER or PS2_KEY_KP_ENTER){
  Display_servos(articulacion,ANGINI1,ANGINI2,ANGINI3,ANGINI4,ANGINI5,ANGINI6);
  control_key();    
  }
}

void fn_atras(){
  
  menu.change_screen(1);
  menu.set_focusedLine(0);
}

void fn_vacio(){ 
  
}
