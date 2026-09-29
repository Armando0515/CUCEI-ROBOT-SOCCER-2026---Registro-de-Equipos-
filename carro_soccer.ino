#include <Bluepad32.h>

GamepadPtr myGamepad = nullptr;

void onConnectedGamepad(GamepadPtr gp)
{
    myGamepad = gp;

    Serial.println();
    Serial.println("==============================");
    Serial.println("CONTROL PS4 CONECTADO");
    Serial.println("==============================");
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
    Serial.println("ESP32 + Bluepad32");
    Serial.println("Esperando control PS4...");

    BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);

    // Solo para esta primera prueba
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
