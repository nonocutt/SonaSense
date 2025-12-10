#include <Adafruit_ICM20948.h>
#include <Adafruit_ICM20X.h>

Adafruit_ICM20948 icm;
Adafruit_Sensor *icm_temp, *icm_accel, *icm_gyro;

const int FLEX_SENSOR = A0;
const int FORCE_SENSOR = A1;
const int LDR_SENSOR = A6;

int flex = 0;  // FLEX_SENSOR
int force = 0;  // FORCE_SENSOR
int ldr = 0; // LDR_SENSOR

void setup() {
  pinMode(FLEX_SENSOR, INPUT);
  pinMode(FORCE_SENSOR, INPUT);
  pinMode(LDR_SENSOR, INPUT);

  Serial.begin(115200);

  if (!icm.begin_I2C()) {
    Serial.println("20948 not found!");
    while (1) {
      delay(10);
    }
  }

  icm_temp  = icm.getTemperatureSensor();
  icm_accel = icm.getAccelerometerSensor();
  icm_gyro  = icm.getGyroSensor();
}

void loop() {
  analogRead(FLEX_SENSOR);  
  flex = analogRead(FLEX_SENSOR);

  analogRead(FORCE_SENSOR);
  force = analogRead(FORCE_SENSOR);

  analogRead(LDR_SENSOR);
  ldr = analogRead(LDR_SENSOR);

  sensors_event_t accel;
  sensors_event_t gyro;

  icm_accel->getEvent(&accel);
  icm_gyro->getEvent(&gyro);

  Serial.print("flex ");
  Serial.println(flex);

  Serial.print("force ");
  Serial.println(force);

  Serial.print("ldr ");
  Serial.println(ldr);

  Serial.print("accX ");
  Serial.println(accel.acceleration.x);
  Serial.print("accY ");
  Serial.println(accel.acceleration.y);

  Serial.print("gyroX ");
  Serial.println(gyro.gyro.x);
  Serial.print("gyroY ");
  Serial.println(gyro.gyro.y);
  Serial.print("gyroZ ");
  Serial.println(gyro.gyro.z);

  delay(20);
}