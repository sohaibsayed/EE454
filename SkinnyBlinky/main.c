// Matt Rienzo
// Sohaib Syed
// 1/17/2019
// SkinnyBlinky source code

#define RCC_BASE        *((volatile unsigned long*)0x40021000)
#define AHB2_ENR        *((volatile unsigned long*)RCC_BASE + 0x4C)

#define GPIOB_BASE      *((volatile unsigned long*)0x48000400)
#define GPIOB_MODER     *((volatile unsigned long*)GPIOB_BASE + 0x00)
#define GPIOB_ODR       *((volatile unsigned long*)GPIOB_BASE + 0x14)

#define PB3_OUTPUT      (1 << 6) // 01000000
#define PB3_CLEAR       ~(1 << 7) // 10000000 & 0111111 = 00000000
#define PB3_OFF         ~(1 << 3)
#define PB3_ON          (1 << 3)
#define PB3_CLKON       (1 << 1)

int main(void){
  AHB2_ENR |= PB3_CLKON;

  GPIOB_MODER &= PB3_CLEAR;
  GPIOB_MODER |= PB3_OUTPUT;

  while(1){
    GPIOB_ODR &= PB3_OFF;
    GPIOB_ODR |= PB3_ON;
  }
}
