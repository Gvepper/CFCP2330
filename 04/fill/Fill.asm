// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

    @place // start
    M=0 // upper left corner

(LOOP)
    @KBD // take kbd input
    D=M // put into D
    @WHITE
    D;JEQ // if input == 0 (aka not pressed) jump to WHITE
    @BLACK
    0;JMP // else, jump to BLACK

(WHITE)
    @place
    D=M // D = place
    @LOOP
    D;JLT // jump to LOOP if at less than minimum (0)
    @place
    D=M
    @SCREEN
    A=A+D // calculate place in the screen
    M=0 // fill w white
    @place
    M=M-1 // decrement place
    @LOOP
    0;JMP // jump to LOOP

(BLACK)
    @place
    D=M
    @8192 // max that place can be
    D=D-A
    @LOOP
    D;JGE // jump to LOOP if at the max (place - 8192 >= 0)
    @place
    D=M
    @SCREEN
    A=A+D // calculate place
    M=-1 // fill w black
    @place
    M=M+1 // increment place
    @LOOP
    0;JMP //jump to LOOP

(END)
    @END
    0;JMP // Infinite loop