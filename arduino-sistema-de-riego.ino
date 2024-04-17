// PINES
const int PIN_SENSOR_A0 = A0;
const int PIN_BOMBA = 19;
const int PIN_LED_ACTIVADO = 13;
const int PIN_BOTON_ACTIVADO = 11;

// VALORES MÁXIMO Y MÍNIMO DEL SENSOR
const int MAX_NUM_SENSOR = 1023;
// const int MIN_NUM_SENSOR = 425;
const int MIN_NUM_SENSOR = 240;

// PORCENTAJES DE ENCENDIDO Y APAGADO DE LA BOMBA
const int PORCENT_ENCENDIDO = 30;
const int PORCENT_APAGADO = 60;

// VARIABLES
int humedad;
int retardo = 3000; // 1000 ms -> 1 s
int porcHumedad;
bool sistemaActivado = false;
bool cambiarSistema = true;

void setup()
{
  // Velocidad de transmisión
  Serial.begin(9600);
  pinMode(PIN_BOMBA, OUTPUT);
  pinMode(PIN_LED_ACTIVADO, OUTPUT);
  pinMode(PIN_BOTON_ACTIVADO, INPUT);
  digitalWrite(PIN_BOMBA, LOW);
  Serial.println("SISTEMA DESACTIVADO");
}

void loop()
{
  
  if(digitalRead(PIN_BOTON_ACTIVADO) == HIGH){
    if(cambiarSistema == true){
      cambiarSistema = false;

      if(sistemaActivado == true){
        sistemaActivado = false;
        digitalWrite(PIN_LED_ACTIVADO, LOW);
        Serial.println("");
        Serial.println("SISTEMA DESACTIVADO");
      }else{
        sistemaActivado = true;
        digitalWrite(PIN_LED_ACTIVADO, HIGH);
      }
    }
  }else{
    cambiarSistema = true;
  }

  if(sistemaActivado == true){ 
    // Leemos la humedad del sensor (0-1023)
    humedad = analogRead(PIN_SENSOR_A0);
    // Tranformamos a porcentajes (0-100)
    porcHumedad = map(humedad, MIN_NUM_SENSOR, MAX_NUM_SENSOR, 100, 0);

    // Mostramos los datos
    Serial.print("Humedad: ");
    Serial.print(porcHumedad);
    Serial.print("% (");
    Serial.print(humedad);
    Serial.print(")");
    Serial.print(" - Bomba: ");
    if(digitalRead(PIN_BOMBA) == LOW){
      Serial.println("Apagada");
    }else{
      Serial.println("Encendida");
    }
    
    // Evaluamos si debemos encender la bomba
    if (porcHumedad <= PORCENT_ENCENDIDO)
    {
      retardo = 500;
      digitalWrite(PIN_BOMBA, HIGH);
    }

    // Evaluamos si debemos apagar la bomba
    if (porcHumedad >= PORCENT_APAGADO)
    {
      retardo = 3000;
      digitalWrite(PIN_BOMBA, LOW);
    }

    // Aplicamos el retardo
    delay(retardo);
  }else{
    digitalWrite(PIN_BOMBA, LOW);
    sistemaActivado = false;
  }
}