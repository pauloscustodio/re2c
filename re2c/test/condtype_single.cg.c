/* Generated by re2c */
#line 1 "condtype_single.cg.re"

#line 5 "condtype_single.cg.c"
{
	YYCTYPE yych;
	static void *yyctable[1] = {
		&&yyc_a,
	};
	goto *yyctable[YYGETCONDITION()];
/* *********************************** */
yyc_a:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == 'a') goto yy4;
yy4:
	++YYCURSOR;
#line 2 "condtype_single.cg.re"
	{}
#line 21 "condtype_single.cg.c"
}
#line 3 "condtype_single.cg.re"

re2c: warning: line 3: control flow in condition 'a' is undefined for strings that match '[\x0-\x60\x62-\xFF]', use default rule '*' [-Wundefined-control-flow]
re2c: warning: line 3: looks like you use hardcoded numbers instead of autogenerated condition names: better add '/*!types:re2c*/' directive or '-t, --type-header' option and don't rely on fixed condition order. [-Wcondition-order]
