// PINES
const int PIN_SENSOR_A0 = A0;
const int PIN_BOMBA = 19;
const int PIN_LED_ACTIVADO = 13;
const int PIN_BOTON_ACTIVADO = 11;

// VALORES MÁXIMO Y MÍNIMO DEL SENSOR
const int MAX_NUM_SENSOR = 1023; // Valor obtenido del sensor cuando está seco
const int MIN_NUM_SENSOR = 240;  // Valor obtenido del sensor cuando está húmedo

// PORCENTAJES DE ENCENDIDO Y APAGADO DE LA BOMBA
const int PORCENT_ENCENDIDO = 30;
const int PORCENT_APAGADO = 60;

// VARIABLES
int humedad;
int retardo = 3000; // 1000 ms -> 1 s
int porcHumedad;
bool sistemaActivado = false; // Iniciamos con el sistema apagado (false)
bool cambiarSistema = true;   // Iniciamos con la opción de poder cambiar el sistema

void setup()
{
  // Velocidad de transmisión sel puerto serial
  Serial.begin(9600);
  // Configuración de pines
  pinMode(PIN_BOMBA, OUTPUT);
  pinMode(PIN_LED_ACTIVADO, OUTPUT);
  pinMode(PIN_BOTON_ACTIVADO, INPUT);
  // Iniciamos el programa con la bomba apagada (LOW)
  digitalWrite(PIN_BOMBA, LOW);
  // Imprimimos un mensaje del sistema desactivado
  Serial.println("SISTEMA DESACTIVADO");
}

void loop()
{
  // Leemos el pin del botón para ver si está pulsado o no
  if (digitalRead(PIN_BOTON_ACTIVADO) == HIGH)
  {
    // Verificamos si podemos cambiar el sistema
    if (cambiarSistema == true)
    {
      // Cuando podemos cambiar el sistema, debemos quitar el opción
      // hasta que soltemos el botón de PIN_BOTON_ACTIVADO

      cambiarSistema = false; // Quitamos la opción de cambiar el sistema

      if (sistemaActivado == true)
      {
        // Si el sistema está activo (true), lo desactivamos (false) y apagamos el led
        sistemaActivado = false;
        digitalWrite(PIN_LED_ACTIVADO, LOW);
        Serial.println("");
        Serial.println("SISTEMA DESACTIVADO");
      }
      else
      {
        // Si el sistema está desactivado (false), lo activamos (true) y encendemos el led
        sistemaActivado = true;
        digitalWrite(PIN_LED_ACTIVADO, HIGH);
      }
    }
  }
  else
  {
    // Cuando soltamos el botón de activación, volvemos a añadir
    // la opción para cambiar el sistema

    cambiarSistema = true; // Añadimos la opción de cambiar el sistema
  }

  if (sistemaActivado == true)
  {
    // Leemos la humedad del sensor (0-1023)
    humedad = analogRead(PIN_SENSOR_A0);
    // Transformamos a porcentajes los valores del sensor (0-100)
    porcHumedad = map(humedad, MIN_NUM_SENSOR, MAX_NUM_SENSOR, 100, 0);

    // Imprimimos los datos
    Serial.print("Humedad: ");
    Serial.print(porcHumedad);
    Serial.print("% (");
    Serial.print(humedad);
    Serial.print(")");
    Serial.print(" - Bomba: ");

    // Leemos si la bomba está apagada o encendida e imprimimos su valor
    if (digitalRead(PIN_BOMBA) == LOW)
    {
      Serial.println("Apagada");
    }
    else
    {
      Serial.println("Encendida");
    }

    // Evaluamos si debemos encender la bomba
    if (porcHumedad <= PORCENT_ENCENDIDO)
    {
      retardo = 500;                 // Bajamos el retardo para leer más rápido el sensor de humedad
      digitalWrite(PIN_BOMBA, HIGH); // Encendemos la bomba
    }

    // Evaluamos si debemos apagar la bomba
    if (porcHumedad >= PORCENT_APAGADO)
    {
      retardo = 3000;               // Subimos el retardo para leer más lento el sensor de humedad
      digitalWrite(PIN_BOMBA, LOW); // Apagamos la bomba
    }

    // Aplicamos el retardo
    delay(retardo);
  }
  else
  {
    // Si se manda a desactivar el sistema
    digitalWrite(PIN_BOMBA, LOW); // Apagamos la bomba
    sistemaActivado = false;
  }
}