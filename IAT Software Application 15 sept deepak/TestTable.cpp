#include "TestTable.h"

SUB_TEST SMFD_VISUAL[] =
{
 {"1.01 CMA-7200 Smart Display",1.01},
 {"1.02 CMA-2140 Multifunction Display",1.02},
 {"1.03 Check for any damages",1.03},
 {"1.04 Check for any scratches",1.04},
 {"1.05 Check for any Loose Screws",1.05},
 {"1.06 Check for any bent pins ",1.06}
};

SUB_TEST SMFD_CURRENT[] =
{
 {"2.01 SMFD1 Current",2.01},
 {"2.02 SMFD2 Current",2.02},
 {"2.03 MFD1 Current",2.03},
 {"2.04 MFD2 Current",2.04}
};

SUB_TEST SMFD_SW[] =
{
 {"3.01 Operational Software",3.01}
};

SUB_TEST SMFD_ANALOG[] =
{
 {"4.01 Engine Oil Temperature",4.01},
 {"4.02 Engine Oil Pressure",4.02},
 {"4.03 Engine Torque",4.03},
 {"4.04 Rudder Trim Position",4.04},
 {"4.05 Elevator Trim",4.05},
 {"4.06 Aileron Trim",4.06},
 {"4.07 Flap Position 3V",4.07},
 {"4.08 Flap Position 4V",4.08},
 {"4.09 Generator Voltage",4.09},
 {"4.10 Battery Voltage",4.10},
 {"4.11 Current  Load",4.11},
 {"4.12 Hydraulics pressure main",4.12},
 {"4.13 Hydraulics pressure emergency",4.13},
 {"4.14 Emergency  brake",4.14},
 {"4.15 LH Brake pressure",4.15},
 {"4.16 RH brake pressure",4.16},
 {"4.17 Engine speed",4.17},
 {"4.18 fuel tank LH",4.18},
 {"4.19 fuel tank RH",4.19 },
 {"4.20 Collector tank",4.20},
};

SUB_TEST SMFD_FUEL[] =
{
 {"5.01 Fuel Flow",5.01}
};

SUB_TEST SMFD_DISCRETE[] =
{
 {"6.01 Bus Tie Contactor",6.01},
 {"6.02 Canopy",6.02},
 {"6.03 ECS OFF",6.03},
 {"6.04 ECS Over Pressure",6.04},
 {"6.05 AOA Mute",6.05},
 {"6.06 Alarm Mute",6.06},
 {"6.07 Demist",6.07},
 {"6.08 Start ON",6.08}
};

SUB_TEST SMFD_REV[] =
{
 {"7.01 Press bottom 5th key on SMFD FC/RC",7.01}
};

SUB_TEST SMFD_ADC[] =
{
 {"8.01 Pressure Altitude",8.01},
 {"8.02 MACH",8.02},
 {"8.03 Computed Air Speed",8.03},
 {"8.04 Altitude Rate",8.04},
 {"8.05 Static Air Temperature",8.05},
 {"8.06 True Air Speed",8.06}
};

SUB_TEST SMFD_AHRS[] =
{
 {"9.01 Magnetic Heading",9.01},
 {"9.02 Pitch",9.02},
 {"9.03 Roll",9.03},
 {"9.04 Body Yaw Rate",9.04},
 {"9.05 Lateral Acceleration",9.05},
 {"9.06 Normal Acceleration",9.06}
};

SUB_TEST SMFD_VOR[] =
{
 {"10.01 VOR/ILS Frequency",10.01},
 {"10.02 Localizer Deviation",10.02},
 {"10.03 Glideslope Deviation",10.03},
 {"10.04 VOR Bearing",10.04}
};

SUB_TEST SMFD_TACAN[] =
{
 {"11.01 TACAN Channel",11.01},
 {"11.02 TACAN Distance",11.02},
 {"11.03 TACAN Bearing",11.03}
};
SUB_TEST SMFD_GPS[] =
{
 {"12.01 GPS Ground Speed",12.01},
 {"12.02 GPS True Track",12.02},
 {"12.03 GPS Mag Track",12.03},
 {"12.04 GPS Actual Time",12.04},
};

MAIN_TEST SMFD_MAIN[] =
{
 {"1.Visual Examination",SMFD_VISUAL,6},
 {"2.Current Consumption Checks",SMFD_CURRENT,4},
 {"3.Software Configuration Checks",SMFD_SW,1},
 {"4.Analog Parameter Checks",SMFD_ANALOG,19},
 {"5.Fuel Flow Checks",SMFD_FUEL,1},
 {"6.Discrete Parameter Checks",SMFD_DISCRETE,8},
 {"7.Reversionary Page Checks",SMFD_REV,1},
 {"8.ADC Parameter Checks",SMFD_ADC,6},
 {"9.AHRS Parameter Checks",SMFD_AHRS,6},
 {"10.VOR/ILS Parameter Checks",SMFD_VOR,4},
 {"11.TACAN Parameter Checks",SMFD_TACAN,3},
 {"12.GPS Parameter Checks",SMFD_GPS,4},
};
/////////////////ISIS/////////////////////////
SUB_TEST ISIS_VISUAL[] =
{
 {"1.01 Display Unit Part No",1.01},
 {"1.02 Air Data Unit Part No",1.02},
 {"1.03 Magnetometer Sensor Part No",1.03},
 {"1.04 AHRS Part No",1.04},
 {"1.05 Check for any damages",1.05},
 {"1.06 Check for any scratches",1.06},
 {"1.07 Check for any Loose Screws",1.07},
 {"1.08 Check for any bent pins ",1.08}
};

SUB_TEST ISIS_POWER[] =
{
 {"2.01 Current Rating of ISIS-DU FC",2.01},
  {"2.02 Current Rating of ISIS-DU RC",2.02},
   {"2.03 Current Rating of ISIS ADU",2.03},
    {"2.04 Current Rating of ISIS AHRS",2.04}
};

SUB_TEST ISIS_SW[] =
{
 {"3.01 ISIS-DU FC MPM Software Version",3.01},
 {"3.02 ISIS-DU FC MPM Software Checksum",3.02},
 {"3.03 ISIS-DU FC BLGM Software Version",3.03},
 {"3.04 ISIS-DU FC BLGM Software Checksum",3.04},
 {"3.05 ISIS-DU RC MPM Software Version",3.05},
 {"3.06 ISIS-DU RC MPM Software Checksum",3.06},
 {"3.07 ISIS-DU RC BLGM Software Version",3.07},
 {"3.08 ISIS-DU RC BLGM Software Checksum",3.08}

};

SUB_TEST ISIS_IBIT[] =
{
 {"4.01 ISIS FC IBIT check",4.01},
 {"4.02 ISIS RC IBIT Check",4.02}
};

SUB_TEST ISIS_BRT[] =
{
 {"5.01 ISIS FC BRT check",5.01},
 {"5.02 ISIS RC BRT Check",5.02}
};

SUB_TEST ISIS_ALN[] =
{
 {"6.01 ISIS FC ALN check",6.01},
 {"6.02 ISIS RC ALN Check",6.02}
};

SUB_TEST ISIS_NAV[] =
{
 {"7.01 ISIS FC NAV check",7.01},
 {"7.02 ISIS RC NAV Check",7.02}
};


SUB_TEST ISIS_ATT[] =
{
 {"8.01 ISIS-DU FC Roll Angle Check",8.01},
 {"8.02 ISIS-DU FC Pitch Angle Check",8.01},
 {"8.03 ISIS-DU FC Heading Check",8.03},
 {"8.04 ISIS-DU RC Roll Angle Check",8.04},
 {"8.05 ISIS-DU RC Pitch Angle Check",8.05},
 {"8.06 ISIS-DU RC Heading Check",8.06}
};

SUB_TEST ISIS_AIRDATA[] =
{
 {"9.01 Air Speed ISIS-DU FC ",9.01},
 {"9.02 Altitude ISIS-DU FC",9.02},
 {"9.03 Mach ISIS-DU FC",9.03},
 {"9.04 Vertical Speed Marker ISIS-DU FC",9.04},
 {"9.05 Air Speed ISIS-DU RC",9.05},
 {"9.02 Altitude ISIS-DU RC",9.06},
 {"9.03 Mach ISIS-DU RC",9.07},
 {"9.04 Vertical Speed Marker ISIS-DU RC",9.08},
};
MAIN_TEST ISIS_MAIN[] =
{
 {"1.Visual Examination",ISIS_VISUAL,8},
 {"2.Power Consumption Checks",ISIS_POWER,4},
 {"3.Software Verification Checks",ISIS_SW,8},
 {"4.IBIT Checks",ISIS_IBIT,2},
 {"5.Brightness and Set knob Checks",ISIS_BRT,2},
 {"6 Alignment Mode Checks",ISIS_ALN,2},
 {"7.Navigation mode Checks",ISIS_NAV,2},
 {"8.Attitude and Heading Checks",ISIS_ATT,6},
 {"9.Air Data Parameter Checks",ISIS_AIRDATA,8}
};


/*                                ADC                     */


SUB_TEST ADC_VISUAL[] =
{
 {"1.01 Part No of ADC",1.01},
 {"1.02 Inspect for any Damage",1.02},
 {"1.03 Inspect for blocking of pressure input holes (ps,pt).",1.03},
 {"1.04 Inspect for corrosion on the ADC.",1.04},
 {"1.05 Inspect for any foreign material and loose parts.",1.05},
 {"1.06 Inspect for markings on pressure connectors",1.06}

};

SUB_TEST ADC_LEAK[] =
{
 {"2.01 Pitot Pressure Leak Test",2.01},
 {"2.02 Static Pressure Leak Test",2.02}
};

SUB_TEST ADC_POWER[] =
{
 {"3.01 Current Drawn by ADC",3.01}
};

SUB_TEST ADC_FUNC[] =
{
 {"4.01 Altitude Check at 7500 ft",4.01},
 {"4.02 Altitude Check at 15000 ft",4.02},
 {"4.03 Altitude Check at 20000 ft",4.03},
 {"4.04 Altitude Rate Check (positive)",4.04},
 {"4.05 Altitude Rate Check (negative)",4.05},
 {"4.06 Air Speed Check at 100 knots",4.06},
 {"4.07 Air Speed Check at 180 knots",4.07},
 {"4.08 Air Speed Check at 220 knots",4.08},
 {"4.09 Mach Number Check at 3000 Altitude",4.09},
 {"4.10 Mach Number Check at 6000 Altitude",4.10},
};
MAIN_TEST ADC_MAIN[] =
{
 {"1.Visual Examination",ADC_VISUAL,6},
 {"2.Leak Test",ADC_LEAK,2},
 {"3.Power Consumption",ADC_POWER,1},
 {"4.Functional Checks",ADC_FUNC,10}
};


/*     AHRS           */

SUB_TEST AHRS_VISUAL[] =
{
 {"1.01 Part No AHRU",1.01},
 {"1.02 Part No RMM",1.02},
 {"1.03 Part No MMS",1.03},
 {"1.04 Check for any damages",1.04},
 {"1.05 Check for any scratches",1.05},
 {"1.06 Check for any Loose Screws",1.06},
 {"1.07 Check for any bent pins ",1.07}
};

SUB_TEST AHRS_POWER[] =
{
 {"2.01 Current Drawn @28V",2.01}
};
SUB_TEST AHRS_Qualitative[] =
{
 {"3.01 AHRS Pitch check",3.01},
 {"3.02 AHRS Roll check",3.02},
 {"3.03 AHRS Heading check",3.03}
};


MAIN_TEST AHRS_MAIN[] =
{
 {"1.Visual Examination",AHRS_VISUAL,4},
 {"2.Power Consumption Checks",AHRS_POWER,1},
 {"3.AHRS Qualitative Checks",AHRS_Qualitative,3}
};


/*  GPS  */

SUB_TEST GPS_VISUAL[] =
{
 {"1.01 GTN625Xi Part & Serial No",1.01},
 {"1.02 Check for any damages",1.02},
 {"1.03 Check for any scratches",1.03},
 {"1.04 Check for any Loose Screws",1.04},
 {"1.05 Check for any bent pins ",1.05}
};

SUB_TEST GPS_POWER[] =
{
 {"2.01 Voltage",2.01},
 {"2.01 Current",2.02}
};

SUB_TEST GPS_DB[] =
{
 {"3.01 Navigation DB",3.01},
 {"3.02 Base DB",3.02},
 {"3.03 Obstacle DB",3.03},
 {"3.04 Safe Taxi DB",3.04},
 {"3.05 Terrain DB",3.05}
};

SUB_TEST GPS_SYS[] =
{
 {"4.01 Serial Number",4.01},
 {"4.02 System ID",4.02},
 {"4.03 Main Software Version",4.03},
 {"4.04 GPS/WAAS Software Version",4.04}
};


MAIN_TEST GPS_MAIN[] =
{
 {"1.Visual Examination",GPS_VISUAL,5},
 {"2.Power ON Checks",GPS_POWER,2},
 {"3.Database Information",GPS_DB,5},
 {"4.System Information",GPS_SYS,4}
 
};


/*  VOR/ILS /TACAN */

SUB_TEST NAV_VISUAL[] =
{
 {"1.01 Serial & Part Number",1.01},
 {"1.02 Check for any damages",1.02},
 {"1.03 Check for any scratches",1.03},
 {"1.04 Check for any Loose Screws",1.04},
 {"1.05 Check for any bent pins ",1.05}
};

SUB_TEST NAV_POWER[] =
{
 {"2.01 Current",2.01}
};

MAIN_TEST NAV_MAIN[] =
{
 {"1.Visual Examination",NAV_VISUAL,5},
 {"2.Power ON Checks",NAV_POWER,1}
 
};




LRU_TEST LRU_Table[] =
{
 {"SMFD_MFD",SMFD_MAIN,12},
 {"ISIS",ISIS_MAIN,9},
 {"ADC",ADC_MAIN,4},
 {"AHRS",AHRS_MAIN,3},
 {"GPS",GPS_MAIN,4},
 {"NAV",NAV_MAIN,2}
};
int g_LRU_Count = sizeof(LRU_Table) / sizeof(LRU_Table[0]);