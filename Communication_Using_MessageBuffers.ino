#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/message_buffer.h"


MessageBufferHandle_t xMessageBuffer;
const size_t BUFFER_SIZE = 100; 

void SenderTask(void *pvParameters) {
  const char *messages[] = {
    "Temp: 24.5C",
  };
  int i = 0;

  while (1) {
      const char *msg = messages[i % 3]; 
      xMessageBufferSend(xMessageBuffer, msg, strlen(msg), portMAX_DELAY);
      Serial.println("Sent: " + String(msg));
     vTaskDelay(pdMS_TO_TICKS(100)); 
  }
}

void ReceiverTask(void *pvParameters) {
  char rxBuffer[50];

  while (1) {
    size_t receivedBytes = xMessageBufferReceive(xMessageBuffer, rxBuffer, sizeof(rxBuffer), portMAX_DELAY);
    if (receivedBytes > 0) {
      Serial.print("Received: ");
      Serial.println(rxBuffer);
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  xMessageBuffer = xMessageBufferCreate(BUFFER_SIZE);


  xTaskCreate(SenderTask, "Sender Task", 2048, NULL, 1, NULL);
  xTaskCreate(ReceiverTask, "Receiver Task", 2048, NULL, 1, NULL);
}

void loop() {
}
