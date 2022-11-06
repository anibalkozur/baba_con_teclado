
void archivo_nuevo(String cadena_archivo){

  if (!SD.begin(SSpin)){
    Serial.println("fallo de inicializacion!");
    }
  else{ 
    Serial.println("inicalización correcta");  

    archivo = SD.open(cadena_archivo, FILE_WRITE); //devuelve un valor verdadero o falso, crea archivo en SD
    delay(10);
  
      }
}
