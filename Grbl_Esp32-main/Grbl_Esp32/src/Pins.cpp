#include "Grbl.h"
#include "I2SOut.h"

portMUX_TYPE spinlock = portMUX_INITIALIZER_UNLOCKED;
#define ISRS_ENABLED() (spinlock.owner == portMUX_FREE_VAL)
#define DISABLE_ISRS() portENTER_CRITICAL(&spinlock)
#define ENABLE_ISRS()  if (spinlock.owner != portMUX_FREE_VAL) portEXIT_CRITICAL(&spinlock)

HardwareSerial YSerial2(2);

void Write_EXIO(unsigned char IO,unsigned char v)
{
    static char serial_init=0;
    if(serial_init==0)
    {
        YSerial2.begin(460800*3,SERIAL_8N1, 16, 17);
        serial_init=1;
    }
   if(ISRS_ENABLED()) 
    {
        DISABLE_ISRS();
        YSerial2.write(0x80|(((char)v)<<5)|(IO-100));
        ENABLE_ISRS();
    }
    else
      YSerial2.write(0x80|(((char)v)<<5)|(IO-100));  
   
}




String pinName(uint8_t pin) {
    if (pin == UNDEFINED_PIN) {
        return "None";
    }
    if (pin < I2S_OUT_PIN_BASE) {
        return String("GPIO(") + pin + ")";
    } else {
        return String("I2SO(") + (pin - I2S_OUT_PIN_BASE) + ")";
    }
}

// Even if USE_I2S_OUT is not defined, it is necessary to
// override the following functions, instead of allowing
// the weak aliases in the library to apply, because of
// the UNDEFINED_PIN check.  That UNDEFINED_PIN behavior
// cleans up other code by eliminating ifdefs and checks.
void IRAM_ATTR digitalWrite(uint8_t pin, uint8_t val) {
    if (pin == UNDEFINED_PIN) {
        return;
    }
   
    
#ifdef USE_I2S_OUT
    if(pin > I2S_OUT_PIN_BASE)
    {
        i2s_out_write(pin - I2S_OUT_PIN_BASE, val);
    }
#else 
    if(pin>=100)
    {
        Write_EXIO(pin, val);
        return;
    }   
#endif
    else
        __digitalWrite(pin, val);
}

void IRAM_ATTR pinMode(uint8_t pin, uint8_t mode) {
    if (pin == UNDEFINED_PIN) {
        return;
    }
    if (pin < I2S_OUT_PIN_BASE) {
        __pinMode(pin, mode);
    }
    // I2S out pins cannot be configured, hence there
    // is nothing to do here for them.
}

int IRAM_ATTR digitalRead(uint8_t pin) {
    if (pin == UNDEFINED_PIN) {
        return 0;
    }
    if (pin < I2S_OUT_PIN_BASE) {
        return __digitalRead(pin);
    }
#ifdef USE_I2S_OUT
    return i2s_out_read(pin - I2S_OUT_PIN_BASE);
#else
    return 0;
#endif
}
