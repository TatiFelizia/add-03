#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <math.h>

int main (void) {
  stdio_init_all();

  int r1=10000;
  float r2;
  float t;
  float t0=298.0;
  int B=3950;
  float vcc=3.3;
  float vr2;
  int cant=4095;
  float ln;
  float ln2;
  float t01;
  float t02;

  adc_init();
  adc_gpio_init(27);
  adc_select_input(1);

  while(1){
    uint16_t val=adc_read();
    vr2=val*vcc/cant;

    r2=(float)r1/((vcc/vr2)-1);
    
    t = B / (log(r2/r1) + (B/t0));

    printf ("La temperatura es: %.2f\n",t);

    printf ("La temperatura es %f \n", t - 273);
  
    sleep_ms(1000);
  }

}