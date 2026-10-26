// main.ino
// ============================================
// RESPONSABILIDAD: Orquestar arranque y bucle principal del sistema.
// No sabe como hacer nada: solo llama a cada modulo en el orden correcto.
// ============================================

#include "config.h"
#include "i2c_manager.h"
#include "display.h"
#include "logo.h"
#include "logboot.h"
#include "eyes.h"
#include "debug_serial.h"

// Estados de la maquina de arranque y marca de tiempo de su ventana
bool bootComplete = false;
unsigned long bootTime = 0;

void setup() {
    Serial.begin(115200);
    Serial.println(F("[BOOT] sistema de ojos OLED"));

    initI2C();
    scanI2C();
    testI2CDevice();
    initDisplay();

    // TODO 2.4: paso 6 (logo + POST) -> pendiente
    // TODO 3.4: paso 7 (ojos) -> pendiente
    // TODO 4.3: paso 8 (ayuda + bootTime) -> pendiente
}

void loop() {
    // TODO 2.4 (continuación): Mientras la ventana de arranque no expire, mantén el logo
    // en pantalla; al expirar, cambia de estado y repórtalo por el monitor.

    // TODO 4.3 (continuación):Con el arranque terminado, atiende la consola en cada
    // vuelta y deja que la animación avance un paso sin bloquear el bucle.
}
