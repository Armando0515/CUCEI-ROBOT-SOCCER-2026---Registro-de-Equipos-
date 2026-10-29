#include <Bluepad32.h>

GamepadPtr myGamepad = nullptr;

// =====================================================
// DEFINIR TU MAC PERMITIDA
// Reemplaza estos valores con los que obtuviste en tu prueba previa
// =====================================================
const uint8_t MAC_PERMITIDA[6] = {0xDC, 0x0C, 0x2D, 0xAA, 0xF7, 0x6F};

void onConnectedGamepad(GamepadPtr gp)
{
    GamepadProperties props = gp->getProperties();

    // 1. Mostrar la MAC del control que intenta conectar
    Serial.print("Intentando conectar MAC: ");
    for (int i = 0; i < 6; i++) {
        if (props.btaddr[i] < 0x10) Serial.print("0");
        Serial.print(props.btaddr[i], HEX);
        if (i < 5) Serial.print(":");
    }
    Serial.println();

    // 2. Comparar byte por byte con la MAC autorizada
    bool esControlAutorizado = true;
    for (int i = 0; i < 6; i++) {
        if (props.btaddr[i] != MAC_PERMITIDA[i]) {
            esControlAutorizado = false;
            break; // Si un solo byte no coincide, se rechaza
        }
    }

    // 3. Aceptar o rechazar según la validación
    if (esControlAutorizado) {
        myGamepad = gp;
        Serial.println();
        Serial.println("==============================");
        Serial.println("CONTROL AUTORIZADO CONECTADO");
        Serial.println("==============================");
    } else {
        Serial.println();
        Serial.println("==============================");
        Serial.println("CONTROL NO AUTORIZADO - DESCONECTANDO");
        Serial.println("==============================");
        gp->disconnect(); // Desconecta de inmediato al mando intruso
    }
}

void onDisconnectedGamepad(GamepadPtr gp)
{
    if (myGamepad == gp)
    {
        myGamepad = nullptr;
    }

    Serial.println();
    Serial.println("CONTROL DESCONECTADO");
}

void setup()
{
    Serial.begin(115200);
    delay(1000);

    Serial.println();
    Serial.println("ESP32 + Bluepad32 (Conexión Segura por MAC)");
    Serial.println("Esperando control autorizado...");

    BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);

    // Borra llaves anteriores para forzar una sincronización limpia
    BP32.forgetBluetoothKeys();
}

void loop()
{
    BP32.update();

    if (myGamepad && myGamepad->isConnected())
    {
        int16_t lx = myGamepad->axisX();
        int16_t ly = myGamepad->axisY();

        int16_t rx = myGamepad->axisRX();
        int16_t ry = myGamepad->axisRY();

        int16_t l2 = myGamepad->brake();
        int16_t r2 = myGamepad->throttle();

        bool A  = myGamepad->a();
        bool B  = myGamepad->b();
        bool X  = myGamepad->x();
        bool Y  = myGamepad->y();

        bool L1 = myGamepad->l1();
        bool R1 = myGamepad->r1();

        Serial.print("LX:");
        Serial.print(lx);

        Serial.print("\tLY:");
        Serial.print(ly);

        Serial.print("\tRX:");
        Serial.print(rx);

        Serial.print("\tRY:");
        Serial.print(ry);

        Serial.print("\tL2:");
        Serial.print(l2);

        Serial.print("\tR2:");
        Serial.print(r2);

        Serial.print("\tA:");
        Serial.print(A);

        Serial.print("\tB:");
        Serial.print(B);

        Serial.print("\tX:");
        Serial.print(X);

        Serial.print("\tY:");
        Serial.print(Y);

        Serial.print("\tL1:");
        Serial.print(L1);

        Serial.print("\tR1:");
        Serial.println(R1);
    }

    delay(20);
}
