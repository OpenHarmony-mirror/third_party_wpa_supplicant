#ifndef __SIDECAR_H__
#define __SIDECAR_H__
#include "message_router.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SideCar_ {
    /*
    sendData ��ָ��ֻ��ʹ�ö��ڴ�
    */
    ErrorCode (*SendOneWayMessage)(struct SideCar_ *sideCar, ServiceID receiver, uint32_t commandID,
        DataBlock sendData);

    /*
    ע��sendData �� recvData�е��ڴ���Ҫ���÷��ͷš�sendData��responseStatus�п���ʹ��ջ�ڴ棬recvDataһ���Ƕ��ڴ�
    */
    ErrorCode (*SendSyncMessage)(struct SideCar_ *sideCar, ServiceID receiver, uint32_t commandID,
        const DataBlock *sendData, DataBlock *recvData, uint16_t *responseStatus);

    /*
    commandID : ��Ϣ��Ψһ��ʶ
    sendData : Ҫ���͵����ݣ�����dataָ�����ʹ�ö��ڴ�
    callback : �ص�������NULL�����ص����Է�ҵ�񷵻���Ϣʱ�ػص��ýӿڡ�callback����������ͷ��ڴ�һ����data��size����0��������ͷ�ϵͳ�᳢�Ի��ա�
    */
    ErrorCode (*SendAsyncMessage)(struct SideCar_ *sideCar, ServiceID receiver, uint32_t commandID, DataBlock sendData,
        MessageCallBack callback);

    void *privateData;
} SideCar;

ErrorCode ConstructSideCar(SideCar *sideCar, ServiceID serviceID);

ErrorCode DeconstructSideCar(SideCar *sideCar);

#ifdef __cplusplus
}
#endif

#endif