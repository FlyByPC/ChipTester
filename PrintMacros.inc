PrintL	macro	Param1
;Print Literal (ASCII)
	movlw	Param1
	movwf	Output
	call	WrLCD
	endm
	
PrintF	macro	Param1
;Print File (ASCII)
	movf	Param1,w
	movwf	Output
	call	WrLCD
	endm

PrintFH	macro	Param1
;Print File (Hex, Low4) 
	movf	Param1,w
	call	HexASCII
	movwf	Output
	call	WrLCD
	endm

PrintFHL	macro	Param1
;Print File (Hex, Low4) 
	movf	Param1,w
	call	HexASCII
	movwf	Output
	call	WrLCD
	endm

PrintFHH	macro	Param1
;Print File (Hex, High4) 
	swapf	Param1,w
	call	HexASCII
	movwf	Output
	call	WrLCD
	endm
