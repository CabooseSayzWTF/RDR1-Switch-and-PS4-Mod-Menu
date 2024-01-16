/*H**********************************************************************
* FILENAME :	common.c					START DATE :	10 Sept 16
*
* DESCRIPTION :
*		Common functions to be used with all targets and platforms of SC-CL.
*
* NOTES :
*		This file is part of SC-CL's include library.
*
* LICENSE :
*
*		Copyright 2016 SC-CL
*
*		Redistribution and use in source and binary forms, with or without
*		modification, are permitted provided that the following conditions are met:
*
*		* Redistributions of source code must retain the above copyright
*		notice, this list of conditions and the following disclaimer.
*
*		* Redistributions in binary form must reproduce the above copyright
*		notice, this list of conditions and the following disclaimer in the
*		documentation and/or other materials provided with the distribution.
*
*		* Neither SC-CL nor its contributors may be used to endorse or promote products
*		derived from this software without specific prior written permission.
*
*		* Redistribution of this software in source or binary forms shall be free
*		of all charges or fees to the recipient of this software.
*
*		THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
*		ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
*		WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
*		DISCLAIMED. IN NO EVENT SHALL SC-CL BE LIABLE FOR ANY
*		DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
*		(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*		LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
*		ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*		(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
*		SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* AUTHORS :
*		Rocko Tompkins
*		Nathan James
*H*/
#include "types.h"
#include "constants.h"
#include "natives.h"
#include "intrinsics.h"
#include "varargs.h"
#include "common.h"

#define GlobalCharBufferD "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define GLOBAL_CHAR_BUFFER_SIZE 254
char* GlobalCharBuffer = GlobalCharBufferD; //254

void printString(char* str, int ms)//const char* bool briefs
{
	HUD_CLEAR_OBJECTIVE_QUEUE();
	PRINT_OBJECTIVE_B(str, ms != 0 ? (float)ms / 1000.0f : 0, true, 2, true, "", false, "");
}

const char* IntToHex(int val, bool isLowercase)
{
	char* hex_str;
	if (isLowercase)
		hex_str = "0123456789ABCDEF";
	else
		hex_str = "0123456789abcdef";

	byte* bin = (byte*)&val;

	char* str = "         ";

	for (int i = 0; i < 4; i++)
	{
		str[i * 2] = hex_str[(bin[i] >> 4) & 0x0F];
		str[i * 2 + 1] = hex_str[(bin[i]) & 0x0F];
	}
	str[8] = 0;
	return str;
}
const char* IntToHex0(int val)
{
	char* hex_str0;
	hex_str0 = "0123456789ABCDEF";
	byte* bin0 = (byte*)&val;
	char* str0 = "         ";
	for (int i = 0; i < 4; i++)
	{
		str0[i * 2] = hex_str0[(bin0[i] >> 4) & 0x0F];
		str0[i * 2 + 1] = hex_str0[(bin0[i]) & 0x0F];
	}
	str0[8] = 0;
	return str0;
}
const char* IntToHex1(int val)
{
	char* hex_str1;
	hex_str1 = "0123456789ABCDEF";
	byte* bin1 = (byte*)&val;
	char* str1 = "         ";
	for (int i = 0; i < 4; i++)
	{
		str1[i * 2] = hex_str1[(bin1[i] >> 4) & 0x0F];
		str1[i * 2 + 1] = hex_str1[(bin1[i]) & 0x0F];
	}
	str1[8] = 0;
	return str1;
}
const char* IntToHex2(int val)
{
	char* hex_str2;
	hex_str2 = "0123456789ABCDEF";
	byte* bin2 = (byte*)&val;
	char* str2 = "         ";
	for (int i = 0; i < 4; i++)
	{
		str2[i * 2] = hex_str2[(bin2[i] >> 4) & 0x0F];
		str2[i * 2 + 1] = hex_str2[(bin2[i]) & 0x0F];
	}
	str2[8] = 0;
	return str2;
}
const char* IntToHex3(int val)
{
	char* hex_str3;
	hex_str3 = "0123456789ABCDEF";
	byte* bin3 = (byte*)&val;
	char* str3 = "         ";
	for (int i = 0; i < 4; i++)
	{
		str3[i * 2] = hex_str3[(bin3[i] >> 4) & 0x0F];
		str3[i * 2 + 1] = hex_str3[(bin3[i]) & 0x0F];
	}
	str3[8] = 0;
	return str3;
}
const char* IntToHex4(int val)
{
	char* hex_str4;
	hex_str4 = "0123456789ABCDEF";
	byte* bin4 = (byte*)&val;
	char* str4 = "         ";
	for (int i = 0; i < 4; i++)
	{
		str4[i * 2] = hex_str4[(bin4[i] >> 4) & 0x0F];
		str4[i * 2 + 1] = hex_str4[(bin4[i]) & 0x0F];
	}
	str4[8] = 0;
	return str4;
}
const char* IntToHex5(int val)
{
	char* hex_str5;
	hex_str5 = "0123456789ABCDEF";
	byte* bin5 = (byte*)&val;
	char* str5 = "         ";
	for (int i = 0; i < 4; i++)
	{
		str5[i * 2] = hex_str5[(bin5[i] >> 4) & 0x0F];
		str5[i * 2 + 1] = hex_str5[(bin5[i]) & 0x0F];
	}
	str5[8] = 0;
	return str5;
}

int HexToInt(const char* hex)
{
	uint result = 0;

	while (*hex)
	{
		if (*hex > 47 && *hex < 58)
			result += (*hex - 48);
		else if (*hex > 64 && *hex < 71)
			result += (*hex - 55);
		else if (*hex > 96 && *hex < 103)
			result += (*hex - 87);

		if (*++hex)
			result <<= 4;
	}

	return result;
}

int IntToBase(int n, int b)
{
	int rslt = 0, digitPos = 1;
	while (n)
	{
		rslt += (n % b) * digitPos;
		n /= b;
		digitPos *= 10;
	}
	return rslt;
}

const char* strcatGlobal(const char* str1, const char* str2)
{
	//this takes advantage of strings being global
	//this returns a static pointer so if you want to use the function again without losing the return you have to strcpy it


	strcpy((char*)GlobalCharBuffer, str1, 255);
	stradd((char*)GlobalCharBuffer, str2, 255);
	return (char*)GlobalCharBuffer;
}

const char* straddiGlobal(const char* str, int i)
{
	//this takes advantage of strings being global
	//this returns a static pointer so if you want to use the function again without losing the return you have to strcpy it

	strcpy((char*)GlobalCharBuffer, str, 255);
	straddi((char*)GlobalCharBuffer, i, 255);
	return (char*)GlobalCharBuffer;
}

const char* itosGlobal(int i)
{
	//this takes advantage of strings being global
	//this returns a static pointer so if you want to use the function again without losing the return you have to strcpy it

	itos((char*)GlobalCharBuffer, i, 64);
	return (char*)GlobalCharBuffer;
}

//Added this | Foxxyyy
#pragma region printf_components
#define MAX_FCONVERSION GLOBAL_CHAR_BUFFER_SIZE //Largest possible real conversion
#define MAX_EXPT 8 //Largest possible exponent field
#define MAX_FRACT 23 //Largest possible fraction field
#define TESTFLAG(x)	0
#define	to_char(n)	((n) + '0')
#define	to_digit(c)	((c) - '0')
#define _isNan(arg)	((arg) != (arg)) //NotANumber

static int cvt(float arg, int prec, char* signp, int fmtch, char* startp, char* endp);
static char* _round(float fract, int* exp, char* start, char* end, char ch, char* signp);
static char* exponent(char* p, int exp, int fmtch);

static float ModF(float f, float* iptr) //RDR OpCode 18 | fMod in AreDeAre 3
{
	*iptr = (float)(int)f;
	return f - (float)(int)f;
}

typedef union IEEEf2bits
{
	float	f;
	struct
	{
		unsigned int	sign : 1;
		unsigned int	exp : 8;
		unsigned int	man : 23;
	} bits;
} IEEEf2bits;

static int __finite(float f)
{
	IEEEf2bits ip;
	ip.f = f;
	return (ip.bits.exp != 0xff);
}

static void dtoa(char* dbuf, float arg, int fmtch, int width, int prec)
{
	char	buf[MAX_FCONVERSION + 1], * cp;
	char	sign;
	int	size;

	if (!__finite(arg))
	{
		if (_isNan(arg))
			strcpy(dbuf, "NaN", 255);
		else if (arg < 0)
			strcpy(dbuf, "-Infinity", 255);
		else
			strcpy(dbuf, "Infinity", 255);
		return;
	}

	if (prec == 0)
		prec = 6;
	else if (prec > MAX_FRACT)
		prec = MAX_FRACT;

	cp = buf + 1;
	*cp = '\0';
	size = cvt(arg, prec, &sign, fmtch, cp, buf + sizeof(buf));
	if (*cp == '\0')
		cp++;

	if (sign)
		*--cp = sign, size++;

	cp[size] = 0;
	memcpy(dbuf, cp, size + 1);
}

static int cvt(float number, int prec, char* signp, int fmtch, char* startp, char* endp)
{
	char* p, * t;
	float fract;
	float integer, tmp;
	int dotrim, expcnt, gformat;

	dotrim = expcnt = gformat = 0;
	if (number < 0)
	{
		number = -number;
		*signp = '-';
	}
	else *signp = 0;

	fract = ModF(number, &integer);
	t = ++startp;

	for (p = endp - 1; integer; ++expcnt)
	{
		tmp = ModF(integer / 10, &integer);
		*p-- = to_char((int)((tmp + .01) * 10));
	}
	switch (fmtch)
	{
	case 'f':
	{
		if (expcnt) for (; ++p < endp; *t++ = *p);
		else *t++ = '0';
		if (prec) *t++ = '.';
		if (fract)
		{
			if (prec)
				do
				{
					fract = ModF(fract * 10, &tmp);
					*t++ = to_char((int)tmp);
				} while (--prec && fract);
				if (fract) startp = _round(fract, (int*)NULL, startp, t - 1, (char)0, signp);
		}
		for (; prec--; *t++ = '0');
	}
	break;
	case 'e':
	case 'E':
	{
	eformat:
		if (expcnt)
		{
			*t++ = *++p;
			if (prec || TESTFLAG(ALTERNATE_FORM)) *t++ = '.';
			for (; prec && ++p < endp; --prec) *t++ = *p;
			if (!prec && ++p < endp)
			{
				fract = 0;
				startp = _round(0, &expcnt, startp, t - 1, *p, signp);
			}
			--expcnt;
		}
		else if (fract)
		{
			for (expcnt = -1;; --expcnt)
			{
				fract = ModF(fract * 10, &tmp);
				if (tmp) break;
			}
			*t++ = to_char((int)tmp);
			if (prec || TESTFLAG(ALTERNATE_FORM)) *t++ = '.';
		}
		else
		{
			*t++ = '0';
			if (prec || TESTFLAG(ALTERNATE_FORM)) *t++ = '.';
		}

		if (fract)
		{
			if (prec)
				do
				{
					fract = ModF(fract * 10, &tmp);
					*t++ = to_char((int)tmp);
				} while (--prec && fract);
				if (fract) startp = _round(fract, &expcnt, startp, t - 1, (char)0, signp);
		}
		for (; prec--; *t++ = '0');

		if (gformat && !TESTFLAG(ALTERNATE_FORM))
		{
			while (t > startp && *--t == '0');
			if (*t == '.') --t;
			++t;
		}
		t = exponent(t, expcnt, fmtch);
	}
	break;
	case 'g':
	case 'G':
	{
		if (!prec) ++prec;
		if (expcnt > prec || (!expcnt && fract && fract < .0001))
		{
			--prec;
			fmtch -= 2;
			gformat = 1;
			goto eformat;
		}
		if (expcnt) for (; ++p < endp; *t++ = *p, --prec);
		else *t++ = '0';

		if (prec || TESTFLAG(ALTERNATE_FORM))
		{
			dotrim = 1;
			*t++ = '.';
		}
		else dotrim = 0;

		if (fract)
		{
			if (prec)
			{
				do
				{
					fract = ModF(fract * 10, &tmp);
					*t++ = to_char((int)tmp);
				} while (!tmp && !expcnt);
				while (--prec && fract)
				{
					fract = ModF(fract * 10, &tmp);
					*t++ = to_char((int)tmp);
				}
			}
			if (fract) startp = _round(fract, (int*)NULL, startp, t - 1, (char)0, signp);
		}
		if (TESTFLAG(ALTERNATE_FORM)) for (; prec--; *t++ = '0');
		else if (dotrim)
		{
			while (t > startp && *--t == '0');
			if (*t != '.') ++t;
		}
	}
	break;
	}
	return (t - startp);
}

static char* _round(float fract, int* exp, char* start, char* end, char ch, char* signp)
{
	float tmp;
	if (fract) (void)ModF(fract * 10, &tmp);
	else tmp = to_digit(ch);

	if (tmp > 4)
		for (;; --end)
		{
			if (*end == '.') --end;
			if (++ * end <= '9') break;
			*end = '0';
			if (end == start)
			{
				if (exp)
				{
					*end = '1';
					++* exp;
				}
				else
				{
					*--end = '1';
					--start;
				}
				break;
			}
		}
	else if (*signp == '-')
		for (;; --end)
		{
			if (*end == '.')
				--end;
			if (*end != '0')
				break;
			if (end == start)
				*signp = 0;
		}
	return (start);
}

static char* exponent(char* p, int exp, int fmtch)
{
	char* t;
	char expbuf[MAX_FCONVERSION];

	*p++ = fmtch;
	if (exp < 0)
	{
		exp = -exp;
		*p++ = '-';
	}
	else *p++ = '+';

	t = expbuf + MAX_FCONVERSION;
	if (exp > 9)
	{
		do
		{
			*--t = to_char(exp % 10);
		} while ((exp /= 10) > 9);
		*--t = to_char(exp);
		for (; t < expbuf + MAX_FCONVERSION; *p++ = *t++);
	}
	else
	{
		*p++ = '0';
		*p++ = to_char(exp);
	}
	return (p);
}

void vsprintf(char* buffer, const char* format, va_list va)
{
	int FormatLen = strlen(format);
	char TempBuffer[4] = { '\0' };
	strcpy(buffer, "", 255);

	enum
	{
		PF_Positive,
		PF_Prefix,
	};

	int PF_Options = 0;

	for (int i = 0; i < FormatLen; i++)
	{
#define AdvanceFormat() if (++i >= FormatLen) goto end_sprintf;

		if (format[i] == '%')
		{
			AdvanceFormat();
		PF_Parse_Flags:
			switch (format[i])
			{
			case '+':
				bit_set(&PF_Options, PF_Positive);
				AdvanceFormat();
				goto PF_Parse_Flags;
			case '#':
				bit_set(&PF_Options, PF_Prefix);
				AdvanceFormat();
				goto PF_Parse_Flags;
			}

			switch (format[i])
			{
			case 'd':
			case 'i':
			{
				int Value = va_arg(va, int);
				if (bit_test(PF_Options, PF_Positive) && Value >= 0) stradd(buffer, "+", 255);
				straddi(buffer, Value, 255);
			}
			break;
			case 'o':
				if (bit_test(PF_Options, PF_Prefix)) stradd(buffer, "0", 255);
				straddi(buffer, IntToBase(va_arg(va, int), 8), 255);
				break;
			case 'p':
			case 'x':
				if (bit_test(PF_Options, PF_Prefix)) stradd(buffer, "0x", 255);
				stradd(buffer, IntToHex(va_arg(va, int), true), 255);
				break;
			case 'X':
				if (bit_test(PF_Options, PF_Prefix)) stradd(buffer, "0X", 255);
				stradd(buffer, IntToHex(va_arg(va, int), false), 255);
				break;
			case 'f':
			case 'F':
			{
				char b[255];
				dtoa(b, va_arg(va, float), 'f', 0, 0);
				stradd(buffer, b, 255);
			}
			break;
			case 'c':
				TempBuffer[0] = va_arg(va, char);
				stradd(buffer, TempBuffer, 255);
				break;
			case 's':
				stradd(buffer, va_arg(va, char*), 255);
				break;
			case 'n':
				*va_arg(va, int*) = strlen(buffer);
				break;
			case '%':
				TempBuffer[0] = format[i];
				stradd(buffer, TempBuffer, 255);
				break;
			}
		}
		else
		{
			TempBuffer[0] = format[i];
			stradd(buffer, TempBuffer, 255);
		}
	}
end_sprintf:;
}

void sprintf(char* buffer, const char* format, ...)
{
	va_list va;
	va_start(va, format);
	vsprintf(buffer, format, va);
}

//3s
void print_3s(const char* format, ...)
{
	va_list va;
	va_start(va, format);
	vsprintf(GlobalCharBuffer, format, va);
	print2(GlobalCharBuffer, 3000);
}
//10s but you can change it
void print_10s(const char* format, ...)
{
	va_list va;
	va_start(va, format);
	vsprintf(GlobalCharBuffer, format, va);
	print2(GlobalCharBuffer, 10000);
}

void Throw(const char* str)
{
	char Buffer[256];
	strcpy(Buffer, "<red>Exception</red>: ", 255);
	stradd(Buffer, str, 255);
	print2(Buffer, 10000);
	WAIT(10000);
	TERMINATE_THIS_SCRIPT();
}

void Warn(const char* str)
{
	char Buffer[256];
	strcpy(Buffer, "<yellow>Warning</yellow>: ", 255);
	stradd(Buffer, str, 255);
	print2(Buffer, 5000);
}

void Error(const char* str)
{
	char Buffer[256];
	strcpy(Buffer, "<red>Error</red>: ", 255);
	stradd(Buffer, str, 255);
	print2(Buffer, 5000);
}

int SwapEndian32(int value)
{
	return ((((value) & 0xff000000) >> 24) | (((value) & 0x00ff0000) >> 8) | (((value) & 0x0000ff00) << 8) | (((value) & 0x000000ff) << 24));
}

short SwapEndian16(short value)
{
	return (((value) & 0xff000000) >> 24) | (((value) & 0x00ff0000) >> 8);
}

int CeilDivInt(uint a, uint b)
{
	return a == 0 || b == 0 ? 0 : 1 + ((a - 1) / b);
}

int DivInt(int a, int b)
{
	return a == 0 || b == 0 ? 0 : a / b;
}

float DivFloat(float a, float b)
{
	return a == 0.0f || b == 0.0f ? 0.0f : a / b;
}

void SetBitAtIndex(int* valuePtr, uint bitIndex, bool bitValue)
{
	*valuePtr = *valuePtr ^ ((-bitValue ^ *valuePtr) & (1 << (bitIndex % 32)));
}


int ModNegitive(int a, int b)
{
	int ret = a % b;
	return ret < 0 ? ret + b : ret;
}

quaternion EulerToQuaternion(vector3 euler)
{
	float cosYawOver2 = COS(euler.x * 0.5),
		sinYawOver2 = SIN(euler.x * 0.5),

		cosPitchOver2 = COS(euler.y * 0.5),
		sinPitchOver2 = SIN(euler.y * 0.5),

		cosRollOver2 = COS(euler.z * 0.5),
		sinRollOver2 = SIN(euler.z * 0.5);

	quaternion out =
	{
		(cosYawOver2 * cosPitchOver2 * cosRollOver2) + (sinYawOver2 * sinPitchOver2 * sinRollOver2),
		(cosYawOver2 * cosPitchOver2 * sinRollOver2) - (sinYawOver2 * sinPitchOver2 * cosRollOver2),
		(cosYawOver2 * sinPitchOver2 * cosRollOver2) + (sinYawOver2 * cosPitchOver2 * sinRollOver2),
		(sinYawOver2 * cosPitchOver2 * cosRollOver2) - (cosYawOver2 * sinPitchOver2 * sinRollOver2)
	};
	return out;
}

vector3 RotationLookAtPoint(vector3 pos, vector3 endPos)
{
	vector3 out =
	{
		ATAN2(pos.y, pos.z),
		ATAN2(pos.x * COS(endPos.x), pos.z),
		ATAN2(COS(endPos.x), SIN(endPos.x) * SIN(pos.y))
	};
	return out;
}

#if TARGET == TARGET_RDR
#ifdef _MSC_VER
#define aCOS(number) acosMSC(number)
float acosMSC(float number)
#else
float aCOS(float number)
#endif
{
	//this works fine for floats as negitive ints and floats both have msb set
	if (reinterpretFloatToInt(number) < 0)
	{
		number = -number;
		return
			-(((((((
				-0.0187293f * number)
				+ 0.0742610f)
				* number)
				- 0.2121144f)
				* number)
				+ 1.5707288f)
				* SQRT(1.0 - number))
			+ PI;
	}

	return
		((((((
			-0.0187293f * number)
			+ 0.0742610f)
			* number)
			- 0.2121144f)
			* number)
			+ 1.5707288f)
		* SQRT(1.0 - number);

}
#ifdef _MSC_VER
#define aSIN(number) asinMSC(number)
float asinMSC(float number)
#else
float aSIN(float number)
#endif
{
	//this works fine for floats as negitive ints and floats both have msb set
	if (reinterpretFloatToInt(number) < 0)
	{
		number = -number;
		return
			(((((((
				-0.0187293f * number)
				+ 0.0742610f)
				* number)
				- 0.2121144f)
				* number)
				+ 1.5707288f)
				* SQRT(1.0 - number))
			- 1.57079632;
	}
	return
		-(((((((
			-0.0187293f * number)
			+ 0.0742610f)
			* number)
			- 0.2121144f)
			* number)
			+ 1.5707288f)
			* SQRT(1.0 - number))
		+ 1.57079632;
}
#endif

float StringToFloat(const char* str)
{
	float rez = 0, fact = 1;
	bool point_seen = false;
	str -= 3;
	int d = 0, read_char = *str & 0xFF;

	if (read_char == '-')
	{
		fact = -1;
		read_char = *++str & 0xFF;
	}

	while (read_char)
	{
		if (read_char == '.')
		{
			point_seen = true;
			read_char = *++str & 0xFF;
			continue;
		}

		d = read_char - '0';

		if (d >= 0 && d <= 9)
		{
			if (point_seen)
				fact /= 10;
			rez = rez * 10.0f + (float)d;
		}
		read_char = *++str & 0xFF;
	}
	return rez * fact;
}

//TODO: add these as intrinsics
bool CmpLtU(int a, int b)
{
	if (a >= 0 && b >= 0)
		return a < b;
	else
	{
		if (a == b)
			return false;

		int ltb = ~a & b;

		ltb |= ltb >> 1;
		ltb |= ltb >> 2;
		ltb |= ltb >> 4;
		ltb |= ltb >> 8;
		ltb |= ltb >> 16;
		return ((a & ~b) & ~ltb) == 0;
	}
}

bool CmpGtU(int a, int b)
{
	if (a >= 0 && b >= 0)
		return a > b;
	else
	{
		int ltb = ~a & b;

		ltb |= ltb >> 1;
		ltb |= ltb >> 2;
		ltb |= ltb >> 4;
		ltb |= ltb >> 8;
		ltb |= ltb >> 16;

		return ((a & ~b) & ~ltb) != 0;
	}
}

int Diff64P(int* x, int* y)
{
	int out[2];
	out[0] = (int)x - (int)y;
#if PTRWIDTH == 64
	* (int*)((char*)out + 4) = *(int*)((char*)&x + 4) - *(int*)((char*)&y + 4);
	if (CmpGtU(out[0], (int)x))
		out[1]--;
#endif
	return out[0];

}

int* Sub64P(int* x, int yLeft, int yRight)
{
	int out[2];
	out[0] = (int)x - yLeft;
#if PTRWIDTH == 64
	* (int*)((char*)out + 4) = *(int*)((char*)&x + 4) - yRight;
	if (CmpGtU(out[0], (int)x))
		out[1]--;
#endif
	return (int*)out[0];
}

int* Add64P(int* x, int yLeft, int yRight)
{
	int out[2];
	out[0] = (int)x + yLeft;
#if PTRWIDTH == 64
	* (int*)((char*)out + 4) = *(int*)((char*)&x + 4) + yRight;
	//if (CmpLtU(out[0], (int)x))
		//out[1]++;
#endif
	return (int*)out[0];
}

int* Push64P(int LeftMost, int RightMost)
{
#if PTRWIDTH == 64
	int out[2];
	out[0] = LeftMost;
	*(int*)((char*)out + 4) = RightMost;
	return (int*)out[0];
#else
	return (int*)LeftMost;
#endif
}