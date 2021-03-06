#ifndef _CSWORLD_INFO_H
#define _CSWORLD_INFO_H


// ���̴����� �ð���
enum GAME_TIME_TYPE
{
	TIME_INVALID = -1,
	TIME_DAWN = 0,			// ����
	TIME_DAYTIME,			// ��
	TIME_SUNSET,			// ������
	TIME_NIGHT,				// ��
	TIME_CUSTOM1,
	TIME_CUSTOM2,
	MAX_TIME_TYPE
};

static const TCHAR* GAME_TIME_TYPE_NAME[] = 
{
	_T("TIME_DAWN"),
	_T("TIME_DAYTIME"),
	_T("TIME_SUNSET"),
	_T("TIME_NIGHT"),
	_T("TIME_CUSTOM1"),
	_T("TIME_CUSTOM2"),
};	

// ���̴����� ����
enum GAME_WEATHER_TYPE
{
	WEATHER_INVALID = -1,
	WEATHER_SUNNY = 0,		// ����
	WEATHER_CLOUDY,			// �帲
	WEATHER_RAINY,			// ��
	WEATHER_HEAVY_RAINY,	// ����
	WEATHER_SNOWY,			// ��
	WEATHER_HEAVY_SNOWY,	// ����
	WEATHER_CUSTOM1,
	WEATHER_CUSTOM2,
	MAX_WEATHER_TYPE
};

static const TCHAR* GAME_WEATHER_TYPE_NAME[] = 
{
	_T("WEATHER_SUNNY"),
	_T("WEATHER_CLOUDY"),
	_T("WEATHER_RAINY"),
	_T("WEATHER_HEAVY_RAINY"),
	_T("WEATHER_SNOWY"),
	_T("WEATHER_HEAVY_SNOWY"),
	_T("WEATHER_CUSTOM1"),
	_T("WEATHER_CUSTOM2")
};	

#define DEFAULT_GAME_TIME		TIME_DAYTIME	// �⺻ �ð���
#define DEFAULT_GAME_WEATHER	WEATHER_SUNNY	// �⺻ ����

#define W_SUN	WEATHER_SUNNY
#define W_CLD	WEATHER_CLOUDY
#define W_RNY	WEATHER_RAINY
#define W_HRN	WEATHER_HEAVY_RAINY
#define W_SNW	WEATHER_SNOWY
#define W_HSW	WEATHER_HEAVY_SNOWY
//#define W_CLR	WEATHER_CLEAR

#define MAX_NORMAL_WEATHER_TYPE	WEATHER_CUSTOM1	// custom1, custom2�� ���ÿ� ������� �ʴ´�.


#endif // _CSWORLD_INFO_H