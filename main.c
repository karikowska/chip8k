unsigned char key[16];

void initialize() {

    unsigned short opcode;
    unsigned char memory[4096];
    unsigned char V[16];
    unsigned short stack[16];
    unsigned short sp;
    unsigned short index;
    unsigned short pc;
    unsigned char delay_timer;
    unsigned char sound_timer;
    unsigned char gfx[64 * 32];
    unsigned char chip8_fontset[80] =
    { 
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    pc = 0x200;  // Program counter starts at 0x200
    opcode = 0;      // Reset current opcode	
    index = 0;      // Reset index register
    sp = 0;      // Reset stack pointer
 
  // Clear display	
  for (int i = 0; i < 64; ++i) {

    for (int j = 0; i < 32; ++j) {

      gfx[i][j] = 0;

    }
  }

  // Clear stack
  for (int i = 0; i < 16; ++i) {

    stack[i] = 0;
  }

  // Clear registers V0-VF
  for (int i = 0; i < 16; ++i) {

    V[i] = 0;
  }
  // Clear memory
  for (int i = 0; i < 4096; ++i) {

    memory[i] = 0;
  }
  // Load fontset
  for(int i = 0; i < 80; ++i) {

    memory[i] = chip8_fontset[i];		
  }
 
  // Reset timers
  delay_timer = 0;
  sound_timer = 0;

}
 
void emulateCycle() {
  // Fetch opcode
  opcode = memory[pc] << 8 | memory[pc + 1];
 
  // Decode opcode
  switch(opcode & 0xF000)
  {    
    // Some opcodes //
 
    case 0xA000: // ANNN: Sets I to the address NNN
      // Execute opcode
      index = opcode & 0x0FFF;
      pc += 2;
    break;
 
    // More opcodes //
 
    default:
      printf ("Unknown opcode: 0x%X\n", opcode);
  }  
 
  // Update timers
  if(delay_timer > 0)
    --delay_timer;
 
  if(sound_timer > 0)
  {
    if(sound_timer == 1)
      printf("BEEP!\n");
    --sound_timer;
  }  
}

void setupGraphics() {
  // Fetch Opcode
  // Decode Opcode
  // Execute Opcode
 
  // Update timers
}

void setKeys() {
  // Fetch Opcode
  // Decode Opcode
  // Execute Opcode
 
  // Update timers
}

void drawGraphics() {
  // Fetch Opcode
  // Decode Opcode
  // Execute Opcode
 
  // Update timers
}

#include <stdio.h>
#include
#include   // OpenGL graphics and input
#include "chip8.h" // Your cpu core implementation
 
////////////////////////////////

int main(int argc, char **argv) 
{
  // Set up render system and register input callbacks
  setupGraphics();
  setupInput();
 
  // Initialize the Chip8 system and load the game into the memory  
  initialize();
  loadGame("pong");
 
  // Emulation loop
  for(;;)
  {
    // Emulate one cycle
    emulateCycle();
 
    // If the draw flag is set, update the screen
    if(drawFlag == True)
      drawGraphics();
 
    // Store key press state (Press and Release)
    setKeys();	
  }
 
  return 0;
}