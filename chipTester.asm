
#include <P16F887.INC>
#include "PrintMacros.inc"
#include "TestVectorMacro.inc"

	cblock 0x20
	Delay1, Delay2, Delay3, Output, 
	LastCO, LastDO, LastCI, LastDI, LastCT, LastDT, CEXP, DEXP
	FailFlag
	endc


	org 0x00
	
	call	Set16F887
	banksel	TRISA
	movlw	0xFF
	movwf	TRISA
	clrf	TRISB
	movwf	TRISC
	movwf	TRISD
	clrf	TRISE
	banksel	0x00
	

	call	SetLCD

	
	;Run test vectors: CTRIS, DTRIS, COUT, DOUT, CEXPECTED, DEXPECTED

	;	 ----------------------------
	;	| 5V  D5  D4  D3  D2  D1  D0 |
	;	|(1 1) 0   0   1   0   0   1 |
	;	|                            |
	;	|  0   0   1   0   0   1(1 1)|
	;	| C0  C1  C2  C3  C4  C5  0V |
	;	 ----------------------------

Loop:

;	TestVector 0xE4, 0xC9, 0x00, 0x00, 0x00, 0x00	;00 00 00 00 --> 0 0 0 0
;	TestVector 0xE4, 0xC9, 0x12, 0x12, 0x36, 0x1B	;01 01 01 01 --> 1 1 1 1
;	TestVector 0xE4, 0xC9, 0x09, 0x24, 0x2D, 0x2D	;10 10 10 10 --> 1 1 1 1
	TestVector 0xE4, 0xC9, 0x1B, 0x36, 0x1B, 0x36	;11 11 11 11 --> 0 0 0 0

	goto	Loop	
	

Pass:
	call	Cls
	PrintL	'P'
	PrintL	'A'
	PrintL	'S'
	PrintL	'S'
	call	PrintTestResults
	;Wait for a short while
	call	Delay_50ms

	return

Fail:
	call	Cls
	PrintL	'F'
	PrintL	'A'
	PrintL	'I'
	PrintL	'L'
	call	PrintTestResults
	;Wait for a while
	call	Delay_1s
	return


RunTest:
	;Set up the TRIS ports
	movf	LastCT,w
	banksel	TRISA
	movwf	TRISC
	banksel	0x00
	movf	LastDT,w
	banksel	TRISA
	movwf	TRISD
	banksel	0x00

	;Set up the outputs
	movf	LastCO, w
	movwf	PORTC
	movf	LastDO, w
	movwf	PORTD


	;Record the results
	movf	PORTC, w
	movwf	LastCI
	movf	PORTD, w
	movwf	LastDI


	;Clear the result.
	clrf	FailFlag

	;Check to see if C results match expected
	movf	LastCI, w
	andlw	0x3F		;Strip out the high two bits
	xorwf	CEXP, w
	iorwf	FailFlag, f


	;Check to see if D results match expected
	movf	LastDI, w
	andlw	0x3F		;Strip out the high two bits
	xorwf	DEXP, w
	iorwf	FailFlag, f 


	;Clear the screen
	call	Cls


	;Call Pass or Fail routine
	movf	FailFlag, f
	btfss	STATUS, Z
	call	Fail
	movf	FailFlag, f
	btfsc	STATUS, Z
	call	Pass

	return


PrintTestResults:
	;Print out CTRIS, DTRIS, COUT, DOUT in hex
	PrintL	' '
	PrintFHH	LastCT
	PrintFHL	LastCT
	PrintL	' '
	PrintFHH	LastDT
	PrintFHL	LastDT
	PrintL	' '
	PrintFHH	LastCO
	PrintFHL	LastCO
	PrintL	' '
	PrintFHH	LastDO
	PrintFHL	LastDO

	;Go to LCD line 2
	movlw	0x40
	movwf	Output
	call	LCDGoto

	;Print out CEXP, DEXP, CIN, DIN, FailFlag
	PrintFHH	CEXP
	PrintFHL	CEXP
	PrintL	' '
	PrintFHH	DEXP
	PrintFHL	DEXP
	PrintL	' '
	PrintFHH	LastCI
	PrintFHL	LastCI
	PrintL	' '
	PrintFHH	LastDI
	PrintFHL	LastDI
	PrintL	' '
	PrintFHH	FailFlag
	PrintFHL	FailFlag

	return

	
#include "HexASCII.inc"
#include "16F887_setup.inc"
#include "delay_8.inc"
#include "LCD.inc"
	
	end