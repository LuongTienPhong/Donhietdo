#ifndef ARDUINO_H
#define ARDUINO_H

// Thư viện Arduino
// Bản quyền (c) 2005-2019 Arduino LLC.
// Điều khoản sử dụng: https://www.arduino.cc/en/main/terms

// Cấu hình hệ thống
#define F_CPU 16000000UL // Tần số CPU
#define ARDUINO 10802 // Phiên bản Arduino
#define ARDUINO_ARCH_AVR // Kiến trúc nền tảng
#define ARDUINO_BOARD_AVR_UNO // Mô hình bo mạch

// Thư viện chuẩn
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

// Đầu ra
#define Serial Serial
#define Serial1 Serial1
#define Serial2 Serial2
#define Serial3 Serial3
#define Serial4 Serial4

// Đầu vào
#define digitalRead(pin) (bit_is_set(PIND, pin))
#define analogRead(pin) ((int)ADCH)

// I/O
#define pinMode(pin, mode) (DDRB &= ~(1 << pin))
#define digitalWrite(pin, value) (PORTB |= (value << pin))

// Timer
#define millis() (micros() / 1000)
#define micros() (clock() * 64)

// Hàm
void setup() {}
void loop() {}

// Các hàm định nghĩa lại
int abs(int x) { return x >= 0 ? x : -x; }
long abs(long x) { return x >= 0 ? x : -x; }
float abs(float x) { return x >= 0 ? x : -x; }

// Các hàm toán học
float sqrt(float x) { return _sqrt(x); }
float pow(float x, float y) { return _pow(x, y); }
float sin(float x) { return _sin(x); }
float cos(float x) { return _cos(x); }
float tan(float x) { return _tan(x); }
float atan(float x) { return _atan(x); }
float atan2(float y, float x) { return _atan2(y, x); }
float log(float x) { return _log(x); }
float exp(float x) { return _exp(x); }
float ceil(float x) { return _ceil(x); }
float floor(float x) { return _floor(x); }
float round(float x) { return _round(x); }

// Các hàm chuỗi
char *strcpy(char *dest, const char *src) { return _strcpy(dest, src); }
char *strcat(char *dest, const char *src) { return _strcat(dest, src); }
int strcmp(const char *s1, const char *s2) { return _strcmp(s1, s2); }
char *strchr(const char *s, int c) { return _strchr(s, c); }
int strlen(const char *s) { return _strlen(s); }

// Các hàm hệ thống
void delay(unsigned long ms) { _delay_ms(ms); }
void noInterrupts() { cli(); }
void interrupts() { sei(); }

#endif

