//----------------------------------------------------
// Copyright (c) 2014, SHENZHEN PENGRUI SOFT CO LTD. All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:

// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------
// Copyright (c) 2014 ����Ȩ�����������������޹�˾���С�����Ȩ�˱���һ��Ȩ����
//
// �����Ȩ�����ʹ���߷������������������£�����ʹ����ʹ�ü���ɢ����
// ������װԭʼ�뼰����λ��ִ����ʽ��Ȩ�������۴˰�װ�Ƿ񾭸�����Ȼ��
//
// 1. ���ڱ�����Դ�������ɢ�������뱣�������İ�Ȩ���桢�������б�����
//    ������������������
// 2. ���ڱ��׼�����λ��ִ����ʽ����ɢ���������������ļ��Լ�������������
//    ��ɢ����װ�е�ý�鷽ʽ����������֮��Ȩ���桢�������б����Լ�����
//    ������������

// �����������������Ǳ�������Ȩ�������Լ�����������״��"as is"���ṩ��
// ��������װ�����κ���ʾ��Ĭʾ֮�������Σ������������ھ��������Լ��ض�Ŀ
// �ĵ�������ΪĬʾ�Ե�������Ȩ�����˼�������֮�����ߣ������κ�������
// ���۳�����κ��������塢���۴�����Ϊ���Լ��ϵ���޹�ʧ������������Υ
// Լ֮��Ȩ��������ʧ������ԭ��ȣ����𣬶����κ���ʹ�ñ�������װ��������
// �κ�ֱ���ԡ�����ԡ�ż���ԡ������ԡ��ͷ��Ի��κν�����𺦣�����������
// �������Ʒ������֮���á�ʹ����ʧ��������ʧ��������ʧ��ҵ���жϵȵȣ���
// �����κ����Σ����ڸ���ʹ���ѻ���ǰ��֪���ܻ���ɴ����𺦵���������Ȼ��
//-----------------------------------------------------------------------------
//����ģ��:ʱ��ģ��
//����:  ������
//�汾��V1.0.0
//�ļ�����: Ϊϵͳ�ṩʱ��
//����˵��:
//�޶���ʷ:
// 1. ����: 2011-10-28
//   ����:  ������
//   �°汾��: V1.0.0
//   �޸�˵��: ԭʼ�汾
//------------------------------------------------------

#ifndef __TIME_H__
#define __TIME_H__
#include "stdint.h"
#include "errno.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef bool_t (*fntRtc_GetTime)(s64 *time); //��RTC�豸�ж�ȡRTCʱ�䣬��λ΢��
                                               //ȡ��1970��1��1��0:0:0�����ڵ�ʱ���
typedef bool_t (*fntRtc_SetTime)(s64 time);  //����RTC�豸RTCʱ�䣬��λ΢��
                                               //��ʱ���1970��1��1��0:0:0�����ڵ�ʱ���

//ʱ��ģ�������Ϣ����
enum _CLOCK_ERROR_CODE_
{
    EN_CLOCK_NO_ERROR = CN_CLOCK_NO_ERROR,    //û�д���
    EN_CLOCK_YEAR_ERROR,
    EN_CLOCK_MON_ERROR,
    EN_CLOCK_DAY_ERROR,
    EN_CLOCK_HOUR_ERROR,
    EN_CLOCK_MIN_ERROR,
    EN_CLOCK_SEC_ERROR,
    EN_CLOCK_FMT_ERROR
};

struct tm
{
    s32 tm_us;      // ΢��-ȡֵ����[0,999999]
    s32 tm_sec;     // ��Cȡֵ����Ϊ[0,59]
    s32 tm_min;     // �� - ȡֵ����Ϊ[0,59]
    s32 tm_hour;    // ʱ - ȡֵ����Ϊ[0,23]
    s32 tm_mday;    // һ�����е����� - ȡֵ����Ϊ[1,31]
    s32 tm_mon;     // �·ݣ���һ�¿�ʼ��0����һ�£� - ȡֵ����Ϊ[0,11]
    s32 tm_year;    // ��ݣ���ֵ��1900��ʼ
    s32 tm_wday;    // ���ڨCȡֵ����Ϊ[0,6]������0���������죬1��������һ��
                    // �Դ�����
    s32 tm_yday;    // ��ÿ���1��1�տ�ʼ�������Cȡֵ����Ϊ[0,365]������0����
                    //1��1�գ�1����1��2�գ��Դ�����
    s32 tm_isdst;   // ����ʱ��ʶ����ʵ������ʱ��ʱ��tm_isdstΪ������ʵ��
                    //����ʱ�Ľ���tm_isdstΪ0�����˽����ʱ��tm_isdst()Ϊ����
    //added by zqf--todo
    long int tm_gmtoff; /*ָ�������ڱ���߶���ʱ����UTC����ʱ����������UTC����ʱ���ĸ�����*/
    const char *tm_zone; /*��ǰʱ��������(�뻷������TZ�й�)*/
};

extern char g_cTmWdays[][8];

//ptu32_t ModuleInstall_TM(ptu32_t para);
s64 Tm_Time(s64 *ret);
s64 Tm_TimeMs(s64 *ret);
s64 Tm_TimeUs(s64 *ret);
struct tm *Tm_GmTime(const s64 *time);
struct tm *Tm_LocalTime(const s64 *time);
struct tm *Tm_LocalTimeUs_r(const s64 *time_us,struct tm *result);
struct tm *Tm_LocalTime_r(const s64 *time,struct tm *result);
void Tm_IncSecond(u32 inc);
void Tm_AscTime(struct tm *tm, char buf[]);
void Tm_AscTimeMs(struct tm *tm, char buf[]);
void Tm_AscTimeuS(struct tm *tm, char buf[]);

s64 Tm_MkTime(struct tm *dt);
s64 Tm_MkTimeUs(struct tm *dt);
extern int Tm_SetDateTimeStr(char *buf);
void Tm_SetDateTime(struct tm *tm);
struct tm *Tm_GmTime(const s64 *time);

bool_t Rtc_RegisterDev(fntRtc_GetTime gettimefunc,
        fntRtc_SetTime settimefunc);


//the c lib interface for time  --modified by zqf

typedef s64  __time_t;
typedef s32  __suseconds_t;
typedef __time_t time_t;

#ifndef _TIMEVAL_DEFINED /* ����������Ҳ���ܶ��� */
#define _TIMEVAL_DEFINED
struct timeval
{
    __time_t           tv_sec;
    __suseconds_t      tv_usec;
};
#define timerisset(tvp)  ((tvp)->tv_sec || (tvp)->tv_usec)
#define timercmp(tvp, uvp, cmp) \
    (((tvp)->tv_sec != (uvp)->tv_sec) ? \
    ((tvp)->tv_sec cmp (uvp)->tv_sec) : \
    ((tvp)->tv_usec cmp (uvp)->tv_usec))
#define timerclear(tvp)  (tvp)->tv_sec = (tvp)->tv_usec = 0
#endif /* _TIMEVAL_DEFINED */

struct timezone {
    int tz_minuteswest;     /* minutes west of Greenwich */
    int tz_dsttime;         /* type of DST correction */
};

char *asctime(const struct tm *tm);
char *asctime_r(const struct tm *tm, char *buf);

char *ctime(const time_t *timep);
char *ctime_r(const time_t *timep, char *buf);

struct tm *gmtime(const time_t *timep);
struct tm *gmtime_r(const time_t *timep, struct tm *result);

struct tm *localtime(const time_t *timep);
struct tm *localtime_r(const time_t *timep, struct tm *result);

time_t mktime(struct tm *tm);
time_t time(time_t *t);

int gettimeofday(struct timeval *tv, struct timezone *tz);
int settimeofday(const struct timeval *tv, const struct timezone *tz);

int gettimezone(int *result);
int settimezone(int timezone);

#ifdef __cplusplus
}
#endif

#endif
