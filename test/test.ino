#define WATER_LEVEL_PIN 4
int val;
void setup()
{
    Serial.begin(9600);
    pinMode(WATER_LEVEL_PIN, INPUT);
}

void loop()
{
    delay(2000);
    val = digitalRead(WATER_LEVEL_PIN);
    Serial.print("alah: ");
    Serial.println(val);
}
