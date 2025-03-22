#include "sierrachart.h"
#include "SCStudyFunctions.h"

SCDLLName("Bookmap Statistics")

/*
 *  This study is designed to putput a csv compatible file that cloud notes in Bookmap can read using Sierra chart.
 *
 *  Output example:
                        Symbol,Price Level,Note,Foreground Color,Background Color,Text Alignment,Notification Enabled,Sound Notification Enabled,Notification Is Repeatable,Delay Before Repeating,Subscribing Offset,Notification Sound
                        ESM5.CME@RITHMIC,5653.50,IBL,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5675.75,IBH,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5662.50,onVPOC,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5668.00,VPOC,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5723.75,ethHi,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5651.25,ethLow,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5687.50,ethMid,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5714.00,yVPOC,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5765.25,yHi,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5684.50,yLow,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5716.50,pCL,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5662.75,VAL,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5672.25,VAH,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5576.75,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5579.75,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5583.50,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5592.25,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5599.75,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5602.25,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5606.00,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5607.25,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5612.00,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5617.25,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5618.50,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5631.25,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5632.50,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5642.25,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5645.75,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5659.25,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5663.00,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5670.25,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5690.00,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5694.50,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5710.00,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5724.50,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5730.00,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5737.00,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5740.00,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5741.75,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5747.75,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5767.75,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5772.25,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5782.50,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5797.25,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5802.25,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5807.50,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5812.25,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5815.00,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5821.25,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5829.75,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5835.00,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5840.25,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5843.75,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5851.25,LVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5858.75,HVN,#FFFFFF,#3b6b01,right,,,,,,
                        ESM5.CME@RITHMIC,5867.25,HVN,#FFFFFF,#3b6b01,right,,,,,,

 *
 *  To use this study you will need to move it to Sierra's ACS directory and compile it.
 *
 *  This requires using a VB TPO chart, you will need to go into settings of the study and enter the TPO ID of the study,   In my config,
 *  I have ES chart as the TPO, then VbP for TPO chart as #2 and this bookmap study as #3.
 *
 *  The TPO chart must have both evening and day sessions configured, as the output depends on both.   The VPO indicator is desgined to show a list of HVNs and
 *  LVNs.
 *
 *  You wil need to set in the settings the name for the output csv file for the instrument.  eg  ESM5.CME@RITHMIC.
 *  You will need to change the settings in write_csv to the right path.
 *
 */

/*
 *  Use this file completely at your own risk.  No guarantees is implied or otherwise.
 *
 */

 typedef struct
{
    float value;
    unsigned int lvn_or_hvn;
} htf_hvn_lvn;

#define MAX_HTF_HVN_LVN 1000
htf_hvn_lvn g_hvn_lvn[MAX_HTF_HVN_LVN];
unsigned int g_hvn_lvn_max_index = 0;

void set_str_element(SCString &out, SCString &in, const char *symbol, const char *element_name, float element)
{
    in.Clear();
    in.AppendFormat(symbol);
    in.AppendFormat(",%.2f,", element);
    in.Append(element_name);
    in.AppendFormat(",#FFFFFF,#3b6b01,right,,,,,,\r\n");
    out += in;
}

void write_csv(SCStudyInterfaceRef &sc, const char *symbol, float ibl, float ibh, float eth_hi, float eth_low, float eth_mid, float onvpoc,
               float vpoc, float yvpoc, float prev_high, float prev_low, float prev_cl, float val, float vah)
{
    int FileHandle = 0;
    unsigned int BytesWritten;

    // Replace PathAndFileName with your path that you desire
    const char *header = "Symbol,Price Level,Note,Foreground Color,Background Color,Text Alignment,Notification Enabled,Sound Notification Enabled,Notification Is Repeatable,Delay Before Repeating,Subscribing Offset,Notification Sound\r\n";
    SCString PathAndFileName = "C:\\Users\\<USER>\\Documents\\tinyserver\\cn.csv"; // sc.DataFilesFolder();
    sc.OpenFile(PathAndFileName, n_ACSIL::FILE_MODE_CREATE_AND_OPEN_FOR_READ_WRITE, FileHandle);
    SCString Data;
    Data += header;
    SCString in_str;

    set_str_element(Data, in_str, symbol, "IBL", ibl);
    set_str_element(Data, in_str, symbol, "IBH", ibh);
    set_str_element(Data, in_str, symbol, "onVPOC", onvpoc);
    set_str_element(Data, in_str, symbol, "VPOC", vpoc);
    set_str_element(Data, in_str, symbol, "ethHi", eth_hi);
    set_str_element(Data, in_str, symbol, "ethLow", eth_low);
    set_str_element(Data, in_str, symbol, "ethMid", eth_mid); // IBL.Clear();
    set_str_element(Data, in_str, symbol, "yVPOC", yvpoc);
    set_str_element(Data, in_str, symbol, "yHi", prev_high); // IBL.Clear();
    set_str_element(Data, in_str, symbol, "yLow", prev_low);
    set_str_element(Data, in_str, symbol, "pCL", prev_cl);
    set_str_element(Data, in_str, symbol, "VAL", val);
    set_str_element(Data, in_str, symbol, "VAH", vah);

    for (int i = 0; i < g_hvn_lvn_max_index; i++)
    {
        if (g_hvn_lvn[i].lvn_or_hvn == 0)
        {
            // lvn
            set_str_element(Data, in_str, symbol, "LVN", g_hvn_lvn[i].value);
        }
        else
        {
            set_str_element(Data, in_str, symbol, "HVN", g_hvn_lvn[i].value);
        }
    }
    // IBL.AppendFormat(symbol);
    // IBL.AppendFormat(",%.2f,IBL,#FFFFFF,#3b6b01,right,,,,,,\r\n", ibl);

    // Data += in_str;
    sc.WriteFile(FileHandle, Data.GetChars(), Data.GetLength(), &BytesWritten);
    sc.CloseFile(FileHandle);
}

/*==========================================================================*/
SCSFExport scsf_Bookmap(SCStudyInterfaceRef sc)
{
    SCSubgraphRef Subgraph_IBHigh = sc.Subgraph[0];
    SCSubgraphRef Subgraph_IBLow = sc.Subgraph[1];
    SCSubgraphRef Subgraph_High = sc.Subgraph[2];
    SCSubgraphRef Subgraph_Low = sc.Subgraph[3];
    SCSubgraphRef Subgraph_EthHigh = sc.Subgraph[4];
    SCSubgraphRef Subgraph_EthLow = sc.Subgraph[5];
    SCSubgraphRef Subgraph_VPOC = sc.Subgraph[6];
    SCSubgraphRef Subgraph_onVPOC = sc.Subgraph[7];
    SCSubgraphRef Subgraph_prevVPOC = sc.Subgraph[8];
    SCSubgraphRef Subgraph_prevHi = sc.Subgraph[9];
    SCSubgraphRef Subgraph_prevLow = sc.Subgraph[10];
    SCSubgraphRef Subgraph_prevCL = sc.Subgraph[11];
    SCSubgraphRef Subgraph_VAL = sc.Subgraph[12];
    SCSubgraphRef Subgraph_VAH = sc.Subgraph[13];

    float ibh = 0.0;
    float ibl = 0.0;
    float eth_low = 0.0;
    float eth_high = 0.0;
    float eth_mid = 0.0;
    float vpoc = 0.0;
    float onvpoc = 0.0;
    float yvpoc = 0.0;

    float pHi = 0.0;
    float pLow = 0.0;
    float pCL = 0.0;

    float val = 0.0;
    float vah = 0.0;

    SCInputRef Input_TPO_Index = sc.Input[0];
    SCInputRef Input_VPS_Index = sc.Input[1];
    SCInputRef Input_HTF_Index = sc.Input[2];
    SCInputRef Input_Symbol = sc.Input[3];
    if (sc.SetDefaults)
    {
        sc.GraphName = "Bookmap";
        sc.DrawZeros = 0;
        sc.GraphRegion = 0;
        sc.AutoLoop = 1;

        // We must use a low precedence level to ensure
        // the other studies are already calculated first.
        // sc.CalculationPrecedence = LOW_PREC_LEVEL;

        sc.ScaleRangeType = SCALE_SAMEASREGION;
        Subgraph_IBHigh.Name = "IB High";
        Subgraph_IBHigh.PrimaryColor = RGB(128, 255, 128);
        Subgraph_IBHigh.DrawStyle = DRAWSTYLE_DASH;
        Subgraph_IBHigh.DrawZeros = false;
        Subgraph_IBHigh.LineLabel |= LL_DISPLAY_VALUE | LL_DISPLAY_NAME;

        Subgraph_IBLow.Name = "IB Low";
        Subgraph_IBLow.PrimaryColor = RGB(255, 0, 0);
        Subgraph_IBLow.DrawStyle = DRAWSTYLE_DASH;
        Subgraph_IBLow.DrawZeros = false;
        Subgraph_IBLow.LineLabel |= LL_DISPLAY_VALUE | LL_DISPLAY_NAME;

        Subgraph_High.Name = "High";
        Subgraph_High.PrimaryColor = RGB(128, 255, 128);
        Subgraph_High.DrawStyle = DRAWSTYLE_DASH;
        Subgraph_High.DrawZeros = false;

        Subgraph_Low.Name = "Low";
        Subgraph_Low.PrimaryColor = RGB(255, 0, 0);
        Subgraph_Low.DrawStyle = DRAWSTYLE_DASH;
        Subgraph_Low.DrawZeros = false;

        Subgraph_EthHigh.Name = "EthHigh";
        Subgraph_EthHigh.PrimaryColor = RGB(128, 255, 128);
        Subgraph_EthHigh.DrawStyle = DRAWSTYLE_DASH;
        Subgraph_EthHigh.DrawZeros = false;
        Subgraph_EthHigh.LineLabel |= LL_DISPLAY_VALUE | LL_DISPLAY_NAME;

        Subgraph_EthLow.Name = "EthLow";
        Subgraph_EthLow.PrimaryColor = RGB(255, 0, 0);
        Subgraph_EthLow.DrawStyle = DRAWSTYLE_DASH;
        Subgraph_EthLow.DrawZeros = false;
        Subgraph_EthLow.LineLabel |= LL_DISPLAY_VALUE | LL_DISPLAY_NAME;

        Subgraph_VPOC.Name = "VPOC";
        Subgraph_VPOC.PrimaryColor = RGB(255, 0, 0);
        Subgraph_VPOC.DrawStyle = DRAWSTYLE_DASH;
        Subgraph_VPOC.DrawZeros = false;
        Subgraph_VPOC.LineLabel |= LL_DISPLAY_VALUE | LL_DISPLAY_NAME;

        Subgraph_onVPOC.Name = "onVPOC";
        Subgraph_onVPOC.PrimaryColor = RGB(255, 0, 0);
        Subgraph_onVPOC.DrawStyle = DRAWSTYLE_DASH;
        Subgraph_onVPOC.DrawZeros = false;
        Subgraph_onVPOC.LineLabel |= LL_DISPLAY_VALUE | LL_DISPLAY_NAME;

        Subgraph_prevVPOC.Name = "yVPOC";
        Subgraph_prevVPOC.PrimaryColor = RGB(255, 0, 0);
        Subgraph_prevVPOC.DrawStyle = DRAWSTYLE_DASH;
        Subgraph_prevVPOC.DrawZeros = false;
        Subgraph_prevVPOC.LineLabel |= LL_DISPLAY_VALUE | LL_DISPLAY_NAME;

        Subgraph_prevHi.Name = "pHi";
        Subgraph_prevHi.PrimaryColor = RGB(255, 0, 0);
        Subgraph_prevHi.DrawStyle = DRAWSTYLE_DASH;
        Subgraph_prevHi.DrawZeros = false;
        Subgraph_prevHi.LineLabel |= LL_DISPLAY_VALUE | LL_DISPLAY_NAME;

        Subgraph_prevLow.Name = "pLow";
        Subgraph_prevLow.PrimaryColor = RGB(255, 0, 0);
        Subgraph_prevLow.DrawStyle = DRAWSTYLE_DASH;
        Subgraph_prevLow.DrawZeros = false;
        Subgraph_prevLow.LineLabel |= LL_DISPLAY_VALUE | LL_DISPLAY_NAME;

        Subgraph_prevCL.Name = "pCL";
        Subgraph_prevCL.PrimaryColor = RGB(255, 0, 0);
        Subgraph_prevCL.DrawStyle = DRAWSTYLE_DASH;
        Subgraph_prevCL.DrawZeros = false;
        Subgraph_prevCL.LineLabel |= LL_DISPLAY_VALUE | LL_DISPLAY_NAME;

        Subgraph_VAL.Name = "VAL";
        Subgraph_VAL.PrimaryColor = RGB(255, 0, 0);
        Subgraph_VAL.DrawStyle = DRAWSTYLE_DASH;
        Subgraph_VAL.DrawZeros = false;
        Subgraph_VAL.LineLabel |= LL_DISPLAY_VALUE | LL_DISPLAY_NAME;

        Subgraph_VAH.Name = "VAH";
        Subgraph_VAH.PrimaryColor = RGB(255, 0, 0);
        Subgraph_VAH.DrawStyle = DRAWSTYLE_DASH;
        Subgraph_VAH.DrawZeros = false;
        Subgraph_VAH.LineLabel |= LL_DISPLAY_VALUE | LL_DISPLAY_NAME;

        // Inputs
        Input_TPO_Index.Name = "TPO ID";
        Input_TPO_Index.SetInt(2);

        Input_VPS_Index.Name = "Volume By Price ID";
        Input_VPS_Index.SetInt(3);

        Input_HTF_Index.Name = "HTF Volume Info (Overlay)";
        Input_HTF_Index.SetInt(4);

        Input_Symbol.Name = "Contract Symbol";
        Input_Symbol.SetString("ESZ4.CME@RITHMIC");
        return;
    }

    n_ACSIL::s_StudyProfileInformation info_0;
    n_ACSIL::s_StudyProfileInformation info_1;
    n_ACSIL::s_StudyProfileInformation info_2;

    sc.GetStudyProfileInformation(Input_TPO_Index.GetInt(), 0, info_0);
    sc.GetStudyProfileInformation(Input_TPO_Index.GetInt(), 1, info_1);
    sc.GetStudyProfileInformation(Input_TPO_Index.GetInt(), 2, info_2);

    n_ACSIL::s_StudyProfileInformation vol_info_0;
    sc.GetStudyProfileInformation(Input_VPS_Index.GetInt(), 0, vol_info_0);

    ibh = Subgraph_IBHigh[sc.Index] = info_0.m_IBRHighPrice;
    ibl = Subgraph_IBLow[sc.Index] = info_0.m_IBRLowPrice;
    Subgraph_High[sc.Index] = info_0.m_HighestPrice;
    Subgraph_Low[sc.Index] = info_0.m_LowestPrice;

    SCDateTime info_0_date_time = info_0.m_StartDateTime;
    SCDateTime StartTimeOfEveningSession;
    StartTimeOfEveningSession.SetTime(sc.StartTime2);

    /* if index 0 is evening session*/
    if (info_0_date_time.GetHour() == StartTimeOfEveningSession.GetHour())
    {
        eth_high = Subgraph_EthHigh[sc.Index] = info_0.m_HighestPrice;
        eth_low = Subgraph_EthLow[sc.Index] = info_0.m_LowestPrice;
        onvpoc = Subgraph_onVPOC[sc.Index] = info_0.m_VolumePOCPrice;
        yvpoc = Subgraph_prevVPOC[sc.Index] = info_1.m_VolumePOCPrice;
        pHi = Subgraph_prevHi[sc.Index] = info_1.m_HighestPrice;
        pLow = Subgraph_prevLow[sc.Index] = info_1.m_LowestPrice;
        pCL = Subgraph_prevCL[sc.Index] = info_1.m_LastPrice;
    }
    else
    {
        eth_high = Subgraph_EthHigh[sc.Index] = info_1.m_HighestPrice;
        eth_low = Subgraph_EthLow[sc.Index] = info_1.m_LowestPrice;
        onvpoc = Subgraph_onVPOC[sc.Index] = info_1.m_VolumePOCPrice;
        vpoc = Subgraph_VPOC[sc.Index] = info_0.m_VolumePOCPrice;
        yvpoc = Subgraph_prevVPOC[sc.Index] = info_2.m_VolumePOCPrice;
        pHi = Subgraph_prevHi[sc.Index] = info_2.m_HighestPrice;
        pLow = Subgraph_prevLow[sc.Index] = info_2.m_LowestPrice;
        pCL = Subgraph_prevCL[sc.Index] = info_2.m_LastPrice;
    }

    vah = Subgraph_VAH[sc.Index] = info_0.m_VolumeValueAreaHigh;
    val = Subgraph_VAL[sc.Index] = info_0.m_VolumeValueAreaLow;
    eth_mid = ((eth_high - eth_low) / 2.0f) + eth_low;

    int hvn_lvn_index = 0;
    int ret = 0;
    float price = 0;
    int hvn_lvn_type = 0;
    int temp_index = 0;
    int temp_index_2 = 0;

    /*
     *  Note:  to get HTF information you need to create a separate chart (TPO one will not give you HTF unfortunately)
     *  and specify the chart number below (1 in my case) and the study number (3 in my case) to use Volume by Price studies.
     */
    while (hvn_lvn_index < MAX_HTF_HVN_LVN)
    {
        ret = sc.GetStudyPeakValleyLine(/*sc.ChartNumber*/ 1, 3 /*Input_HTF_Index.GetInt()*/, price, hvn_lvn_type,
                                        temp_index, temp_index_2, -1, hvn_lvn_index);
        if (ret)
        {
            // sc.AddMessageToLog("Got a valley or peak\n", 0);
            g_hvn_lvn[hvn_lvn_index].value = price;
            if (hvn_lvn_type == PEAKVALLEYTYPE_PEAK)
            {
                g_hvn_lvn[hvn_lvn_index].lvn_or_hvn = 1;
            }
            else
            {
                g_hvn_lvn[hvn_lvn_index].lvn_or_hvn = 0;
            }
            hvn_lvn_index++;
            g_hvn_lvn_max_index = hvn_lvn_index;
            if (hvn_lvn_index >= MAX_HTF_HVN_LVN)
            {
                g_hvn_lvn_max_index = hvn_lvn_index;
                break;
            }
        }
        else
        {
            // sc.AddMessageToLog("Didn't find a valley or peak, last index\n", 0);
            g_hvn_lvn_max_index = hvn_lvn_index;
            break;
        }
    }

    write_csv(sc, Input_Symbol.GetString(), ibl, ibh, eth_high, eth_low, eth_mid, onvpoc, vpoc, yvpoc, pHi, pLow,
              pCL, val, vah);
}
