#ifndef __OLEDFONT_H
#define __OLEDFONT_H 	   
//常用ASCII表
//偏移量32
//ASCII字符集
//偏移量32
//大小:12*6
//晴 0
unsigned char BMP0[]=
{
0x80,0x86,0x8E,0x0C,0xC0,0x60,0x30,0x97,0x97,0x30,0x60,0xC0,0x0C,0x8E,0x86,0x80,
0x01,0x61,0x71,0x30,0x03,0x06,0x0C,0xE9,0xE9,0x0C,0x06,0x03,0x30,0x71,0x61,0x01,
};
//夜晚晴 1
unsigned char BMP1[]=
{
0x00,0xE0,0xF8,0xFC,0x1E,0x06,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x07,0x1F,0x1F,0x3F,0x3C,0x78,0x78,0x70,0x70,0x70,0x78,0x38,0x3C,0x0E,0x00};
//多云 4
unsigned char BMP4[]=
{
0x00,0x80,0xE0,0xF8,0xFC,0x3C,0x0E,0x0E,0x8E,0x4C,0x78,0x60,0xC0,0xC0,0x80,0x00,
0x00,0x23,0x3B,0x3B,0x33,0x33,0x27,0x09,0x08,0x0B,0x0B,0x0B,0x0A,0x0B,0x07,0x02};
//白天晴间多云 5
unsigned char BMP5[]=
{
0x00,0x00,0x80,0xC0,0x60,0x30,0xB0,0xE0,0x80,0xA8,0x70,0xD8,0x70,0xA8,0x00,0x00,
0x00,0x0E,0x0F,0x08,0x0F,0x0B,0x0A,0x09,0x0D,0x0B,0x0D,0x0D,0x0A,0x0A,0x0C,0x00
};
//夜间晴间多云 6
unsigned char BMP6[]=
{
0x00,0x00,0x80,0xC0,0x60,0x30,0xB0,0xE0,0x80,0x80,0x82,0xC6,0xFC,0x78,0x00,0x00,
0x00,0x0E,0x0F,0x08,0x0F,0x0B,0x0A,0x09,0x0D,0x0B,0x0D,0x0D,0x0A,0x0A,0x0C,0x00
};
//阴 9
unsigned char BMP9[]=
{
0x00,0x80,0xC0,0xC0,0xC0,0x80,0x00,0xC0,0xF0,0xF8,0xF8,0xF8,0xF0,0xE0,0x80,0x00,
0x00,0x0F,0x0F,0x1F,0x1F,0x1F,0x1F,0x1D,0x1B,0x17,0x17,0x1F,0x1F,0x0F,0x07,0x00
};
//阵雨 10
unsigned char BMP10[]=
{
0x00,0x80,0xC0,0xE0,0x70,0x28,0xC8,0x70,0x40,0xC0,0xD4,0x38,0x6C,0x38,0x74,0x00,
0x00,0x07,0x65,0x14,0x07,0x06,0x04,0x66,0x17,0x07,0x04,0x07,0x65,0x15,0x06,0x00
};
//雷阵雨 11
unsigned char BMP11[]=
{
0x00,0x00,0xE0,0x38,0x00,0xC0,0xF0,0xFC,0xBC,0x9C,0x84,0x00,0x00,0xE0,0x38,0x00,
0x00,0x3F,0x01,0x00,0x61,0x31,0x19,0x0F,0x07,0x03,0x01,0x00,0x3E,0x01,0x00,0x00
};
//小雨 13
unsigned char BMP13[]=
{
0x00,0x80,0xE0,0xF8,0xF8,0xFC,0xFE,0x7E,0xBE,0xDC,0xF0,0xE0,0xC0,0xC0,0x80,0x00,
0x00,0x63,0x13,0x03,0x03,0x03,0x06,0x67,0x17,0x07,0x07,0x07,0x67,0x17,0x07,0x02
};
//中雨 14
unsigned char BMP14[]=
{
0x00,0x80,0xE0,0xF8,0xF8,0xFC,0xFE,0x7E,0xBE,0xDC,0xF0,0xE0,0xC0,0xC0,0x80,0x00,
0x00,0x63,0x13,0x03,0x03,0x63,0x16,0x07,0x07,0x67,0x17,0x07,0x07,0x67,0x17,0x02
};
//大雨 15
unsigned char BMP15[]=
{
0x00,0x80,0xE0,0xF8,0xF8,0xFC,0xFE,0x7E,0xBE,0xDC,0xF0,0xE0,0xC0,0xC0,0x80,0x00,
0x00,0x63,0x13,0x03,0x63,0x13,0x06,0x67,0x17,0x07,0x67,0x17,0x07,0x67,0x17,0x02
};

//小雪 22
unsigned char BMP22[]=
{
0x00,0x80,0xE0,0xF8,0xF8,0xFC,0xFE,0x7E,0xBE,0xDC,0xF0,0xE0,0xC0,0xC0,0x80,0x00,
0x00,0x53,0x23,0x53,0x03,0x03,0x06,0x07,0x07,0x07,0x07,0x07,0x57,0x27,0x57,0x02
};
//雾 30
unsigned char BMP30[]=
{
0x00,0x00,0x00,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x00,0x00,0x00,
0x00,0x00,0x00,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x00,0x00,0x00
};
//霾 31
unsigned char BMP31[]=
{
0x00,0xC0,0x24,0x14,0x10,0x20,0x44,0x84,0x84,0x44,0x20,0x10,0x14,0x24,0xC0,0x00,
0x00,0x03,0x24,0x28,0x08,0x04,0x22,0x21,0x21,0x22,0x04,0x08,0x28,0x24,0x03,0x00
};
//风 32
unsigned char BMP32[]=
{
0x00,0x00,0x10,0x50,0x54,0x52,0x52,0x4C,0x40,0x48,0x44,0x44,0x38,0x00,0x00,0x00,
0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x19,0x31,0x21,0x21,0x21,0x32,0x1C,0x00,0x00
};
//大风 33
unsigned char BMP33[]=
{
0x00,0x00,0x10,0x50,0x54,0x52,0x52,0x4C,0x40,0x48,0x44,0x44,0x38,0x00,0x00,0x00,
0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x19,0x31,0x21,0x21,0x21,0x32,0x1C,0x00,0x00
};
//龙卷风 36
unsigned char BMP36[]=
{
0x00,0x00,0x48,0x94,0x24,0x32,0x4A,0x4A,0x4A,0x4A,0x32,0xA4,0x58,0x08,0x00,0x00,
0x00,0x00,0x00,0x00,0x03,0x15,0x2B,0x4A,0x2B,0x19,0x05,0x02,0x00,0x00,0x00,0x00
};
//指示符
unsigned char BMP37[]=
{
0x80,0xC0,0xE0,0xF0,0xF8,0xFC,0xFE,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

/************************************6*8的点阵************************************/
const unsigned char F6x8[][6] =		
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,// sp
0x00, 0x00, 0x00, 0x2f, 0x00, 0x00,// !
0x00, 0x00, 0x07, 0x00, 0x07, 0x00,// "
0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14,// #
0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12,// $
0x00, 0x62, 0x64, 0x08, 0x13, 0x23,// %
0x00, 0x36, 0x49, 0x55, 0x22, 0x50,// &
0x00, 0x00, 0x05, 0x03, 0x00, 0x00,// '
0x00, 0x00, 0x1c, 0x22, 0x41, 0x00,// (
0x00, 0x00, 0x41, 0x22, 0x1c, 0x00,// )
0x00, 0x14, 0x08, 0x3E, 0x08, 0x14,// *
0x00, 0x08, 0x08, 0x3E, 0x08, 0x08,// +
0x00, 0x00, 0x00, 0xA0, 0x60, 0x00,// ,
0x00, 0x08, 0x08, 0x08, 0x08, 0x08,// -
0x00, 0x00, 0x60, 0x60, 0x00, 0x00,// .
0x00, 0x20, 0x10, 0x08, 0x04, 0x02,// /
0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
0x00, 0x00, 0x42, 0x7F, 0x40, 0x00,// 1
0x00, 0x42, 0x61, 0x51, 0x49, 0x46,// 2
0x00, 0x21, 0x41, 0x45, 0x4B, 0x31,// 3
0x00, 0x18, 0x14, 0x12, 0x7F, 0x10,// 4
0x00, 0x27, 0x45, 0x45, 0x45, 0x39,// 5
0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
0x00, 0x01, 0x71, 0x09, 0x05, 0x03,// 7
0x00, 0x36, 0x49, 0x49, 0x49, 0x36,// 8
0x00, 0x06, 0x49, 0x49, 0x29, 0x1E,// 9
0x00, 0x00, 0x36, 0x36, 0x00, 0x00,// :
0x00, 0x00, 0x56, 0x36, 0x00, 0x00,// ;
0x00, 0x08, 0x14, 0x22, 0x41, 0x00,// <
0x00, 0x14, 0x14, 0x14, 0x14, 0x14,// =
0x00, 0x00, 0x41, 0x22, 0x14, 0x08,// >
0x00, 0x02, 0x01, 0x51, 0x09, 0x06,// ?
0x00, 0x32, 0x49, 0x59, 0x51, 0x3E,// @
0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C,// A
0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,// B
0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,// C
0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C,// D
0x00, 0x7F, 0x49, 0x49, 0x49, 0x41,// E
0x00, 0x7F, 0x09, 0x09, 0x09, 0x01,// F
0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A,// G
0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F,// H
0x00, 0x00, 0x41, 0x7F, 0x41, 0x00,// I
0x00, 0x20, 0x40, 0x41, 0x3F, 0x01,// J
0x00, 0x7F, 0x08, 0x14, 0x22, 0x41,// K
0x00, 0x7F, 0x40, 0x40, 0x40, 0x40,// L
0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F,// M
0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F,// N
0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E,// O
0x00, 0x7F, 0x09, 0x09, 0x09, 0x06,// P
0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
0x00, 0x7F, 0x09, 0x19, 0x29, 0x46,// R
0x00, 0x46, 0x49, 0x49, 0x49, 0x31,// S
0x00, 0x01, 0x01, 0x7F, 0x01, 0x01,// T
0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,// U
0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F,// V
0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F,// W
0x00, 0x63, 0x14, 0x08, 0x14, 0x63,// X
0x00, 0x07, 0x08, 0x70, 0x08, 0x07,// Y
0x00, 0x61, 0x51, 0x49, 0x45, 0x43,// Z
0x00, 0x00, 0x7F, 0x41, 0x41, 0x00,// [
0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55,// 55
0x00, 0x00, 0x41, 0x41, 0x7F, 0x00,// ]
0x00, 0x04, 0x02, 0x01, 0x02, 0x04,// ^
0x00, 0x40, 0x40, 0x40, 0x40, 0x40,// _
0x00, 0x00, 0x01, 0x02, 0x04, 0x00,// '
0x00, 0x20, 0x54, 0x54, 0x54, 0x78,// a
0x00, 0x7F, 0x48, 0x44, 0x44, 0x38,// b
0x00, 0x38, 0x44, 0x44, 0x44, 0x20,// c
0x00, 0x38, 0x44, 0x44, 0x48, 0x7F,// d
0x00, 0x38, 0x54, 0x54, 0x54, 0x18,// e
0x00, 0x08, 0x7E, 0x09, 0x01, 0x02,// f
0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C,// g
0x00, 0x7F, 0x08, 0x04, 0x04, 0x78,// h
0x00, 0x00, 0x44, 0x7D, 0x40, 0x00,// i
0x00, 0x40, 0x80, 0x84, 0x7D, 0x00,// j
0x00, 0x7F, 0x10, 0x28, 0x44, 0x00,// k
0x00, 0x00, 0x41, 0x7F, 0x40, 0x00,// l
0x00, 0x7C, 0x04, 0x18, 0x04, 0x78,// m
0x00, 0x7C, 0x08, 0x04, 0x04, 0x78,// n
0x00, 0x38, 0x44, 0x44, 0x44, 0x38,// o
0x00, 0xFC, 0x24, 0x24, 0x24, 0x18,// p
0x00, 0x18, 0x24, 0x24, 0x18, 0xFC,// q
0x00, 0x7C, 0x08, 0x04, 0x04, 0x08,// r
0x00, 0x48, 0x54, 0x54, 0x54, 0x20,// s
0x00, 0x04, 0x3F, 0x44, 0x40, 0x20,// t
0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C,// u
0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C,// v
0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C,// w
0x00, 0x44, 0x28, 0x10, 0x28, 0x44,// x
0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C,// y
0x00, 0x44, 0x64, 0x54, 0x4C, 0x44,// z
0x14, 0x14, 0x14, 0x14, 0x14, 0x14,// horiz lines
};
/****************************************8*16的点阵************************************/
const unsigned char F8X16[]=	  
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 0
  0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x30,0x00,0x00,0x00,//! 1
  0x00,0x10,0x0C,0x06,0x10,0x0C,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//" 2
  0x40,0xC0,0x78,0x40,0xC0,0x78,0x40,0x00,0x04,0x3F,0x04,0x04,0x3F,0x04,0x04,0x00,//# 3
  0x00,0x70,0x88,0xFC,0x08,0x30,0x00,0x00,0x00,0x18,0x20,0xFF,0x21,0x1E,0x00,0x00,//$ 4
  0xF0,0x08,0xF0,0x00,0xE0,0x18,0x00,0x00,0x00,0x21,0x1C,0x03,0x1E,0x21,0x1E,0x00,//% 5
  0x00,0xF0,0x08,0x88,0x70,0x00,0x00,0x00,0x1E,0x21,0x23,0x24,0x19,0x27,0x21,0x10,//& 6
  0x10,0x16,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//' 7
  0x00,0x00,0x00,0xE0,0x18,0x04,0x02,0x00,0x00,0x00,0x00,0x07,0x18,0x20,0x40,0x00,//( 8
  0x00,0x02,0x04,0x18,0xE0,0x00,0x00,0x00,0x00,0x40,0x20,0x18,0x07,0x00,0x00,0x00,//) 9
  0x40,0x40,0x80,0xF0,0x80,0x40,0x40,0x00,0x02,0x02,0x01,0x0F,0x01,0x02,0x02,0x00,//* 10
  0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x1F,0x01,0x01,0x01,0x00,//+ 11
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xB0,0x70,0x00,0x00,0x00,0x00,0x00,//, 12
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,//- 13
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00,//. 14
  0x00,0x00,0x00,0x00,0x80,0x60,0x18,0x04,0x00,0x60,0x18,0x06,0x01,0x00,0x00,0x00,/// 15
  0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00,//0 16
  0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//1 17
  0x00,0x70,0x08,0x08,0x08,0x88,0x70,0x00,0x00,0x30,0x28,0x24,0x22,0x21,0x30,0x00,//2 18
  0x00,0x30,0x08,0x88,0x88,0x48,0x30,0x00,0x00,0x18,0x20,0x20,0x20,0x11,0x0E,0x00,//3 19
  0x00,0x00,0xC0,0x20,0x10,0xF8,0x00,0x00,0x00,0x07,0x04,0x24,0x24,0x3F,0x24,0x00,//4 20
  0x00,0xF8,0x08,0x88,0x88,0x08,0x08,0x00,0x00,0x19,0x21,0x20,0x20,0x11,0x0E,0x00,//5 21
  0x00,0xE0,0x10,0x88,0x88,0x18,0x00,0x00,0x00,0x0F,0x11,0x20,0x20,0x11,0x0E,0x00,//6 22
  0x00,0x38,0x08,0x08,0xC8,0x38,0x08,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,//7 23
  0x00,0x70,0x88,0x08,0x08,0x88,0x70,0x00,0x00,0x1C,0x22,0x21,0x21,0x22,0x1C,0x00,//8 24
  0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x00,0x31,0x22,0x22,0x11,0x0F,0x00,//9 25
  0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,//: 26
  0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x60,0x00,0x00,0x00,0x00,//; 27
  0x00,0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x00,//< 28
  0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x00,//= 29
  0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x00,0x20,0x10,0x08,0x04,0x02,0x01,0x00,//> 30
  0x00,0x70,0x48,0x08,0x08,0x08,0xF0,0x00,0x00,0x00,0x00,0x30,0x36,0x01,0x00,0x00,//? 31
  0xC0,0x30,0xC8,0x28,0xE8,0x10,0xE0,0x00,0x07,0x18,0x27,0x24,0x23,0x14,0x0B,0x00,//@ 32
  0x00,0x00,0xC0,0x38,0xE0,0x00,0x00,0x00,0x20,0x3C,0x23,0x02,0x02,0x27,0x38,0x20,//A 33
  0x08,0xF8,0x88,0x88,0x88,0x70,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x11,0x0E,0x00,//B 34
  0xC0,0x30,0x08,0x08,0x08,0x08,0x38,0x00,0x07,0x18,0x20,0x20,0x20,0x10,0x08,0x00,//C 35
  0x08,0xF8,0x08,0x08,0x08,0x10,0xE0,0x00,0x20,0x3F,0x20,0x20,0x20,0x10,0x0F,0x00,//D 36
  0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x20,0x23,0x20,0x18,0x00,//E 37
  0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x00,0x03,0x00,0x00,0x00,//F 38
  0xC0,0x30,0x08,0x08,0x08,0x38,0x00,0x00,0x07,0x18,0x20,0x20,0x22,0x1E,0x02,0x00,//G 39
  0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x20,0x3F,0x21,0x01,0x01,0x21,0x3F,0x20,//H 40
  0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//I 41
  0x00,0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,0x00,//J 42
  0x08,0xF8,0x88,0xC0,0x28,0x18,0x08,0x00,0x20,0x3F,0x20,0x01,0x26,0x38,0x20,0x00,//K 43
  0x08,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x20,0x30,0x00,//L 44
  0x08,0xF8,0xF8,0x00,0xF8,0xF8,0x08,0x00,0x20,0x3F,0x00,0x3F,0x00,0x3F,0x20,0x00,//M 45
  0x08,0xF8,0x30,0xC0,0x00,0x08,0xF8,0x08,0x20,0x3F,0x20,0x00,0x07,0x18,0x3F,0x00,//N 46
  0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x10,0x20,0x20,0x20,0x10,0x0F,0x00,//O 47
  0x08,0xF8,0x08,0x08,0x08,0x08,0xF0,0x00,0x20,0x3F,0x21,0x01,0x01,0x01,0x00,0x00,//P 48
  0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x18,0x24,0x24,0x38,0x50,0x4F,0x00,//Q 49
  0x08,0xF8,0x88,0x88,0x88,0x88,0x70,0x00,0x20,0x3F,0x20,0x00,0x03,0x0C,0x30,0x20,//R 50
  0x00,0x70,0x88,0x08,0x08,0x08,0x38,0x00,0x00,0x38,0x20,0x21,0x21,0x22,0x1C,0x00,//S 51
  0x18,0x08,0x08,0xF8,0x08,0x08,0x18,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,//T 52
  0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,//U 53
  0x08,0x78,0x88,0x00,0x00,0xC8,0x38,0x08,0x00,0x00,0x07,0x38,0x0E,0x01,0x00,0x00,//V 54
  0xF8,0x08,0x00,0xF8,0x00,0x08,0xF8,0x00,0x03,0x3C,0x07,0x00,0x07,0x3C,0x03,0x00,//W 55
  0x08,0x18,0x68,0x80,0x80,0x68,0x18,0x08,0x20,0x30,0x2C,0x03,0x03,0x2C,0x30,0x20,//X 56
  0x08,0x38,0xC8,0x00,0xC8,0x38,0x08,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,//Y 57
  0x10,0x08,0x08,0x08,0xC8,0x38,0x08,0x00,0x20,0x38,0x26,0x21,0x20,0x20,0x18,0x00,//Z 58
  0x00,0x00,0x00,0xFE,0x02,0x02,0x02,0x00,0x00,0x00,0x00,0x7F,0x40,0x40,0x40,0x00,//[ 59
  0x00,0x0C,0x30,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x06,0x38,0xC0,0x00,//\ 60
  0x00,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x7F,0x00,0x00,0x00,//] 61
  0x00,0x00,0x04,0x02,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//^ 62
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,//_ 63
  0x00,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//` 64
  0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x19,0x24,0x22,0x22,0x22,0x3F,0x20,//a 65
  0x08,0xF8,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x3F,0x11,0x20,0x20,0x11,0x0E,0x00,//b 66
  0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x0E,0x11,0x20,0x20,0x20,0x11,0x00,//c 67
  0x00,0x00,0x00,0x80,0x80,0x88,0xF8,0x00,0x00,0x0E,0x11,0x20,0x20,0x10,0x3F,0x20,//d 68
  0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x22,0x22,0x22,0x22,0x13,0x00,//e 69
  0x00,0x80,0x80,0xF0,0x88,0x88,0x88,0x18,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//f 70
  0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x6B,0x94,0x94,0x94,0x93,0x60,0x00,//g 71
  0x08,0xF8,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20,//h 72
  0x00,0x80,0x98,0x98,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//i 73
  0x00,0x00,0x00,0x80,0x98,0x98,0x00,0x00,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,//j 74
  0x08,0xF8,0x00,0x00,0x80,0x80,0x80,0x00,0x20,0x3F,0x24,0x02,0x2D,0x30,0x20,0x00,//k 75
  0x00,0x08,0x08,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//l 76
  0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x20,0x3F,0x20,0x00,0x3F,0x20,0x00,0x3F,//m 77
  0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20,//n 78
  0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,//o 79
  0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x80,0xFF,0xA1,0x20,0x20,0x11,0x0E,0x00,//p 80
  0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x0E,0x11,0x20,0x20,0xA0,0xFF,0x80,//q 81
  0x80,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x20,0x20,0x3F,0x21,0x20,0x00,0x01,0x00,//r 82
  0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x33,0x24,0x24,0x24,0x24,0x19,0x00,//s 83
  0x00,0x80,0x80,0xE0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x1F,0x20,0x20,0x00,0x00,//t 84
  0x80,0x80,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x1F,0x20,0x20,0x20,0x10,0x3F,0x20,//u 85
  0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x00,0x01,0x0E,0x30,0x08,0x06,0x01,0x00,//v 86
  0x80,0x80,0x00,0x80,0x00,0x80,0x80,0x80,0x0F,0x30,0x0C,0x03,0x0C,0x30,0x0F,0x00,//w 87
  0x00,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x31,0x2E,0x0E,0x31,0x20,0x00,//x 88
  0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x80,0x81,0x8E,0x70,0x18,0x06,0x01,0x00,//y 89
  0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x21,0x30,0x2C,0x22,0x21,0x30,0x00,//z 90
  0x00,0x00,0x00,0x00,0x80,0x7C,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x3F,0x40,0x40,//{ 91
  0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,//| 92
  0x00,0x02,0x02,0x7C,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x3F,0x00,0x00,0x00,0x00,//} 93
  0x00,0x06,0x01,0x01,0x02,0x02,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//~ 94
};
char Hzk[][32]={
	
{0x04,0x24,0x44,0x84,0x64,0x9C,0x40,0x30,0x0F,0xC8,0x08,0x08,0x28,0x18,0x00,0x00},
{0x10,0x08,0x06,0x01,0x82,0x4C,0x20,0x18,0x06,0x01,0x06,0x18,0x20,0x40,0x80,0x00},/*"欢",0*/
{0x40,0x40,0x42,0xCC,0x00,0x00,0xFC,0x04,0x02,0x00,0xFC,0x04,0x04,0xFC,0x00,0x00},
{0x00,0x40,0x20,0x1F,0x20,0x40,0x4F,0x44,0x42,0x40,0x7F,0x42,0x44,0x43,0x40,0x00},/*"迎",1*/
{0x80,0x60,0xF8,0x07,0x04,0xE4,0x24,0x24,0x24,0xFF,0x24,0x24,0x24,0xE4,0x04,0x00},
{0x00,0x00,0xFF,0x00,0x80,0x81,0x45,0x29,0x11,0x2F,0x41,0x41,0x81,0x81,0x80,0x00},/*"使",2*/
{0x00,0x00,0xFE,0x22,0x22,0x22,0x22,0xFE,0x22,0x22,0x22,0x22,0xFE,0x00,0x00,0x00},
{0x80,0x60,0x1F,0x02,0x02,0x02,0x02,0x7F,0x02,0x02,0x42,0x82,0x7F,0x00,0x00,0x00},/*"用",3*/
{0x40,0x40,0x42,0x42,0x42,0x42,0x42,0xFE,0x42,0x42,0x42,0x42,0x42,0x40,0x40,0x00},
{0x80,0x80,0x40,0x20,0x10,0x0C,0x03,0x00,0x03,0x0C,0x10,0x20,0x40,0x80,0x80,0x00},/*"天",4*/
{0x20,0x10,0x4C,0x47,0x54,0x54,0x54,0x54,0x54,0x54,0x54,0xD4,0x04,0x04,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x30,0x40,0xF0,0x00},/*"气",5*/
{0x00,0xFC,0x84,0x84,0x84,0xFC,0x00,0x10,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x00},
{0x00,0x3F,0x10,0x10,0x10,0x3F,0x00,0x00,0x01,0x06,0x40,0x80,0x7F,0x00,0x00,0x00},/*"时",6*/
{0x20,0x10,0x2C,0xE7,0x24,0x24,0x00,0xF0,0x10,0x10,0xFF,0x10,0x10,0xF0,0x00,0x00},
{0x01,0x01,0x01,0x7F,0x21,0x11,0x00,0x07,0x02,0x02,0xFF,0x02,0x02,0x07,0x00,0x00},/*"钟",7*/


{0x00,0x02,0x02,0xC2,0x02,0x02,0x02,0xFE,0x82,0x82,0x82,0x82,0x82,0x02,0x00,0x00},
{0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00},/*"正",8*/
{0x08,0x08,0x88,0xC8,0x38,0x0C,0x0B,0x08,0x08,0xE8,0x08,0x08,0x08,0x08,0x08,0x00},
{0x02,0x01,0x00,0xFF,0x40,0x41,0x41,0x41,0x41,0x7F,0x41,0x41,0x41,0x41,0x40,0x00},/*"在",9*/
{0x02,0xFE,0x92,0x92,0xFE,0x02,0x00,0x10,0x11,0x16,0xF0,0x14,0x13,0x10,0x00,0x00},
{0x10,0x1F,0x08,0x08,0xFF,0x04,0x81,0x41,0x31,0x0D,0x03,0x0D,0x31,0x41,0x81,0x00},/*"联",10*/
{0x00,0xFE,0x02,0x22,0x42,0x82,0x72,0x02,0x22,0x42,0x82,0x72,0x02,0xFE,0x00,0x00},
{0x00,0xFF,0x10,0x08,0x06,0x01,0x0E,0x10,0x08,0x06,0x01,0x4E,0x80,0x7F,0x00,0x00},/*"网",11*/


{0x00,0x00,0xF8,0x88,0x88,0x88,0x88,0x08,0x08,0xFF,0x08,0x09,0x0A,0xC8,0x08,0x00},
{0x80,0x60,0x1F,0x00,0x10,0x20,0x1F,0x80,0x40,0x21,0x16,0x18,0x26,0x41,0xF8,0x00},/*"成",12*/
{0x08,0x08,0x08,0xF8,0x08,0x08,0x08,0x10,0x10,0xFF,0x10,0x10,0x10,0xF0,0x00,0x00},
{0x10,0x30,0x10,0x1F,0x08,0x88,0x48,0x30,0x0E,0x01,0x40,0x80,0x40,0x3F,0x00,0x00},/*"功",13*/

{0x40,0x42,0xCC,0x00,0x00,0x44,0x54,0x54,0x54,0x7F,0x54,0x54,0x54,0x44,0x40,0x00},
{0x00,0x00,0x7F,0x20,0x10,0x00,0xFF,0x15,0x15,0x15,0x55,0x95,0x7F,0x00,0x00,0x00},/*"请",14*/
{0x02,0xE2,0x22,0xF2,0x2E,0xE2,0x22,0xE2,0x12,0x10,0x10,0x10,0xFF,0x10,0x10,0x00},
{0x00,0xFF,0x00,0x3F,0x00,0x3F,0x80,0xFF,0x00,0x01,0x46,0x80,0x7F,0x00,0x00,0x00},/*"耐",15*/
{0x00,0x00,0x80,0x00,0x00,0xE0,0x02,0x04,0x18,0x00,0x00,0x00,0x40,0x80,0x00,0x00},
{0x10,0x0C,0x03,0x00,0x00,0x3F,0x40,0x40,0x40,0x40,0x40,0x78,0x00,0x01,0x0E,0x00},/*"心",16*/
{0x08,0x04,0x23,0x22,0x26,0x2A,0x22,0xFA,0x24,0x23,0x22,0x26,0x2A,0x02,0x02,0x00},
{0x01,0x09,0x09,0x09,0x19,0x69,0x09,0x09,0x49,0x89,0x7D,0x09,0x09,0x09,0x01,0x00},/*"等",17*/
{0x00,0x10,0x88,0xC4,0x33,0x40,0x48,0x48,0x48,0x7F,0x48,0xC8,0x48,0x48,0x40,0x00},
{0x02,0x01,0x00,0xFF,0x00,0x02,0x0A,0x32,0x02,0x42,0x82,0x7F,0x02,0x02,0x02,0x00},/*"待",18*/

{0x00,0x02,0x02,0xC2,0x02,0x02,0x02,0xFE,0x82,0x82,0x82,0x82,0x82,0x02,0x00,0x00},
{0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00},/*"正",19*/
{0x08,0x08,0x88,0xC8,0x38,0x0C,0x0B,0x08,0x08,0xE8,0x08,0x08,0x08,0x08,0x08,0x00},
{0x02,0x01,0x00,0xFF,0x40,0x41,0x41,0x41,0x41,0x7F,0x41,0x41,0x41,0x41,0x40,0x00},/*"在",20*/
{0x04,0x14,0xA4,0x44,0xAF,0x14,0x04,0x04,0x04,0xF4,0x0F,0x24,0x44,0x04,0x04,0x00},
{0x12,0x49,0x84,0x42,0x3F,0x81,0x41,0x31,0x0D,0x03,0x0D,0x31,0x41,0x81,0x81,0x00},/*"获",21*/
{0x02,0x02,0xFE,0x92,0x92,0x92,0xFE,0x02,0x06,0xFC,0x04,0x04,0x04,0xFC,0x00,0x00},
{0x08,0x18,0x0F,0x08,0x08,0x04,0xFF,0x04,0x84,0x40,0x27,0x18,0x27,0x40,0x80,0x00},/*"取",22*/
{0x90,0x52,0x34,0x10,0xFF,0x10,0x34,0x52,0x80,0x70,0x8F,0x08,0x08,0xF8,0x08,0x00},
{0x82,0x9A,0x56,0x63,0x22,0x52,0x8E,0x00,0x80,0x40,0x33,0x0C,0x33,0x40,0x80,0x00},/*"数",23*/
{0x10,0x10,0xFF,0x10,0x90,0x00,0xFE,0x92,0x92,0x92,0xF2,0x92,0x92,0x9E,0x80,0x00},
{0x42,0x82,0x7F,0x01,0x80,0x60,0x1F,0x00,0xFC,0x44,0x47,0x44,0x44,0xFC,0x00,0x00},/*"据",24*/

{0x00,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x10,0xF0,0x00,0x00,0x00,0x00,0x00},
{0x80,0x40,0x20,0x18,0x07,0x00,0x00,0x00,0x00,0x00,0x3F,0x40,0x40,0x40,0x78,0x00},/*"九",25*/
{0x10,0x60,0x02,0x0C,0xC0,0x04,0x04,0x04,0x04,0xFC,0x04,0x04,0x04,0x04,0x00,0x00},
{0x04,0x04,0x7C,0x03,0x20,0x20,0x20,0x20,0x20,0x3F,0x20,0x20,0x20,0x20,0x20,0x00},/*"江",26*/
{0x00,0x00,0x10,0x10,0x98,0xA4,0x47,0x44,0xA4,0x54,0x0C,0x04,0x00,0x00,0x00,0x00},
{0x00,0x81,0x89,0x89,0x44,0x44,0x4A,0x31,0x21,0x11,0x09,0x05,0x03,0x00,0x00,0x00},/*"多",27*/
{0x40,0x40,0x42,0x42,0x42,0x42,0xC2,0x42,0x42,0x42,0x42,0x42,0x42,0x40,0x40,0x00},
{0x00,0x20,0x70,0x28,0x24,0x23,0x20,0x20,0x20,0x24,0x28,0x30,0xE0,0x00,0x00,0x00},/*"云",28*/

{0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x20,0x40,0x80,0x00,0x00},
{0x08,0x04,0x03,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,0x00,0x01,0x0E,0x00},/*"小",29*/
{0x02,0xE2,0x22,0x22,0x22,0x22,0x22,0xFE,0x22,0x22,0x22,0x22,0x22,0xE2,0x02,0x00},
{0x00,0xFF,0x00,0x00,0x09,0x12,0x00,0x7F,0x00,0x09,0x12,0x40,0x80,0x7F,0x00,0x00},/*"雨",30*/

{0x10,0x60,0x02,0x8C,0x00,0x00,0xFE,0x92,0x92,0x92,0x92,0x92,0xFE,0x00,0x00,0x00},
{0x04,0x04,0x7E,0x01,0x40,0x7E,0x42,0x42,0x7E,0x42,0x7E,0x42,0x42,0x7E,0x40,0x00},/*"温",31*/
{0x00,0x00,0xFC,0x24,0x24,0x24,0xFC,0x25,0x26,0x24,0xFC,0x24,0x24,0x24,0x04,0x00},
{0x40,0x30,0x8F,0x80,0x84,0x4C,0x55,0x25,0x25,0x25,0x55,0x4C,0x80,0x80,0x80,0x00},/*"度",32*/

{0x10,0x10,0xD0,0xFF,0x90,0x10,0x00,0x42,0xE2,0x52,0x4A,0xC6,0x42,0x40,0xC0,0x00},
{0x04,0x03,0x00,0xFF,0x00,0x23,0x10,0x8C,0x43,0x20,0x18,0x47,0x80,0x40,0x3F,0x00},/*"杨",33*/
{0x00,0x80,0x60,0xF8,0x07,0x08,0x08,0xC8,0x39,0xCE,0x08,0x08,0x08,0x88,0x08,0x00},
{0x01,0x00,0x00,0xFF,0x04,0x02,0x01,0xFF,0x40,0x21,0x06,0x0A,0x11,0x20,0x40,0x00},/*"依",34*/
{0x40,0x40,0x42,0x42,0x42,0x42,0x42,0xFE,0x42,0x42,0x42,0x42,0x42,0x40,0x40,0x00},
{0x80,0x80,0x40,0x20,0x10,0x0C,0x03,0x00,0x03,0x0C,0x10,0x20,0x40,0x80,0x80,0x00},/*"天",35*/
{0x40,0x40,0x42,0x42,0x42,0x42,0x42,0xFE,0x42,0x42,0x42,0x42,0x42,0x40,0x40,0x00},
{0x80,0x80,0x40,0x20,0x10,0x0C,0x03,0x00,0x03,0x0C,0x10,0x20,0x40,0x80,0x80,0x00},/*"天",36*/
{0x80,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0x80,0x00},
{0x00,0x80,0x40,0x30,0x0F,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00},/*"开",37*/
{0x00,0x00,0x80,0x00,0x00,0xE0,0x02,0x04,0x18,0x00,0x00,0x00,0x40,0x80,0x00,0x00},
{0x10,0x0C,0x03,0x00,0x00,0x3F,0x40,0x40,0x40,0x40,0x40,0x78,0x00,0x01,0x0E,0x00},/*"心",38*/

{0x40,0x40,0x42,0xCC,0x00,0x00,0x00,0x84,0x84,0x84,0x84,0x84,0xFC,0x00,0x00,0x00},
{0x00,0x00,0x00,0x7F,0x20,0x10,0x00,0x3F,0x40,0x40,0x40,0x40,0x41,0x40,0x70,0x00},/*"记",39*/
{0x00,0x10,0x88,0xC4,0x33,0x00,0xBE,0xAA,0xAA,0xAA,0xAA,0xAA,0xBE,0x80,0x00,0x00},
{0x02,0x01,0x00,0xFF,0x00,0x02,0x0A,0x12,0x02,0x42,0x82,0x7F,0x02,0x02,0x02,0x00},/*"得",40*/
{0x10,0x10,0x10,0xFF,0x90,0x20,0x98,0x88,0x88,0xE9,0x8E,0x88,0x88,0xA8,0x98,0x00},
{0x02,0x42,0x81,0x7F,0x00,0x00,0x80,0x84,0x4B,0x28,0x10,0x28,0x47,0x80,0x00,0x00},/*"按",41*/
{0x00,0xFC,0x84,0x84,0x84,0xFC,0x00,0x10,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x00},
{0x00,0x3F,0x10,0x10,0x10,0x3F,0x00,0x00,0x01,0x06,0x40,0x80,0x7F,0x00,0x00,0x00},/*"时",42*/
{0x00,0xFC,0x04,0x04,0xFC,0x20,0x10,0x4C,0x4B,0x48,0x48,0x48,0xC8,0x08,0x08,0x00},
{0x00,0x0F,0x04,0x04,0x0F,0x00,0x30,0x48,0x44,0x42,0x42,0x41,0x40,0x40,0x70,0x00},/*"吃",43*/
{0x40,0x30,0xCF,0x08,0x28,0x18,0x00,0xFC,0x24,0xE4,0x24,0x22,0x23,0xE2,0x00,0x00},
{0x00,0x00,0x7F,0x20,0x10,0x80,0x60,0x1F,0x80,0x41,0x26,0x18,0x26,0x41,0x80,0x00},/*"饭",44*/

{0x00,0x08,0x08,0x28,0xC8,0x08,0x08,0xFF,0x08,0x08,0x88,0x68,0x08,0x08,0x00,0x00},
{0x21,0x21,0x11,0x11,0x09,0x05,0x03,0xFF,0x03,0x05,0x09,0x11,0x11,0x21,0x21,0x00},/*"来",45*/
{0x00,0x00,0x00,0xF8,0x88,0x8C,0x8A,0x89,0x88,0x88,0x88,0xF8,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0xFF,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0xFF,0x00,0x00,0x00,0x00},/*"自",46*/
{0x10,0x4C,0x44,0x44,0x44,0x44,0x45,0xC6,0x44,0x44,0x44,0x44,0x44,0x54,0x0C,0x00},
{0x40,0x40,0x44,0x44,0x44,0x44,0x44,0x7F,0x44,0x44,0x54,0x64,0x44,0x40,0x40,0x00},/*"宝",47*/
{0x00,0x00,0x00,0xFE,0x02,0x02,0x02,0xE2,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00},
{0x00,0x00,0x80,0x47,0x20,0x10,0x0C,0x03,0x08,0x10,0x20,0x47,0x80,0x00,0x00,0x00},/*"贝",48*/
{0x00,0xF8,0x0C,0x0B,0x08,0x08,0xF8,0x40,0x30,0x8F,0x08,0x08,0x08,0xF8,0x00,0x00},
{0x00,0x7F,0x21,0x21,0x21,0x21,0x7F,0x00,0x00,0x00,0x43,0x80,0x40,0x3F,0x00,0x00},/*"的",49*/
{0x10,0x10,0x10,0xFF,0x10,0x90,0x00,0xFE,0x92,0x92,0x92,0x92,0x92,0xFE,0x00,0x00},
{0x04,0x44,0x82,0x7F,0x01,0x80,0x42,0x3A,0x42,0x82,0xFE,0x92,0x92,0x92,0x82,0x00},/*"提",50*/
{0xF2,0x12,0xFE,0x12,0xFE,0x12,0xF2,0x00,0x00,0xBE,0x2A,0xEA,0x2A,0x3E,0x00,0x00},
{0xFF,0x4A,0x49,0x48,0x49,0x49,0xFF,0x00,0x42,0x49,0x49,0x7F,0x49,0x49,0x40,0x00},/*"醒",51*/

{0x40,0x40,0x42,0xCC,0x00,0x80,0x88,0x88,0xFF,0x88,0x88,0xFF,0x88,0x88,0x80,0x00},
{0x00,0x40,0x20,0x1F,0x20,0x40,0x50,0x4C,0x43,0x40,0x40,0x5F,0x40,0x40,0x40,0x00},/*"进",52*/
{0x00,0x00,0x00,0x00,0x00,0x01,0xE2,0x1C,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x80,0x40,0x20,0x10,0x0C,0x03,0x00,0x00,0x00,0x03,0x0C,0x30,0x40,0x80,0x80,0x00},/*"入",53*/
{0x00,0x00,0x22,0x32,0x2A,0xA6,0xA2,0x62,0x21,0x11,0x09,0x81,0x01,0x00,0x00,0x00},
{0x00,0x42,0x22,0x13,0x0B,0x42,0x82,0x7E,0x02,0x02,0x0A,0x12,0x23,0x46,0x00,0x00},/*"系",54*/
{0x20,0x30,0xAC,0x63,0x30,0x00,0x88,0xC8,0xA8,0x99,0x8E,0x88,0xA8,0xC8,0x88,0x00},
{0x22,0x67,0x22,0x12,0x12,0x80,0x40,0x30,0x0F,0x00,0x00,0x3F,0x40,0x40,0x71,0x00},/*"统",55*/

{0x40,0x44,0x24,0xA4,0x94,0x8C,0x84,0xFF,0x84,0x8C,0x94,0xA4,0x24,0x44,0x40,0x00},
{0x40,0x40,0x40,0x5F,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x5F,0x40,0x40,0x40,0x00},/*"查",56*/
{0x20,0x22,0x2A,0x2A,0xAA,0x6A,0x3A,0x2E,0x29,0x29,0x29,0x29,0x29,0x20,0x20,0x00},
{0x08,0x04,0x02,0x01,0xFF,0x55,0x55,0x55,0x55,0x55,0x55,0xFF,0x00,0x00,0x00,0x00},/*"看",57*/
{0x00,0xFC,0x84,0x84,0x84,0xFC,0x00,0x10,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x00},
{0x00,0x3F,0x10,0x10,0x10,0x3F,0x00,0x00,0x01,0x06,0x40,0x80,0x7F,0x00,0x00,0x00},/*"时",58*/
{0x00,0xF8,0x01,0x06,0x00,0xF0,0x12,0x12,0x12,0xF2,0x02,0x02,0x02,0xFE,0x00,0x00},
{0x00,0xFF,0x00,0x00,0x00,0x1F,0x11,0x11,0x11,0x1F,0x00,0x40,0x80,0x7F,0x00,0x00},/*"间",59*/


{0x00,0x80,0x60,0xF8,0x07,0x00,0x04,0x24,0x24,0x25,0x26,0x24,0x24,0x24,0x04,0x00},
{0x01,0x00,0x00,0xFF,0x00,0x00,0x00,0xF9,0x49,0x49,0x49,0x49,0x49,0xF9,0x00,0x00},/*"信",60*/
{0x00,0x00,0x00,0xFC,0x54,0x54,0x56,0x55,0x54,0x54,0x54,0xFC,0x00,0x00,0x00,0x00},
{0x40,0x30,0x00,0x03,0x39,0x41,0x41,0x45,0x59,0x41,0x41,0x73,0x00,0x08,0x30,0x00},/*"息",61*/

{0x00,0x00,0x7C,0x40,0x40,0x40,0x40,0xFF,0x40,0x40,0x40,0x40,0xFC,0x00,0x00,0x00},
{0x00,0x7C,0x40,0x40,0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x40,0x40,0xFC,0x00,0x00},/*"出",62*/
{0x00,0xFE,0x20,0x20,0x3F,0x20,0x00,0xFC,0x24,0xE4,0x24,0x22,0x23,0xE2,0x00,0x00},
{0x80,0x7F,0x01,0x01,0xFF,0x80,0x60,0x1F,0x80,0x41,0x26,0x18,0x26,0x41,0x80,0x00},/*"版",63*/
{0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x80,0x40,0x20,0x10,0x0C,0x03,0x00,0x00,0x00,0x03,0x0C,0x10,0x20,0x40,0x80,0x00},/*"人",64*/
{0x80,0x80,0x40,0x20,0x50,0x48,0x44,0xC3,0x44,0x48,0x50,0x20,0x40,0x80,0x80,0x00},
{0x00,0x40,0x22,0x1A,0x02,0x42,0x82,0x7F,0x02,0x02,0x02,0x0A,0x12,0x60,0x00,0x00},/*"余",65*/
{0x10,0x60,0x02,0x8C,0x00,0x44,0x54,0x54,0x54,0x7F,0x54,0x54,0x54,0x44,0x40,0x00},
{0x04,0x04,0x7E,0x01,0x00,0x00,0xFF,0x15,0x15,0x15,0x55,0x95,0x7F,0x00,0x00,0x00},/*"清",65*/
{0x02,0xE2,0x22,0x22,0x3E,0x00,0x80,0x9E,0x92,0x92,0xF2,0x92,0x92,0x9E,0x80,0x00},
{0x00,0x43,0x82,0x42,0x3E,0x40,0x47,0x44,0x44,0x44,0x7F,0x44,0x44,0x54,0xE7,0x00},/*"强",67*/

{0x10,0x88,0xC4,0x33,0x80,0x9E,0x90,0x9F,0x90,0x9E,0x20,0xD8,0x17,0xF0,0x10,0x00},
{0x01,0x00,0xFF,0x80,0x40,0x3E,0x02,0x02,0x3E,0x10,0x88,0x67,0x18,0x67,0x80,0x00},/*"微",68*/
{0x00,0x80,0x60,0xF8,0x07,0x00,0x04,0x24,0x24,0x25,0x26,0x24,0x24,0x24,0x04,0x00},
{0x01,0x00,0x00,0xFF,0x00,0x00,0x00,0xF9,0x49,0x49,0x49,0x49,0x49,0xF9,0x00,0x00},/*"信",69*/

{0x00,0xFC,0x84,0x84,0xFC,0x00,0x44,0x54,0x54,0x54,0x7F,0x54,0x54,0x54,0x44,0x00},
{0x00,0x3F,0x10,0x10,0x3F,0x00,0x00,0xFF,0x15,0x15,0x15,0x55,0x95,0x7F,0x00,0x00},/*"晴",70*/
{0x00,0xFE,0x02,0x22,0xDA,0x06,0x00,0xFE,0x22,0x22,0x22,0x22,0x22,0xFE,0x00,0x00},
{0x00,0xFF,0x08,0x10,0x88,0x47,0x30,0x0F,0x02,0x02,0x02,0x42,0x82,0x7F,0x00,0x00},/*"阴",71*/

{0x00,0x00,0xbe,0x2a,0x2a,0x2a,0x2a,0xea,0x2a,0x2a,0x2a,0x2a,0xbf,0x02,0x00,0x00},
{0x48,0x44,0x4b,0x49,0x49,0x49,0x49,0x7f,0x49,0x49,0x49,0x4d,0x49,0x61,0x40,0x00},/*"星",72*/

/*-- ID:1,??:"?",ASCII??:C6DA,???:?x?=16x16,??:?W=16 ?H=16,?32??*/
{0x00,0x08,0xff,0xa8,0xa8,0xa8,0xff,0x08,0x00,0xfe,0x22,0x22,0x22,0xff,0x02,0x00},
{0x84,0x44,0x37,0x04,0x04,0x14,0xa7,0x44,0x24,0x1f,0x02,0x42,0x82,0x7f,0x00,0x00},/*"期",73*/

/*-- ID:0,??:"?",ASCII??:D2BB,???:?x?=16x16,??:?W=16 ?H=16,?32??*/
{0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xc0,0x80,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"一",74*/

/*-- ID:1,??:"?",ASCII??:B6FE,???:?x?=16x16,??:?W=16 ?H=16,?32??*/
{0x00,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x0c,0x08,0x00,0x00,0x00},
{0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x18,0x10,0x00},/*"二�",75*/

/*-- ID:2,??:"?",ASCII??:C8FD,???:?x?=16x16,??:?W=16 ?H=16,?32??*/
{0x00,0x04,0x84,0x84,0x84,0x84,0x84,0x84,0x84,0x84,0x84,0xc4,0x86,0x04,0x00,0x00},
{0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x30,0x20,0x00},/*"三,76*/

/*-- ID:3,??:"?",ASCII??:CBC4,???:?x?=16x16,??:?W=16 ?H=16,?32??*/
{0x00,0xfc,0x04,0x04,0x04,0xfc,0x04,0x04,0x04,0xfc,0x04,0x04,0x04,0xfe,0x04,0x00},
{0x00,0x7f,0x20,0x28,0x24,0x23,0x20,0x20,0x20,0x21,0x22,0x22,0x22,0x7f,0x00,0x00},/*"四",77*/

/*-- ID:4,??:"?",ASCII??:CEE5,???:?x?=16x16,??:?W=16 ?H=16,?32??*/
{0x00,0x04,0x84,0x84,0x84,0x84,0xfc,0x84,0x84,0x84,0x84,0xc4,0x86,0x84,0x00,0x00},
{0x40,0x40,0x40,0x40,0x78,0x47,0x40,0x40,0x40,0x40,0x40,0x7f,0x40,0x60,0x40,0x00},/*"五,78*/

/*-- ID:5,??:"?",ASCII??:C1F9,???:?x?=16x16,??:?W=16 ?H=16,?32??*/
{0x20,0x20,0x20,0x20,0x20,0x22,0x2c,0x38,0x20,0x20,0x20,0x20,0x20,0x30,0x20,0x00},
{0x00,0x40,0x20,0x18,0x06,0x03,0x00,0x00,0x00,0x01,0x02,0x0c,0x38,0x70,0x00,0x00},/*"六",79*/

/*-- ID:6,??:"?",ASCII??:C8D5,???:?x?=16x16,??:?W=16 ?H=16,?32??*/
{0x00,0x00,0x00,0xfe,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0xff,0x02,0x00,0x00,0x00},
{0x00,0x00,0x00,0x7f,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x7f,0x00,0x00,0x00,0x00},/*"日",80*/

/*-- ID:0,??:"?",ASCII??:BDAD,???:?x?=16x16,??:?W=16 ?H=16,?32??*/
{0x10,0x21,0x62,0x06,0x80,0x04,0x04,0x04,0x04,0xfc,0x04,0x04,0x06,0x04,0x00,0x00},
{0x04,0x04,0xfe,0x01,0x20,0x20,0x20,0x20,0x20,0x3f,0x20,0x20,0x20,0x30,0x20,0x00},/*"江",81*/

/*-- ID:1,??:"?",ASCII??:CEF7,???:?x?=16x16,??:?W=16 ?H=16,?32??*/
{0x04,0xc4,0x44,0x44,0x44,0xfc,0x44,0x44,0x44,0xfc,0x44,0x44,0x44,0xe6,0x44,0x00},
{0x00,0xff,0x40,0x50,0x48,0x47,0x40,0x40,0x40,0x47,0x48,0x48,0x40,0xff,0x00,0x00},/*西,82*/

/*-- ID:2,??:"?",ASCII??:CAA1,???:?x?=16x16,??:?W=16 ?H=16,?32??*/
{0x00,0x00,0x20,0x18,0x86,0x80,0x40,0x5f,0x20,0x20,0x12,0x04,0x88,0x18,0x00,0x00},
{0x02,0x02,0x01,0x01,0xff,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0xff,0x01,0x00,0x00},/*省",83*/

/*-- ID:3,??:"?",ASCII??:CAD0,???:?x?=16x16,??:?W=16 ?H=16,?32??*/
{0x08,0x08,0xc8,0x48,0x48,0x48,0x49,0xfa,0x48,0x48,0x48,0x48,0xe8,0x4c,0x08,0x00},
{0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0x10,0x20,0x1f,0x00,0x00,0x00},/*"市",84*/

{0x80,0x80,0x80,0x80,0xFF,0x80,0x80,0xA0,0x90,0x88,0x84,0x82,0x80,0x80,0x80,0x00},
{0x00,0x00,0x00,0x00,0xFF,0x40,0x21,0x12,0x04,0x08,0x10,0x20,0x20,0x40,0x40,0x00},/*"长",85*/

{0x10,0x60,0x02,0x8C,0x00,0x80,0x60,0x18,0x00,0xFF,0x00,0x00,0x88,0x10,0x60,0x00},
{0x04,0x04,0x7E,0x01,0x00,0x80,0x80,0x40,0x40,0x23,0x10,0x0C,0x03,0x00,0x00,0x00},/*"沙",86*/


{0x20,0x20,0xFF,0x20,0x20,0xF8,0x88,0x88,0x88,0x08,0xFF,0x08,0x09,0xCA,0x08,0x00},
{0x10,0x30,0x1F,0x88,0x68,0x1F,0x10,0x20,0x9F,0x40,0x27,0x18,0x26,0x41,0xF0,0x00},/*"城",87*/

{0x00,0x08,0x88,0x88,0x88,0x88,0x89,0xFA,0x88,0x88,0x88,0x88,0x88,0x08,0x00,0x00},
{0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x10,0x20,0x1F,0x00,0x00,0x00},/*"市",88*/

{0x40,0x40,0x42,0xCC,0x00,0x50,0x4E,0xC8,0x48,0x7F,0xC8,0x48,0x48,0x40,0x00,0x00},
{0x00,0x40,0x20,0x1F,0x20,0x50,0x4C,0x43,0x40,0x40,0x4F,0x50,0x50,0x5C,0x40,0x00},/*"选",89*/

{0x10,0x10,0xFF,0x10,0x00,0x82,0x86,0x4A,0x52,0xA2,0x52,0x4A,0x86,0x80,0x80,0x00},
{0x42,0x82,0x7F,0x01,0x00,0x10,0x12,0x12,0x12,0xFF,0x12,0x12,0x12,0x10,0x00,0x00},/*"择",90*/

{0x10,0x60,0x02,0x8C,0x00,0x88,0x88,0xFF,0x88,0x88,0x00,0xFE,0x22,0x22,0xFE,0x00},
{0x04,0x04,0x7E,0x01,0x00,0x1F,0x08,0x08,0x08,0x9F,0x60,0x1F,0x42,0x82,0x7F,0x00},/*"湖",91*/

{0x04,0xE4,0x24,0x24,0x64,0xA4,0x24,0x3F,0x24,0xA4,0x64,0x24,0x24,0xE4,0x04,0x00},
{0x00,0xFF,0x00,0x08,0x09,0x09,0x09,0x7F,0x09,0x09,0x09,0x48,0x80,0x7F,0x00,0x00},/*"南",92*/



};
#endif


