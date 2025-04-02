/**
 * Minimal LED Blink example for nRF52832
 * Just toggles P0.07 to confirm basic functionality
 */

#include <stdbool.h>
#include <stdint.h>
#include "nrf.h"

#define LED_PIN 7  // P0.07

// Simple delay function
static void delay_ms(uint32_t ms)
{
    // Approximate delay, not precise
    for (uint32_t i = 0; i < ms * 4000; i++)
    {
        __NOP(); // No operation (compiler won't optimize this away)
    }
}

int main(void)
{
    // Give debugger time to connect before configuring anything
    delay_ms(100);
    
    // Use default clock settings - no explicit configuration to avoid issues
    // The chip defaults to the internal RC oscillator on reset
    
    // Configure LED pin as output
    NRF_GPIO->DIRSET = (1 << LED_PIN);
    
    // Initial state: LED off (set high for active low LED)
    NRF_GPIO->OUTSET = (1 << LED_PIN);

    // Simple infinite loop to blink the LED
    while (true)
    {
        // Turn LED on (clear the output for active low)
        NRF_GPIO->OUTCLR = (1 << LED_PIN);
        delay_ms(100);  // Use shorter blink periods to confirm function
        
        // Turn LED off (set the output for active low)
        NRF_GPIO->OUTSET = (1 << LED_PIN);
        delay_ms(900);  // Longer off period creates distinctive pattern
    }
}