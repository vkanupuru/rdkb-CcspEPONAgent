/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2015 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#include "ansc_platform.h"
#include "cosa_apis_epon_plugin.h"
#include "ccsp_trace.h"
#include "dpoe_hal.h"

static ULONG                           i               = 0;

#ifndef EPONAGENTLOG
#define INFO  0
#define WARNING  1
#define ERROR 2
#define EPONAGENTLOG(x, ...) {fprintf(stderr, "EponAgentLog<%s:%d> ", __FUNCTION__, __LINE__);fprintf(stderr, __VA_ARGS__);}
#endif

BOOL
DPoE_GetParamUlongValue
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        ULONG*                      puLong
    )
{
EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)
    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "NumberOfNetworkPorts", TRUE) )
    {
        return dpoe_getNumberOfNetworkPorts(puLong);
    }
    else if( AnscEqualString(ParamName, "NumberOfS1Interfaces", TRUE) )
    {
        return dpoe_getNumberOfS1Interfaces( puLong );
    }
    else if( AnscEqualString(ParamName, "DynamicMacAddressAgeLimit", TRUE) )
    {
        return dpoe_getDynamicMacAddressAgeLimit( puLong );
    }
    else if( AnscEqualString(ParamName, "DynamicMacLearningTableSize", TRUE) )
    {
        return dpoe_getDynamicMacLearningTableSize( puLong );
    }
    else if( AnscEqualString(ParamName, "MacLearningAggregateLimit", TRUE) )
    {
        return dpoe_getMacLearningAggregateLimit( puLong );
    }

    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return FALSE;
}

BOOL
DPoE_SetParamUlongValue
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        ULONG                       uValue
    )
{
EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)
    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return FALSE;
}


BOOL
DPoE_SetParamStringValue
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        char*                       pString
    )
{
EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)
    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return FALSE;
}


BOOL
DPoE_GetParamStringValue
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        char*                       pValue,
        ULONG*                      pUlSize
    )
{
EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)
    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "Mac_Address", TRUE) )
    {
        /* todo */
        // set pUlSize to total bytes of OnuId...
        return dpoe_getOnuId( (dpoe_mac_address_t *)pValue );
    }

    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return FALSE;
}


BOOL
DPoE_GetParamBoolValue
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        BOOL*                       pBool
    )
{
EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)
    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return FALSE;
}
BOOL
DPoE_SetParamBoolValue
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        BOOL                        bValue
    )
{
EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)
    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "ResetOnu", TRUE) )
    {
        return dpoe_setResetOnu();
    }
    else if( AnscEqualString(ParamName, "ClearOnuLinkStatistics", TRUE) )
    {
        return dpoe_setClearOnuLinkStatistics();
    }
EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
    return FALSE;
}

BOOL
DPoE_GetParamIntValue
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        INT*                        iValue
    )
{
EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)
    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return FALSE;
}

BOOL
DPoE_SetParamIntValue
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        INT                         iValue
    )
{
EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)
    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return FALSE;
}

/**********************************************************************  

    caller:     owner of this object 

    prototype: 

        ULONG
        DPoE_Commit
            (
                ANSC_HANDLE                 hInsContext
            );

    description:

        This function is called to finally commit all the update.

    argument:   ANSC_HANDLE                 hInsContext,
                The instance handle;

    return:     The status of the operation.

**********************************************************************/
ULONG
DPoE_Commit
    (
        ANSC_HANDLE                 hInsContext
    )
{
    EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)
    EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return 0;
}

BOOL
DPoE_Validate
    (
        ANSC_HANDLE                 hInsContext,
        char*                       pReturnParamName,
        ULONG*                      puLength
    )
{
    EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)
    EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return FALSE;
}

ULONG
DPoE_Rollback
    (
        ANSC_HANDLE                 hInsContext
    )
{
    EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)
    EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return 0;
}

BOOL DPoE_FirmwareInfo_GetParamStringValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    char*                       pValue,
    ULONG*                      pUlSize
)
{
    dpoe_firmware_info_t    FirmwareInfo;
    BOOL status = dpoe_getFirmwareInfo( &FirmwareInfo );
    *pValue = NULL;
    *pUlSize = 0L;

    EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)
    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "bootVersion", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *pUlSize = strlen( (char *)&FirmwareInfo.info_bootVersion );
            strncpy ( pValue, (char *)&FirmwareInfo.info_bootVersion, *pUlSize );
        }
    }
    else if( AnscEqualString(ParamName, "appVersion", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *pUlSize = strlen( (char *)&FirmwareInfo.info_appVersion );
            strncpy( pValue, (char *)&FirmwareInfo.info_appVersion, *pUlSize );
        }
    }
    else
    {
        AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
        return FALSE;
    }
    
    EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return status;
}

BOOL DPoE_FirmwareInfo_GetParamUlongValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    ULONG*                      pLong
)
{
    dpoe_firmware_info_t    FirmwareInfo;
    BOOL status = dpoe_getFirmwareInfo( &FirmwareInfo );
    *pLong = 0L;

    EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)

    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "bootCrc32", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *pLong = FirmwareInfo.info_bootCrc32;
        }
    }
    else if( AnscEqualString(ParamName, "appCrc32", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *pLong = FirmwareInfo.info_appCrc32;
        }
    }
    else
    {
        AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
        return FALSE;
    }

    EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return status;
}

BOOL DPoE_ChipInfo_GetParamStringValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    char*                       pValue,
    ULONG*                      pUlSize
)
{
    dpoe_epon_chip_info_t EponChipInfo;
    BOOL status = dpoe_getEponChipInfo( &EponChipInfo );
    *pValue = NULL;
    *pUlSize = 0L;

    EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)

    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "chipModel", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *pUlSize = strlen( (char *)&EponChipInfo.info_ChipModel );
            strncpy( pValue, (char *)&EponChipInfo.info_ChipModel, *pUlSize );
        }
    }
    else if( AnscEqualString(ParamName, "chipVersion", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *pUlSize = strlen( (char *)&EponChipInfo.info_ChipVersion );
            strncpy( pValue, (char *)&EponChipInfo.info_ChipVersion, *pUlSize );
        }
    }
    else
    {
        AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
        return FALSE;
    }

    EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return status;
}

BOOL DPoE_ChipInfo_GetParamUlongValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    ULONG*                      pLong
)
{
    dpoe_epon_chip_info_t EponChipInfo;
    BOOL status = dpoe_getEponChipInfo( &EponChipInfo );
    *pLong = 0L;

    EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)
    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "jedecId", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *pLong = EponChipInfo.info_JedecId;
        }
    }
    else
    {
        AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
        return FALSE;
    }

    EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return status;
}

BOOL DPoE_ManufacturerInfo_GetParamStringValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    char*                       pValue,
    ULONG*                      pUlSize
)
{
    dpoe_manufacturer_t    ManufacturerInfo;
    BOOL status = dpoe_getManufacturerInfo(&ManufacturerInfo);
    *pValue = NULL;
    *pUlSize = 0L;

    EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)
    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "info", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *pUlSize = strlen( (char *)&ManufacturerInfo.manufacturer_Info );
        }
    }
    else if( AnscEqualString(ParamName, "organizationName", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            //TODO: Abdul
            //*pUlSize = strlen( (char *)&ManufacturerInfo.manufacturer_organizationName );
        }
    }
    else if( AnscEqualString(ParamName, "manufacturerDate", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *pUlSize = sizeof(ManufacturerInfo.manufacturer_Date);
        }
    }
    else
    {
        AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
        return FALSE;
    }

    EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return status;
}

BOOL DPoE_DeviceSysDescrInfo_GetParamStringValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    char*                       pValue,
    ULONG*                      pUlSize
)
{
    dpoe_device_sys_descr_info_t    DeviceSysDescrInfo;
    BOOL status = dpoe_getDeviceSysDescrInfo(&DeviceSysDescrInfo);
    *pValue = NULL;
    *pUlSize = 0L;

    EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)

    //check the parameter name and return the corresponding value
    //TODO: Abdul
    /*
    if( AnscEqualString(ParamName, "vendorName", TRUE) )
    {
        if ( status == RETURN_OK )
        {            
            *pUlSize = strlen( (char *)&DeviceSysDescrInfo.info_vendorName );
        }
    }
    else if( AnscEqualString(ParamName, "modelNumber", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *pUlSize = strlen( (char *)&DeviceSysDescrInfo.info_modelNumber );
        }
    }
    else if( AnscEqualString(ParamName, "hardwareVersion", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *pUlSize = strlen( (char *)&DeviceSysDescrInfo.info_hardwareVersion );
        }
    }
    else
    {
        AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
        return FALSE;
    }
    */

    EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return status;
}

BOOL DPoE_OnuPacketBufferCapabilities_GetParamUlongValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    ULONG*                      puLong
)
{
    dpoe_onu_packet_buffer_capabilities_t    Capabilities;
    BOOL status = dpoe_getOnuPacketBufferCapabilities( &Capabilities );
    *puLong = 0L;

    EPONAGENTLOG(INFO, "Entering into <%s>\n", __FUNCTION__)

    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "upstreamQueues", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *puLong = Capabilities.capabilities_UpstreamQueues;
        }
    }
    else if( AnscEqualString(ParamName, "upQueuesMaxPerLink", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *puLong = Capabilities.capabilities_UpQueuesMaxPerLink;
        }
    }
    else if( AnscEqualString(ParamName, "upQueueIncrement", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *puLong = Capabilities.capabilities_UpQueueIncrement;
        }
    }
    else if( AnscEqualString(ParamName, "downstreamQueues", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *puLong = Capabilities.capabilities_DownstreamQueues;
        }
    }
    else if( AnscEqualString(ParamName, "dnQueuesMaxPerPort", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *puLong = Capabilities.capabilities_DnQueuesMaxPerPort;
        }
    }
    else if( AnscEqualString(ParamName, "dnQueueIncrement", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *puLong = Capabilities.capabilities_DnQueueIncrement;
        }
    }
    else if( AnscEqualString(ParamName, "totalPacketBuffer", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *puLong = Capabilities.capabilities_TotalPacketBuffer;
        }
    }
    else if( AnscEqualString(ParamName, "dnPacketBuffer", TRUE) )
    {
        if ( status == RETURN_OK )
        {
            *puLong = Capabilities.capabilities_DnPacketBuffer;
        }
    }
    else
    {
        AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
        return FALSE;
    }

    EPONAGENTLOG(INFO, "Exiting from <%s>\n", __FUNCTION__)
    return status;
}

ULONG DPoE_LlidForwardingState_GetEntryCount
(
    ANSC_HANDLE                 hInsContext
)
{
    AnscTraceWarning(("Unsupported parameter \n"));
    return 0;
}

ANSC_HANDLE DPoE_LlidForwardingState_GetEntry
(
    ANSC_HANDLE                 hInsContext,
    ULONG                       nIndex,
    ULONG*                      pInsNumber
)
{
    AnscTraceWarning(("Unsupported parameter \n"));
    return NULL;
}

BOOL DPoE_LlidForwardingState_GetParamBoolValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    BOOL*                       pBool
)
{
    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "forwardingState", TRUE) )
    {

    }
    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
    return FALSE;
}

BOOL DPoE_LlidForwardingState_GetParamIntValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    INT*                        iValue
)
{
    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
    return FALSE;
}

ULONG DPoE_OamFrameRate_GetEntryCount
(
    ANSC_HANDLE                 hInsContext
)
{
    AnscTraceWarning(("Unsupported parameter \n"));
    return 0;
}

ANSC_HANDLE DPoE_OamFrameRate_GetEntry
(
    ANSC_HANDLE                 hInsContext,
    ULONG                       nIndex,
    ULONG*                      pInsNumber
)
{
    AnscTraceWarning(("Unsupported parameter \n"));
    return NULL;
}

BOOL DPoE_OamFrameRate_GetParamIntValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    INT*                        iValue
)
{
    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "maxRate", TRUE) )
    {

    }

    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
    return FALSE;
}

ULONG DPoE_DynamicMacTable_GetEntryCount
(
    ANSC_HANDLE                 hInsContext
)
{
    AnscTraceWarning(("Unsupported parameter \n"));
    return 0;
}

ANSC_HANDLE DPoE_DynamicMacTable_GetEntry
(
    ANSC_HANDLE                 hInsContext,
    ULONG                       nIndex,
    ULONG*                      pInsNumber
)
{
    AnscTraceWarning(("Unsupported parameter \n"));
    return NULL;
}

BOOL DPoE_DynamicMacTable_GetParamStringValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    char*                       pValue,
    ULONG*                      pUlSize
)
{
    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "macAddress", TRUE) )
    {

    }

    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
    return FALSE;
}

BOOL DPoE_DynamicMacTable_GetParamIntValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    INT*                        iValue
)
{
    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "link", TRUE) )
    {

    }

    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
    return FALSE;
}

ULONG DPoE_StaticMacTable_GetEntryCount
(
    ANSC_HANDLE                 hInsContext
)
{
    AnscTraceWarning(("Unsupported parameter \n"));
    return 0;
}

ANSC_HANDLE DPoE_StaticMacTable_GetEntry
(
    ANSC_HANDLE                 hInsContext,
    ULONG                       nIndex,
    ULONG*                      pInsNumber
)
{
    AnscTraceWarning(("Unsupported parameter \n"));
    return NULL;
}

BOOL DPoE_StaticMacTable_GetParamUlongValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    ULONG*                      puLong
)
{
    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "link", TRUE) )
    {

    }

    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
    return FALSE;
}

BOOL DPoE_StaticMacTable_GetParamStringValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    char*                       pValue,
    ULONG*                      pUlSize
)
{
    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "macAddress", TRUE) )
    {

    }

    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
    return FALSE;
}

ULONG DPoE_OnuLinkStatistics_GetEntryCount
(
    ANSC_HANDLE                 hInsContext
)
{
    AnscTraceWarning(("Unsupported parameter \n"));
    return 0;
}

ANSC_HANDLE DPoE_OnuLinkStatistics_GetEntry
(
    ANSC_HANDLE                 hInsContext,
    ULONG                       nIndex,
    ULONG*                      pInsNumber
)
{
    AnscTraceWarning(("Unsupported parameter \n"));
    return NULL;
}

BOOL DPoE_OnuLinkStatistics_GetParamUlongValue
(
    ANSC_HANDLE                 hInsContext,
    char*                       ParamName,
    ULONG*                      puLong
)
{
    /* check the parameter name and return the corresponding value */
    if( AnscEqualString(ParamName, "rxUnicastFrames", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "txUnicastFrames", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "rxFrameTooShort", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "rxFrame64", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "rxFrame65_127", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "rxFrame128_255", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "rxFrame256_511", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "rxFrame512_1023", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "rxFrame1024_1518", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "rxFrame1519_Plus", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "txFrame64", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "txFrame65_127", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "txFrame128_255", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "txFrame256_511", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "txFrame512_1023", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "txFrame_1024_1518", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "txFrame_1519_Plus", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "framesDropped", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "bytesDropped", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "opticalMonVcc", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "opticalMonTxBiasCurrent", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "opticalMonTxPower", TRUE) )
    {

    }
    else if( AnscEqualString(ParamName, "opticalMonRxPower", TRUE) )
    {

    }
    AnscTraceWarning(("Unsupported parameter '%s'\n", ParamName));
    return FALSE;
}

