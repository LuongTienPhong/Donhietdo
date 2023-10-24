#include <stdio.h>
#include <stdlib.h>
#include "diag/trace.h"
#include <Arduino.h>
// Hàm để đọc nhiệt độ từ cảm biến
float readTemperature(uint8_t pin) {
  // Đọc giá trị ADC từ cảm biến
  int16_t adc_value = analogRead(pin);

  // Tính toán giá trị nhiệt độ
  float temperature = (adc_value * 1.1) / 1023.0;

  // Trả về giá trị nhiệt độ
  return temperature;
}

int
main(int argc, char* argv[])
{
  // At this stage the system clock should have already been configured
  // at high speed.

#define LOOP_COUNT (5)
  int loops = LOOP_COUNT;
  if (argc > 1)
    {
      // If defined, get the number of loops from the command line,
      // configurable via semihosting.
      loops = atoi (argv[1]);
    }

  // Short loop.
  for (int i = 0; i < loops; i++)
    {
      // Đọc nhiệt độ từ cảm biến nhiệt độ
      float temperature = readTemperature(14);

      // In nhiệt độ lên màn hình
      printf("Nhiệt độ hiện tại là: %.2f độ C\n", temperature);
    }
  return 0;
}
