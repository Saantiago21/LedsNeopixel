#include <Adafruit_NeoPixel.h>

// Configuración de los LEDs
#define LED_PIN 6        // Pin conectado al DIN de los LEDs
#define NUM_LEDS 87      // Número de LEDs en la tira
#define TRANSITION_DELAY 100 // Tiempo entre cambios en cada LED (ms)

// Crear el objeto NeoPixel
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Colores definidos
const int violet[3] = {138, 43, 226};  // Violeta
const int iphoneBlue[3] = {52, 120, 147}; // Azul del iPhone 13 Pro

void setup() {
  strip.begin();  // Inicializar LEDs
  strip.show();   // Apagar todos los LEDs al inicio
}

void loop() {
  // Cambiar al violeta lentamente
  gradualChange(violet[0], violet[1], violet[2]);
  delay(480000); // Esperar 10 minutos

  // Cambiar al azul del iPhone lentamente
  gradualChange(iphoneBlue[0], iphoneBlue[1], iphoneBlue[2]);
  delay(480000); // Esperar 10 minutos
}

// Función para establecer el color gradualmente
void gradualChange(int red, int green, int blue) {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(red, green, blue)); // Actualizar el LED actual
    strip.show();  // Mostrar el cambio
    delay(TRANSITION_DELAY); // Esperar antes de cambiar al siguiente
  }
}
