#ifndef __CD_API_H__
#define __CD_API_H__
#include "CDCASS.h"
#include "gxcas.h"
#define GXCAS_CD_MAX_PIN_LEN (8)
#define MAX_DATA_LEN (GXCAS_EVENT_MAX_LEN - 4)

typedef struct{
	CDCA_U16 wTvsID;
	CDCA_U8 byActionType;
	CDCA_U8 byLen;
	CDCA_U8 pbyData[MAX_DATA_LEN];
}GxCas_CdActionRequestExit;

typedef struct {
	CDCA_U16 byMessageType;
	CDCA_U16 wEcmPid;
	SCDCAIppvBuyInfo pIppvProgram;
}GxCas_CdIppvBuyInfo;

typedef struct{
	CDCA_U32 byShow;
	CDCA_U32 dwEmailId;
}GxCas_CdEmailNotify;

typedef struct {
	CDCA_U8 pin[GXCAS_CD_MAX_PIN_LEN];
	CDCA_U8 start_hour;
	CDCA_U8 start_min;
	CDCA_U8 start_sec;
	CDCA_U8 end_hour;
	CDCA_U8 end_min;
	CDCA_U8 end_sec;
}GxCas_CdWorkTime;

typedef struct{
	CDCA_U8 pin[GXCAS_CD_MAX_PIN_LEN];
	CDCA_U32 rating;
}GxCas_CdSetRating;

typedef struct{
	CDCA_U32 byStyle;
	char szMessage[CDCA_MAXLEN_OSD];
}GxCas_CdShowOsdMessage;

typedef struct{
	CDCA_U16 wEcmPid;
	CDCA_U16 byMessageType;
}GxCas_CdBuyMessage;

typedef struct{
	CDCA_U32 wEcmPid;
	char fingerMsg[MAX_DATA_LEN];
}GxCas_CdFingerMessage;

typedef struct{
	CDCA_U16 wEcmPid;
	CDCA_U16 wCurtainCode;
}GxCas_CdShowCurtainNotify;

typedef struct{
	CDCA_U16 byProgress;
	CDCA_U16 byMark;
}GxCas_CdProgressStrip;

typedef struct{
	CDCA_U16 operator_id;
	CDCA_U16 count;
	SCDCAIppvInfo info[CDCA_MAXNUM_IPPVP];
}GxCas_CdGetIppvInfo;

typedef struct{
	CDCA_U32 operator_id;
	CDCA_U8 slot_id[CDCA_MAXNUM_SLOT];
}GxCas_CdGetIppvSlotIDS;

typedef struct{
	CDCA_U16 operator_id;
	CDCA_U16 slot_id;
	SCDCATVSSlotInfo info;
}GxCas_CdGetSlotInfo;

typedef struct {
    unsigned int mail_id;//
    unsigned char read_status;// 0:read; 1:unread
    char          create_time[20];//2015-09-18 13:20:09
    char          importance;// 0: normal; 1:important
    char          title[37];
}GxCas_CdGetHeadInfo;

typedef struct {
    unsigned short mail_total;// the max num is 100
    unsigned short mail_unread_count;
    GxCas_CdGetHeadInfo *mail_head;
}GxCas_CdGetMailHeadInfo;

typedef struct{
	CDCA_U32 pos;
	SCDCAEmailContent email_content;
}GxCas_CdGetMailContent;

typedef struct{
	CDCA_U16 operator_id;
	CDCA_BOOL read_status;
	CDCA_U32 chknums[CDCA_MAXNUM_DETITLE];
}GxCas_CdDetitleChk;

typedef struct{
	CDCA_U32 pos;
	CDCA_U32 count;
}GxCas_CdDelMail;

typedef struct{
	CDCA_U8 old_pin[GXCAS_CD_MAX_PIN_LEN];
	CDCA_U8 new_pin[GXCAS_CD_MAX_PIN_LEN];
}GxCas_CdChangePin;

typedef struct{
	CDCA_U16 operator_id;
	CDCA_U16 res;
	SCDCAEntitles entitle_info;
}GxCas_CdGetEntitle;

typedef struct{
	CDCA_BOOL buy_flag;
	CDCA_U16 ecm_pid;
	CDCA_U8 pin[GXCAS_CD_MAX_PIN_LEN];
	SCDCAIPPVPrice price;
}GxCas_CdStopIppv;

typedef struct{
	CDCA_U16 operator_id;
	SCDCAOperatorInfo operator_info;
}GxCas_CdGetOperatorInfo;

typedef struct{
	CDCA_U16 operator_id;
	CDCA_U32 ac_list[CDCA_MAXNUM_ACLIST];
}GxCas_CdGetAclist;

typedef struct{
	CDCA_U16 wTvsID;
	CDCA_U32 dwDetitleChkNum;
}GxCas_CdSetDelDetitleNum;

typedef struct{
	CDCA_U16 operator_id;
	CDCA_U16 count;
}GxCas_CdGetEntitleCount;

typedef struct{
	CDCA_U8 pbyNum;
	CDCA_U8 stb_id[30];
}GxCas_CdGetPaired;

typedef struct{
	CDCA_U16 ecm_pid;
	CDCA_U16 record;
}GxCas_CdGetRecordAttribute;

typedef struct{
	CDCA_U16 wTvsID;
	CDCA_U8 pbyChild;
	CDCA_U16 pbyDelayTime;
	CDCA_U32 pLastFeedTime;
	char pParentCardSN[CDCA_MAXLEN_SN + 1];
	CDCA_BOOL pbIsCanFeed;
}GxCas_CdGetChildInfo;

typedef struct {
	uint8_t serial_number[8];
	uint8_t card_id[4];
	uint8_t card_sn[16];
}GxCas_CdGetCardInfo;

#define GXCAS_CD_CARD_IN                          GXCAS_IO(GXCAS_EVENT, 0)
#define GXCAS_CD_CARD_OUT                         GXCAS_IO(GXCAS_EVENT, 1)
#define GXCAS_CD_EMAIL_NOTIFY                     GXCAS_IOR(GXCAS_EVENT, 2, GxCas_CdEmailNotify)
#define GXCAS_CD_ENTITLE_CHANGED                  GXCAS_IOR(GXCAS_EVENT, 3, CDCA_U16)
#define GXCAS_CD_DETITLE                          GXCAS_IOR(GXCAS_EVENT, 4, CDCA_U8)
#define GXCAS_CD_SHOW_IPPV                        GXCAS_IOR(GXCAS_EVENT, 5, GxCas_CdIppvBuyInfo)
#define GXCAS_CD_HIDE_IPPV                        GXCAS_IOR(GXCAS_EVENT, 6, CDCA_U16)
#define GXCAS_CD_OSD_SHOW                         GXCAS_IOR(GXCAS_EVENT, 7, GxCas_CdShowOsdMessage)
#define GXCAS_CD_OSD_HIDE                         GXCAS_IOR(GXCAS_EVENT, 8, CDCA_U8)
#define GXCAS_CD_LOCK_SERVICE                     GXCAS_IOR(GXCAS_EVENT, 9, SCDCALockService)
#define GXCAS_CD_UNLOCK_SERVICE                   GXCAS_IO(GXCAS_EVENT, 10)
#define GXCAS_CD_SHOW_BUY_MESSAGE                 GXCAS_IOR(GXCAS_EVENT, 11, GxCas_CdBuyMessage)
#define GXCAS_CD_SHOW_FINGER_MESSAGE              GXCAS_IOR(GXCAS_EVENT, 12, GxCas_CdFingerMessage)
#define GXCAS_CD_HIDE_FINGER_MESSAGE              GXCAS_IOR(GXCAS_EVENT, 13, GxCas_CdFingerMessage)
#define GXCAS_CD_ACTION_REQUEST_EXIT              GXCAS_IOR(GXCAS_EVENT, 14, GxCas_CdActionRequestExit)
#define GXCAS_CD_SHOW_PROGRESS                    GXCAS_IOR(GXCAS_EVENT, 15, GxCas_CdProgressStrip)
#define GXCAS_CD_SHOW_CURTAIN_NOTIFY              GXCAS_IOR(GXCAS_EVENT, 16, GxCas_CdShowCurtainNotify)
#define GXCAS_CD_SHOW_FEEDINGREQUEST              GXCAS_IOR(GXCAS_EVENT, 17, CDCA_BOOL)

#define GXCAS_CD_SWITCH_CHANNEL                   GXCAS_IOW(GXCAS_SET, 30, GxCasSet_SwitchChannel)
#define GXCAS_CD_DELETE_EMAIL                     GXCAS_IOW(GXCAS_SET, 31, GxCas_CdDelMail)
#define GXCAS_CD_SET_WORKTIME                     GXCAS_IOW(GXCAS_SET, 32, GxCas_CdWorkTime)
#define GXCAS_CD_SET_RATING                       GXCAS_IOW(GXCAS_SET, 33, GxCas_CdSetRating)
#define GXCAS_CD_SET_PIN                          GXCAS_IOW(GXCAS_SET, 34, GxCas_CdChangePin)
#define GXCAS_CD_STOP_IPPV                        GXCAS_IOW(GXCAS_SET, 35, GxCas_CdStopIppv)
#define GXCAS_CD_STOP_DESCRAMBLE                  GXCAS_IO(GXCAS_SET, 36)
#define GXCAS_CD_STOP_CA                          GXCAS_IO(GXCAS_SET, 37)
#define GXCAS_CD_DELETE_DETITLE                   GXCAS_IOW(GXCAS_SET, 38, GxCas_CdSetDelDetitleNum)
#define GXCAS_CD_SET_TIMEZONE                     GXCAS_IOW(GXCAS_SET, 39, double)
#define GXCAS_CD_ADD_SERVICE                      GXCAS_IOW(GXCAS_SET, 40, GxCas_Service[8])
#define GXCAS_CD_DELETE_SERVICE                   GXCAS_IOW(GXCAS_SET, 41, GxCas_Service[8])
#define GXCAS_CD_SET_LOCK_SERVICE                 GXCAS_IOW(GXCAS_SET, 42, GxCas_Service[8])
#define GXCAS_CD_READ_FEED_DATA                   GXCAS_IOW(GXCAS_SET, 42, CDCA_U16)
#define GXCAS_CD_WRITE_FEED_DATA                  GXCAS_IOW(GXCAS_SET, 43, CDCA_U16)
#define GXCAS_CD_START_CA                         GXCAS_IO(GXCAS_SET, 44)

#define GXCAS_CD_GET_SN                           GXCAS_IOR(GXCAS_GET, 50, CDCA_U8[CDCA_MAXLEN_SN + 1])
#define GXCAS_CD_GET_PLATFORM                     GXCAS_IOR(GXCAS_GET, 51, CDCA_U16)
#define GXCAS_CD_GET_CAS_VER_ID                   GXCAS_IOR(GXCAS_GET, 52, CDCA_U32)
#define GXCAS_CD_GET_RATING                       GXCAS_IOR(GXCAS_GET, 53, CDCA_U8)
#define GXCAS_CD_GET_CHIP_ID                      GXCAS_IOR(GXCAS_GET, 54, CDCA_U32)

#define GXCAS_CD_GET_EMAIL_HEAD                   GXCAS_IOR(GXCAS_GET, 55, GxCas_CdGetMailHeadInfo)
#define GXCAS_CD_GET_EMAIL_COUNT                  GXCAS_IOR(GXCAS_GET, 56, CDCA_U8)
#define GXCAS_CD_GET_EMAIL_CONTENT                GXCAS_IOR(GXCAS_GET, 57, GxCas_CdGetMailContent)

#define GXCAS_CD_GET_OPERATOR_ID                  GXCAS_IOR(GXCAS_GET, 58, CDCA_U16[CDCA_MAXNUM_OPERATOR])
#define GXCAS_CD_GET_OPERATOR_INFO                GXCAS_IOR(GXCAS_GET, 59, SCDCAOperatorInfo)
#define GXCAS_CD_GET_ENTITLE_COUNT                GXCAS_IOR(GXCAS_GET, 60, GxCas_CdGetEntitleCount)
#define GXCAS_CD_GET_ENTITLE_INFO                 GXCAS_IOR(GXCAS_GET, 61, GxCas_CdGetEntitle)

#define GXCAS_CD_GET_DETITLE                      GXCAS_IOR(GXCAS_GET, 62, GxCas_CdDetitleChk)
#define GXCAS_CD_GET_IPPV_SLOT_IDS                GXCAS_IOR(GXCAS_GET, 63, GxCas_CdGetIppvSlotIDS)
#define GXCAS_CD_GET_IPPV_SLOT_INFO               GXCAS_IOR(GXCAS_GET, 64, GxCas_CdGetSlotInfo)
#define GXCAS_CD_GET_IPPV_INFO                    GXCAS_IOR(GXCAS_GET, 65, GxCas_CdGetIppvInfo)
#define GXCAS_CD_GET_FEATURE                      GXCAS_IOR(GXCAS_GET, 66, GxCas_CdGetAclist)
#define GXCAS_CD_GET_WORKTIME                     GXCAS_IOR(GXCAS_GET, 67, GxCas_CdWorkTime)
#define GXCAS_CD_GET_IS_PAIRED                    GXCAS_IOR(GXCAS_GET, 68, GxCas_CdGetPaired)
#define GXCAS_CD_GET_RECORD_ATTRIBUTE             GXCAS_IOR(GXCAS_GET, 69, GxCas_CdGetRecordAttribute)
#define GXCAS_CD_GET_CHILDINFO                    GXCAS_IOR(GXCAS_GET, 70, GxCas_CdGetChildInfo)
#define GXCAS_CD_GET_CARD_INFO                    GXCAS_IOR(GXCAS_GET, 71, GxCas_CdGetCardInfo)

int32_t GxCas_CdHsInit(const GxCasInitParam);
#endif

