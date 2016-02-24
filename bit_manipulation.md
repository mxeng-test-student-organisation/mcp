# Writing a register at once

```c
REGISTER = 0xFF; //all high
REGISTER = 0xF0; //upper nibble high, lower nibble low
REGISTER = 0x00; //all low
REGISTER = 0xCA; //HHLL HLHL, 8+4=12=0xC, 8+2=10=A
```

Setting one bit high
```c
REGISTER = 0x01; //R0 high, all other bits low, 0000 0001, LLLL LLLH
REGISTER = 0x04; //R2 high, all other bits low  0000 0100, LLLL LHLL
```

# Bit shift notation
Bit shifting is easier and more clear.

Let's do the same thing as above.
```c
REGISTER = (1<<0); //R0 high, all other bits low, 0000 0001, LLLL LLLH
REGISTER = (1<<2); //R2 high, all other bits low  0000 0100, LLLL LHLL
```

Bit shifting is even more useful when we want to set multiple bits. We do this with the bitwise OR opeator which is "|" (the pipe key on the keyboard)

```c
REGISTER = (1<<0)|(1<<2); //R0 and R2 high, all other bits low, 0000 0101
REGISTER = (1<<0)|(1<<2)|(1<<5)|(1<<7); //adding more bits is easy!
```


//*************
//SETTING A BIT
//*************

//it is possible to set one bit and leave the rest alone

//this is very useful for controlling devices that are
//connected to your microcontroller one pin at a time

//to set one bit high we do a bitwise OR with the current value
//and then write it back to the register

//set R2 while leaving all the other bits as they are
REGISTER = REGISTER | (1<<2); //xxxx xx1x (x means value unchanged)

//this notation can be condensed
//using the bitwise OR assignment operator "|="
REGISTER |= (1<<2);

//you can set multiple bits and leave the rest alone
//just like before but with "|="
REGISTER \= (1<<0)|(1<<2); //R0 and R2 high, others left alone, xxxx x1x1
//**************
//CLEARING A BIT
//**************

//clearing a bit is a little more tricky
//we have to us the bitwise AND assignment operator "&="
//we also need the bitwise complement of the shifted expression

//this is done with the bitwise NOT operator "~"
REGISTER = REGISTER & ~(1<<2); //xxxx xx0x

//once again it can be shortened to save typing
REGISTER &= ~(1<<2); //xxxx xx0x

//the combination is a little more complicated (but not much)
//just add extra brackets and the "~"
REGISTER &= ~((1<<0)|(1<<2)); //xxxx x0x0



//**************
//TOGGLING A BIT
//**************

//it's useful for lights or switching the direction of things

//this is pretty much the same as setting a bit,
//but we use the exclusive or operator "^="
//this lets us toggle a bit from 1 to 0 or 0 to 1 without knowing it's value
REGISTER = REGISTER ^ (1<<2);
//shortened
REGISTER ^= (1<<2);
//multiple toggles
REGISTER ^= (1<<0)|(1<<2);
//once again it can be shortened to save typing
REGISTER &= ~(1<<2); //xxxx xx0x




//*******
//SUMMARY
//*******

//use hex to set a whole register or port
REGISTER = 0x00;
REGISTER = 0xFF;
//use bit shift notation when only setting a couple of bits
//it will make your life much easier!
REGISTER = (1<<4)|(1<<5);
//use |= to set a bit at a time
REGISTER |= (1<<3);
//or multiple bits
REGISTER |= (1<<2)|(1<<7);
//use &= with the ~ for clearing bits
REGISTER &= ~(1<<3);
REGISTER &= ~((1<<2)|(1<<4));
//use ^= to toggle bits
REGISTER ^= (1<<5);
REGISTER ^= (1<<1)|(1<<3);



//****
//TIPS
//****

//comment your code and use the clearest notation possible
//don't expect help if your code isn't organised and readable

//the bits of the registers from the data sheet have names --- USE THEM! eg:
//turn on the transmission and reception circuitry for USART0
UCSR0B = (1<<RXEN0)|(1<<TXEN0);

//initialise registers when using them (especially configuration registers)
CONFIG_REGISTER = 0x00;
CONFIG_REGISTER |= (1<<BIT_A)|(1<<BIT_B);
//or set them using "=" not "|=" on the first write
CONFIG_REGISTER = (1<<BIT_A)|(1<<BIT_B);

//search for "bitwise operations" and "bit manipulation
//if you're having trouble
