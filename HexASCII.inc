HexASCII:			;Takes 4-bit value in W and returns ASCII code
;---------------------------------------------------------------------		
		andlw	0x0F	;Make *sure* it's really a 4-bit value!
		addwf	PCL,f	
		dt		"0123456789ABCDEF"
		return

