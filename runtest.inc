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
