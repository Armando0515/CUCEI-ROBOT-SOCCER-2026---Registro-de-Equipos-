#include <Bluepad32.h>

// Puntero para almacenar la referencia del gamepad
GamepadPtr myGamepad = nullptr;

// =====================================================
// FUNCIÓN DE CONEXIÓN (Obtiene y muestra la MAC)
// =====================================================
void onConnectedGamepad(GamepadPtr gp)
{
    myGamepad = gp;

    Serial.println("=================================");
    Serial.println("CONTROL CONECTADO EXITOSAMENTE!");
    Serial.print("Dirección MAC de tu control: ");
    
    // Obtener las propiedades del gamepad
    GamepadProperties props = gp->getProperties();
    
    // Imprimir los 6 bytes en formato hexadecimal (XX:XX:XX:XX:XX:XX)
    for (int i = 0; i < 6; i++) {
        if (props.btaddr[i] < 0x10) {
            Serial.print("0"); // Añade cero a la izquierda si el valor es menor a 16
        }
        Serial.print(props.btaddr[i], HEX);
        if (i < 5) {
            Serial.print(":");
        }
    }
    Serial.println();
    Serial.println("=================================");
}

// =====================================================
// FUNCIÓN DE DESCONEXIÓN
// =====================================================
void onDisconnectedGamepad(GamepadPtr gp)
{
    if (myGamepad == gp) {
        myGamepad = nullptr;
    }
    Serial.println("¡Control desconectado!");
}

// =====================================================
// SETUP
// =====================================================
void setup()
{
    // Iniciar comunicación serial a 115200 baudios
    Serial.begin(115200);
    delay(1000);

    Serial.println();
    Serial.println("---------------------------------");
    Serial.println("PROGRAMA PARA OBTENER MAC DE CONTROL");
    Serial.println("---------------------------------");
    Serial.println("Pon tu control en modo emparejamiento...");

    // Inicializar la librería Bluepad32
    BP32.setup(
        &onConnectedGamepad,
        &onDisconnectedGamepad
    );

    // Borrar llaves anteriores para facilitar la vinculación inicial
    BP32.forgetBluetoothKeys();
}

// =====================================================
// LOOP
// =====================================================
void loop()
{
    // Actualizar el estado de Bluepad32 constantemente
    BP32.update();

    delay(20);
}
