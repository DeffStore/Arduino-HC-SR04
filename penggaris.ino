#define TRIG_PIN 9  // Pin Trig HC-SR04
#define ECHO_PIN 10 // Pin Echo HC-SR04

void setup() {
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    long duration;
    float distance;
    
    // Kirim sinyal ultrasonik
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    // Baca waktu pantulan
    duration = pulseIn(ECHO_PIN, HIGH);
    
    // Konversi ke jarak dalam cm
    distance = duration * 0.034 / 2;
    
    // Tampilkan di Serial Monitor
    Serial.print("Jarak: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    delay(500);
}
